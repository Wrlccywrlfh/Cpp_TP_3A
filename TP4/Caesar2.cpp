#include "Caesar2.h"

Caesar2::Caesar2(std::string message) {
		_plain = message;
		_cypher = message;
}

void Caesar2::encode(int decalage) {
	if (decalage <= 0) {
		std::cout << "ERROR : Votre décalage doit être positif pour encode ! Nous avons fait le travail pour vous.\n" << std::endl;
		decalage = -decalage; }
	for (int i = 0; i < _plain.length(); i++) {
		if( _plain[i] > 31 && _plain[i] < 127 - decalage) {
			_cypher += char(_plain[i] + decalage);
		}
		else if(_plain[i] >= 127 - decalage  && _plain[i] < 127)
			_cypher[i] = char(_plain[i] + decalage - 96);
		
		else _cypher += _plain[i];
		
		std::cout <<_cypher[i];
	}
		std::cout << std::endl;
}

void Caesar2::decode(int decalage) {
	if (decalage >= 0) {
		std::cout << "ERROR : Votre décalage doit être négatif pour decode ! Nous avons fait le travail pour vous.\n" << std::endl;
		decalage = -decalage; }
	for (int i = 0; i < _plain.length(); i++) {
		if( _cypher[i] > (31 - decalage) && _cypher[i] < 127) {
			_plain[i] = char(_cypher[i] + decalage);
		}
		else if(_cypher[i] > 31 && _cypher[i] <= 31 - decalage)
			 _plain[i] = char(_cypher[i] + decalage + 96);
		else _plain[i] = _cypher[i];

		std::cout <<char(_plain[i]) ;
		}
	std::cout << std::endl;
}

void Caesar2::read(std::string fichier){
	Encrypt::read(fichier);
}

void Caesar2::write(std::string fichier){
	Encrypt::write(fichier);
}