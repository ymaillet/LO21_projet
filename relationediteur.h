#ifndef RELATIONEDITEUR_H
#define RELATIONEDITEUR_H

#include <QWidget>
#include <QLineEdit>
#include <QTextEdit>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QTextEdit>
#include "relation.h"


class RelationEditeur : public QWidget
{
    Q_OBJECT
private:
    QLineEdit *titre;
    QLineEdit *desc;


    QLabel *titre1;
    QLabel *desc1;



    QHBoxLayout *ctitre;
    QHBoxLayout *cdesc;

    QVBoxLayout *couche;

    Relation *relation;

public:
    explicit RelationEditeur(Relation* rel, QWidget *parent = 0);

signals:

public slots:
};

#endif // RELATIONEDITEUR_H
