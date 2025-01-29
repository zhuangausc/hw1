/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"

/* Add a prototype for a helper function here if you need */

void split(Node*& in, Node*& odds, Node*& evens)
{
  /* Add code here */
// WRITE YOUR CODE HERE

  //Base Cases
  if(in==NULL){
    return;
  }

  //Recursive Case
  int val = in->value;
  
  //If val is even
  if(val%2==0){
    //If the evens list is empty
    if(evens==NULL){
      evens = in;
      split(in->next, odds, evens)
    //If the evens list is not empty
    } else {
      evens->next = in;
      split(in->next, odds, evens->next)
    }
    evens = in;
  //If val is odd
  } else {
    if(odds==NULL){
    //If the odds list is empty
      odds = in;
      split(in->next, odds, evens)
    }
    //If the odds list is not empty
    } else {
      odds->next = in;
      split(in->next, odds->next, evens)
  }
}

/* If you needed a helper function, write it here */
