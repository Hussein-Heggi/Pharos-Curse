/********************************************************************************
** Form generated from reading UI file 'win.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIN_H
#define UI_WIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Win
{
public:
    QLabel *Win_2;
    QPushButton *Quit_a;

    void setupUi(QDialog *Win)
    {
        if (Win->objectName().isEmpty())
            Win->setObjectName(QString::fromUtf8("Win"));
        Win->resize(1100, 501);
        Win_2 = new QLabel(Win);
        Win_2->setObjectName(QString::fromUtf8("Win_2"));
        Win_2->setGeometry(QRect(-10, 10, 851, 551));
        Quit_a = new QPushButton(Win);
        Quit_a->setObjectName(QString::fromUtf8("Quit_a"));
        Quit_a->setGeometry(QRect(170, 480, 291, 32));

        retranslateUi(Win);

        QMetaObject::connectSlotsByName(Win);
    } // setupUi

    void retranslateUi(QDialog *Win)
    {
        Win->setWindowTitle(QCoreApplication::translate("Win", "Dialog", nullptr));
        Win_2->setText(QString());
        Quit_a->setText(QCoreApplication::translate("Win", "Quit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Win: public Ui_Win {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIN_H
