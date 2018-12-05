#include "header.h"
using namespace std;
vegNode::vegNode()
{
	int x1, y1;
	string s;
	cout<<"Enter name: ";
	cin>>s;
	cout<<"Enter Location: ";
	cin>>x1>>y1;
	cout<<"Enter volume per kg: ";
	float vl;
	cin>>vl;
	cout<<"Enter price per kg: ";
	int pr;
	cin>>pr;
	cout<<"Enter calories: ";
	int cl;
	cin>>cl;
	cout<<"Enter amount to add: ";
	int am;
	cin>>am;
	assignFruit(0);
	this->x = x1;
	this->y = y1;
	this->vol = vl;
	this->type = s;
	this->price = pr;
	this->calories = cl;
	this->amount = am;
	this->next = NULL;
}

vegNode::vegNode(string type, int x, int y, float weight, int price, int calories, int units)
{
	assignFruit(0);
	this->x = x;
	this->y = y;
	this->vol = weight;
	this->type = type;
	this->price = price;
	this->calories = calories;
	this->amount = units;
	this->next = NULL;
}

// void vegNode::print()
// {
// }

// bool vegNode::searchNode(string s)
// {
// 	if(this->type == s)
// 	{
// 		cout<<s<<" is available at (";
// 		cout<<this->x<<", "<<this->y<<") @ "<<this->price<<"/kg and "<<this->amount<<" kg are available"<<endl;
// 		return 1;
// 	}
// 	return 0;
// }

// bool vegNode::searchStore(int xs, int ys)
// {
// 	if(this->x == xs && this->y == ys)
// 	{
// 		cout<<this->type<<" is available at (";
// 		cout<<this->x<<", "<<this->y<<") @ "<<this->price<<"/kg and has "<<this->amount<<"kg available"<<endl;
// 		return 1;
// 	}
// 	return 0;
// }

int vegNode::returnPrice() const
{
	return this->price;
}

// bool vegNode::isAvail(string s)
// {
// 	if(this->type == s)
// 		return 1;
// 	return 0;
// }

int vegNode::returnAmount() const
{
	return this->amount;
}

// int vegNode::returnCalories()
// {
// 	return this->calories;
// }

string vegNode::returnName() const
{
	return this->type;
}

// void vegNode::modifyAmount(int x)
// {
// 	this->amount = this->amount - x;
// }
