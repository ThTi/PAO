#ifndef AUTHENTIFICATION_H
#define AUTHENTIFICATION_H

#include <QWidget>
#include "explorateur.h"

namespace Ui {
class authentification;
}

class authentification : public QWidget
{
    Q_OBJECT

public:
    explicit authentification(QWidget *parent = 0);
    ~authentification();
    const char* getMDP();

public slots:
    void enregistrerMDP();
private:
    Ui::authentification *ui;
    QString mdp;
};

#endif // AUTHENTIFICATION_H
