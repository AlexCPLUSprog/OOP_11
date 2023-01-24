#include <iostream>
#include <vector>
#include "Person.h"
// Виртуальное наследование, виртуальные функции

//	a
// b c	b::a	c::a
//	d


// B : A		A() a1 B() b1		A() a2 C() c1	----- когда 2 класса наследуются от 1, то у этих двух создаются 2 объекта "родителя" (в этом случае 2 раза A)

// QT GUI
// wxWidgets

class IVehicle {	// I - интерфейс, негласное имя. Класс без определенных функций. Обычно у интерфейсов нет полей
public:

	virtual ~IVehicle(){		// у родителя пишем виртуальный деструктор
		std::cout << "IVehicle destructor was called" << '\n';
	}

	virtual void printName() {
		std::cout << "IVehicle" << '\n';
	}
	virtual int getSpeed() = 0;	// Абстрактный метод. = 0 означает, что у метода нет определения. Не сможем создать объект такого класса

};

class Car : public IVehicle {
public:
	Car(int speed) : _speed(speed) {}
	~Car() {
		std::cout << "Car destructor was called" << '\n';
	}
	void printName() override {				// перегружаем виртуальную функцию,т.к она не самостоятельная, и ее определение находится выше
		std::cout << "Car" << '\n';
	}
	int getSpeed() override {
		return _speed;
	}
private:
	int _speed;
};

void printer(IVehicle* vehicle) {
	vehicle->printName();
	std::cout << "Speed: " << vehicle->getSpeed() << '\n';
}

class Van : public Car{
public:
	Van(int speed) : Car(speed){}
	~Van() {
		std::cout << "Van destructor was called" << '\n';
	}
};

class HouseVan : public Van {
public:
	HouseVan(int speed) : Van(speed){}
	~HouseVan() {
		std::cout << "HouseVan Destructor was called" << '\n';
	}
};

class Motorcycle : public IVehicle {
public:
	Motorcycle(int speed) : _speed(speed) {}
	~Motorcycle() {
		std::cout << "Motorcycle destructor was called" << '\n';
	}

	int getSpeed() override {
		return _speed;
	}
private:
	int _speed;
};

class IMoveble {		// еще один абстрактный класс
public:
	virtual void move(int x, int y) = 0;
	virtual void transform(int degree) = 0;
};



// Каждый класс с виртуальным методом становится виртуальным классом
// Таблица создается одна на один класс

int main() {
	// Пример динамического полиморфизма

	// IVehicle* a = new IVehicle();	// интерфейс не создаем
	IVehicle* b = new Car(60);
	IVehicle* c = new Motorcycle(50);
	IVehicle* d = new Van(45);
	IVehicle* e = new HouseVan(35);

	std::vector<IVehicle *> vehicles;	// вектор указателей на объекты
	//vehicles.push_back(a);
	vehicles.push_back(b);
	vehicles.push_back(c);
	vehicles.push_back(d);
	vehicles.push_back(e);
	// a->b() == (*a).b()
	std::cout << "Traversing vehicles:" << '\n';
	/*for (size_t i = 0; i < vehicles.size(); i++) {
		vehicles[i]->printName();	// vehicles[0] == *a; a->printName()
	}*/

	for (size_t i = 0; i < vehicles.size(); i++) {
		printer(vehicles[i]);
	}

	delete b;
	delete c;
	delete d;
	delete e;

	/*Person p1("Alex");
	p1.fight();*/

	IPerson* p1 = new Person("Alex");
	p1->fight();
}