#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <string>
# include <stdint.h>

typedef struct s_Data {
	std::string	str;
	int			nb;
	double		d_nb;
} Data;

class Serializer {
	private:
		Serializer();
		Serializer(const Serializer &cpy);
		
		~Serializer();

		Serializer &operator=(const Serializer &rhs);

	public:
		static uintptr_t	serialize(Data *ptr);
		static Data			*deserialize(uintptr_t raw);
};
#endif
