#include <QApplication>
#include <QWidget>
#include "relation.h"
#include "relationediteur.h"

int main(int argc, char *argv[]) {
QApplication app(argc, argv);



HistoNotes n1(2,5);
HistoNotes n2(3,4);

Couple c1(n1,n2);
Couple c2(n2,n1,"coucou");

HistoNotes& ref1=n1;
HistoNotes& ref2=n2;

Relation r1("Implique","quand un l'autre",0);
r1.addCouple(&c2);
r1.addCouple(ref1,ref2,"label");

r1.setTitre("coucou");

RelationEditeur fenetre(&r1);


fenetre.show();
return app.exec();
}
