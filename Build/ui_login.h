/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QLabel *LogMenu;
    QLabel *Eye2;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *user;
    QLabel *label_2;
    QLineEdit *pass;
    QPushButton *Log;
    QPushButton *Clear;
    QLabel *status;

    void setupUi(QDialog *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QString::fromUtf8("Login"));
        Login->resize(1100, 630);
        LogMenu = new QLabel(Login);
        LogMenu->setObjectName(QString::fromUtf8("LogMenu"));
        LogMenu->setGeometry(QRect(-340, -10, 1441, 721));
        Eye2 = new QLabel(Login);
        Eye2->setObjectName(QString::fromUtf8("Eye2"));
        Eye2->setGeometry(QRect(190, 40, 291, 221));
        gridLayoutWidget = new QWidget(Login);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(130, 390, 321, 121));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("font: 700 14pt \"Times New Roman\";"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        user = new QLineEdit(gridLayoutWidget);
        user->setObjectName(QString::fromUtf8("user"));

        gridLayout->addWidget(user, 0, 1, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("font: 700 14pt \"Times New Roman\";"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        pass = new QLineEdit(gridLayoutWidget);
        pass->setObjectName(QString::fromUtf8("pass"));

        gridLayout->addWidget(pass, 1, 1, 1, 1);

        Log = new QPushButton(gridLayoutWidget);
        Log->setObjectName(QString::fromUtf8("Log"));

        gridLayout->addWidget(Log, 2, 0, 1, 1);

        Clear = new QPushButton(gridLayoutWidget);
        Clear->setObjectName(QString::fromUtf8("Clear"));

        gridLayout->addWidget(Clear, 2, 1, 1, 1);

        status = new QLabel(Login);
        status->setObjectName(QString::fromUtf8("status"));
        status->setGeometry(QRect(480, 450, 251, 41));
        status->setStyleSheet(QString::fromUtf8("font: 700 14pt \"Times New Roman\";"));

        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QDialog *Login)
    {
        Login->setWindowTitle(QCoreApplication::translate("Login", "Dialog", nullptr));
        LogMenu->setText(QCoreApplication::translate("Login", "TextLabel", nullptr));
        Eye2->setText(QString());
        label->setText(QCoreApplication::translate("Login", "Username", nullptr));
        label_2->setText(QCoreApplication::translate("Login", "Password", nullptr));
        Log->setText(QCoreApplication::translate("Login", "Login", nullptr));
        Clear->setText(QCoreApplication::translate("Login", "Clear", nullptr));
        status->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
