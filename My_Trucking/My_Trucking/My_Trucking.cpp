#include "pch.h"
#include "init.h"
#include "Driver.h"
#include "Load.h"


void startup();

int main()
{
	startup();
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
	else if (res == 'B') {
		cout << "Enter Driver's Name\n";
		cin.get();
		getline(cin, name);
		ifstream driver_record;
		driver_record.open("./drivers/" +name+".dat");
		cout << "You Typed: " << name << endl;
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
	else if (res == 'C') {
		int counter = 0;
		counter = 1;
		ofstream loads;
		fstream all_loads;
		Load new_load = Load();
		all_loads.open("./loads/all_loads.dat", ios::app);
		loads.open("./loads/" + new_load.load_name + ".dat");
		loads << "LOAD TYPE: " << new_load.load_type
			<< endl << "LOAD NAME: " << new_load.load_name
			<< endl << "LOAD WEIGHT: " << new_load.load_weight
			<< endl << "DUE IN: " << new_load.due_in << " DAY(s)"
			<< endl << "WORTH: $" << new_load.value
			<< endl << "PICKUP LOCATION: " << new_load.pickup_location
			<< endl << "DROP-OFF LOCATION: " << new_load.drop_location
			<< endl;
		all_loads << counter << '\n';
		cout << "ALL LOADS " << counter << endl;
	}
	else startup();

}