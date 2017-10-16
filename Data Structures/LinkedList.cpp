#include <iostream>
#include <string>

#include "LinkedList.h"
#include "Error.h"

LinkedList::LinkedList(LLNode *begin)
{
	_beginNode = begin;
	_size = 1;
}

LLNode * LinkedList::getBeg()
{
	if (_size < 1)
	{
		Error err("Error: could not get beginning node, list has no elements");
		std::cerr << err.what() << std::endl;
	}

	//get the node at the beginning
	return _beginNode;
}

int LinkedList::size()
{
	return _size;
}

void LinkedList::destroyNodes()
{
	if (_size > 1)
	{
		//free memory from the heap!
		LLNode *it = _beginNode;
		LLNode *next = _beginNode;

		//loops through and deletes the nodes
		while (it->nextNode != nullptr)
		{
			next = it->nextNode;
			delete it;
			it = next;
		}
		//delete the last one!
		delete it;
	}
	if (_size == 1)
	{
		delete _beginNode;
		_size--;
	}
}

void LinkedList::pushBack(float data)
{
	//basically just insert a node at the _size position
	insertNode(data, _size);
}

void LinkedList::insertNode(float data, int p)
{
	//if its an invalid position, make and error and return
	if (p < 0 || p > _size)
	{
		Error invPos("Error inserting new node, invalid position at: " + std::to_string(p));
		std::cerr << invPos.what() << std::endl;
		return;
	}

	//if they want to insert it to the front, create a new node that points to the (previous) beginning element
	if (p == 0)
	{
		LLNode *n = new LLNode(data, _beginNode);
		_beginNode = n;
	}

	//if they want to insert it anywhere else
	else if (p <= _size)
	{
		//we are going to end at one before the actual value, because i can't go backwards
		//in a link list. Meaning since I can't modify the value BEFORE it (the variable),
		//i have to make it the value i actually want to modify. I could have set this up
		//as a condition in the while loop as well.
		p--;

		int pos = 0;
		LLNode *it = _beginNode;

		//go through the list up to the position they enter
		while (pos != p)
		{
			it = it->nextNode;
			pos++;
		}
		//if the node is at the end
		if(it->nextNode == nullptr)
			it->nextNode = new LLNode(data, nullptr);
		//if the node is not at the end
		else
			it->nextNode = new LLNode(data, it->nextNode);
	}

	//increase the size of the linked list!
	_size++;
}

void LinkedList::printNodes(int p)
{
	//this basically creates an iterator to go through all the nodes
	//and then prints their values out. pretty simple

	//if there are no elements, tell us!
	if (_size == 0)
	{
		Error err("Error printing nodes, list size is zero");
		std::cerr << err.what() << std::endl;
		return;
	}

	LLNode *it = _beginNode;
	int count = 0;
	while (it->nextNode != nullptr)
	{
		if(count >= p)
			std::cout << it->val << std::endl;

		it = it->nextNode;
		count++;
	}
	std::cout << it->val << std::endl;
}

void LinkedList::deleteNode(int p)
{
	//pretty much does the same thing as the insert, just deletes the node.
	//We end at one before the actual value of p because if i delete it->nextNode then that's all good.
	//However, if i delete the iterator itself, im screwed.
	


	//if the size of the node is 1 (just the root node), and we delete it, the list doens't exist anymore
	if (_size == 1)
	{
		destroyNodes();
		return;
	}

	if (p > _size || p == 0)
	{
		Error err("Error deleting node, invalid position at: " + std::to_string(p));
		std::cerr << err.what() << std::endl;
		return;
	}

	p--;

	int pos = 0;
	LLNode *it = _beginNode;

	while (pos != p)
	{
		it = it->nextNode;
		pos++;
	}
	
	//if this is the last node, then the new last node's nextNode needs to be nullptr
	if (it->nextNode == nullptr)
	{
		delete it->nextNode;
		it->nextNode = nullptr;
	}
	else
	{
		//we are about to delete the next node so we need to store the value
		LLNode *it2 = it->nextNode->nextNode;
		delete it->nextNode;
		it->nextNode = it2;
	}

	//our LL is now one element smaller. The size should reflect that!
	_size--;
}

void LinkedList::popBack()
{
	//just call the deleteNode() function with the position set to the end
	deleteNode(_size);
}

LinkedList::~LinkedList()
{
	//made a separate function for destroy nodes, just incase you want to delete
	//them all for whatever reason (without running the destructor)
	destroyNodes();
}
