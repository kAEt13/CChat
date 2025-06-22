#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTcpSocket>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_connectToServerButton_clicked();

    void on_sendMessageButton_clicked();

    // Обработка приема данных от сервера
    void socketReadyRead();
    // Обработка отключения от сервера
    void socketDisconnected();
    // Обработка подключения к серверу
    void socketConnected();
    // Желательно реализовавть еще и обработку ошибок сокета
    void socketErr(QAbstractSocket::SocketError err);

    //две кнопки на два эмодзи
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Widget *ui;
    // Клиентский сокет
    QTcpSocket *socket;
    bool newClient = false;
};

#endif // WIDGET_H
