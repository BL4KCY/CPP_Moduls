#include "Serializer.hpp"

int main(void)
{
	Data data = -1234;
	Data data2 = 42;

	// Serializer s;
	uintptr_t raw = Serializer::serialize(&data);
	Data* ptr = Serializer::deserialize(raw);
	
	*Serializer::deserialize(Serializer::serialize(&data2)) = 1337;

	std::cout << *ptr << std::endl;
	std::cout << data2 << std::endl;
	return 0;
}
