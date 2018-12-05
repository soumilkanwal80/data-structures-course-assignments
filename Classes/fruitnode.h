#pragma once
#include "header.h"

using namespace std;
class fruitNode : public itemNode
{
protected:
	int price;
	string type;
	float weight;
	int calories;
	int amount;

public:
	fruitNode();

	fruitNode(string, int, int,float, int, int, int);
	void print();
	bool searchNode(string);
	bool searchStore(int, int);
	int returnCalories();
	int returnAmount();
	int returnPrice();
	void modifyAmount(int);
	bool isAvail(string);
	string returnName();

};



