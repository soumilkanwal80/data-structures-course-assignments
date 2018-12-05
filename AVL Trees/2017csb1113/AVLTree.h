#include "header.h"
using namespace std;

#define ALLOWED_IMBALANCE 1
template<typename T>
class AVLNode{
public:
    T key;
    T meaning;
    AVLNode *left;
    AVLNode *right;
    AVLNode(const T val);
    AVLNode(const T val, const T val2);
};

template<typename T>
AVLNode<T>::AVLNode(const T val)
{
    left = NULL;
    right = NULL;
    key = val;
    
}

template<typename T>
AVLNode<T>::AVLNode(const T val, const T val2)
{
    left = NULL;
    right = NULL;
    key = val;
    meaning = val2;
    
}

template <typename T>
class AVLTree
{
private:
    AVLNode<T> *root;
    int size;
    int countAllinRangeUtil(AVLNode<T> *node, const T k1, const T k2) const;
    AVLNode<T>* rotateWithLeft(AVLNode <T> *node);
    AVLNode<T>* rotateWithRight(AVLNode <T> *node);
    AVLNode<T> *deleteKeyUtil(AVLNode <T> *node, const T val);
    AVLNode<T> *findMin(AVLNode <T> *node) const;
    int findHeight(AVLNode<T> *node) const;
    AVLNode<T> * insertUtil(AVLNode <T> *node, T val, T val2);
    
    
public:
    AVLTree();
    void insert(T val, T val2);
    void deleteKey(T key);
    void printTree() const;
    int countAllinRange(const T k1, const T k2) const;
    bool searchTree(T val) const;
    int returnSize() const;
};

template<typename T>
AVLTree<T>::AVLTree()
{
    size = 0;
    root = NULL;
}

template<typename T>
AVLNode<T> * AVLTree<T>::insertUtil(AVLNode<T> *node, const T val, const T val2)
{
    
    if(node == NULL)
    {
        this->size++;
        return new AVLNode<T>(val, val2);
    }
    
    if(val<node->key)
    {
//        cout<<this->size<<endl;
        node->left = insertUtil(node->left, val, val2);
    }
    else if(val>node->key)
    {
//        cout<<this->size<<endl;
        node->right = insertUtil(node->right, val, val2);
    }
         
    else
    {
        node->meaning = val2;
        return node;
    }
    
    int balance = (int)findHeight(node->left) - (int)findHeight(node->right);
    if(balance > 1)
    {
        if(val<node->left->key)
        {
            return rotateWithRight(node);
        }

        if(val>node->left->key)
        {
            node->left = rotateWithLeft(node->left);
            return rotateWithRight(node);
        }
    }

    if( -balance > 1)
    {
        if(val>node->right->key)
        {
            return rotateWithLeft(node);
        }

        if(val<node->right->key)
        {
            node->right = rotateWithRight(node->right);
            return rotateWithLeft(node);
        }
    }

    return node;
}

template<typename T>
void AVLTree<T> :: insert(const T val1, const T val2)
{
    root = insertUtil(root, val1, val2);
}

template<typename T>
int AVLTree<T>::returnSize() const
{
    return this->size;
}

template<typename T>
bool AVLTree<T>::searchTree(const T val) const
{
    AVLNode<T> *temp = root;
    if(root == NULL)
        cout<<"YES"<<endl;
    while(temp!=NULL)
    {
        
        if(val<temp->key)
            temp = temp->left;
        else if(val > temp -> key)
            temp = temp->right;
        else if(val == temp->key)
        {
            cout<<"Meaning: "<<temp->meaning<<endl;
            return 1;
        }
    }
    
    cout<<"Does not exist\n";
    return 0;
}

