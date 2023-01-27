#pragma once
#include "lecteur.h"
#include <cstdlib>

Lecteur::Lecteur(std::string nom, std::string prenom , Date naissance, Date inscription) :
	_nom(nom), _prenom(prenom), _naissance(naissance), _inscription(inscription)
{
	srand (time(NULL));
	int x = rand()%1000000;
	std::string test = std::to_string(x);
	_id = _prenom.substr(0,1) + _nom.substr(0,1) + test;
}

std::string Lecteur::id() {
	return _id;
}
std::string Lecteur::nom() {
	return _nom;
}
std::string Lecteur::prenom() {
	return _prenom;
}

void Lecteur::ajout(Livre &l) {
	if(_livre_actuel.size() < 20 && l.disponible()) {
		_livre_actuel.push_back(l);
		l.setDispo(false);
	}
	else std::cout << "Vous ne pouvez pas emprunter ce livre." << std::endl;
}

void Lecteur::suppr(Livre l) {
	int i = 0;
	while(!(_livre_actuel[i]==l) && (i < _livre_actuel.size()))	{
		i++;
	}
	if (_livre_actuel[i] == l)  
		_livre_actuel.erase( _livre_actuel.begin() + i);
	else std::cout << "Vous n'avez pas emprunté ce livre." << std::endl;
}

void Lecteur::ajout_lus(Livre l) {
	_ISBN_lus.push_back(l);
}

void Lecteur::display_livre_actuel() {
	if (_livre_actuel.size() == 0){
		std::cout<< "Vous n'avez pas de livres empruntés";
		
	}
	else
		for(int i = 0; i < _livre_actuel.size(); i++) {
		std::cout << _livre_actuel[i] << "\n";
		}
}

std::ostream& operator<<(std::ostream& out, Lecteur& lecteur) {
	out << lecteur.nom() << " " << lecteur.prenom() << " inscrit depuis : " ;
	lecteur._inscription.displayDate();
	out << " ID : " << lecteur.id();
	return out;
}

int Lecteur::nombre_livres_lus(){
	_n_ISBN_lus = _ISBN_lus.size();
	return _n_ISBN_lus;
}


