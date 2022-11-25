#include "PersonKeeper.h"


MyStack<Person>*
PersonKeeper::readPersons(const std::string& filePath, int maxSize) const
{
	std::cout << "Stack max size:" << maxSize << std::endl;

    MyStack<Person>* stack = new MyStack<Person>(maxSize);

	// ��������� ���� ��� ������
	std::fstream stream;
	stream.open(filePath, std::ios_base::in);
	if (!stream.is_open())
	{
		// �������� ��������� ������ ���������, ���� �� ������� ������� ���� ��� ������
		std::cerr << "Failed to open input file: " << filePath << std::endl;
        return NULL;
	}

	stream.exceptions(std::ios_base::eofbit | std::ios_base::failbit | std::ios_base::badbit);

	// �������� ������ ����� (����) �� ��� ���, ���� �� �� ���������� ��� �� ���������� ����
    while (!stack->isFull())
	{
		std::string firstName;
		std::string middleName;
		std::string lastName;

		bool needBreak = false;

		try
		{
			stream >> lastName;
			stream >> firstName;
			stream >> middleName;
		}
		catch (...)
		{
			// ������� ���������� ������, ������� ��� ���� ������ �� �����
			std::cout << "End of file\n";
			needBreak = true;
		}

		//��������� ��������� � ����
		if (!firstName.empty() && !lastName.empty() && !middleName.empty())
		{
			Person p;
			p.setFirstName(firstName);
			p.setLastName(lastName);
			p.setMiddleName(middleName);
            stack->push(p);
		}
		else
		{
			break;
		}

		if (needBreak)
		{
			break;
		}
	}

	return stack;
}


void 
PersonKeeper::writePersons(MyStack<Person> stack, std::fstream& stream)
{
	if (!stream.is_open())
	{
		// ���� ����� �� ������, �� ��������� ������ ������
		std::cerr << "Stream is close!";
		return;
	}

	// ���� �� ���������� �������� � �����: ������ � ���������� � �����
	while (!stack.isEmpty())
	{
		Person p = stack.pop();
		try {
			stream << p.getLastName() << " " << p.getFirstName() << " " << p.getMiddleName() << "\n";
		}
		catch (...)
		{
			// �� �����-�� ������� �� ������ ���������� ������ � �����, ��������� ������
			std::cerr << "Unknown stream error";
			return;
		}
	}
}
