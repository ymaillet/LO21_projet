#include "relationediteur.h"
#include <QApplication>
#include <QString>
#include <QLineEdit>
#include "relation.h"
#include <QMessageBox>
#include <QLineEdit>
#include <QTextEdit>


RelationEditeur::RelationEditeur(Relation* r, QWidget *parent):
    QWidget(parent), relation(r)
{
    titre=new QLineEdit(this);
    desc= new QLineEdit(this);

    titre1=new QLabel("Titre", this);
    desc1= new QLabel("Description", this);

    ctitre=new QHBoxLayout;
    ctitre->addWidget(titre1);
    ctitre->addWidget(titre);

    cdesc=new QHBoxLayout;
    cdesc->addWidget(desc1);
    cdesc->addWidget(desc);

    couche= new QVBoxLayout;

    couche->addLayout(ctitre);
    couche->addLayout(cdesc);

    titre->setText(relation->getTitre());
    desc->setText(relation->getDescription());

    setLayout(couche);
}
