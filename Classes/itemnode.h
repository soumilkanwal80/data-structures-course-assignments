#pragma once
#include "header.h"
using namespace std;
class itemNode
{
protected:
	long long id;
	bool isFruit;
	int x, y;
	int hours, mins;
public:
	itemNode *next;



friend class itemList;
public:
itemNode();
bool isVisited;
long long returnID();
virtual void print();
virtual bool isAvail(string);
virtual bool searchNode(string);
virtual bool searchStore(int, int);
int returnX(){ return this->x;}
int returnY(){ return this->y;}
void assignFruit(bool);
bool returnIsFruit();


};



