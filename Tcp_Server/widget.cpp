#include "widget.h"
#include "ui_widget.h"
#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>
#include <QDataStream>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    users.clear();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_startButton_clicked()
{
    // Создаем и настраиваем сервер
    server = new QTcpServer(this);
    connect(server, &QTcpServer::newConnection, this, &Widget::clientNewConnection);

    ushort port = ui->listenPortEdit->text().toUShort();

    // Попытка запуска прослушивания порта
    bool success = server->listen(QHostAddress::Any, port);

    if (success)
    {
        // Если сервер успешно начал прослушивание порта
        qDebug() << "Сервер успешно начал прослушивание порта:" << port;
        ui->startButton->setEnabled(false);
    }
    else
    {
        // Если сервер не смог начать прослушивание порта
        qDebug() << "Не удалось запустить прослушивание порта:" << port;
        qDebug() << "Ошибка:" << server->errorString();
    }
}

// Обработка подключения нового клиента
void Widget::clientNewConnection()
{
    // Пока есть ожидающие клиентские поключения
    while(server->hasPendingConnections()) {
        // Получаем и настраиваем клиентское подключение
        QTcpSocket *client = server->nextPendingConnection();
        connect(client, &QTcpSocket::readyRead, this, &Widget::clientReadyRead);
        connect(client, &QTcpSocket::disconnected, this, &Widget::clientDisconnected);
        // Сохраняем сокет подключенного клиента
        clients << client;
        // Отображаем IP подключенного клиента
        ui->clientListWidget->addItem(QHostAddress(client->peerAddress().toIPv4Address()).toString());


        QDataStream out (client);
        out << qint32(4) << users;
    }
}

// Обработка приема данных от клиентов
void Widget::clientReadyRead()
{
    QTcpSocket *client = (QTcpSocket*)sender();
    QDataStream stream(client);

    while(client->bytesAvailable() > 0)
    {
        stream.startTransaction();
        int id;
        stream >> id;
        qDebug() << "Received id:" << id;

        if (id == 1 ) { // Клиент прислал сообщение
            QTime time;
            QString nick;
            QString message;
            stream >> time >> nick >> message;

            if(!stream.commitTransaction()) {
                stream.rollbackTransaction();
                break;
            }

            QString messag = time.toString("hh:mm:ss") + "\n" + "Отправил:" + nick + "\n" + message;
            ui->chatEdit->append(messag);

            for(QTcpSocket *cli : qAsConst(clients)) {
                if(cli != client) {
                    QDataStream out (cli);
                    out << qint32(3) << QTime::currentTime()  << nick << message;
                }
            }
        }
        else if(id == 2) { // Клиент прислал свой ник
            QString clienNick;
            stream >> clienNick;

            if(!stream.commitTransaction()) {
                stream.rollbackTransaction();
                break;
            }

            int clientIndex = clients.indexOf(client);
            ui->clientListWidget->item(clientIndex)->setText(clienNick);

            users << clienNick;

            for(QTcpSocket *cli : qAsConst(clients)) {
                QDataStream out (cli);
                out << qint32(4) << users;
            }
        }
    }
//    if (id == 3)
//    {
//        QString clientNickname;
//        stream1 >> clientNickname;
//        users.append(clientNickname);
//        for(QTcpSocket *cli : qAsConst(clients)){
//            QString cl = ",";

//            cli->write(cl.toUtf8());
//            cli->waitForReadyRead(20);
//            for (int i = 0; i < users.length(); ++i)
//            {
//                cli->write(("!" + users[i].toUtf8()));
//                cli->waitForReadyRead(20);
//            }
//        }
//    }

}

// Обработка отключения клиента
void Widget::clientDisconnected()
{
    // Клиентский сокет, который отключился
    QTcpSocket *client = (QTcpSocket*)sender();
    // Удаляем клиента из списков
    int index = clients.indexOf(client);
    ui->clientListWidget->takeItem(index);
    if(index >= 0) {
        clients.removeAt(index);
        ui->clientListWidget->takeItem(index);
    }
}
