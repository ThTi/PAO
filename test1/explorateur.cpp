#include "explorateur.h"
#include "ui_explorateur.h"

#define TAILLE_MAX 1000

explorateur::explorateur(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::explorateur)
{


    ui->setupUi(this);
    ui->lineEdit_2->setEchoMode(QLineEdit::Password);
    ui->lineEdit_2->setPlaceholderText("Tapez votre mot de passe");
    ui->lineEdit->setPlaceholderText("Entrez votre répertoire");
    repertoireChoisi.setFilter(QDir::NoDotAndDotDot | QDir::AllDirs);
    repertoireParent.setFilter(QDir::NoDotAndDotDot | QDir::AllDirs);
    repertoireFils.setFilter(QDir::AllEntries);
    ui->scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    ui->scrollArea->setWidgetResizable(true);
    QObject::connect(ui->pushButton,SIGNAL(clicked()), this, SLOT(enregistrerChemin()));
    QObject::connect(ui->pushButton_2,SIGNAL(clicked(bool)),this,SLOT(recupererMotDePasse()));

}


explorateur::~explorateur()
{
    delete ui;
}

//slots
void explorateur::enregistrerChemin(){

    setDossier(ui->lineEdit->text());
    repertoireChoisi.setPath(dossier);
    listeFichier = repertoireChoisi.entryList();
    ecrireSnapshotDansFichier(dossier);
    int i =  listeSousVolume.count()-1;
    recupererListeSnapshot();
    ecrireUUIDParent(dossier);
    recupererUUIDParents();
    ecrireListeSousVolume(dossier);
    recurerListeSousVolume();
    groupParent = new QButtonGroup(ui->frame_3);
    tableParent = new QPushButton[TAILLE_MAX];
    int j=0;
    foreach (QString sousVolume, listeSousVolume) {
        if(!(listeSnapshot.contains(sousVolume))){
            ajouterBoutonParent(5,j*30,j,sousVolume);
            ui->retranslateUi(this);
            j++;
        }
    }
}

void explorateur::ouvrirListeSnapshot(int i){

    QString parent = tableParent[i].text();
    QString UUIDSousVolume = recupererUUIDSousVolume(parent);
    QStringList listeSnap = recupererLesFils(UUIDSousVolume);
    int j = listeSnap.count()-1;
    groupFils = new QButtonGroup(ui->scrollArea_2);
    tableFils = new QPushButton[TAILLE_MAX];
    while(j>=0){
        ajouterBoutonFils(5,j*30,j,listeSnap.at(j));
        ui->retranslateUi(this);
        j--;
    }
}

void explorateur::ouvrirDossier(int i){

    QString dir = tableFils[i].text();
    QString dire = dossier + "/"+dir;
    repertoireFils.setPath(dire);
    listeFils = repertoireFils.entryList();
    if(listeFils.count()>0){
        int j = listeFils.count() -1;
        groupFin = new QButtonGroup(ui->scrollArea);
        tableFin = new QPushButton[TAILLE_MAX];
        while(j>=0){
            ajouterContenu(5,j*30,j);
            ui->retranslateUi(this);
            j--;
        }
    }


}

void explorateur::recupererMotDePasse(){
    setMDP(ui->lineEdit_2->text());
}


// méthode
void explorateur::ajouterBoutonParent(int x, int y, int pos, QString text){

    tableParent[pos].setText(text);
    tableParent[pos].setParent(ui->frame_3);
    tableParent[pos].move(x,y);
    groupParent->addButton(&tableParent[pos],pos);
    tableParent[pos].setVisible(true);
    QObject::connect(groupParent,SIGNAL(buttonClicked(int)),this, SLOT(ouvrirListeSnapshot(int)));


}

void explorateur::ajouterBoutonFils(int x, int y, int pos,QString text){

    tableFils[pos].setText(text);
    tableFils[pos].setParent(ui->scrollArea_2);
    tableFils[pos].move(x,y);
    groupFils->addButton(&tableFils[pos],pos);
    tableFils[pos].setVisible(true);
    QObject::connect(groupFils,SIGNAL(buttonClicked(int)),this, SLOT(ouvrirDossier(int)));
}

void explorateur::ajouterContenu(int x, int y, int pos){

    tableFin[pos].setText(listeFils.at(pos));
    tableFin[pos].setParent(ui->scrollArea);
    tableFin[pos].move(x,y);
    groupFin->addButton(&tableFin[pos],pos);
    tableFin[pos].setVisible(true);
}

