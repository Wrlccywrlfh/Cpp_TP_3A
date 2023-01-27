#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "livre.h"

	class Lecteur
	{
	private:
		std::string _nom;
		std::string _prenom;
		std::string _id;
		Date _naissance;
		Date _inscription;
		std::vector<Livre> _ISBN_lus;
		std::vector<Livre> _livre_actuel;
	public:
		Lecteur(std::string  nom, std::string  prenom, Date naissance, Date _inscription);
		std::string id();
		void ajout(Livre &l);
		void suppr(Livre l);
		void ajout_lus(Livre l);
		void display_livre_actuel();
		std::string nom();
		std::string prenom();
		int nombre_livres_lus();
		int getISBN_lus();
		int _n_ISBN_lus;
		friend std::ostream& operator<<(std::ostream& out, Lecteur& lecteur);
	};

