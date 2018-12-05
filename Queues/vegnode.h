#pragma once
#include "header.h"

using namespace std;
class vegNode: public itemNode
{
protected:
	int price;
	float vol;
	string type;
	int amount;
public:

	vegNode();
	vegNode(string, int, int,float, int, int, int);
	// bool searchNode(string);
	// bool searchStore(int, int);
	// int returnCalories();
	int returnAmount() const;
	int returnPrice() const;
	// covoid modifyAmount(int x);
	// bool isAvail(string);
	string returnName() const;

};




