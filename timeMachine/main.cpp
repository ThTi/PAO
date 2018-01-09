#include <QApplication>
#include "explorateur.h"
#include <stdio.h>



int main(int argc, char *argv[])
{

    QApplication app(argc, argv);

    explorateur fenetre;
    fenetre.show();

    return app.exec();

}
