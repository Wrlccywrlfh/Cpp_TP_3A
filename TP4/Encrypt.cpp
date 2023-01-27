#include "Encrypt.h"
#include <fstream>

void Encrypt::read(std::string fichier){
	 std::ifstream flux(fichier.c_str());
 	std::string line="";
 	_plain = "";
 	if(flux) {
 		while(getline(flux, line)){
 			_plain = _plain + line;
 			std::cout << line << "\n";
 		}
 	}
 	else  {
		std::cout << "\033[1;94;39mFATAL ERROR : VOTRE ORDINATEUR VA ÊTRE DÉCONNECTÉ.\033[0m" << std::endl;
		exit(0);
		}
 }

void Encrypt::write(std::string fichier){

	std::fstream file;
 	file.open(fichier, std::ios::out);
 	if(file.is_open()) {
 		file << _cypher;
 	}
 	else{
		std::cout << "\033[1;94;39mFATAL ERROR : VOTRE ORDINATEUR VA ÊTRE DÉCONNECTÉ.\033[0m" << std::endl;
		//exit(0);
	}
	file.close();
}

std::string Encrypt::plain() {
	std::cout << _plain << std::endl;
	return _plain;
}

std::string  Encrypt::cypher() {
	std::cout << _cypher << std::endl;
	return _cypher;
}
