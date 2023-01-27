#include "emprunt.h"
#include "bibliotheque.h"

int main(int argc, char const *argv[])
{
	/////////////  Création de la bibliotheque /////////////
	Bibliotheque b;

	Lecteur le1("Brottel-Patience", "Florent", Date(11, 2001), Date(01, 2023));
	b.add_lecteur(le1); 
	Lecteur le2("Haricot", "Magique", Date(4, 2000), Date(01, 2023));
	b.add_lecteur(le2);
	Lecteur le3("Gerard", "Titouan", Date(03, 1988), Date(03, 2014));
	b.add_lecteur(le3);

	Auteur a1("Houellbecq", "Michel", Date(02,1956));
	Auteur a2("Caroll", "Lewis", Date(01, 1832));
	Auteur a3("Barjavel", "René", Date(01, 1911));
	Auteur a4("Brown", "Dan", Date(06, 1964));
	Auteur a5("Dostoïevski", "Fiodor", Date(11, 1821));
	Auteur a6("Ionesco", "Eugene", Date(11, 1909));
	Auteur a7("Sukegawa", "Durian", Date(6, 62));
	Auteur a8("Philippon", "Benoît", Date(11, 1976));

	Livre l1("Les délices de Tokyo", a7, Langue::Français, Genre::Roman, Date(2,2013), 9782253070870);
	Livre l2("La carte et le terrtoire", a1, Langue::Français, Genre::Roman, Date(9,2010), 9782081246331);
	Livre l3("Da Vinci Code", a4, Langue::Français, Genre::Roman, Date(9,2003), 9782266144346);
	Livre l4("Inferno", a4, Langue::Français, Genre::Roman, Date(5,2013), 9782253004561);
	Livre l5("Anges et Démons", a4, Langue::Français, Genre::Roman, Date(4,2000), 9782253093008);
	Livre l6("Crimes et Chatîments", a5, Langue::Français, Genre::Roman, Date(6,1866), 9782070392537);
	Livre l8("Les Freres Karamazov", a5, Langue::Français, Genre::Roman, Date(8,1879), 9782070389629);
	Livre l7("Rhinicéros", a6, Langue::Français, Genre::Théâtre, Date(11,1959), 9782070368167);	
	Livre l9("Humiliés et offensés", a5, Langue::Français, Genre::Roman, Date(9,1861), 9782070406760);
	Livre l10("Alice au Pays des Merveilles", a2, Langue::Français, Genre::Roman, Date(2,1965), 9782210740587);
	Livre l11("La nuit des temps", a3, Langue::Français, Genre::Roman, Date(4, 1969), 6543456686);
	Livre l12("Mamie Luger", a8, Langue::Français, Genre::Roman, Date(4, 2020), 9782253241485); //Excellent livre

	b.add_livre(l1);
	b.add_livre(l2);
	b.add_livre(l3);
	b.add_livre(l4);
	b.add_livre(l5);
	b.add_livre(l6);
	b.add_livre(l7);
	b.add_livre(l8);
	b.add_livre(l9);
	b.add_livre(l10);
	b.add_livre(l11);

	b.add_auteur(a1);
	b.add_auteur(a2);
	b.add_auteur(a3);
	b.add_auteur(a4);
	b.add_auteur(a5);
	b.add_auteur(a6);

	///////////// Exemple d'utilisation /////////////

	Lecteur Flo = b.cherche_lecteur(le1.id());	
	Emprunt e1= b.emprunt(Date(4, 01, 2023), l1, le1);
	Emprunt e2= b.emprunt(Date(4, 01, 2023), l2, le1);
	Emprunt e3= b.emprunt(Date(4, 01, 2023), l3, le1);
	Emprunt e4= b.emprunt(Date(4, 01, 2023), l4, le1);
	std::cout<<std::endl;
	Emprunt e5= b.emprunt(Date(4, 01, 2023), l5, le2);
	Emprunt e6= b.emprunt(Date(4, 01, 2023), l6, le2);
	Emprunt e8= b.emprunt(Date(4, 01, 2023), l8, le2);
	Emprunt e9= b.emprunt(Date(4, 01, 2023), l4, le2); //Ne peut pas être emprunté une seconde fois
	le2.display_livre_actuel(); //Fonctionne
	
	std::cout<<std::endl;
	b.retour(e1, le1, l1);
	b.retour(e2, le1, l2);
	b.retour(e3, le1, l3);
	b.retour(e4, le1, l4);
	Emprunt e10= b.emprunt(Date(4, 01, 2023), l4, le2);

	Emprunt e11= b.emprunt(Date(4, 01, 2023), l2, le3);
	Emprunt e12= b.emprunt(Date(4, 01, 2023), l3, le3);
	Emprunt e13= b.emprunt(Date(4, 01, 2023), l10, le3);
	Emprunt e14= b.emprunt(Date(4, 01, 2023), l12, le3);
	Emprunt e15= b.emprunt(Date(4, 01, 2023), l11, le3);
	b.retour(e11, le3, l2);
	b.retour(e12, le3, l3);
	b.retour(e13, le3, l10);
	b.retour(e14, le3, l12);
	b.retour(e15, le3, l11);
	b.livre_auteur(a6);

	std::cout << "\n"<<std::endl;
	le1.nombre_livres_lus(); 
	le2.nombre_livres_lus(); 
	le3.nombre_livres_lus(); 

	return 0;
}