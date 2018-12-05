#include "header.h"
using namespace std;

itemNode::itemNode()
{
	isVisited = 0;
}


void itemNode::assignFruit(bool b)
{
	this->isFruit = b;
}

bool itemNode::returnIsFruit() const
{
	return this->isFruit;
}
