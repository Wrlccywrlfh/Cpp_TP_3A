#include "BasicEncrypt.h"

BasicEncrypt::BasicEncrypt(std::string plain, std::string cypher)
{
	_plain  = plain;
	_cypher = cypher;
}

std::string BasicEncrypt::plain() {
	std::cout << "Plain : "  << _plain << std::endl;
	return _plain;
}

std::string BasicEncrypt::cypher() {
	std::cout << "Cypher : " << _cypher << std::endl;
	return _cypher;
}

 void BasicEncrypt::encode() {
	std::string temp = _plain;
	_plain = _cypher;
	_cypher = temp;
}

void BasicEncrypt::decode(){
	std::string temp = _cypher;
	_cypher = _plain;
	_plain = temp;
}
