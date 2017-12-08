/********************************************************************************
** Form generated from reading UI file 'explorateur.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXPLORATEUR_H
#define UI_EXPLORATEUR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_explorateur
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QPushButton *pushButton;
    QLineEdit *lineEdit;
    QSpacerItem *verticalSpacer;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout;
    QFrame *frame_3;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_2;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *explorateur)
    {
        if (explorateur->objectName().isEmpty())
            explorateur->setObjectName(QStringLiteral("explorateur"));
        explorateur->resize(771, 583);
        verticalLayout = new QVBoxLayout(explorateur);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        frame = new QFrame(explorateur);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setMinimumSize(QSize(0, 50));
        frame->setMaximumSize(QSize(16777215, 51));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        pushButton = new QPushButton(frame);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(240, 10, 101, 31));
        lineEdit = new QLineEdit(frame);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(20, 10, 211, 31));

        verticalLayout->addWidget(frame);

        verticalSpacer = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Maximum);

        verticalLayout->addItem(verticalSpacer);

        frame_2 = new QFrame(explorateur);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame_2);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        frame_3 = new QFrame(frame_2);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        frame_3->setMinimumSize(QSize(120, 0));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);

        horizontalLayout->addWidget(frame_3);

        scrollArea_2 = new QScrollArea(frame_2);
        scrollArea_2->setObjectName(QStringLiteral("scrollArea_2"));
        scrollArea_2->setMaximumSize(QSize(100, 16777215));
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QStringLiteral("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 98, 471));
        scrollArea_2->setWidget(scrollAreaWidgetContents_2);

        horizontalLayout->addWidget(scrollArea_2);

        scrollArea = new QScrollArea(frame_2);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setMaximumSize(QSize(16777215, 16777215));
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        scrollArea->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 485, 471));
        gridLayout = new QGridLayout(scrollAreaWidgetContents);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalSpacer = new QSpacerItem(373, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        horizontalLayout->addWidget(scrollArea);


        verticalLayout->addWidget(frame_2);


        retranslateUi(explorateur);

        QMetaObject::connectSlotsByName(explorateur);
    } // setupUi

    void retranslateUi(QWidget *explorateur)
    {
        explorateur->setWindowTitle(QApplication::translate("explorateur", "Explorateur", Q_NULLPTR));
        pushButton->setText(QApplication::translate("explorateur", "Selectionner", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class explorateur: public Ui_explorateur {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXPLORATEUR_H
