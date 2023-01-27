#ifndef CAESAR_H
#define CAESAR_H

#include <string>
#include <iostream>
#include <cstring>
#include "Encrypt.h"

class Caesar : public Encrypt {
public:
	Caesar(std::string message);
	void encode(int decalage) override;
	void decode(int decalage) override;
	void read(std::string fichier);
	void write(std::string fichier);
};

#endif
