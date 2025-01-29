/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"

void print(Node*& in);

int main(int argc, char* argv[])
{
    //void split(Node*& in, Node*& odds, Node*& evens);
    //  Node(int v, Node* n)

    //in node is NULL
    Node*& nothing = NULL;
    Node*& odds = NULL;
    Node*& evens = NULL;
    split(nothing, odds, evens)
    
    //both odds and evens in NULL
}

void print(Node*& in){
    while(in!=NULL){
        cout << in->val;
        in = in->next;
    }
}