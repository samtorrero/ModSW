// Parcial01.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>
#include <Windows.h>

using namespace std;

class Cake {
public:
	virtual void batido() = 0;
	virtual void amaseado() = 0;
	virtual void horneado() = 0;
	virtual void decorado() = 0;
	virtual void empacado() = 0;

	virtual Cake* clone() = 0;
};

template <class SubClass>
class CloneCake : public Cake {
public:
	virtual Cake* clone() {
		return new SubClass(dynamic_cast<SubClass&>(*this));
	}
};

class TresLeches : public CloneCake<TresLeches> {
public:
	void batido() {

	}
	void amaseado() {

	}
	void horneado() {

	}
	void decorado() {

	}
	void empacado() {

	}
};

class Sacher : public CloneCake<Sacher> {
public:
	void batido() {

	}
	void amaseado() {

	}
	void horneado() {

	}
	void decorado() {

	}
	void empacado() {

	}
};

class Imposible : public CloneCake<Imposible> {
public:
	void batido() {

	}
	void amaseado() {

	}
	void horneado() {

	}
	void decorado() {

	}
	void empacado() {

	}
};

class Sucursal {
public:
	int tipoC
	void createCake(int tipo) {
		tipoC = tipo;
		Creator* creator = new ConcreteCreator();
		Cake* cake = creator->createCake(tipoC);
	}
};

class Creator {
public:
	virtual Cake* factoryMethod(int) = 0;

	Cake* createCake(int tipo) {
		Cake* cake = factoryMethod(tipo);
		cake->batido();
		cake->amaseado();
		cake->horneado();
		cake->decorado();
		cake->empacado();
		return cake;
	}
};


class ConcreteCreator : public Creator {
	Cake* factoryMethod(int tipo) {
		if (tipo == 1)
			return new TresLeches;
		if (tipo == 2)
			return new Sacher;
		if (tipo == 3)
			return new Imposible;
	}
};

class Menu {
public:
	char op;
	void menu() {
		do {
			system("cls");
			cout << "a. Ordenar pastel" << endl;
			cout << "b. Crear pastel" << endl;
			cout << "c. Administrar sucursales" << endl;
			cout << "d. Administrar pasteles creados" << endl;
			cout << "e. Ingredientes" << endl;
			cout << "indica la opcion: " << endl;
			op = _getche();
			if ((op < 'a') || (op > 'e'))
				cout << "Opcion no valida" << endl;
			else {
				switch (op) {
				case 'a': 
					Creator* creator = new ConcreteCreator();
					Cake* cake = creator->createCake(1);
					
					break;
				//case 'b': mayor(); break;
				}
			}
		} while (op != 'e');
	}
};


int main()
{
	Menu* menu = new Menu();
	menu->menu();
    return 0;
}

