#ifndef EXPLORATEUR_H
#define EXPLORATEUR_H

#include <QWidget>
#include <QDir>
#include <QString>
#include <iostream>
#include <fstream>
#include <QHash>
#include <string>
#include <QPushButton>




namespace Ui {
class explorateur;
}

class explorateur : public QWidget
{
    Q_OBJECT

public:
    explicit explorateur(QWidget *parent = 0);
    ~explorateur();
    void ajouterBoutonParent(int x, int y, int pos,QString text);
    void ajouterBoutonFils(int x, int y, int pos, QString text);
    void ajouterContenu(int x, int y, int pos);
    QString getMDP();
    void setMDP(QString mdp);
    QString getDossier();
    void setDossier(QString dos);
    void ecrireSnapshotDansFichier(QString dos);
    void recupererListeSnapshot();
    void ecrireUUIDParent(QString dos);
    void recupererUUIDParents();
    void ecrireListeSousVolume(QString dos);
    void recupererListeSousVolume();
    QString recupererUUIDSousVolume(QString nomSousVolume);
    QStringList recupererLesFils(QString UUIDParent);

public slots:
    void enregistrerChemin();
    void ouvrirListeSnapshot(int i);
    void ouvrirDossier(int i);
    void recupererMotDePasse();



private:
    Ui::explorateur *ui;
    QPushButton *tableParent, *tableFils, *tableFin;
    QDir repertoireChoisi,repertoireParent, repertoireFils;
    QStringList listeFils, listeSnapshot,listeUUID, listeSousVolume;
    QButtonGroup *groupParent,*groupFils,*groupFin;
    QString motDePasse,dossier;


};

#endif // EXPLORATEUR_H
