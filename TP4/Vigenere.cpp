#include "Vigenere.h"

Vigenere::Vigenere(std::string message, std::vector<int> clef) {
	_plain = message;
	_cypher = message;
	_clef = clef;
	_taille = _clef.size();
}

Vigenere::Vigenere(std::string message, std::string alpha_clef) {
	_plain = message;
	_cypher = message;
	_alpha_clef = alpha_clef;
	_taille = _alpha_clef.size();
	_existe = true;
}

void Vigenere::transformation(std::string alpha_clef) {
	std::vector<int> inupi = {};
	for(int i = 0; i < alpha_clef.size() ; i++) {
		if (65 <= alpha_clef[i] && alpha_clef[i] <= 90)
		{
			inupi.push_back(alpha_clef[i] - 64) ;
		}
		else if (97 <= alpha_clef[i] && alpha_clef[i] <= 122)
		{
			inupi.push_back(int(alpha_clef[i]) - 96) ;
		}
		else {
			std::cout << "\033[1;94;39mFATAL ERROR : VOTRE ORDINATEUR VA ÊTRE DÉCONNECTÉ.\033[0m" << std::endl;
			exit(0);
		}
	}
	_clef = inupi;
}

void Vigenere::encode(int decalage) {
	if(_existe) transformation(_alpha_clef);

	for(int i = 0; i < _taille; i++) {
		if(_clef[i] < 0)  _clef[i] = -_clef[i];
		if(_clef[i] > 26) {
			_clef[i] = _clef[i] - (_clef[i]/26)*26;
			std::cout << "Votre clef ne correspondait pas, nous l'avons modifiée pour vous." << std::endl;
		}
	}
	decalage = _taille;
	std::string inupi = "";
	for(int i = 0; i < _plain.size(); i ++) {
		if((_plain[i] >= 65 && _plain[i] <= 90) || (_plain[i] >= 97 && _plain[i] < 123)) {
			inupi.push_back(_plain[i]); //On ôte les espaces	
		}
	}

	//Encode les lettre
	int comp = 0;
	for(int i = 0; i < inupi.size(); i++) {
		if((inupi[i] >= 65 && inupi[i] <= 90 - _clef[comp%decalage]) || (inupi[i] >= 97 && inupi[i] < 123 - _clef[comp%decalage])) {
			inupi[i] = char(inupi[i] + _clef[comp%decalage]);
			comp++;
		}
		else {
			inupi[i] = char(inupi[i] + _clef[comp%decalage] - 26); comp++;
		}
	}
	//Si char spécial, on le laisse tel quel
	int comp2 = 0;
	_cypher = "";
	for(int i = 0; i < _plain.size(); i ++) {
		if((_plain[i] >= 65 && _plain[i] <= 90) || (_plain[i] >= 97 && _plain[i] < 123)) {
			_cypher += inupi[comp2];
			comp2++;
		}
		else _cypher += _plain[i];
	}
	std::cout << _cypher << std::endl;
}

void Vigenere::decode(int decalage) {
if(_existe) transformation(_alpha_clef);
	for(int i = 0; i < _taille; i++) {
		if(_clef[i] < 0)  _clef[i] = -_clef[i];
		if(_clef[i] > 26) {
			_clef[i] = _clef[i] - (_clef[i]/26)*26;
			std::cout << "Votre clef ne correspondait pas, nous l'avons modifiée pour vous." << std::endl;
		}
	}
	decalage = _taille;
	std::string inupi = "";
	for(int i = 0; i < _cypher.size(); i ++) {
		if((_cypher[i] >= 65 && _cypher[i] <= 90) || (_cypher[i] >= 97 && _cypher[i] < 123)) {
			inupi.push_back(_cypher[i]); //On ôte les espaces	
		}
	}

	int comp = 0;
	for(int i = 0; i < inupi.size(); i++) {
		if((inupi[i] >= 65 + _clef[comp%decalage] && inupi[i] <= 90) || (inupi[i] >= 97 + _clef[comp%decalage] && inupi[i] < 123)) {
			inupi[i] = char(inupi[i] - _clef[comp%decalage]);
			comp++;
		}
		else {
		inupi[i] = char(inupi[i] - _clef[comp%decalage] + 26);
		comp++;
		}
	}

	int comp2 = 0;
	for(int i = 0; i < _cypher.size(); i ++) {
		if((_cypher[i] >= 65 && _cypher[i] <= 90) || (_cypher[i] >= 97 && _cypher[i] < 123)) {
			_plain[i] = inupi[comp2];
			comp2++;
		}
		else _plain[i] = _cypher[i];
	}

	std::cout << _plain << std::endl;
}

std::string Vigenere::plain() const{
	return _plain;
}

 void Vigenere::read(std::string fichier) {
 	Encrypt::read(fichier);
 }

void Vigenere::write(std::string fichier) {
	Encrypt::write(fichier);
 }
