// Tarea2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <cstring>
#include <Windows.h>

using namespace std;

class Computer {
public:
	virtual void componentSelection() = 0;
	virtual void componentEnsambling() = 0;
	virtual void SWInstalation() = 0;
	virtual void computerPacking() = 0;
};

class Desktop : public Computer {
	void componentSelection() {
		cout << "Seleccionando componentes" << endl;
	}
	void componentEnsambling() {
		cout << "Ensablando componentes" << endl;
	}
	void SWInstalation() {
		cout << "Instalando y configurando SW" << endl;
	}
	void computerPacking() {
		cout << "Empaquetando equipo" << endl;
	}
};

class Laptop : public Computer {
	void componentSelection() {
		cout << "Seleccionando componentes" << endl;
	}
	void componentEnsambling() {
		cout << "Ensablando componentes" << endl;
	}
	void SWInstalation() {
		cout << "Instalando y configurando SW" << endl;
	}
	void computerPacking() {
		cout << "Empaquetando equipo" << endl;
	}
};

class Netbook : public Computer {
	void componentSelection() {
		cout << "Seleccionando componentes" << endl;
	}
	void componentEnsambling() {
		cout << "Ensablando componentes" << endl;
	}
	void SWInstalation() {
		cout << "Instalando y configurando SW" << endl;
	}
	void computerPacking() {
		cout << "Empaquetando equipo" << endl;
	}
};

class Tablet : public Computer {
	void componentSelection() {
		cout << "Seleccionando componentes" << endl;
	}
	void componentEnsambling() {
		cout << "Ensablando componentes" << endl;
	}
	void SWInstalation() {
		cout << "Instalando y configurando SW" << endl;
	}
	void computerPacking() {
		cout << "Empaquetando equipo" << endl;
	}
};

class Creator {
public:
	virtual Computer* factoryMethod(int) = 0;

	Computer* createProduct(int tipo) {
		Computer* myComputer = factoryMethod(tipo);
		myComputer->componentSelection();
		myComputer->componentEnsambling();
		myComputer->SWInstalation();
		myComputer->computerPacking();
		return myComputer;
	}
};

class ConcreteCreator : public Creator {
	Computer* factoryMethod(int tipo) {
		if (tipo == 1)
			return new Desktop;
		if (tipo == 2)
			return new Laptop;
		if (tipo == 3)
			return new Netbook;
		if (tipo == 4)
			return new Tablet;
		else
			cout << "Computadora no seleccionada" << endl;
	}
};

int main() {
	return 0;
}

