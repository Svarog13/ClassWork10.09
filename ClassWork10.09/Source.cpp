#include <iostream>

class Student
{
private:
	std::string name;
	int age;
	std::string specialization;
	int* marks;
	int markCount;
public:
	Student() :name("none"), age(0), specialization("none"), marks(nullptr), markCount(0) {}
	Student(std::string name, int age, std::string specialization)
	{
		this->name = name;
		this->age = age;
		this->specialization = specialization;
		this->markCount = rand() % 10 + 1;
		marks = new int[markCount];
		for (size_t i = 0; i < markCount; i++)
		{
			marks[i] = rand() % 3 + 9;
		}
	}

	virtual void Print()const
	{
		std::cout << "Name: " << name << std::endl;
		std::cout << "Age: " << age << std::endl;
		std::cout << "Specialization: " << specialization << std::endl;
		std::cout << "Marks: " << std::endl;
		for (size_t i = 0; i < markCount; i++)
		{
			std::cout << marks[i] << " ";
		}
		std::cout << std::endl;
	}

	virtual ~Student()
	{
		if (marks != nullptr)
		{
			delete[]marks;
		}
		std::cout << "Student destructor." << std::endl;
	}
	
};

class Aspirant : public Student
{
private:
	std::string* subjects;
	int countSubjects;
public:
	Aspirant(std::string name,int age, std::string specialization,std::initializer_list<std::string> list):Student(name,age,specialization)
	{
		countSubjects = list.size();
		subjects = new std::string[countSubjects];
		int i = 0;
		for (std::string elem : list)
		{
			subjects[i] = elem;
			i++;
		}
		
	}
	void Print()const override
	{
		Student::Print();
		std::cout << "Subjects : " << std::endl;
			for (size_t i = 0; i < countSubjects; i++)
			{
				std::cout << subjects[i] << " , ";
			}
			std::cout << std::endl;
	}
	~Aspirant()override
	{
		if (subjects != nullptr)
		{
			delete[]subjects;
		}
		std::cout << "Aspirant destructor" << std::endl;
	}

};

int main()
{
	srand(time(0));
	Student st1("Valera", 22, "Ingeneer");
	st1.Print();
	Aspirant asp1("Georhii", 25, "Designer", { "UI Disigne", "UX Disign", "Maya" });
	asp1.Print();

	Student* group[3]
	{
		new Student("Vasya",24,"No ingeneer"),
		new Aspirant("Petro",35 ,"Programmer", {"C++","JS","SQL"}),
		new Aspirant("Ivan",27 ,"Programmer", {"C#","Python","PostGree"})
	};

	for (size_t i = 0; i < 3; i++)
	{
		group[i]->Print();
		delete group[i];
	}
}