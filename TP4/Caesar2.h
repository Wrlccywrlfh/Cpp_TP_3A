#ifndef CAESAR2_H
#define CAESAR2_H

#include <string>
#include <iostream>
#include <cstring>
#include "Encrypt.h"

class Caesar2 : public Encrypt {
public:
	Caesar2(std::string message);
	void encode(int decalage) override;
	void decode(int decalage) override;
	void read(std::string fichier);
	void write(std::string fichier);
};

#endif
