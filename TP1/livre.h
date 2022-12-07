#include "genre.h"
#include "langue.h"
#include "date.h"
using namespace std;

	class Livre
	{
	public:
		Livre(std::string nom, std::string auteur, Langue langue, Genre genre, Date publication, int isbn);
		std::string auteur();
		std::string nom();
		int ISBN();
		bool disponible();
		void setDispo();
	private:
		std::string _nom; 
		std::string _auteur; 
		Langue _langue;
		Genre _genre; 
		Date _publication;
		int _ISBN;
		//std::vector<Lecteur> _lecteurs;
		bool _disponible = true;
	};
