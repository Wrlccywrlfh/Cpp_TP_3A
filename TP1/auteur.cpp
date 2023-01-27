#pragma once
#include "auteur.h"
#include <cstdlib>

Auteur::Auteur(std::string nom, std::string prenom , Date naissance) :
	_nom(nom), _prenom(prenom), _naissance(naissance)
{
	srand (time(NULL));
	int x = rand()%100000;
	std::string test = std::to_string(x);
	_id = _prenom.substr(0,1) + _nom.substr(0,1) + test;
}

std::string Auteur::id() {
	return _id;
}

std::string Auteur::nom() {
	return _nom;
}

std::string Auteur::prenom() {
	return _prenom;
}

std::ostream& operator<<(std::ostream& out, Auteur& auteur) {
	out << auteur.prenom() << " " << auteur.nom();
	return out;
}

bool Auteur::operator == (Auteur& auteur) const {
	if (_id==auteur.id())
		return true;
	else 
		return false;
}




