#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "date.h"

	class Auteur
	{
	private:
		std::string  _nom;
		std::string  _prenom;
		std::string  _id;
		Date _naissance;
	public:
		Auteur(std::string  nom, std::string  prenom, Date naissance);
		std::string id();
		std::string nom();
		std::string prenom();
		bool operator == (Auteur& auteur) const;
	};

std::ostream& operator<<(std::ostream& out, Auteur& auteur);

