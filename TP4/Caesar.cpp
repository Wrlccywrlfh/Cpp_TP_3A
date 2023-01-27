#include "Caesar.h"

Caesar::Caesar(std::string message) {
		_plain = message;
		_cypher = message;
}

void Caesar::encode(int decalage) {
	if (decalage <= 0) {
		std::cout << "ERROR : Votre décalage doit être positif pour encode ! Nous avons fait le travail pour vous." << std::endl;
		decalage = -decalage; }
	for (int i = 0; i < _plain.length(); i++) {
		if( _plain[i] > 96 && _plain[i] < 123 - decalage) {
			_cypher += char(_plain[i] + decalage);
		}
		else if(_plain[i] >= 123 - decalage  && _plain[i] < 123)
		_cypher[i] = char(_plain[i] + decalage - 26);
		else _cypher +=_plain[i];
		std::cout <<char(_cypher[i]);
	}
		std::cout << std::endl;
}

void Caesar::decode(int decalage) {
	if (decalage >= 0) {
		std::cout << "ERROR : Votre décalage doit être négatif pour decode ! Nous avons fait le travail pour vous." << std::endl;
		decalage = -decalage; }
	for (int i = 0; i < _plain.length(); i++) {
		if( _cypher[i] > (96 - decalage) && _cypher[i] < 123) {
			_plain[i] = char(_cypher[i] + decalage);
		}
		else if(_cypher[i] > 96 && _cypher[i] <= 96 - decalage)
			 _plain[i] = char(_cypher[i] + decalage + 26);
		else _plain[i] = _cypher[i];
		std::cout <<char(_plain[i]) ;
		}
	std::cout << std::endl;
}

void Caesar::read(std::string fichier){
	Encrypt::read(fichier);
}

void Caesar::write(std::string fichier){
	Encrypt::write(fichier);
}