/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *Menu;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *Title;
    QPushButton *Login;
    QPushButton *Quit;
    QLabel *Eye;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        Menu = new QLabel(centralwidget);
        Menu->setObjectName(QString::fromUtf8("Menu"));
        Menu->setGeometry(QRect(-230, -70, 1341, 751));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(190, 390, 511, 161));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        Title = new QLabel(verticalLayoutWidget);
        Title->setObjectName(QString::fromUtf8("Title"));

        verticalLayout->addWidget(Title);

        Login = new QPushButton(verticalLayoutWidget);
        Login->setObjectName(QString::fromUtf8("Login"));

        verticalLayout->addWidget(Login);

        Quit = new QPushButton(verticalLayoutWidget);
        Quit->setObjectName(QString::fromUtf8("Quit"));

        verticalLayout->addWidget(Quit);

        Eye = new QLabel(centralwidget);
        Eye->setObjectName(QString::fromUtf8("Eye"));
        Eye->setGeometry(QRect(170, 20, 291, 221));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        Menu->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        Title->setText(QString());
        Login->setText(QCoreApplication::translate("MainWindow", "Login", nullptr));
        Quit->setText(QCoreApplication::translate("MainWindow", "Quit", nullptr));
        Eye->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
