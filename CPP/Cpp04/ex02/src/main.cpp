#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	const int size = 4;
	Animal* animals[size];

	for (int i = 0; i < size / 2; i++)
		animals[i] = new Dog();
	for (int i = size / 2; i < size; i++)
		animals[i] = new Cat();

	for (int i = 0; i < size; i++)
	{
		std::cout << animals[i]->getType() << std::endl;
		animals[i]->makeSound();
	}

	for (int i = 0; i < size; i++)
		delete animals[i];

	std::cout << "---------------------" << std::endl;

	Dog a;
	a.setIdea(0, "bone");

	Dog b(a);
	b.setIdea(0, "new bone");

	std::cout << a.getIdea(0) << std::endl;
	std::cout << b.getIdea(0) << std::endl;

	return 0;
}