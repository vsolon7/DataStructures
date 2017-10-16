#include "LinkedList.h"
#include <iostream>
#include <Windows.h>

int main()
{
	LinkedList list(new LLNode(1.01f));
	list.pushBack(1.02f);
	list.pushBack(1.03f);
	list.pushBack(1.04f);
	list.pushBack(1.05f);
	list.pushBack(1.06f);
	list.pushBack(1.07f);

	list.printNodes();
	std::cout << "=============" << std::endl;

	list.reverse();

	list.popBack();

	list.printNodes();

	system("pause");

	return 0;
}