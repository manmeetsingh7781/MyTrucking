#include "pch.h"
#include "init.h"
#include "Driver.h"
#include "Load.h"


Driver::Driver(string name, string company, int age)
{
	driver_age = age;
	driver_name = name;
	driver_company = company;
	ofstream driver;
	driver.open("./drivers/"+name + ".dat");
	driver << "Driver Name: " << driver_name << '\n';
	driver << "Driver Age: " << driver_age << '\n';
	driver << "Driver Company: " << driver_company << '\n';
}

void Driver::set_trailer_number(int number) {
	trailer_number = number;
}

void Driver::set_truck_number(int number) {
	truck_number = number;
}

void Driver::set_truck_name(string name) {
	truck_name = name;
}

bool Driver::pick_up_load(Load load) {
	if (not loaded) {
		my_currunt_load = load;
		loaded = true;
		return loaded;
	}
	return loaded;
}

void Driver::get_load_info(Load load) {

	if (loaded) {
		cout << "Load Type: " << load.load_type
			<< "\nLoad Value: $" << load.value
			<< "\nLoad Weight: " << load.load_weight << " Pounds "
			<< "\nDue in: " << load.due_in << " Day(s)"
			<< "\nPickup Location: " << load.pickup_location
			<< "\nDrop-off Location: " << load.drop_location
			<< "\nUnder-Driver: " << driver_name
			<< endl;
	}
	else cout << "Trailer is Empty\n";
}