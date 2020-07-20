#include "stack.cpp"
#include <assert.h>
#include "sorting.cpp"

//Stack tests

void testEmpty(){
  Stack myStack =  Stack();
  assert(myStack.getSize() == 0);
  assert(myStack.Peek() == NULL);
}

void testPushNode(){
  Stack myStack =  Stack();
  myStack.Push(5);
  assert(myStack.getSize() == 1);
  assert(myStack.Peek() == 5);
}

void testPopNode(){
  Stack myStack =  Stack();
  myStack.Push(5);
  assert(myStack.Pop() == 5);
  assert(myStack.getSize() == 0);
}

void testMultipleNodes(){
  Stack myStack =  Stack();
  myStack.Push(5);
  myStack.Push(4);
  myStack.Push(3);
  myStack.Push(2);
  myStack.Push(1);
  assert(myStack.getSize() == 5);
  assert(myStack.Peek() == 1);
  assert(myStack.Pop() == 1);
  assert(myStack.getSize() == 4);
}



//List tests

void testConstructor(){
  List mylist = List();
  assert(mylist.getSize() == 0);
}

void testAppend(){
  List mylist = List();
  mylist.append(2);
  assert(mylist.getSize() == 1);
  //mylist.print();
}

void testPopSmall(){
  List mylist = List();
  mylist.append(2);
  assert(mylist.pop(0) == 2);
  //mylist.print();
}

void testPopLarge(){
  List mylist = List();
  for(int j=0;j<20;j++){
    mylist.append(j);
  }
  assert(mylist.pop(0) == 0);
  assert(mylist.pop(10) == 11);
  assert(mylist.pop(14) == 16);
  assert(mylist.pop(16) == 19);
  //mylist.print();
}

void testRemoveSmall(){
  List mylist = List();
  mylist.append(2);
  assert(mylist.remove(2) == 2);
  //mylist.print();
}

void testRemoveLarge(){
  List mylist = List();
  for(int j=0;j<20;j++){
    mylist.append(j);
  }
  assert(mylist.remove(0) == 0);
  assert(mylist.remove(10) == 10);
  assert(mylist.remove(14) == 14);
  //mylist.print();
}

void testInsertSmall(){
  List mylist = List();
  mylist.insert(2,69);
  assert(mylist.getSize() == 1);
  assert(mylist.pop(0) == 69);
  //mylist.print();
}

void testInsertLarge(){
  List mylist = List();
  for(int j=0;j<20;j++){
    mylist.insert(j,j);
  }
  mylist.insert(14, 69);
  mylist.insert(15, 420);
  assert(mylist.pop(14) == 69);
  assert(mylist.pop(14) == 420);
  //mylist.print();
}

void testClear() {
    List mylist = List();
    for (int j = 0;j < 100;j++) {
        mylist.insert(j, j);
    }
    assert(mylist.getSize() == 100);
    //mylist.print();
    mylist.clear();
    assert(mylist.getSize() == 0);
}

void testGetNode() {
    List mylist = List();
    for (int j = 0;j < 100;j++) {
        mylist.insert(j, j);
    }
    assert(mylist.getNode(69)->num == 69);
}

void testSwapNode() {
    List mylist = List();
    for (int j = 0;j < 100;j++) {
        mylist.insert(j, j);
    }
    mylist.swap(69, 42);
    assert(mylist.getNode(42)->num == 69);
    assert(mylist.getNode(69)->num == 42);
}

void testBracketOverload() {
    List mylist = List();
    for (int j = 0;j < 100;j++) {
        mylist.insert(j, j);
    }
    mylist[69] = 69420;
    assert(mylist[69] == 69420);
}

void testSortingFalse() {
    List mylist = List();
    for (int j = 0;j < 100;j++) {
        mylist.insert(j, j);
    }
    mylist[69] = 69420;
    assert(!testSort(mylist));
}


void testSortingTrue() {
    List mylist = List();
    for (int j = 0;j < 100;j++) {
        mylist.insert(j, j);
    }
    assert(testSort(mylist));
}

int main(){

  //stack tests
  testEmpty();
  testPushNode();
  testPopNode();
  testMultipleNodes();


  //list tests
  testConstructor();
  testAppend();
  testPopSmall();
  testPopLarge();
  testRemoveSmall();
  testRemoveLarge();
  testInsertSmall();
  testInsertLarge();
  testClear();
  testGetNode();
  testSwapNode();
  testBracketOverload();

  //sorting tests
  testSortingFalse();
  testSortingTrue();

  
  return 0;
}
