#include "structs.h"
#include <iostream>
using namespace std;
class Stack{

private:
  node *head, *tail;
  int size;

public:

  Stack(){ // constructor
    head=NULL;
    tail=NULL;
    size=0;
  }

  int Peek(){
    if(head!=NULL){
      return head->num;
    }
    return 0;
  }

  void Push(int x){
    //create a temp node
    node *temp = new node;
    temp->num = x;
    temp->next = NULL;

    //first node in the stack
    if(head==NULL){
      head=temp;
      tail=temp;
      temp=NULL;
    }else{
      //nodes already exist in the stack
      temp->next=head;
      head=temp;
      temp=NULL;
    }

    //increment size counter of stack
    size++;
  }

  int Pop(){
    //get head node
    node *temp = new node;
    temp = head;

    //set new head node as next node of the previous head node
    head = head->next;

    //decrement size
    size--;

    return temp->num;
  }

  int getSize(){
    return size;
  }

  void print(){
    node* temp = head;
    while(temp!=NULL){
      cout << temp->num << "\n";
      temp = temp->next;
    }
  }

};
