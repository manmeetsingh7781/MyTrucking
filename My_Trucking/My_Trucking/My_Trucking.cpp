#include "pch.h"
#include "init.h"
#include "Driver.h"
#include "Load.h"

void startup();

int main()
{
	startup();
	cin.get();
	return 0;
}


void startup() {
	char res;
	cout << cout.width(30) << "\bWelcome to MyTrucking" << endl;
	cout << "A. To Register a Driver.\n";
	cout << "B. To Check Driver Information.\n";
	cout << "C. To Setup Load.\n";
	cin >> res;
	res = toupper(res);
	if (res == 'A') {
		string name, company;
		int age;
		cout << "Enter Driver Name\n";
		cin >> name;
		cin.ignore();
		cin.clear();
		cin.ignore(' ', 10);
		cout << "Enter Company Name\n";
		cin >> company;
		cin.ignore();
		cin.clear();
		cout << "Enter Driver Age\n";
		cin >> age;
		cin.ignore();
		cin.clear();
		Driver driver = Driver(name, company, age);
		get_driver_information(driver);
	}
}