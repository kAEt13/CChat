/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLabel *label_3;
    QTextEdit *chatEdit;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *serverIpEdit;
    QLabel *label_2;
    QLineEdit *serverPortEdit;
    QSpacerItem *horizontalSpacer;
    QLabel *label_4;
    QLineEdit *nickEdit;
    QPushButton *connectToServerButton;
    QPushButton *sendMessageButton;
    QTextEdit *sendMessageEdit;
    QListWidget *nickList;
    QLabel *label_5;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(1762, 775);
        QFont font;
        font.setPointSize(20);
        Widget->setFont(font);
        label_3 = new QLabel(Widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(6, 47, 71, 27));
        chatEdit = new QTextEdit(Widget);
        chatEdit->setObjectName(QString::fromUtf8("chatEdit"));
        chatEdit->setGeometry(QRect(6, 88, 1461, 571));
        chatEdit->setReadOnly(true);
        pushButton = new QPushButton(Widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(1600, 700, 141, 31));
        pushButton_2 = new QPushButton(Widget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(1610, 740, 80, 33));
        layoutWidget = new QWidget(Widget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 0, 1757, 51));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        serverIpEdit = new QLineEdit(layoutWidget);
        serverIpEdit->setObjectName(QString::fromUtf8("serverIpEdit"));

        horizontalLayout->addWidget(serverIpEdit);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        serverPortEdit = new QLineEdit(layoutWidget);
        serverPortEdit->setObjectName(QString::fromUtf8("serverPortEdit"));

        horizontalLayout->addWidget(serverPortEdit);

        horizontalSpacer = new QSpacerItem(100, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        horizontalLayout->addItem(horizontalSpacer);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout->addWidget(label_4);

        nickEdit = new QLineEdit(layoutWidget);
        nickEdit->setObjectName(QString::fromUtf8("nickEdit"));

        horizontalLayout->addWidget(nickEdit);

        connectToServerButton = new QPushButton(layoutWidget);
        connectToServerButton->setObjectName(QString::fromUtf8("connectToServerButton"));

        horizontalLayout->addWidget(connectToServerButton);

        sendMessageButton = new QPushButton(Widget);
        sendMessageButton->setObjectName(QString::fromUtf8("sendMessageButton"));
        sendMessageButton->setEnabled(false);
        sendMessageButton->setGeometry(QRect(1600, 660, 141, 41));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(sendMessageButton->sizePolicy().hasHeightForWidth());
        sendMessageButton->setSizePolicy(sizePolicy);
        sendMessageEdit = new QTextEdit(Widget);
        sendMessageEdit->setObjectName(QString::fromUtf8("sendMessageEdit"));
        sendMessageEdit->setGeometry(QRect(37, 660, 1561, 112));
        nickList = new QListWidget(Widget);
        nickList->setObjectName(QString::fromUtf8("nickList"));
        nickList->setGeometry(QRect(1470, 90, 271, 571));
        label_5 = new QLabel(Widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(1370, 50, 377, 40));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", nullptr));
        label_3->setText(QApplication::translate("Widget", "\320\247\320\260\321\202", nullptr));
        pushButton->setText(QApplication::translate("Widget", "\320\255\320\274\320\276\320\264\320\267\320\270", nullptr));
        pushButton_2->setText(QApplication::translate("Widget", "\360\237\230\216", nullptr));
        label->setText(QApplication::translate("Widget", "\320\220\320\264\321\200\320\265\321\201 \321\201\320\265\321\200\320\262\320\265\321\200\320\260", nullptr));
        serverIpEdit->setText(QApplication::translate("Widget", "127.0.0.1", nullptr));
        label_2->setText(QApplication::translate("Widget", "\320\237\320\276\321\200\321\202 \321\201\320\265\321\200\320\262\320\265\321\200\320\260", nullptr));
        serverPortEdit->setText(QApplication::translate("Widget", "40000", nullptr));
        label_4->setText(QApplication::translate("Widget", "\320\222\320\260\321\210 \320\275\320\270\320\272", nullptr));
        connectToServerButton->setText(QApplication::translate("Widget", "\320\237\320\276\320\264\320\272\320\273\321\216\321\207\320\270\321\202\321\214\321\201\321\217", nullptr));
        sendMessageButton->setText(QApplication::translate("Widget", ">", nullptr));
        label_5->setText(QApplication::translate("Widget", " \320\237\320\276\320\264\320\272\320\273\321\216\321\207\320\265\320\275\320\275\321\213\320\265 \320\272\320\273\320\270\320\265\320\275\321\202\321\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
