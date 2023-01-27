#include <string.h>
#include <iostream>

class BasicEncrypt 
{ 
 public:
 	BasicEncrypt(std::string plain, std::string cypher);
	std::string plain();
	std::string cypher();
	void encode();
	void decode();
protected: 
	std::string _plain; //Message non chiffré
	 std::string _cypher; //Message chiffré
 };

