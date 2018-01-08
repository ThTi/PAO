#include "maFenetre.h"

maFenetre::maFenetre() : QFileDialog()
{

}

maFenetre::maFenetre(QString repertoire) : QFileDialog(){

    setDirectory(repertoire);
    show();

}

