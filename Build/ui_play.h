/********************************************************************************
** Form generated from reading UI file 'play.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLAY_H
#define UI_PLAY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Play
{
public:
    QLabel *PlayMenu;
    QLabel *Eye3;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *Play_x;
    QPushButton *Music;
    QPushButton *Quit_2;

    void setupUi(QDialog *Play)
    {
        if (Play->objectName().isEmpty())
            Play->setObjectName(QString::fromUtf8("Play"));
        Play->resize(1101, 678);
        PlayMenu = new QLabel(Play);
        PlayMenu->setObjectName(QString::fromUtf8("PlayMenu"));
        PlayMenu->setGeometry(QRect(-330, 10, 1431, 781));
        Eye3 = new QLabel(Play);
        Eye3->setObjectName(QString::fromUtf8("Eye3"));
        Eye3->setGeometry(QRect(150, 20, 301, 231));
        verticalLayoutWidget = new QWidget(Play);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(280, 410, 321, 131));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        Play_x = new QPushButton(verticalLayoutWidget);
        Play_x->setObjectName(QString::fromUtf8("Play_x"));

        verticalLayout->addWidget(Play_x);

        Music = new QPushButton(verticalLayoutWidget);
        Music->setObjectName(QString::fromUtf8("Music"));

        verticalLayout->addWidget(Music);

        Quit_2 = new QPushButton(verticalLayoutWidget);
        Quit_2->setObjectName(QString::fromUtf8("Quit_2"));

        verticalLayout->addWidget(Quit_2);


        retranslateUi(Play);

        QMetaObject::connectSlotsByName(Play);
    } // setupUi

    void retranslateUi(QDialog *Play)
    {
        Play->setWindowTitle(QCoreApplication::translate("Play", "Dialog", nullptr));
        PlayMenu->setText(QCoreApplication::translate("Play", "TextLabel", nullptr));
        Eye3->setText(QString());
        Play_x->setText(QCoreApplication::translate("Play", "Play", nullptr));
        Music->setText(QCoreApplication::translate("Play", "Music On/Off", nullptr));
        Quit_2->setText(QCoreApplication::translate("Play", "Quit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Play: public Ui_Play {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAY_H
