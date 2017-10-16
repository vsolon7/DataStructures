#pragma once
#include "LLNode.h"


class LinkedList
{
public:
	LinkedList(LLNode *begin);
	~LinkedList();

	//returns the start of the linked list; the beginning node
	LLNode * getBeg();

	//returns the size of the linked list
	int size();

	//destroy all the nodes, freeing the memory
	void destroyNodes();

	//insert a node at position p (default is beginning)
	void insertNode(float data, int p = 0);

	//adds a node to the back
	void pushBack(float data);

	//print all the nodes out starting from position p (default is 0)
	void printNodes(int p = 0);

	//deletes a node at a position p
	void deleteNode(int p);

	//deletes the last node in the linked list
	void popBack();

private:
	LLNode *_beginNode;
	int _size;
};

