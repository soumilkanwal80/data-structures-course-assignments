#include "header.h"
using namespace std;

itemNode::itemNode()
{
	isVisited = 0;
}

long long itemNode::returnID()
{
	return this->id;
}

void itemNode::print()
{
	cout<<this->id<<" "<<this->x<<" "<<this->y<<" "<<this->hours<<":"<<this->mins<<endl;
}

bool itemNode::searchNode(string s)
{
	return 0;
}

bool itemNode::isAvail(string s)
{
	return 0;
}


bool itemNode::searchStore(int xs, int ys)
{
	return 0;
}

void itemNode::assignFruit(bool b)
{
	this->isFruit = b;
}

bool itemNode::returnIsFruit()
{
	return this->isFruit;
}
