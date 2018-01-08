#include "selectionDossier.h"


//Constructeur
selectionDossier::selectionDossier() : QWidget(){

    cheminDossier = new QLineEdit(this);

    choixRepertoire = new QSlider(Qt::Vertical,this);
    choixRepertoire->move(150,0);


    repertoireChoisi.setFilter(QDir::NoDotAndDotDot | QDir::AllEntries);

    valider = new QPushButton("Selectionner",this);
    valider->move(20,30);
    QObject::connect(valider,SIGNAL(clicked()),this,SLOT(enregistrerChemin()));
    QObject::connect(choixRepertoire,SIGNAL(valueChanged(int)), this,SLOT(ouvrirRepertoire(int)));


}


//Méthode
QString selectionDossier::getDossier(){
    return dossier;
}

int selectionDossier::getNbDossier(){
    return listeFichier.count();
}




//Slots

void selectionDossier::enregistrerChemin(){
    dossier = cheminDossier->text();
    repertoireChoisi.setPath(dossier);
    listeFichier = repertoireChoisi.entryList();
    std::cout<<listeFichier.count()<<std::endl;
    choixRepertoire->setRange(1,getNbDossier());
}


void selectionDossier::ouvrirRepertoire(int index){
    std::cout<<"index "<<index<<std::endl;
    QString dos = listeFichier.value(index);

    std::cout<<listeFichier.count()<<std::endl;
    int i = listeFichier.count();
    fenetre.show();
}


