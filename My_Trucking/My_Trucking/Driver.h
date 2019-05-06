#include "init.h"
#include "Load.h"
#include <fstream>

class Driver {
public:
	Driver(string, string, int);
	void set_truck_number(int);
	void set_trailer_number(int);
	void set_truck_name(string);
	bool pick_up_load(Load);
	void get_load_info(Load);
	friend void get_driver_information(Driver driver) {
		cout << "===========Driver Details==========\n\nName: "
			<< driver.driver_name
			<< "\nAge: " << driver.driver_age
			<< "\nTrucking Company: " << driver.driver_company
			<< "\nTruck Number: " << driver.truck_number
			<< "\nTrailer Number: " << driver.trailer_number
			<< "\nTruck Name: " << driver.truck_name
			<< "\nTrailer Loaded: " << driver.loaded
			<< endl;
	}

	
private:
	int truck_number, driver_age, trailer_number;
	string driver_name, truck_name, driver_company;
	bool loaded = false;
	Load my_currunt_load;
};