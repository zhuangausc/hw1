#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}

//Code starts HERE
std::string* ULListStr::getValAtLoc(size_t loc) const{
  Item *temp = head_;
  while(temp != NULL){
    for(size_t i=temp->first; i<temp->last; i++){
      if(loc==0){
        return (temp->val)+i;
      }
      loc--;
    }
    temp = temp->next;
  }
  // Invalid "loc"
  return NULL;
}

void ULListStr::push_back(const std::string& val){
  //If list is empty
  if(tail_==NULL){
    head_ = new Item();
    tail_ = head_;
    tail_->val[0] = val;
    tail_->last = 1;
    tail_->prev = NULL;
    tail_->next = NULL;
  } else {
    //If list is not empty
    //If the last Item's array is full
    if(tail_->last==10){
      tail_->next = new Item(); 
      (tail_->next)->prev = tail_;
      tail_ = tail_->next;
      tail_->next = NULL;
      tail_->val[0] = val;
      tail_->last = 1;
    } else {
      //If the last Item's array is not full
      tail_->val[tail_->last] = val;
      (tail_->last)++;
    }
  }

  //Increase size_ by 1
  size_++;
}

void ULListStr::pop_back(){
  //If this is the only value in the List
  if(size_==1){
    Item* temp = tail_;
    tail_ = NULL;
    head_ = NULL;
    delete temp;
  } else {
    //If this is not the only value in the List
    //If the Item will be empty after popping
    if(tail_->last==1){
      Item* temp = tail_;
      tail_ = tail_->prev;
      if(tail_==NULL){
        //Do nothing
      } else{
        tail_->next = NULL;
        delete temp;
      }
    } else {
      //If the Item will not be empty after popping
      (tail_->last)--;
    }
  }

  //Decrease size by 1
  size_--;
}

void ULListStr::push_front(const std::string& val){
  //If list is empty
  if(tail_==NULL){
    head_ = new Item();
    tail_ = head_;
    tail_->val[9] = val;
    tail_->first = 9;
    tail_->last = 10;
    tail_->prev = NULL;
    tail_->next = NULL;
  } else {
    //If list is not empty
    //If the first Item's array is full
    if(head_->first==0){
      head_->prev = new Item(); 
      (head_->prev)->next = head_;
      head_ = head_->prev;
      head_->prev = NULL;
      head_->val[0] = val;
      head_->last = 1;
    } else {
      //If the first Item's array is not full
      head_->val[(head_->first)-1] = val;
      (head_->first)--;
    }
  }

  //Increase size_ by 1
  size_++;
}

void ULListStr::pop_front(){
  //If this is the only value in the List
  if(size_==1){
    Item* temp = tail_;
    tail_ = NULL;
    head_ = NULL;
    delete temp;
  } else {
    //If this is not the only value in the List
    //If the Item will be empty after popping
    if(head_->first==9){
      Item* temp = head_;
      head_ = head_->next;
      if(head_==NULL){
        //Do nothing
      } else {
        head_->prev = NULL;
        delete temp;
      }
    } else {
      //If the Item will not be empty after popping
      (head_->first)++;
    }
  }

  //Decrease size by 1
  size_--;
}

std::string const & ULListStr::back() const{
  return tail_->val[(tail_->last)-1];
}

std::string const & ULListStr::front() const{
  return head_->val[head_->first];
}