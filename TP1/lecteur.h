#include "date.h"
#include <iostream>
#include <string>

//namespace livre {

	class Lecteur
	{
	public:
		Lecteur(std::string  nom, std::string  prenom, Date naissance);
		std::string id();

	private:
		std::string  _nom;
		std::string  _prenom;
		std::string  _id;
		Date _naissance;
		//std::vector <int> _ISBN_lus = {};
		//std::array<int, 20> _livre_actuel = {0};
	};
//}
