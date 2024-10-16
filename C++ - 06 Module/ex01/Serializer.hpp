// c++98

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP
# include <string>
# include <iostream>
# include <stdint.h>
# include <stdlib.h>

using std::string;
using std::cout;
using std::endl;

typedef int Data;

class Serializer
{
private:
	Serializer();
	Serializer(const Serializer& obj);
	Serializer& operator=(const Serializer& obj);
	~Serializer();
public:
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
};

#endif // SERIALIZER_HPP