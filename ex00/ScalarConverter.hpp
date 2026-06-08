#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>

class ScalarConverter {
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &cpy);
		
		~ScalarConverter();

		ScalarConverter &operator=(const ScalarConverter &rhs);

	public:
		static void	convert(std::string str);
};

#endif
