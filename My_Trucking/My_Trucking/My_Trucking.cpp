#include "pch.h"
#include "init.h"
#include "Driver.h"
#include "Load.h"
#include <string>

void startup();
void write_file(string, string);
string get_loads_details(string);
ifstream my_file;
const string PATH = "./loads/all_loads.dat";


int main()
{
	my_file.open(PATH);
	startup();
	return 0;
}


void startup() {
	char res;
	string name, c_name;
	int age;
	bool Running = true;
	int spacer;
	while (Running) {
		cout << cout.width(30) << "\bWelcome to MyTrucking" << endl;
		cout << "A. To Register a Driver.\n";
		cout << "B. To Check Driver Information.\n";
		cout << "C. To Setup Load.\n";
		cout << "D. To Change Load Status.\n";
		for (spacer = 0; spacer < 10; spacer++)	cout << endl;
		cout << ">";
		cin>> res;
		res = toupper(res);
		if (res == 'M')	startup();
		if (res == 'E') Running = false;
		if (res == 'A') {
			cout << "Enter Driver Name\n>";
			cin.get();
			getline(cin, name);
			cout << "Enter Driver Company\n>";
			getline(cin, c_name);
			cout << "Enter Driver Age\n>";
			cin >> age;
			Driver driver = Driver(name, c_name, age);
		}
		else if (res == 'B') {
			cout << "Enter Driver's Name\n";
			cin.get();
			getline(cin, name);
			ifstream driver_record;
			driver_record.open("./drivers/" + name + ".dat");
			cout << "You Typed: " << name << endl;
			if (not driver_record.is_open()) {
				cout << "Driver Not Found\n";
			}
			else {
				string line;
				for (spacer = 0; spacer < 10; spacer++)	cout << endl;
				cout << "===========Driver Details==========\n";
				while (getline(driver_record, line)) {
					cout << line << endl;
				}
				for (spacer = 0; spacer < 5; spacer++)	cout << endl;

			}
		}
		else if (res == 'C') {
			int counter = 0;
			string status;
			counter = atoi(get_loads_details("all").c_str());
			string line;
			ofstream loads, all_loads;
			Load new_load;
			new_load.Set_Load();
			loads.open("./loads/" + new_load.load_name + ".dat");
			all_loads.open("./loads/all_loads.dat");
			if (new_load.isDone != 0) status = "True";
			else status = "False";
			loads << "LOAD TYPE: " << new_load.load_type
				<< endl << "LOAD NAME: " << new_load.load_name
				<< endl << "LOAD WEIGHT: " << new_load.load_weight
				<< endl << "DUE IN: " << new_load.due_in << " DAY(s)"
				<< endl << "WORTH: $" << new_load.value
				<< endl << "PICKUP LOCATION: " << new_load.pickup_location
				<< endl << "DROP-OFF LOCATION: " << new_load.drop_location
				<< endl << "STATUS: " << status
				<< endl;

			all_loads << "LOAD TYPE: " << new_load.load_type
				<< '\t\t' << "LOAD NAME: " << new_load.load_name
				<< '\t\t' << "STATUS: " << status
				<< endl;

			cout << "All Loads: " << counter << endl;
		}
		else if (res == 'D') {
			string name;
			cout << "Enter Load Name\n>";
			cin.get();
			getline(cin, name);
			ifstream load_file;
			load_file.open("./loads/" + name + ".dat");
			if (not load_file.is_open()) cout << "Load Not Found\n";
		}
	}
}


// Writes to the file
void write_file(string name, string obj) {
	ofstream my_file;
	my_file.open("./loads/" + name + ".dat", ios::app);
	if (my_file.is_open()) {
		my_file << obj << '\n';
	}
	my_file.close();
}

// gets load details
string get_loads_details(string type) {
	string line;
	string all_lines;
	int value;
	value = 0;
	int line_limit = 3;
	size_t finder;
	if (not my_file.eof() and my_file.is_open()) {
		while (getline(my_file, line)) {
			if (type == "True") {
				finder = line.find("True");
				if (finder != string::npos)	all_lines += line + '\n';
			}
			else if (type == "False") {
				finder = line.find("False");
				if (finder != string::npos)	all_lines += line + '\n';
			}else all_lines += line + '\n';
		}
	}
	return all_lines;
}
