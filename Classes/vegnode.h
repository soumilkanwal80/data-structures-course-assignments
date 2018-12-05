#pragma once
#include "header.h"

using namespace std;
class vegNode: public itemNode
{
protected:
	int price;
	float vol;
	string type;
	int calories;
	int amount;
public:

	vegNode();
	vegNode(string, int, int,float, int, int, int);
	void print();
	bool searchNode(string);
	bool searchStore(int, int);
	int returnCalories();
	int returnAmount();
	int returnPrice();
	void modifyAmount(int x);
	bool isAvail(string);
	string returnName();

};




