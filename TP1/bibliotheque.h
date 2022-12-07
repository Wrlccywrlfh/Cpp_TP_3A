#include "lecteur.h"
#include "livre.h"
#include <vector>

class Bibliotheque {
public:
	Bibliotheque();
	void add_lecteur(Lecteur le);
	void add_livre(Livre li);
private:
	std::vector<Lecteur> _lecteurs;
	std::vector<Livre> _livres;
};