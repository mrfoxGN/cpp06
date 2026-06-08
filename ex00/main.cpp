#include "ScalarConverter.hpp"
#include <iostream>

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Error: Invalid argument(s)" << std::endl;
		std::cerr << "Type ./convert [CHAR / INT / FLOAT / DOUBLE]" << std::endl;
		std::cerr << "Examples :" << std::endl;
		std::cerr << "./convert c" << std::endl;
		std::cerr << "./convert -123" << std::endl;
		std::cerr << "./convert +23.57f" << std::endl;
		std::cerr << "./convert 7594.045" << std::endl;
		return (1);
	}
	ScalarConverter::convert(av[1]);
	return (0);
}