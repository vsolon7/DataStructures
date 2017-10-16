#include "LinkedList.h"
#include <iostream>
#include <Windows.h>

int main()
{
	LinkedList list(new LLNode(1.01f));
	list.pushBack(1.1f);
	list.pushBack(1.2f);
	list.pushBack(1.3f);
	list.pushBack(1.4f);
	list.pushBack(1.5f);
	list.pushBack(1.6f);
	list.pushBack(1.7f);
	list.pushBack(1.8f);

	list.printNodes();

	std::cout << "size: " << list.size() << std::endl;

	int size = list.size();

	for (int i = 0; i != size; i++)
	{
		list.popBack();
	}

	list.printNodes();

	std::cout << "size: " << list.size() << std::endl;

	system("pause");

	return 0;
}