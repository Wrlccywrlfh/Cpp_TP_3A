#ifndef VIGENERE_H
#define VIGENERE_H

#include <fstream>
#include <string>
#include <iostream>
#include <cstring>
#include <vector>
#include "Encrypt.h"

class Vigenere : public Encrypt {
public:
	Vigenere(std::string message, std::vector<int> clef);
	Vigenere(std::string message, std::string clef);

	std::string plain() const;

	void encode(int decalage) override;
	void decode(int decalage) override;
	void transformation(std::string alpha_clef);
	void read(std::string fichier);
	void write(std::string fichier);

private :  	
	std::vector<int> _clef = {};
	std::string _alpha_clef;
	bool _existe = false;
	int _taille;
};

#endif
