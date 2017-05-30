#include "relation.h"


RelationManager::RelationManager():relations(0),nbRel(0),nbMaxRel(0){}

RelationManager::~RelationManager(){
    for(unsigned int i=0; i<nbRel; i++) delete relations[i];
    delete[] relations;
}

//SINGLETON
RelationManager* RelationManager::instance = 0; //initialisation + définition à nullptr

RelationManager& RelationManager::getInstance(){ //méthode qui vérifie qu'il n'y ait qu'une seule instance de NotesManager
    if(RelationManager::instance==0)
        RelationManager::instance = new RelationManager; //crée une instance
    return *RelationManager::instance;
}

void RelationManager::libererInstance(){
    if(RelationManager::instance !=0) //si instance existe
        delete RelationManager::instance; // supprime
    RelationManager::instance=0; //réinitialisation à nullptr
}

void RelationManager::addRelation(Relation* r){
    if(nbRel==nbMaxRel){
        Relation** newRel = new Relation*[nbMaxRel+5];

        for(unsigned int i=0; i<nbRel; i++) newRel[i]=relations[i];
        Relation** oldRel=relations;
        relations=newRel;
        nbMaxRel+=5;
        if(oldRel) delete[] oldRel;

    }

    relations[nbRel++]=r;
}

void RelationManager::addRelation(QString t, QString d, bool o){
//Verif existe pas deja à faire
    Relation* r= new Relation(t,d,o);
    addRelation(r);

}

/*void RelationManager::deleteRelation(){

}*/

void Relation::addCouple(Couple* c){
        //ORIENTATION A GERER
    if(nbCouples==nbMaxCouples){
        Couple** newCouples = new Couple*[nbMaxCouples+5];

        for(unsigned int i=0; i<nbCouples; i++) newCouples[i]=couples[i];
        Couple** oldCouples=couples;
        couples=newCouples;
        nbMaxCouples+=5;
        if(oldCouples) delete[] oldCouples;

    }

    couples[nbCouples++]=c;
}

void Relation::addCouple(HistoNotes& n1, HistoNotes& n2, QString l){
    //ORIENTATION A GERER

    //A FAIRE QUAND operator== définit pour HistoNotes
    /*for(unsigned int i=0; i<nbCouples; i++){
        if (couples[i]->getPred()==n1 && couples[i]->getSucc()==n2) throw RelationException("Erreur : couple déjà existant");
    }*/
    Couple* c=new Couple(n1,n2,l);
    addCouple(c);
}





