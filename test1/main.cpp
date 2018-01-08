#include <QApplication>
#include <QPushButton>
#include <QWidget>
#include <QFont>
#include <QIcon>
#include "maFenetre.h"
#include "selectionDossier.h"
#include "authentification.h"
#include "explorateur.h"
#include <stdio.h>



int main(int argc, char *argv[])
{

    QApplication app(argc, argv);

    explorateur fenetre;
    fenetre.show();

    return app.exec();

}
