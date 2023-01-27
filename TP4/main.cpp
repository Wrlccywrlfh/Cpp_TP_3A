#include "BasicEncrypt.h" 
#include "Caesar2.h"
#include "Caesar.h"
#include "Vigenere.h"


int main(int argc, char const *argv[])
{
	////////////////// Exemple de code //////////////////
	std::string test1 = "Chrollo et Kurapikaz" ;
	std::string test2 ="Ceci est un test";
	int clef =3;
	std::vector<int> vect = {2345,2,2,0,-354};
	Vigenere v(test1, vect);
	Caesar c(test2);
	Caesar2 c2(test1);
	c.encode(clef); 	
	c.decode(clef);
	c2.encode(clef);
	c2.decode(clef);
	v.encode(4);
	v.decode(4);

	Caesar2 c3(test1);
	c3.read("fichier.txt");
	c3.encode(clef);
	c3.write("ficher3.txt");

	Vigenere v3(test1 ,"zschbezh" );
	v3.read("fichier.txt");
	v3.encode(4);
	v3.write("fichier2.txt");

	return 0;
}