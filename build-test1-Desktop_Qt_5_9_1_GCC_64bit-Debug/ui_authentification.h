/********************************************************************************
** Form generated from reading UI file 'authentification.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUTHENTIFICATION_H
#define UI_AUTHENTIFICATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_authentification
{
public:
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *authentification)
    {
        if (authentification->objectName().isEmpty())
            authentification->setObjectName(QStringLiteral("authentification"));
        authentification->resize(202, 92);
        verticalLayout = new QVBoxLayout(authentification);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        lineEdit = new QLineEdit(authentification);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        verticalLayout->addWidget(lineEdit);

        widget = new QWidget(authentification);
        widget->setObjectName(QStringLiteral("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);


        verticalLayout->addWidget(widget);


        retranslateUi(authentification);

        QMetaObject::connectSlotsByName(authentification);
    } // setupUi

    void retranslateUi(QWidget *authentification)
    {
        authentification->setWindowTitle(QApplication::translate("authentification", "Form", Q_NULLPTR));
        pushButton->setText(QApplication::translate("authentification", "Ok", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("authentification", "Annuler", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class authentification: public Ui_authentification {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTHENTIFICATION_H
