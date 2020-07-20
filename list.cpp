#include "structs.h"
#include <iostream>
using namespace std;
class List{
  private:
    node *head, *tail;
    int size;

  public:
    List(){ // constructor
      head=NULL;
      tail=NULL;
      size=0;
    }

    int& operator[](int i) { return getNumPointer(i); }

    void append(int x){
      node* temp = new node;
      temp->num = x;
      temp->next = NULL;

      if(head==NULL){
        head=temp;
        tail=temp;
      }else{
        tail->next = temp;
        tail = temp;
      }
      temp = NULL;
      size++;
    }

    int& getNumPointer(int i) {
        if (i < size - 1) {
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
      if (x >= size) {
          append(y);
          delete temp;
          return;
      }
      if(x==0){
        temp->next = prev;
        head=temp;
      }else{
        for (int c = 0;c < x - 1;c++) {
              prev = prev->next;
        }
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
      node* prev = head;
      node* temp = head;
      for(int i=0;i<y-1;i++){
        prev = prev->next;
      }
      if(y==0){
        temp = prev;
        head = head->next;
      }
      if(y==size-1){
        temp = tail;
        tail=prev;
      }
      if(y<size-1 && y!=0){
        temp = prev->next;
        prev->next = temp->next;
      }
      if(y>size){
        return -1;
      }
      size--;
      return temp->num;
    }

    int remove(int y){
      node* prev = head;
      node* curr = head;
      while(curr!=tail){
        if(curr->num==y){
          break;
        }
        prev=curr;
        curr=curr->next;
      }
      if(curr==NULL){
        return -1;
      }
      if(curr==tail){
        tail=prev;
        return curr->num;
      }
      if(curr==head){
        head = head->next;
        return curr->num;
      }
      prev->next = curr->next;
      return curr->num;
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