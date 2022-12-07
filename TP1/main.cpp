#include "date.h"
#include "emprunt.h"
#include "bibliotheque.h"

int main(int argc, char const *argv[])
{
	Date date(11, 12);
	Lecteur l("Brottel-Patience", "Florent", date);
	Livre livre("La maison des feuilles", "Je ne sais pas", Langue::Français, Genre::Roman, date, 2442);
	Emprunt e(date, 342314, "de11343", true);

	return 0;
}