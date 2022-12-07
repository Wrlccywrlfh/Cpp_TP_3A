#include "lecteur.h"
#include <cstdlib>

Lecteur::Lecteur(std::string nom, std::string prenom , Date naissance) :
	_nom(nom), _prenom(prenom), _naissance(naissance)
{
	srand (time(NULL));
	int x = rand()%1000000;
	std::string test = std::to_string(x);

	_id = _prenom.substr(0,1) + _nom.substr(0,1) + test;
}

std::string Lecteur::id() {
	return _id;
}

