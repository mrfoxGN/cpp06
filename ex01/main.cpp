#include <iostream>
#include "Serializer.hpp"

int	main(void)
{
	Data		test;
	uintptr_t	serialized;
	Data		*deserialized;

	std::cout << "Initializing struct Data test with:" << std::endl;
	test.str = "a custom string";
	std::cout << &test << std::endl;
	std::cout << "str: " << test.str << std::endl;

	test.nb = 123;
	std::cout << "nb: " << test.nb << std::endl;

	test.d_nb = 123.321;
	std::cout << "d_nb: " << test.d_nb << std::endl;

	std::cout << std::endl;
	serialized = Serializer::serialize(&test);

	std::cout << "Serialized struct Data test is:" << std::endl;
	std::cout << serialized << std::endl;

	std::cout << std::endl;
	deserialized = Serializer::deserialize(serialized);

	std::cout << "Deserialized serialized struct Data test is:" << std::endl;
	std::cout << deserialized << std::endl;
	std::cout << "str: " << deserialized->str << std::endl;
	std::cout << "nb: " << deserialized->nb << std::endl;
	std::cout << "d_nb: " << deserialized->d_nb << std::endl;

	return (0);
}