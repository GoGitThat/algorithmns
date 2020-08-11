#include "structs.h"
#include <iostream>
using namespace std;
class List{
  private:
    node* head;
    int size;

  public:
    List(){ // constructor
      head=NULL;
      size=0;
    }

    int& operator[](int i) { return getNumPointer(i); }

    void append(int x){
      node* temp = new node;
      temp->num = x;
      temp->next = NULL;

      if(head==NULL){
        head=temp;
      }else{
          node* tempTwo = getNode(size - 1);
          tempTwo->next = temp;
      }
      temp = NULL;
      size++;
    }

    int& getNumPointer(int i) {
        if (i < size) {
            return getNode(i)->num;
        }
    }

    void clear(){
      while(head!=NULL){
        node* temp = head;
        head = head->next;
        delete temp;
        size--;
      }
    }

    void print(){
      node* temp = head;
      while(temp!=NULL){
        cout << temp->num << "->";
        temp = temp->next;
      }
      cout << "\n";
    }

    int getSize(){
      return size;
    }

    void insert(int x, int y){
      node* prev=head;
      node* temp=new node;
      temp->num = y;
      temp->next = NULL;
      if (x >= size-1) {
          append(y);
          delete temp;
          return;
      }
      if(x==0){
        temp->next = head;
        head=temp;
      }else{
          prev = getNode(x - 1);
          temp->next = prev->next;
          prev->next = temp;
      }
      size++;
    }

    int index(int x){
      node* temp = head;
      for(int ind=0;ind<size;ind++){
        if(temp->num == x){
          return ind;
        }
        temp = temp->next;
      }
      return -1;
    }

    int pop(int y){
        int retme = -1;
        node* prev = head;
        node* temp = head;
        if (y==0) {
            retme = head->num;
            head = head->next;
            size--;
            return retme;
        }
        if (y==size-1) {
            prev = getNode(y - 1);
            retme = prev->next->num;
            prev->next = NULL;
        }
        else {
            prev = getNode(y - 1);
            temp = getNode(y);
            prev->next = temp->next;
            retme = temp->num;
        }
        size--;
        return retme;
    }

    int remove(int y){
        int count = 0;
      node* curr = head;
      while(count<size){
        if(curr->num==y){
          break;
        }
        curr = curr->next;
        count++;
      }
      return pop(count);
    }

    node* getNode(int x) {
        node* temp = head;
        for (int j = 0;j < x;j++) {
            temp = temp->next;
        }
        return temp;
    }

    void swap(int x, int y) {
        node* nodeX = getNode(x);
        node* nodeY = getNode(y);
        int z = nodeX->num;
        nodeX->num = nodeY->num;
        nodeY->num = z;
    }
};