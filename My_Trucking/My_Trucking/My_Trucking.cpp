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
	string name, c_name;
	int age;
	cout << cout.width(30) << "\bWelcome to MyTrucking" << endl;
	cout << "A. To Register a Driver.\n";
	cout << "B. To Check Driver Information.\n";
	cout << "C. To Setup Load.\n";
	cin >> res;
	res = toupper(res);
	if (res == 'A') {
		cout << "Enter Driver Name\n>";
		cin.get();
		getline(cin, name);
		cout << "Enter Driver Company\n>";
		getline(cin, c_name);
		cout << "Enter Driver Age\n>";
		cin >> age;
		Driver driver = Driver(name, c_name, age);
		get_driver_information(driver);
	}
	if (res == 'B') {
		cout << "Enter Driver's Name\n";
		cin.get();
		getline(cin, name);
		ifstream driver_record;
		driver_record.open("./drivers/" +name+".dat");
		cout << "You Typed: " << name << endl;
		cout << "Does Found: "<< driver_record.is_open() << endl;
		if (not driver_record.is_open()) {
			cout << "Driver Not Found\n";
		}
		else {
			string line;
			while (getline(driver_record, line)) {
				cout << line << endl;
			}
		}
	}
}