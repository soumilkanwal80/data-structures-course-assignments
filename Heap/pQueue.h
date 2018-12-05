#pragma once
#include "header.h"
using namespace std;

template <typename E, typename C>//E is element type and C is comparator
class pQueue
{             // adaptable priority queue
private:
    int size;
    E *arr;
    void heapifyUp(int i);
    void heapifyDown(int i);
    void reallocate();
    
public:
    pQueue();
    pQueue(E *input, int input_size);
    void removeMin();                                // remove minimum
    const E& returnMin() const;                        // minimum element
    void insert(const E& e);                        // insert element
    void print();
    void bottomUpConst(vector<E> e, int len);
    void remove();                                // remove at location l
    void replace(const E& e);                 // replace at position p
    
    int returnSize() const {return size;}            // number of elements
    bool isEmpty() const { return size == 0; }                // is the queue empty?
    static int getLeftChild(int i){ return 2*i; }
    static int getRightChild(int i){ return 2*i + 1;}
    static int getParent(int i){ return i/2; }
    C cmp;
    class locator{
    public:
        int index;
    } locate;
};


template<typename E, typename C>
void pQueue<E, C> :: bottomUpConst(vector<E> e, int len)
{
    int num = log2(len);
    num++;
    size = len;
    int new_size = 1<<num;
    arr = new E[new_size];
    

    for(int i=1;i<len;i++)
    {
        arr[i] = e[i-1];
        cout<<arr[i].name<<endl;
    }

    for(int i = len/2;i>=1;i--)
        heapifyDown(i);

}

template <typename E, typename C>
pQueue<E, C>::pQueue()
{
    size = 0;
    arr = new E[1];
}


template <typename E, typename C>
const E& pQueue<E, C>::returnMin() const
{
    if(size == 0)
        throw "Empty Queue";
    
    return arr[1];
}


 template <typename E, typename C>
 void pQueue<E, C>::print()
 {
    for(int i=1;i<size+1;i++)
    {
        if(floor(log2(i)) == ceil(log2(i))) 
            cout<<endl;
        cout<<arr[i].name<<" ";
    }
 }

template <typename E, typename C>
void pQueue<E, C>::heapifyDown(int i)
{
    int l = getLeftChild(i);
    int r = getRightChild(i);
    int smallest = i;
    if(l<size && cmp(arr[l], arr[i]))
        smallest = l;
    else if(r<size && cmp(arr[r], arr[smallest]))
        smallest = r;
    
    if(smallest != i)
    {

        if(smallest == locate.index)
            locate.index = i;
        else if(i == locate.index)
            locate.index = smallest;

        swap(arr[smallest], arr[i]);
        heapifyDown(smallest);
    }


}

template <typename E, typename C>
void pQueue<E, C>::heapifyUp(int i)
{
    assert(size>0);
    
    while(i>=2 && cmp(arr[i], arr[getParent(i)]))
    {
        if(i == locate.index)
            locate.index = getParent(i);
        else if(getParent(i) == locate.index)
            locate.index = i;

        swap(arr[getParent(i)],arr[i]);
        i = getParent(i);
    }
}

template<typename E, typename C>
void pQueue<E, C>::reallocate()
{
    if(size!=0 && (ceil(log2(size)) == floor(log2(size))))
    {
        // Doubling the size of heap array
        E *temp = new E[size + 1];
        for(int i=1;i<size + 1;i++)
            temp[i] = arr[i];
        arr = new E[2*size + 1];
        for(int i = 1;i<size + 1;i++)
            arr[i] = temp[i];
        delete[] temp;

    }
}

template<typename E, typename C>
void pQueue<E, C>::insert(const E& e)
{
    if(size == 0)
    {
        arr = new E[2];
    }
    
    // Check for overflow
    else if(ceil(log2(size)) == floor(log2(size)))
    {
        reallocate();
    }
    
    size++;
    arr[size] = e;
    locate.index = size;
    heapifyUp(size);

    
}


template<typename E, typename C>
void pQueue<E, C>::remove()
{
    if(locate.index == 0)
    {
        cout<<"Element has already been removed/replaced\n";
        return;
    }
    arr[locate.index] = arr[size-1];
    size--;
    heapifyDown(locate.index);
    heapifyUp(locate.index);
    locate.index = 0;
}

template<typename E, typename C>
void pQueue<E, C>::removeMin()
{
    arr[1] = arr[size-1];
    size--;
    if(locate.index == 1)
        locate.index = 0;
    heapifyDown(1);
    
}

template<typename E, typename C>
void pQueue<E, C>::replace(const E& e)
{
    if(locate.index == 0)
    {
        cout<<"Element has already been removed/replaced\n";
        return;
    }
    arr[locate.index] = e;
    heapifyDown(locate.index);
    heapifyUp(locate.index);
}








