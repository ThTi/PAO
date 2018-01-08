#ifndef DEF_MAFENETRE
#define DEF_MAFENETRE

#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QMessageBox>
#include <QFileDialog>
#include <iostream>

class maFenetre : public QFileDialog

{

    public:
    maFenetre();
    maFenetre(QString repertoire);

};


#endif
