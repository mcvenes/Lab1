#include <iostream>
#include <string>

#include "MyStack.h"
#include "Person.h"
#include "PersonKeeper.h"


int main(int argc, char** argv)
{
    const std::string inputFilePath = argv[1];
    const std::string outputFilePath = argv[2];

	MyStack<std::string> stack(3);

	for (int i = 0; i < 5; i++)
	{
		std::string str = "test string N_" + std::to_string(i);

		try
		{
			stack.push(str);
		}
		catch (const Exc::EStackOverflow& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	for (int i = 0; i < 5; i++)
	{
		try
		{
			std::string str = stack.pop();
		}
		catch (const Exc::EStackEmpty& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}


	MyStack<Person> personStack = PersonKeeper::instance().readPersons(inputFilePath, 100);

	std::fstream outStream;
	outStream.open(outputFilePath, std::ios_base::out);
	if (!outStream.is_open())
	{
		return 1;
	}

	PersonKeeper::instance().writePersons(personStack, outStream);

	return 0;
}