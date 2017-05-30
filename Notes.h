#if !defined(_Notes_H)
#define _Notes_H
#include <iostream>
#include <string>


class Notes{
	private :
		int id;
		std::string titre;
		Date dateModif;
		Date dateCrea;

	public :
		const std::string& getId() const { return id; }
		const std::string& getTitre() const { return titre; }
		const std::string& getModif() const { return dateModif; }
		const std::string& getCrea() const { return dateCrea; }
		void setTitre(const std::string& s ) { titre=s;}
		void setModif(const Date& d) { dateModif=d;}
		void setCrea(const Date& d ) { dateCrea=d;}
		virtual ~Notes(){}
		virtual Notes* clone() const=0;
		Notes(int i, const std::string& t) : id(i), titre(t) {
			 /*date_now = on récupère la date*/
			 dateModif= date_now;
			 dateCrea= date_now; }

}

class Article : public Notes {
	private :
		std:string texte;

	public :
		const std::string& getText() const { return texte; }
		void setTexte(const std::string& s ) { texte=s;}
		Article(int i, const std::string& titr, const std::string& text) : Notes(i,titr), texte(text)  {}
		virtual ~Article() {}
		virtual Article* clone() const { return new Article(*this);}

}

class Tache : public Notes {
	private :
		std:string action;
		int priorite;
		Date dateEcheance;
		char statut;

	public :
		const std::string& getAction() const { return action; }
		void setAction(const std::string& a ) { action=a;}

		const std::string& getPriorite() const { return priorite; }
		void setPrio(const int p ) { priorite=p;}

		const std::string& getEcheance() const { return dateEcheance; }
		void setEcheance(const Date& d ) { dateEcheance=d;}

		const std::string& getStatut() const { return statut; }
		void setStatut(const char& s ) { statut=s;}



		Tache(int i, const std::string& titr, const std::string& act, const int prio, const Date& d, const char& c ) : Notes(i,titr), action(act), priorite(prio), dateEcheance(d), statut(c)  {}
		virtual ~Tache() {}
		virtual Tache* clone() const { return new Tache(*this);}

}

class Multimedia : public Notes {
	private :
		std:string description;
		blob fichier;

	public :
		const std::string& getDescription() const { return description; }
		void setDesc(const std::string& d ) { description=d;}

		const std::string& getFichier() const { return fichier; }
		void setFichier(const blob& f ) { fichier=f;}

		Multimedia(int i, const std::string& titr, const std::string& desc, const blob& f) : Notes(i,titr), description(desc), fichier(f) {}
		virtual ~Multimedia() {}
		virtual Multimedia* clone() const { return new Multimedia(*this);}

}





#endif
