#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base	*generate(void)
{
	int	rand = std::rand() % 3;

	if (rand == 0)
		return (new A);
	else if (rand == 1)
		return (new B);
	else
		return (new C);
}

void	identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void	identify(Base &p)
{
	try {
		A &a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "A" << std::endl;
		return ;
	} catch (std::exception &e) {}

	try {
		B &b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "B" << std::endl;
		return ;
	} catch (std::exception &e) {}

	try {
		C &c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "C" << std::endl;
		return ;
	} catch (std::exception &e) {}
}

int	main(void)
{
	Base	*tmp;

	std::srand(std::time(NULL));

	std::cout << "Identifying with pointer: 10 random classes" << std::endl;
	for (int i = 0; i < 10; i++) {
		tmp = generate();
		identify(tmp);
		delete tmp;
	}

	std::cout << std::endl;
	std::cout << "Identifying with reference: 10 random classes" << std::endl;
	for (int i = 0; i < 10; i++) {
		tmp = generate();
		identify(*tmp);
		delete tmp;
	}

	std::cout << std::endl;
	std::cout << "Identifying with pointer: manual classes" << std::endl;

	tmp = new A;
	std::cout << "A: ";
	identify(tmp);
	delete tmp;

	tmp = new B;
	std::cout << "B: ";
	identify(tmp);
	delete tmp;

	tmp = new C;
	std::cout << "C: ";
	identify(tmp);
	delete tmp;

	std::cout << std::endl;
	std::cout << "Identifying with reference: manual classes" << std::endl;

	tmp = new A;
	std::cout << "A: ";
	identify(*tmp);
	delete tmp;

	tmp = new B;
	std::cout << "B: ";
	identify(*tmp);
	delete tmp;

	tmp = new C;
	std::cout << "C: ";
	identify(*tmp);
	delete tmp;

	return (0);
}