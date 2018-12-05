#include "header.h"
using namespace std;

fruitNode::fruitNode()
{
	long long id1 = rand();
	int x1, y1, time1 = rand()%100;
	string s;
	cout<<"Enter name: ";
	cin>>s;
	cout<<"Enter Location: ";
	cin>>x1>>y1;
	cout<<"Enter weight per unit: ";
	float vl;
	cin>>vl;
	cout<<"Enter price per unit: ";
	int pr;
	cin>>pr;
	cout<<"Enter calories: ";
	int cl;
	cin>>cl;
	cout<<"Enter units to add: ";
	int am;
	cin>>am;
	assignFruit(1);

	this->x = x1;
	this->y = y1;


	this->weight = vl;
	this->type = s;
	this->price = pr;
	this->calories = cl;
	this->amount = am;
	this->next = NULL;
}

fruitNode::fruitNode(string type, int x, int y, float weight, int price, int calories, int units)
{
	assignFruit(1);
	this->type = type;
	this->x = x;
	this->y = y;
	this->weight = weight;
	this->price = price;
	this->calories = calories;
	this->amount = units;
	this->next = NULL;
}

// void fruitNode::print()
// {
// 	cout<<this->type<<setw(20)<<this->x<<setw(20)<<this->y<<setw(20)<<this->price<<setw(20)<<this->weight<<setw(20)<<this->calories<<setw(20)<<this->amount<<endl;
// }

// bool fruitNode::searchNode(string s)
// {
// 	if(this->type == s)
// 	{
// 		cout<<s<<" is available at (";
// 		cout<<this->x<<", "<<this->y<<") @ "<<this->price<<"/unit and "<<this->amount<<" units are available"<<endl;
// 		return 1;
// 	}
// 	return 0;
// }

// bool fruitNode::isAvail(string s)
// {
// 	if(this->type == s)
// 	{
// 		return 1;
// 	}
// 	return 0;
// }

// bool fruitNode::searchStore(int xs, int ys)
// {
// 	if(this->x == xs && this->y == ys)
// 	{
// 		cout<<this->type<<" is available at (";
// 		cout<<this->x<<", "<<this->y<<") @ "<<this->price<<"/unit and has "<<this->amount<<"units available"<<endl;
// 		return 1;
// 	}
// 	return 0;
// }

// const int fruitNode::returnCalories() const
// {
// 	return this->calories;
// }

int fruitNode::returnAmount() const
{
	return this->amount;
}

int fruitNode::returnPrice() const
{
	return this->price;
}

string fruitNode::returnName() const
{
	return this->type;
}

// const void fruitNode::modifyAmount(int x)
// {
// 	this->amount = this->amount - x;
// }

