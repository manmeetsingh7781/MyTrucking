#pragma once
#include "init.h"

class Load
{
public:
	int load_weight, due_in, value;
	string load_type, under_driver, drop_location, pickup_location;
	void set_location(string, string);
	void setup_load();
};

