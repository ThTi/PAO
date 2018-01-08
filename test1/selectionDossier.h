#ifndef SELECTIONDOSSIER_H
#define SELECTIONDOSSIER_H


#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QMessageBox>
#include <QInputDialog>
#include <QFileDialog>
#include <QTreeView>
#include <QLineEdit>
#include <iostream>
#include <QFileDialog>
#include <QDir>
#include "explorateur.h"


class selectionDossier : public QWidget
{

    Q_OBJECT

public:
    selectionDossier();

    QString getDossier();

    int getNbDossier();

public slots:
    void enregistrerChemin();
    void ouvrirRepertoire(int index);

private:
    QLineEdit *cheminDossier;
    QPushButton *valider;
    QString dossier;
    explorateur fenetre;
    QStringList listeFichier;
    QDir repertoireChoisi;
    QSlider *choixRepertoire;

};

#endif // SELECTIONDOSSIER_H
