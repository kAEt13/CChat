#include "widget.h"
#include "ui_widget.h"
#include <QHostAddress>
#include <QMessageBox>
#include <QDateTime>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    // Создаем и настраиваем клиенсткий сокет.
    socket = new QTcpSocket(this);
    connect(socket, &QTcpSocket::readyRead, this, &Widget::socketReadyRead);
    connect(socket, &QTcpSocket::disconnected, this, &Widget::socketDisconnected);
    connect(socket, &QTcpSocket::connected, this, &Widget::socketConnected);
    connect (socket,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(socketErr(QAbstractSocket::SocketError)));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_connectToServerButton_clicked()
{
    // "Координаты" сервера (IP-адрес и порт).
    QString serverIp = ui->serverIpEdit->text();
    QHostAddress serverAddress(serverIp);
    ushort serverPort = ui->serverPortEdit->text().toUShort();

    // Подключаемся к серверу.
    // Может быть долго...
    socket->connectToHost(serverAddress, serverPort);

    // Дождаться подключения к серверу можно и тут.
    // Ожидание (10 сек) подключения ...
    bool connected = socket->waitForConnected(10000);
    ui->sendMessageButton->setEnabled(connected);
    ui->pushButton->setEnabled(connected);
    ui->pushButton_2->setEnabled(connected);
    if(!connected)
    {
        // Подключиться к серверу не удалось (закончился таймаут ожидания).
        socket->disconnectFromHost();
        // QMessageBox::warning(this,"Внимание!","Не удалось подключиться к серверу!");
    }
    //    else
    //    {
    //        socket->write((3 + (ui->nickEdit->text())).toUtf8());
    //    }
}
//отправка сообщения на сервер
void Widget::on_sendMessageButton_clicked()
{
    if (!ui->sendMessageEdit->toPlainText().isEmpty()){
        QMessageBox::warning(this,"Ошибка","Пустое сообщение.");
    }
    QDataStream out (socket);
    QString nick = ui->nickEdit->text();
    out << qint32(1) << QTime::currentTime() << nick << ui->sendMessageEdit->toPlainText();
    ui->chatEdit->append("ME");
    ui->chatEdit->append(ui->sendMessageEdit->toPlainText());
    ui->sendMessageEdit->clear();

}

// Обработка приема данных от сервера
void Widget::socketReadyRead()
{
    QDataStream stream (socket);

    while(socket->bytesAvailable() > 0)
    {
        stream.startTransaction();

        int id;
        stream >> id;

        if (id == 3 ) { // Сервер переслал сообщение другого клиента
            QTime time;
            QString mes;
            QString nick;
            stream >> time >> nick >> mes;

            if(!stream.commitTransaction()) {
                stream.rollbackTransaction();
                break;
            }

            ui->chatEdit->append(time.toString() + "\n" + nick + "\n" + mes);
        }
        else if(id == 4) { // Сервер прислал список всех клиентов
            QStringList users;
            stream >> users;

            if(!stream.commitTransaction()) {
                stream.rollbackTransaction();
                break;
            }

            ui->nickList->clear();
            ui->nickList->addItems(users);
        }
    }
}
// Обработка отключения от сервера
void Widget::socketDisconnected()
{
    ui->sendMessageButton->setEnabled(false);
    ui->connectToServerButton->setEnabled(true);
    ui->nickEdit->setEnabled(true);
}

// Обработка подключения к серверу
void Widget::socketConnected()
{
    // Дождаться подключения к серверу можно и тут.
    ui->sendMessageButton->setEnabled(true);
    QMessageBox::information(this,"Внимание","Подключено к серверу.");
    QDataStream stream(socket);
    stream << qint32(2) << ui->nickEdit->text();
}
//обработка ошибок при подключении
void Widget::socketErr(QAbstractSocket::SocketError err)
{
    QString error = "Ошибка: "+
            ( err == QAbstractSocket::HostNotFoundError ? "Хост не найден." :
              err == QAbstractSocket::RemoteHostClosedError ? "Хост закрыт." :
              err == QAbstractSocket::ConnectionRefusedError ? "Отказано в соединении." :
                QString(socket->errorString())) ;

    QMessageBox::warning(this,"",error);
}

void Widget::on_pushButton_clicked()
{
    ui->sendMessageEdit->insertPlainText("\U0001F602");
}

//пара эмодзи
void Widget::on_pushButton_2_clicked()
{
    ui->sendMessageEdit->insertPlainText("😎");
}


