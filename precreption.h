#pragma once
#define PRECREPTION_H
using namespace std;

class precreption {
	string illness;
	int cost;
public:
	precreption();
	void illnessCost(string x);
	void doctorCost(string x);
	int totalCost();
};