template<typename T>
AVLNode<T>* AVLTree<T>::deleteKeyUtil(AVLNode<T> *node, const T val)
{
    if(node == NULL)
    {
        return node;
    }
    
    if(val<node->key)
    {
       node->left =  deleteKeyUtil(node->left, val);
    }
    
    else if(val>node->key)
    {
        node->right = deleteKeyUtil(node->right, val);
    }
    
    else if(val == node->key)
    {
        if(node->left != NULL && node->right!=NULL)
        {
            AVLNode<T> *temp = findMin(node->right);
//            node->key.clear();
//            node->meaning.clear();
            node->key = temp->key;
            node->meaning = temp->meaning;
            node->right = deleteKeyUtil(node->right, node->key);
        }
        
        else
        {
            AVLNode<T> *delNode = node;
            node = (node->left!=NULL)?node->left:node->right;
            delete delNode;
        }
    }
    
    if(node == NULL)
        return node;
    
    int balance = (int) findHeight(node->left) - (int) findHeight(node->right);
    int lbalance = 0, rbalance = 0;
    if(node->left!=NULL)
        lbalance = (int) findHeight(node->left->left) - (int) findHeight(node->left->right);
    if(node->right!=NULL)
        rbalance = (int) findHeight(node->right->left) - (int) findHeight(node->right->right);
    
    
    if(balance>1)
    {
       if(lbalance>=0)
           return rotateWithRight(node);
        else
        {
            node->left = rotateWithLeft(node->left);
            return rotateWithRight(node);
        }
    }
    
    if(-balance > 1)
    {
        if(rbalance>=0)
            return rotateWithLeft(node);
        else
        {
            node->right = rotateWithRight(node->right);
            return rotateWithLeft(node);
        }
    }
    
    return node;
    
}

template<typename T>
void AVLTree<T>::deleteKey(const T val)
{
    if(searchTree(val))
    {
        root = deleteKeyUtil(root, val);
        this->size--;
        cout<<"Word Deleted\n";
    }

    return;
}



template<typename T>
void AVLTree<T>::printTree() const
{
    if(root == NULL)
    {
        cout<<"Empty Tree\n";
        return;
    }
    
    queue<AVLNode<T>*> q;
    q.push(root);
    while(!q.empty())
    {
        int nc = (int) q.size();
        
        while(nc>0)
        {
            AVLNode<T> *node = q.front();
            cout<<q.front()->key<<" ";
            q.pop();
            if(node->left!=NULL)
                q.push(node->left);
            if(node->right!=NULL)
                q.push(node->right);
            nc--;
            
            
        }
        cout<<endl;
        
    }
    
}

template<typename T>
AVLNode<T> * AVLTree<T>::rotateWithRight(AVLNode <T> *node)
{
    AVLNode <T> * child = node->left;
    AVLNode <T> * T2 = child->right;
    child->right = node;
    node->left = T2;
    return child;
}

template<typename T>
AVLNode<T> * AVLTree<T>::rotateWithLeft(AVLNode <T> *node)
{
    AVLNode<T> *child = node->right;
    AVLNode<T> *T2 = child->left;
    child->left = node;
    node->right = T2;
    return child;
}


template<typename T>
AVLNode<T>* AVLTree<T>::findMin(AVLNode<T> *node) const
{
    while(node->left!=NULL)
        node = node->left;
    return node;
}

template<typename T>
int AVLTree<T> :: findHeight(AVLNode<T> *node) const
{
    if(node == NULL)
        return 0;
    
    return max(findHeight(node->right), findHeight(node->left)) + 1;
}

template<typename T>
int AVLTree<T> :: countAllinRangeUtil(AVLNode<T> *node, const T k1, const T k2) const
{
    if(node==NULL)
        return 0;
    
    if(node->key == k1 && node->key == k2)
        return 1;
    
    if(node->key<=k2 && node->key>=k1)
    {
        return 1 + countAllinRangeUtil(node->left, k1, k2) + countAllinRangeUtil(node->right, k1, k2);
    }
    
    else if(node->key<k1)
    {
        return countAllinRangeUtil(node->right, k1, k2);
    }
    
    else
    {
        return countAllinRangeUtil(node->left, k1, k2);
    }
}

template<typename T>
int AVLTree<T> :: countAllinRange(const T k1, const T k2) const
{
    if(root==NULL)
        return 0;
    
    if(root->key == k1 && root->key == k2)
        return 1;
    
    return countAllinRangeUtil(root, k1, k2);
        
}
