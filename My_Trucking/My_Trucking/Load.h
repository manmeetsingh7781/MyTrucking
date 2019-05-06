#pragma once
#include "init.h"

class Load
{
public:
	Load();
	int load_weight, due_in, value;
	string load_type, under_driver, load_name, drop_location, pickup_location;
	Load *all_loads[10];
	void count_loads();

private:	int load_counter;
};

