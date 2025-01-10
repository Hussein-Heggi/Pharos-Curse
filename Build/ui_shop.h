/********************************************************************************
** Form generated from reading UI file 'shop.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOP_H
#define UI_SHOP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Shop
{
public:
    QLabel *shop;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *Return;
    QPushButton *Healt_x;
    QPushButton *Health_x;
    QLabel *Heart;
    QLabel *shopI;

    void setupUi(QDialog *Shop)
    {
        if (Shop->objectName().isEmpty())
            Shop->setObjectName(QString::fromUtf8("Shop"));
        Shop->resize(1100, 613);
        shop = new QLabel(Shop);
        shop->setObjectName(QString::fromUtf8("shop"));
        shop->setGeometry(QRect(40, 40, 421, 371));
        verticalLayoutWidget = new QWidget(Shop);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(370, 320, 211, 171));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        Return = new QPushButton(verticalLayoutWidget);
        Return->setObjectName(QString::fromUtf8("Return"));

        verticalLayout->addWidget(Return);

        Healt_x = new QPushButton(verticalLayoutWidget);
        Healt_x->setObjectName(QString::fromUtf8("Healt_x"));

        verticalLayout->addWidget(Healt_x);

        Health_x = new QPushButton(verticalLayoutWidget);
        Health_x->setObjectName(QString::fromUtf8("Health_x"));

        verticalLayout->addWidget(Health_x);

        Heart = new QLabel(Shop);
        Heart->setObjectName(QString::fromUtf8("Heart"));
        Heart->setGeometry(QRect(350, 50, 321, 251));
        shopI = new QLabel(Shop);
        shopI->setObjectName(QString::fromUtf8("shopI"));
        shopI->setGeometry(QRect(20, 410, 281, 181));

        retranslateUi(Shop);

        QMetaObject::connectSlotsByName(Shop);
    } // setupUi

    void retranslateUi(QDialog *Shop)
    {
        Shop->setWindowTitle(QCoreApplication::translate("Shop", "Dialog", nullptr));
        shop->setText(QString());
        Return->setText(QCoreApplication::translate("Shop", "Return", nullptr));
        Healt_x->setText(QCoreApplication::translate("Shop", " Health + 10 ( -20 score )", nullptr));
        Health_x->setText(QCoreApplication::translate("Shop", " Health + 30 ( -50 score)", nullptr));
        Heart->setText(QString());
        shopI->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Shop: public Ui_Shop {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOP_H
