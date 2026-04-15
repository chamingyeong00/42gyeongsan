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
		delete animals[i];

	std::cout << "---------------------" << std::endl;

	Dog dog1;
	dog1.setIdea(0, "I want a bone");

	Dog dog2 = dog1;
	std::cout << dog1.getIdea(0) << std::endl;
	std::cout << dog2.getIdea(0) << std::endl;

	dog2.setIdea(0, "I want another bone");
	std::cout << dog1.getIdea(0) << std::endl;
	std::cout << dog2.getIdea(0) << std::endl;

	std::cout << "---------------------" << std::endl;

	Cat cat1;
	cat1.setIdea(0, "I want fish");

	Cat cat2(cat1);
	std::cout << cat1.getIdea(0) << std::endl;
	std::cout << cat2.getIdea(0) << std::endl;

	cat2.setIdea(0, "I want sleep");
	std::cout << cat1.getIdea(0) << std::endl;
	std::cout << cat2.getIdea(0) << std::endl;

	for (int i = 0; i < size; i++)
		delete animals[i];

	return 0;
}