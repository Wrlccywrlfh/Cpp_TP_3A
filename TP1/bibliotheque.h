#pragma once
#include "lecteur.h"
#include "emprunt.h"
#include <vector>
#include <algorithm>

class Bibliotheque {
public:
	Bibliotheque();
	void add_lecteur(Lecteur &le);
	void add_livre(Livre &li);
	void add_auteur(Auteur &au);
	int livre_existe(long &ISBN);
	int lecteur_existe(std::string &id);
	int auteur_existe(std::string &id);	
	Livre cherche_livre(long ISBN);
	Lecteur cherche_lecteur(std::string id);
	Auteur cherche_auteur(std::string id);
	std::vector<Livre> livre_auteur(Auteur& au);
	std::vector<Livre> livre_emprunte();
	Emprunt emprunt(Date date_emprunt, Livre &livre, Lecteur &lecteur);
	void retour (Emprunt &e, Lecteur &lecteur, Livre &livre);
	void classement(); //Ne fonctionne pas :(
	std::vector<Lecteur> lecteurs();
	int nombre_lecteurs();
private:
	std::vector<Lecteur> _lecteurs;
	std::vector<Livre> _livres;
	std::vector<Auteur> _auteurs;
	
};


