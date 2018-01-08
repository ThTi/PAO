#include "authentification.h"
#include "ui_authentification.h"
#define MAX_LEN 1028

authentification::authentification(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::authentification)
{
    ui->setupUi(this);
    ui->lineEdit->setEchoMode(QLineEdit::Password);
    QObject::connect(ui->pushButton, SIGNAL(clicked(bool)),this,SLOT(enregistrerMDP()));
}

authentification::~authentification()
{
    delete ui;
}


void authentification::enregistrerMDP(){

    mdp = ui->lineEdit->text();
    std::string a = mdp.toStdString();
    const char* motDePasse;
    std::string commande1;
    commande1 = "echo " + a +" | sudo -S btrfs subvolume list -s /media/thomas/63c98c1a-8f67-444a-9ec9-41362cb3e71f1 |cut -d ' ' -f 14 >> /tmp/text.txt";
    motDePasse = commande1.c_str();
    printf("%s", motDePasse);

    char buf1[BUFSIZ];
    FILE *ptr;

    if ((ptr = popen(motDePasse, "r")) != NULL)
    {
      while (fgets(buf1, BUFSIZ, ptr) != NULL)
      {
        (void) printf("%s", buf1);
          printf("yo");
      }
      printf("ferme");
      pclose(ptr);
    }
    else
    {
      fprintf(stderr, "Echec de popen\n");
      exit(1);
    }
    this->hide();
}

const char* authentification::getMDP(){
    std::string motDePasse_String = mdp.toStdString();
    printf("%s",motDePasse_String.c_str());
    return motDePasse_String.c_str();
}
