// structs.h
#ifndef STRUCTS_H // include guard
#define STRUCTS_H

#define NULL 0
struct node
{
int num;
node *next;
};

struct tnode
{
	int num;
	node* left;
	node* right;
};


#endif //STRUCTS_H
