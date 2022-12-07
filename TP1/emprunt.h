#include "date.h"
class Emprunt
{
public:
	Emprunt(Date date_emprunt, int ISBN, std::string id_lecteur, bool autorisation);
private:
	Date _date_emprunt;
	int _ISBN;
	std::string _id_lecteur;
	bool _autorisation;
};