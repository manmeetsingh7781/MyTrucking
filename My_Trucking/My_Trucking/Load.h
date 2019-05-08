#pragma once
#include "init.h"

class Load
{
public:
	Load();
	bool isDone = false;
	string load_type, under_driver, load_name, drop_location, pickup_location
		, load_weight, due_in, value;
	void setStatus(Load, bool);
};


