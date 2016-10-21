#include<iostream>
#include<string>
#include <cstdlib>
#include <vector>

using namespace std;

class ArrayPositiveInts;

class Proxy {
private:
    ArrayPositiveInts& arr;
    int idx;
    
public:
    Proxy(ArrayPositiveInts& arr, int idx)
    : arr(arr), idx(idx){}
    
    Proxy& operator=(int value);
};

class ArrayPositiveInts {
private:
    int* values;
    int size;
public:
    friend class Proxy;
    ArrayPositiveInts() {
        size = 100;
        values = new int[size];
    }
    Proxy operator[](int idx) {
        return Proxy(*this, idx);
        
    }
    int get(int pos) {
        return values[pos];
    }
};

class Subject {
    vector < class Observer * > views;
    string news;
  public:
    void attach(Observer *obs) {
        views.push_back(obs);
    }
    void setNews(string note) {
        news = note;
        notify();
    }
    string getNews() {
        return news;
    }
    void notify();
};

class Observer {
    Subject *model;
public:
    Observer(Subject *mod) {
        model = mod;
        model->attach(this);
    }
    virtual void update() = 0;
protected:
    Subject *getSubject() {
        return model;
    }
};

void Subject::notify() {
  for (int i = 0; i < views.size(); i++)
    views[i]->update();
}

class MVS: public Observer {
  public:
    MVS(Subject *mod): Observer(mod){}
    void update() {
        string mvsNote = getSubject()->getNews();
        cout << "MVS News: " << mvsNote << endl;
    }
};

class Televisa: public Observer {
  public:
    Televisa(Subject *mod): Observer(mod){}
    void update() {
        string televisaNote = getSubject()->getNews();
        cout << "Televisa: " << televisaNote << endl;
    }
};

class TVAzteca: public Observer {
  public:
    TVAzteca(Subject *mod): Observer(mod){}
    void update() {
        string tvAztecaNote = getSubject()->getNews();
        cout << "TV Azteca: " << tvAztecaNote << endl;
    }
};

class RadioFormula: public Observer {
  public:
    RadioFormula(Subject *mod): Observer(mod){}
    void update() {
        string radioFormulaNote = getSubject()->getNews();
        cout << "Radio Formula: " << radioFormulaNote << endl;
    }
};

class CNN: public Observer {
  public:
    CNN(Subject *mod): Observer(mod){}
    void update() {
        string cnnNote = getSubject()->getNews();
        cout << "CNN News: " << cnnNote << endl;
    }
};

void publish(int num) {
	ArrayPositiveInts a;
	a[0]=num;
}

Proxy& Proxy::operator=(int value) {
	string newNote = ("");
    if(value==1) {
    	Subject subj;
    	
		MVS mvs(&subj);
		Televisa televisa(&subj);
		TVAzteca tvazteca(&subj);
		RadioFormula radio(&subj);
		
		getline(cin, newNote);
		subj.setNews(newNote);
    }
    if(value==2) {
    	Subject subj;
    	
		MVS mvs(&subj);
		Televisa televisa(&subj);
		TVAzteca tvazteca(&subj);
		RadioFormula radio(&subj);
		CNN cnn(&subj);
		
		getline(cin, newNote);
		subj.setNews(newNote);
	}
	if(value==3) {
		Subject subj;
		MVS mvs(&subj);
		Televisa televisa(&subj);
		TVAzteca tvazteca(&subj);
		RadioFormula radio(&subj);
		CNN cnn(&subj);
		
		getline(cin, newNote);
		subj.setNews(newNote);
	}
    else {
        cout << "error" << endl;
        return *this;
    }
}

class Menu {
public:
	char op;
	string note;
	void menu() {
		do {
			system("cls");
			cin.clear();
			cout << "User:" << endl;
			cout << "a. Pena Nieto" << endl;
			cout << "b. Hilary" << endl;
			cout << "c. Trump" << endl;
			cin >> op;
			
			switch (op) {
				case 'a':
					system("cls");
					cout << "Note:" << endl;
    				
					publish(1);
					getwchar();
					getwchar();
					break;
					
				case 'b':
					system("cls");
					cout << "Note:" << endl;
    				
					publish(2);
					getwchar();
					getwchar();
					break;
					
				case 'c':
					system("cls");
					cout << "Note:" << endl;
    				
					publish(3);
					getwchar();
					getwchar();
					break;
					
				default:
					system("cls");
					cout << "Please enter an existing user..." << endl;
					getwchar();
					getwchar();
					break;
			}
		} while (op != 'e');
	}
};

int main() {
	Menu* menu = new Menu();
	menu->menu();
}
