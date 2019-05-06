#include "pch.h"
#include "init.h"
#include "Load.h"


// Initilization the load
Load::Load()
{
	string temp;
	cout << "Enter the load Type: ";
	cin.get();
	getline(cin, load_type);
	cout << "Enter the load Name: ";
	getline(cin, load_name);
	cout << "Weight: ";
	cin >> load_weight;
	cout << "Due in(Days): ";
	cin >> due_in;
	cin.get();
	cout << "Worth ($): ";
	cin >> value;
	cout << "From: ";
	cin.get();
	getline(cin, pickup_location);
	cout << "To: ";
	getline(cin, drop_location);
	cout << "======= Load Ready Details ======= \n";
	cout << endl << "LOAD TYPE: " << load_type
		<< endl << "LOAD NAME: " << load_name
		<< endl << "LOAD WEIGHT: " << load_weight
		<< endl << "DUE IN: " << due_in << " DAY(s)"
		<< endl << "WORTH: $" << value
		<< endl << "PICKUP LOCATION: " << pickup_location
		<< endl << "DROP-OFF LOCATION: " << drop_location
		<< endl;
}

void Load::count_loads() {
	
}