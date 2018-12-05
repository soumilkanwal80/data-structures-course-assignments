#pragma once
#include "header.h"
#include "itemnode.h"
using namespace std;

class itemList
{
protected:
	itemNode *head, *tail;
public:
	itemList()
	{
		head = NULL;
		tail = NULL;
	}
	~itemList();
	void insertNode();
	void insertNode(string, int, int, float, int, int, int, bool);
	void printList();
	void searchList(int);
	void itemBuy();
	void deleteNode();

};

