#pragma once
#include "lecteur.h"
#include <iostream>

class Emprunt
{
public:
	Emprunt(Date date_emprunt, Livre &livre, Lecteur &lecteur); 
	bool autorisation(Livre l);
	void retour(Lecteur &lect, Livre &livre);
	Livre livre();
	Lecteur lecteur();

private:
	Date _date_emprunt;
	long _ISBN;
	Livre _livre;
	std::string _id_lecteur;
	Lecteur _lecteur;
	bool _autorisation;
};


