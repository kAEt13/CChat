#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTcpServer>
#include <QTcpSocket>
#include <QList>
#include <QDateTime>


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
    void on_startButton_clicked();

    // Обработка подключения нового клиента
    void clientNewConnection();

    // Обработка приема данных от клиентов
    void clientReadyRead();

    // Обработка отключения клиента
    void clientDisconnected();


private:
    Ui::Widget *ui;

    // TCP-сервер. Позволяет принимать входящие соединения.
    QTcpServer *server;

    // Список подключенных клиентов (сокетов).
    QList<QTcpSocket*> clients;
    QStringList users = {};
};

#endif // WIDGET_H
