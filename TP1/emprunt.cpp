#include "emprunt.h"

Emprunt::Emprunt(Date date_emprunt, int ISBN, std::string id_lecteur, bool autorisation) :  
_date_emprunt(date_emprunt), _ISBN(ISBN), _id_lecteur(id_lecteur), _autorisation(autorisation) {
}
