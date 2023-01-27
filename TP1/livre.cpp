#include "livre.h"

Livre::Livre(std::string nom, Auteur auteur, Langue langue, Genre genre, Date publication, long isbn):
	_nom(nom), _auteur(auteur), _langue(langue), _genre(genre), _publication(publication), _ISBN(isbn)
{ 
	_disponible = true; 
}

std::string Livre::nom() {
	return _nom;
}

Auteur Livre::auteur() {
	return _auteur;
}

long Livre::ISBN(){
	return _ISBN;
}

bool Livre::disponible() {
	return _disponible;
}

void Livre::setDispo(bool b) {
	if(b == false) 
		_disponible = false;
	else 
		_disponible = true;
}

bool Livre::operator == (Livre& li) const {
	if (_ISBN==li.ISBN())
		return true;
	else 
		return false;
}

std::ostream& operator<<(std::ostream& out, Livre& livre) {
	out << livre.nom() << " de " << livre._auteur << ", écrit en " ; 
	livre._publication.displayDate();
	out << ". Genre : " << tabGenre[int(livre._genre)] << " disponible dans nos bibliotheques en " << tabLangue[int(livre._langue)]; 
	out << ". ISBN : " << livre.ISBN();
	return out;
}



