//
//  main.cpp
//  AVLTree
//
//  Created by Soumil on 03/11/18.
//  Copyright © 2018 Soumil. All rights reserved.
//

#include "header.h"
using namespace std;


int main()
{
    cout<<"Enter the name of file\n";
    string s = "words.txt";
   cin>>s;
    
    fstream f;
    f.open(s.c_str(), ios::in);
    
    
    AVLTree<string> tree;
    int cnt = 0;
    string word, meaning;
    while(!f.eof())
    {
        f>>word;
        for(int i=0;i<word.size();i++)
            word[i] = tolower(word[i]);

        // if(word[0] == 'a')
        // {    
        //     cnt++;
        //     cout<<word<<endl;
        //     int n;
        //     cin>>n;
        // }
        // cout<<cnt<<endl;


        getline(f, meaning);
//        cout<<word<<meaning<<endl;
        tree.insert(word, meaning);
    }

    cout<<"No of words read: "<<tree.returnSize()<<endl;
    int inp;
    cin.clear();
    while(1)
    {
        cout<<"1. Add entry\n2. Remove Key\n3. Number of Words\n4. Find Word\n5. Print Tree\n6. Count All in Range\n7. Exit\n";
        // scanf("%d", &inp);
        cin>>inp;
        
        if(inp == 1)
        {
            cout<<"Enter word: ";
            cin>>word;
            for(int i=0;i<word.size();i++)
                word[i] = tolower(word[i]);
            cout<<"Enter Meaning: ";
            // cin>>meaning;
            cin.ignore();
            getline(cin, meaning);
            tree.insert(word, meaning);
        }
        
        else if(inp == 2)
        {
            cout<<"Enter a word to remove\n";
            cin>>word;
            cin.ignore();
            for(int i=0;i<word.size();i++)
                word[i] = tolower(word[i]);
            tree.deleteKey(word);
        }
        
        else if(inp == 3)
        {
            cout<<"No of words are: "<<tree.returnSize()<<endl;
        }
        
        else if(inp == 4)
        {
            cout<<"Enter word: ";
            cin>>word;
            for(int i=0;i<word.size();i++)
                word[i] = tolower(word[i]);
            tree.searchTree(word);
        }
        
        else if(inp == 5)
        {
            tree.printTree();
            cout<<endl;
        }
        
        else if(inp == 6)
        {
            cout<<"Enter 2 strings: ";
            cin>>word>>meaning;
            cout<<tree.countAllinRange(word, meaning)<<endl;
        }
        
        else
        {
            break;
        }
        
    }
}
