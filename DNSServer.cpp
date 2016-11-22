#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;


class IPRequest {
	string domain;

public:
	IPRequest(string dom) : domain(dom) {}

	string getDomain() {
		return domain;
	}
};

class Server {
	vector <string> domains;
	Server* successor;
	string name;

public:
	Server(string _name) : name(_name), successor(NULL) {
	}

	string getName() {
		return name;
	}

	Server* getSuccessor() {
		return successor;
	}

	void setSuccessor(Server* _successor) {
		successor = _successor;
	}

	void processIPRequest(IPRequest request) {
		for (int a = 0; a<domains.size(); a += 2) {
			string position = domains.at(a);

			if (position.compare(request.getDomain()) == 0) {
				cout << getName() << " has found " << domains.at(a) << " at " << domains.at(a + 1) << endl;
				cout << "----------------------------------------------------" << endl;
				return;
			}
		}

		if (getSuccessor() == NULL) {
			cout << "Unable to found " << request.getDomain() << endl;
			return;
		}
		else
			cout << getName() << " could't found " << request.getDomain() << ", sent to " << getSuccessor()->getName() <<endl;
		return getSuccessor()->processIPRequest(request);
	}

	void insertRelation(string domain, string IP) {
		domains.push_back(domain);
		domains.push_back(IP);
	}
};

int main() {
	Server* server1 = new Server("Server1");
	Server* server2 = new Server("Server2");
	Server* server3 = new Server("Server3");

	server1->setSuccessor(server2);
	server2->setSuccessor(server3);

	server1->insertRelation("google.com", "192.168.10.12");

	server2->insertRelation("mitec.itesm.mx", "192.168.11.2");

	server3->insertRelation("github.com", "192.168.12.1");

	server1->processIPRequest(IPRequest("google.com"));
	server1->processIPRequest(IPRequest("mitec.itesm.mx"));
	server1->processIPRequest(IPRequest("github.com"));
	server1->processIPRequest(IPRequest("sam.com"));

	return 0;
}