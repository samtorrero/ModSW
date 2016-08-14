#include <iostream>
#include <cstring>
#include <Windows.h>

using namespace std;

class Computer {
public:
        void assembleComputer(char computerReceived[10]);
};

void Computer::assembleComputer(char computerReceived[10]){
	if(strlen(computerReceived)>0){
		if(strncmp(computerReceived, "Desktop", 7) == 0){
			cout << "Desktop" << endl;
			Sleep(1000);
			cout << "Seleccion de componentes" << endl;
			Sleep(1000);
			cout << "Ensamblado de componentes" << endl;
			Sleep(1000);
			cout << "Instalacion y configuracion de Software" << endl;
			Sleep(1000);
			cout << "Empaquetado del computador" << endl;
			Sleep(1000);
			cout << "Desktop creada con exito" << endl;
		}
		if(strncmp(computerReceived, "Laptop", 7) == 0){
			cout << "Laptop" << endl;
			Sleep(1000);
			cout << "Seleccion de componentes" << endl;
			Sleep(1000);
			cout << "Ensamblado de componentes" << endl;
			Sleep(1000);
			cout << "Instalacion y configuracion de Software" << endl;
			Sleep(1000);
			cout << "Empaquetado del computador" << endl;
			Sleep(1000);
			cout << "Laptop creada con exito" << endl;
		}
		if(strncmp(computerReceived, "Netbook", 7) == 0){
			cout << "Notebook" << endl;
			Sleep(1000);
			cout << "Seleccion de componentes" << endl;
			Sleep(1000);
			cout << "Ensamblado de componentes" << endl;
			Sleep(1000);
			cout << "Instalacion y configuracion de Software" << endl;
			Sleep(1000);
			cout << "Empaquetado del computador" << endl;
			Sleep(1000);
			cout << "Netbook creada con exito" << endl;
		}
		if(strncmp(computerReceived, "Tablet", 7) == 0){
			cout << "Tablet" << endl;
			Sleep(1000);
			cout << "Seleccion de componentes" << endl;
			Sleep(1000);
			cout << "Ensamblado de componentes" << endl;
			Sleep(1000);
			cout << "Instalacion y configuracion de Software" << endl;
			Sleep(1000);
			cout << "Empaquetado del computador" << endl;
			Sleep(1000);
			cout << "Tablet creada con exito" << endl;
		}
	} 
	else{
		cout<<"NADA SELECCIONADO"<<endl;
	}
}

int main(){
	Computer c;
	c.assembleComputer("Desktop");
	return (0);
}
