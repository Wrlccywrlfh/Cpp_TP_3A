#include "bibliotheque.h"

Bibliotheque::Bibliotheque(){};

void Bibliotheque::add_lecteur(Lecteur &le) {
	_lecteurs.push_back(le);
}

void Bibliotheque::add_livre(Livre &li) {
	_livres.push_back(li);
}

void Bibliotheque::add_auteur(Auteur &au) {
	_auteurs.push_back(au);
}

int Bibliotheque::livre_existe(long &ISBN){
	for(int i = 0; i<_livres.size(); i++) {
		if (ISBN == _livres[i].ISBN())
			return i;
	}
	return -1;
}

int Bibliotheque::lecteur_existe(std::string &id){
	for(int i = 0; i<_lecteurs.size(); i++) {
		if (id == _lecteurs[i].id())
			return i;
	}
	return -1;
}

int Bibliotheque::auteur_existe(std::string &id){
	for(int i = 0; i<_auteurs.size(); i++) {
		if (id == _auteurs[i].id())
			return i;
	}
	return -1;
}

Livre Bibliotheque::cherche_livre(long ISBN){
	int indice = livre_existe(ISBN);
	if(indice != -1) {
		std::cout<<_livres[indice]<<std::endl;
		return _livres[indice];
	} else 
		std::cout<< "Nos plus plates excuses, ce livre n'est pas disponible dans nos registres." << std::endl;
}	

Lecteur Bibliotheque::cherche_lecteur(std::string id){
	int indice = lecteur_existe(id);
	if(indice != -1) {
		std::cout<<_lecteurs[indice]<<std::endl;
		return _lecteurs[indice];
	} else 
		std::cout<< "Ce lecteur n'existe pas" << std::endl;
}

Auteur Bibliotheque::cherche_auteur(std::string id){
	int indice = auteur_existe(id);
	if(indice != -1) {
		std::cout<<_auteurs[indice]<<std::endl;
		return _auteurs[indice];
	} else 
		std::cout<< "\033[1;39;49mNos plus plates excuses, cet auteur n'est pas disponible dans nos registres.\n\033[0m";
		std::cout<<"\033[1;95;49mN'hésitez pas à faire un dont à notre établissement si vous désirez voir un livre particulier dans nos rayons.\033[0m" << std::endl;
}	

std::vector<Livre> Bibliotheque::livre_auteur(Auteur &au) {
	std::vector<Livre> ress;
	for(int i = 0; i < _livres.size() ; i++) {
		if (_livres[i].auteur() == au) {
			ress.push_back(_livres[i]);
			std::cout << "- "<<_livres[i] << std::endl;
		}
	}
	return ress;
}

std::vector<Livre> Bibliotheque::livre_emprunte() {
	std::vector<Livre> ress;
	ress.clear();
	int n = _livres.size();
	int p = 0;
	for(int i = 0; i < n; i++) {
		if(_livres[i].disponible() == false){
			p++;
			ress.push_back(_livres[i]);
			std::cout << "- "<<_livres[i] << std::endl;
		}
	}
	float pf = (float) p;
	float nf = (float) n;
	float pourcentage = (pf/nf) * 100;
	std::cout << p << " livres sont empruntés, soit un pourcentage de " << pourcentage << "%" << std::endl;
	return ress;
}


Emprunt Bibliotheque::emprunt(Date date_emprunt, Livre &livre, Lecteur &lecteur){
	Emprunt e(date_emprunt, livre, lecteur);
	int n= _livres.size();
	for(int i = 0; i < n; i++) {
		if(_livres[i] == livre && _livres[i].disponible()){
			_livres[i].setDispo(false);
		}
	}
	return e;
}

void Bibliotheque::retour(Emprunt& e, Lecteur &lecteur, Livre &livre){
	e.retour(lecteur,livre);
	int n= _livres.size();
	for(int i = 0; i < n; i++) {
		if(_livres[i] == livre && _livres[i].disponible()==false){
			_livres[i].setDispo(true);
		}	
	}
}

//Ne fonctionne pas :(
void Bibliotheque::classement(){
	for(int i = 0; i<nombre_lecteurs(); i++){
		std::cout << _lecteurs[i].nom() << " a lu " << _lecteurs[i].nombre_livres_lus() << " livres."<< std::endl;
	}
}

std::vector<Lecteur> Bibliotheque::lecteurs(){
	return _lecteurs;
}

int Bibliotheque::nombre_lecteurs(){
	std::cout << std::endl;
	return _lecteurs.size();
}








