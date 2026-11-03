#include<iostream>
#include "LinkedList.h"

using namespace std;

int main() {
	LinkedList list1;

	for (int i = 1; i <= 5; i++) {
		list1.ListC(i, i * 7);
	}

	list1.print();

	list1.ListS(2);
	list1.print();

	LinkedList list2 = list1;
	LinkedList list3;
	list3 = list1;

	list2.ListS(1);
	list2.print();

	return 0;
}