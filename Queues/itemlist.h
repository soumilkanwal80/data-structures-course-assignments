#pragma once
#include "header.h"
#include "itemnode.h"
using namespace std;

template<typename T> class sQueue;
template <typename T> bool operator <=(const itemNode a, const  itemNode b);

template <typename T>
class sQueue 										// an interface for the queue
{
private:
	int size;
	T *front;
	T *rear;
	deque<T *> dq;
public:
	sQueue();
	int returnSize() const;				      // number of items in queue
	bool empty() const;					     // is the queue empty?
	const T& returnMin();
	const T& returnFront();	     		   // the front element
	void enqueue (T* e);			  	  // enqueue element at rear	
	void dequeue (); 		     		 // dequeue element at front
	friend bool operator <=(const itemNode a, const itemNode b);
	//bool operator<= (const itemNode& a){return this->returnCalories()<=a.returnCalories();}
};

 template<typename T>
 bool operator <=(itemNode a,itemNode b)
 {
 	if(a.returnCalories()<=b.returnCalories())
 		return 1;
 	return 0;
 }

template<typename T>
sQueue<T>::sQueue()
{
	this->size = 0;
	front = NULL;
	rear= NULL;
}

template<typename T>
int sQueue<T>::returnSize() const
{
	return this->size;
}

template<typename T>
bool sQueue<T>::empty() const
{
	return this->size == 0;
}

template<typename T>
const T& sQueue<T> ::returnFront()
{
	if(this->size == 0)
	{
		cout<<"Queue is Empty\n";
		return *front;
	}
	else 
		return *front;
}

template<typename T>
void sQueue<T>::enqueue(T* e)
{

	if(rear == NULL)
	{
		rear = e;
		front = e;
		dq.push_back(e);
	}

	else
	{
		rear->next = e;
		rear = e;
		while(!dq.empty() && e->returnCalories()<=dq.back()->returnCalories())
		{
			dq.pop_back();
		}
		dq.push_back(e);
	}
	this->size++;
}

template<typename T>
void sQueue<T>::dequeue()
{
	if(this->size == 0)
	{
		cout<<"Queue is Empty\n";
		return;
	}
	itemNode *temp = front;
	if(temp->returnCalories() == dq.front()->returnCalories())
		dq.pop_front();
	front = front->next;
	delete front;
	this->size--;
}

template<typename T>
const T& sQueue<T>::returnMin()
{
	if(dq.size() == 0)
	{
		cout<<"Queue is Empty\n";
		return *front;
	}

	return *dq.front();
}


