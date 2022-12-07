#include "bibliotheque.h"

Bibliotheque::Bibliotheque(){};

void Bibliotheque::add_lecteur(Lecteur le) {
	_lecteurs.push_back(le);
}

void Bibliotheque::add_livre(Livre li) {
	_livres.push_back(li);
}