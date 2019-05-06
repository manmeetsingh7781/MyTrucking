#include "pch.h"
#include "init.h"
#include "Load.h"


// Initilization the load
void Load::setup_load()
{
	string types;
	int weight, due, worth;
	cout << "Enter the load Type, Weight, Due in(Days), and Money Amount\n";
	cin >> types >> weight >> due >> worth;
	load_type = types;
	load_weight = weight;
	due_in = due;
	value = worth;
	cin.clear();
	cin.ignore();
}

// Load Location
void Load::set_location() {
	cout << "Please set the location\n";
	string from, to;
	cout << "From: ";
	getline(cin, from);
	cin.clear();
	cout << "To: ";
	getline(cin, to);
	pickup_location = from;
	drop_location = to;
}
