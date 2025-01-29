/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include <cstddef>
#include <iostream>

using namespace std;

void deleteList(Node*& in);
void print(Node* in);

int main(int argc, char* argv[])
{
    //void split(Node*& in, Node*& odds, Node*& evens);
    //  Node(int v, Node* n)

    //in node is NULL
    Node* nothing = NULL;
    Node* odds = NULL;
    Node* evens = NULL;
    split(nothing, odds, evens);

    print(nothing);
    print(odds);
    print(evens);
    
    //both odds and evens in NULL
    nothing = new Node(0, NULL);
    Node* thisNode = nothing;
    for(int i=1; i<10; i++){
      thisNode->next = new Node(i, NULL);
      thisNode = thisNode->next;
    }

    split(nothing, odds, evens);

    print(nothing);
    print(odds);
    print(evens);

    deleteList(odds);
    deleteList(evens);

    print(nothing);
    print(odds);
    print(evens);
}

void print(Node* in){
    while(in!=NULL){
        cout << in->value << " ";
        in = in->next;
    }
    cout << "Done." << endl;
}

void deleteList(Node*& in){
  while(in!=NULL){
    Node* temp = in;
    in = in->next;
    delete temp;
  }
}