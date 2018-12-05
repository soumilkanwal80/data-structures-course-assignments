#pragma once
#include "header.h"
using namespace std;
class itemNode
{
protected:
	bool isFruit;
	int x, y;
	int calories;

public:
	itemNode *next;



friend class itemList;
public:
itemNode();
bool isVisited;

// virtual bool isAvail(string);
// virtual bool searchNode(string);
// virtual bool searchStore(int, int);
int returnCalories() const { return this->calories;}
int returnX() const { return this->x;}
int returnY() const { return this->y;}
void assignFruit(bool);
bool returnIsFruit() const ;


};



