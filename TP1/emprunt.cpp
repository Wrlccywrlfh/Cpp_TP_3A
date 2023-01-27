#include "emprunt.h"

Emprunt::Emprunt(Date date_emprunt, Livre &livre, Lecteur &lecteur) :  
_date_emprunt(date_emprunt), _livre(livre), _lecteur(lecteur) {
	lecteur.ajout(livre);
	livre.setDispo(false);
}

bool Emprunt::autorisation(Livre l) {
	return l.disponible();
}

void Emprunt::retour(Lecteur &lect, Livre &livre) {
	if(livre.disponible() == false) {
		lect.suppr(livre); 
		lect.ajout_lus(livre);
		livre.setDispo(true);
	}
	else std::cout << "Vous n'avez pas emprunté ce livre. " << std::endl;
}

Livre Emprunt::livre(){
	return _livre;
}	
Lecteur Emprunt::lecteur(){
	return _lecteur;
}

