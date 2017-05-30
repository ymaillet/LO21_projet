#ifndef RELATION_H
#define RELATION_H
#include <QString>
using namespace std;

class RelationException{
public:
    RelationException(const string& message):info(message){}
    string getInfo() const { return info; }
private:
    string info;
};

class HistoNotes {
private:
    int i;
    int current;
public:
    HistoNotes(int a, int b):i(a),current(b){}
};

class Couple
{
    //param const HistoNotes& pour x et y???
private:
    HistoNotes& x;
    HistoNotes& y;
    QString label;

public:
    Couple(HistoNotes& a, HistoNotes& b, QString l=""):x(a),y(b),label(l){}
    HistoNotes& getPred() const {return x;}
    HistoNotes& getSucc() const {return y;}
    const QString& getLabel() const {return label;}
};

class Relation
{
private:
    QString titre;
    QString description;
    bool orientation;
    Couple** couples;
    unsigned int nbCouples;
    unsigned int nbMaxCouples;
public:
    Relation(QString t, QString d,bool o):titre(t),description(d),orientation(o),nbCouples(0),nbMaxCouples(0){}
    void addCouple(Couple* c);
    void addCouple(HistoNotes& n1, HistoNotes& n2, QString l="");
    void deleteCouple(Couple& c);

    const QString& getTitre() const {return titre;}
    const QString& getDescription() const {return description;}

    void setTitre(QString t){titre=t;} //REFERENCE POUR QSTRING OU PAS??
    void setDesc(QString d){description=d;}

    class iterator{
        Couple **current;
        iterator(Couple **c):current(c){}

        friend class Relation;

    public:
        iterator():current(0){}

        Couple& operator*(){
            return **current;
        }

        iterator &operator++(){
            ++current;
            return *this;
        }

        bool operator!=(iterator it) const{
            return current != it.current;
        }
    };

    iterator begin(){
        return iterator(couples);
    }
    iterator end(){
        return iterator(couples + nbCouples);
    }

    class const_iterator{
        Couple **current;
        const_iterator(Couple **c):current(c){}

        friend class Relation;
    public:
        const_iterator():current(0){}

        const Couple& operator*() const {
            return **current;
        }

        const_iterator& operator++(){
            ++current;
            return *this;
        }

        bool operator!=(const_iterator it) const{
            return current != it.current;
        }

    };

    const_iterator begin() const{   //1ère case du tableau articles
        return const_iterator(couples);
    }
    const_iterator end() const{ //case juste après la dernière case du tableau articles (condition boucle for : !=m.end
        return const_iterator(couples + nbCouples);
    }

};

class RelationManager {
private:
    Relation** relations;
    unsigned int nbRel;
    unsigned int nbMaxRel;

    static RelationManager *instance;


    RelationManager();
    ~RelationManager();
    RelationManager(const RelationManager& m);
    RelationManager& operator=(const RelationManager&);


public:

    static RelationManager& getInstance(); //DP singleton
    static void libererInstance(); //DP singleton
    void addRelation(Relation* r);
    void addRelation(QString t, QString d, bool o=0);
    //void deleteRelation();

};

#endif // RELATION_H
