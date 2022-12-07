#include "livre.h"

Livre::Livre(std::string nom, std::string auteur, Langue langue, Genre genre, Date publication, int isbn):
	_nom(nom), _auteur(auteur), _langue(langue), _genre(genre), _publication(publication), _ISBN(isbn)//, disponible = true
{}

std::string Livre::nom() {
	return _nom;
}

std::string Livre::auteur() {
	return _auteur;
}

int Livre::ISBN() {
	return _ISBN;
}

bool Livre::disponible() {
	return _disponible;
}

void Livre::setDispo() {
	if(_disponible == false) 
		_disponible = true;
	else 
		_disponible = false;
}
