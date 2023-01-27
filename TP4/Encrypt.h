#ifndef ENCRYPT_H
#define ENCRYPT_H
#include <string.h>
#include <iostream>
#include <cstring>
#include <fstream>

class Encrypt
{
public:
	std::string plain();
	std::string cypher();
	virtual void encode(int decalage) = 0;
	virtual void decode(int decalage) = 0; 
	void read(std::string fichier);
	void write(std::string fichier);
protected: 
	std::string _plain; //Message non chiffré
	std::string _cypher; //Message chiffré
};

#endif