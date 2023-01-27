#pragma once
#include "genre.h"
#include "date.h"
#include "langue.h"
#include "auteur.h"

using namespace std;

	class Livre
	{
	public:
		Auteur auteur();
		Livre(std::string nom, Auteur auteur, Langue langue, Genre genre, Date publication, long isbn);
		std::string nom();
		long ISBN();
		bool disponible();
		void setDispo(bool b);
		bool operator == (Livre& livre) const;
		friend std::ostream& operator<<(std::ostream& out, Livre& livre);
	private:
		std::string _nom; 
		Auteur _auteur; 
		Langue _langue;
		Genre _genre; 
		Date _publication;
		long _ISBN;
		bool _disponible;
	};

	