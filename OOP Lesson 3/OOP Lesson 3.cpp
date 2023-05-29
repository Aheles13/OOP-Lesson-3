#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


// Статик переменная и статик функция 

//Задача 1.
class Client
{
private:
	std::string _name;
	int _id;
	static  std::vector <Client*> _clients; // Создание статической переменной 
	
	 void ShowClient()
	{
		std::cout << "Name:" << _name << "\n";
		std::cout << "Id:" << _id << "\n";
	}

public:
	Client(std::string name, int id) : _name(name), _id(id)
	{
		_clients.push_back(this); 
	}

	static void ShowClients()
	{
		for (const auto& it : _clients)
			it->ShowClient();
	}

};

//SOLID

//Открыт для расширения, но закрыт для модификацииюю.

//O - open-closed principl
class Animal
{
private:
	std::string _type;
public:
	Animal(std::string type) : _type(type){ }
	
	virtual std::string GetSound() = 0;

};

class Cow : public Animal
{
public:
	Cow() : Animal ("Cow"){ }
	std::string GetSound() override {
	
		return "MMMMMUUU";
	}
};

class Cat : public Animal
{
public:
	Cat() : Animal("Cat") { }
	std::string GetSound()  override {
	
		return "Myamya";
	}
};

class Dog : public Animal
{
public:
	Dog() : Animal("Dog") { }
	std::string GetSound()  override {
	
		return "GavGAv";
	}
};

void AnimalSound(Animal &animal)
{
	/*if (animal.GetType() == "lion")
		std::cout << "RRR";
	else if (animal.GetType() == "Cat")
		std::cout << "MRRR";
	else if (animal.GetType() == "Dog")
		std::cout << "GavGav";
	else if (animal.GetType() == "Cow")
		std::cout << "MMMMMUUU";*/

	std::cout << animal.GetSound() << "\n";
}

//S
//---------------------------------------------
//Принцип единой ответственности 
/*class ClientServis
{
public:
	void ShowClient(std::vector<Client*>clients)
		{
		for (const auto& it : clients)
			it->Pay();
		}
};*/
//---------------------------------------------

//std::vector <Client*> Client::_clients;  // Статик поле для инициализации переменной 

class Vector
{
private:
	int _size;
	int* _massivPtr;
public:
	Vector()
	{
		_size = 0;
		int* _massivPtr = nullptr;
	}

	void Push_back(int element)
	{
		_size++;
		int* newMassiv = new int[_size];

		if (_massivPtr == nullptr)
		{
			newMassiv[0] = element;
			_massivPtr = newMassiv;
			return;
		}

		for (int i = 0; i < _size - 1; ++i)
			newMassiv[i] = _massivPtr[i];

		newMassiv[_size - 1] = element;

		//int* temp = _massivPtr;
		//delete[]temp;

		delete[]_massivPtr;
		_massivPtr = newMassiv;
	}

		void ShowElement()
		{
			for (int i = 0; i < _size; ++i)
				std::cout << i << " element: " << _massivPtr[i] << "\n";
		}

	
};





int main() {
	setlocale(LC_ALL, "Ru");


	// Задача 1.
	/*Client* client = new Client("John", 20);
	Client* client2 = new Client("Alex", 22);
	Client* client3 = new Client("Bob", 30);
	Client::ShowClients();
	*/
	
	// Задача 2.
	
	/*Cat* cat = new Cat();
	Dog* dog = new Dog();
	Cow* cow = new Cow();
	AnimalSound(*cat);
	AnimalSound(*dog);
	AnimalSound(*cow);*/


	Vector* vector = new Vector();
	vector->Push_back(20);
	vector->Push_back(30);
	vector->Push_back(41);
	vector->Push_back(50);
	vector->Push_back(25);
	vector->ShowElement();







	return 0;
}