QString explorateur::getMDP(){
    return motDePasse;
}

void explorateur::setMDP(QString mdp){
    motDePasse=mdp;
}


QString explorateur::getDossier(){
    return dossier;
}

void explorateur::setDossier(QString dos){
    dossier=dos;
}

void explorateur::ecrireSnapshotDansFichier(QString dos){
    std::string mdpString = getMDP().toStdString();
    std::string dossierString = dos.toStdString();
    const char* commandeConstChar;
    std::string commandeString;
    commandeString = "echo " + mdpString +" | sudo -S btrfs subvolume list -s "+dossierString+" |cut -d ' ' -f 14 >> /tmp/listeSnapshot.txt";
    commandeConstChar = commandeString.c_str();
    system(commandeConstChar);

}

void explorateur::recupererListeSnapshot(){

    std::ifstream fichier("//tmp//listeSnapshot.txt");
    if(fichier){
        std::string snap;
        while(std::getline(fichier,snap)){
            QString snaptmp = QString::fromStdString(snap);
            listeSnapshot<<snaptmp;
        }
        fichier.close();
    }

    }

void explorateur::ecrireUUIDParent(QString dos){
    std::string mdpString = getMDP().toStdString();
    std::string dossierString = dos.toStdString();
    const char* commandeConstChar;
    std::string commandeString;
    foreach (QString snapshot, listeSnapshot) {
        std::string snapshottmp = snapshot.toStdString();
        std::string snap = dossierString +"/"+ snapshottmp;
        commandeString = "echo " + mdpString +" | sudo -S btrfs subvolume show "+snap+" |sed -n '4p' |cut -d : -f 2 >> /tmp/UUIDParent.txt";
        commandeConstChar = commandeString.c_str();
        system(commandeConstChar);
    }

}

void explorateur::recupererUUIDParents(){
    std::ifstream fichier("//tmp//UUIDParent.txt");
    Qt::CaseSensitivity cs = Qt::CaseInsensitive;
    if(fichier){
        std::string uuid;
        while(std::getline(fichier,uuid)){
            QString uuidtemp = QString::fromStdString((uuid)).trimmed();
                listeUUID.append(uuidtemp.trimmed());            
        }
        fichier.close();
    }
}

void explorateur::ecrireListeSousVolume(QString dos){
    std::string mdpString = getMDP().toStdString();
    std::string dossierString = dos.toStdString();
    const char* commandeConstChar;
    std::string commandeString;
    commandeString = "echo " + mdpString +" | sudo -S btrfs subvolume list  "+dossierString+" |cut -d ' ' -f 9 >> /tmp/listeSousVolume.txt";
    commandeConstChar = commandeString.c_str();
    system(commandeConstChar);
}

void explorateur::recurerListeSousVolume(){
    std::ifstream fichier("//tmp//listeSousVolume.txt");
    if(fichier){
        std::string sousVolume;
        while(std::getline(fichier,sousVolume)){
                listeSousVolume.append(QString::fromStdString(sousVolume).trimmed());
        }
        fichier.close();
    }

}

QString explorateur::recupererUUIDSousVolume(QString nomSousVolume){

    QString uuidSV;
    std::string mdpString = getMDP().toStdString();
    std::string dossierString = dossier.toStdString();
    const char* commandeConstChar;
    std::string commandeString;
    std::string SVtmp = nomSousVolume.toStdString();
    std::string SV = dossierString +"/"+ SVtmp;
    commandeString = "echo " + mdpString +" | sudo -S btrfs subvolume show "+SV+" |sed -n '3p' |cut -d : -f 2 >> /tmp/UUIDSV.txt";
    commandeConstChar = commandeString.c_str();
    system(commandeConstChar);
    std::ifstream fichier("//tmp//UUIDSV.txt");
    if(fichier){
        std::string uuid;
        while(std::getline(fichier,uuid)){
            uuidSV = QString::fromStdString((uuid)).trimmed();

        }
        fichier.close();
    }
    system("rm /tmp/UUIDSV.txt");
    return uuidSV;
}

QStringList explorateur::recupererLesFils(QString UUIDParent){
    QStringList listeSnap;
    int i=0;
    foreach(QString uuid , listeUUID){
        if(uuid==UUIDParent){
            listeSnap.append(listeSnapshot.at(i));
        }
        i++;
    }
    return listeSnap;
}
