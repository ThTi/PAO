/********************************************************************************
** Form generated from reading UI file 'monbouton.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MONBOUTON_H
#define UI_MONBOUTON_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_monBouton
{
public:
    QPushButton *pushButton;
    QLabel *label;

    void setupUi(QWidget *monBouton)
    {
        if (monBouton->objectName().isEmpty())
            monBouton->setObjectName(QStringLiteral("monBouton"));
        monBouton->resize(106, 86);
        pushButton = new QPushButton(monBouton);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(10, 10, 89, 41));
        label = new QLabel(monBouton);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 60, 67, 17));

        retranslateUi(monBouton);

        QMetaObject::connectSlotsByName(monBouton);
    } // setupUi

    void retranslateUi(QWidget *monBouton)
    {
        monBouton->setWindowTitle(QApplication::translate("monBouton", "Form", Q_NULLPTR));
        pushButton->setText(QString());
        label->setText(QApplication::translate("monBouton", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class monBouton: public Ui_monBouton {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MONBOUTON_H
