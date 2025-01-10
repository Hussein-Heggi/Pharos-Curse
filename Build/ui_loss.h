/********************************************************************************
** Form generated from reading UI file 'loss.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOSS_H
#define UI_LOSS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Loss
{
public:
    QLabel *Lost;
    QPushButton *Quit_0;

    void setupUi(QDialog *Loss)
    {
        if (Loss->objectName().isEmpty())
            Loss->setObjectName(QString::fromUtf8("Loss"));
        Loss->resize(1099, 566);
        Lost = new QLabel(Loss);
        Lost->setObjectName(QString::fromUtf8("Lost"));
        Lost->setGeometry(QRect(0, -100, 851, 461));
        Quit_0 = new QPushButton(Loss);
        Quit_0->setObjectName(QString::fromUtf8("Quit_0"));
        Quit_0->setGeometry(QRect(180, 200, 241, 32));

        retranslateUi(Loss);

        QMetaObject::connectSlotsByName(Loss);
    } // setupUi

    void retranslateUi(QDialog *Loss)
    {
        Loss->setWindowTitle(QCoreApplication::translate("Loss", "Dialog", nullptr));
        Lost->setText(QString());
        Quit_0->setText(QCoreApplication::translate("Loss", "Quit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Loss: public Ui_Loss {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOSS_H
