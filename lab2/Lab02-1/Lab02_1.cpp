//
//  Lab02_1.cpp
//  Lab02
//
//  Modified by Jeman Park on 2026/03/31.
//


#include <iostream>
#include "SortedType.h"
using namespace std;


int main() {

	SortedType<int> sList;

	/* Feel free to edit codes below (test with more cases) */

	sList.insertItem(27);
	sList.insertItem(15);
	sList.insertItem(5);
	sList.insertItem(12);
	sList.insertItem(20);
	sList.insertItem(21);
	sList.insertItem(4);
	sList.insertItem(2);
	sList.insertItem(7);


	sList.printList();
	// [2 4 5 7 12 15 20 21 27 ]

	sList.removeItem(4);
	sList.removeItem(15);
	sList.printList();
	// [2 5 7 12 20 21 27 ]



	cout << "[BinarySearch]: the result of input '5' is " << sList.binarySearch(5) << endl;
	cout << "[BinarySearch]: the result of input '20' is " << sList.binarySearch(20) << endl;
	cout << "[BinarySearch]: the result of input '4' is " << sList.binarySearch(4) << endl;
	cout << "[BinarySearch]: the result of input '15' is " << sList.binarySearch(15) << endl;

	//    [BinarySearch]: the result of input '5' is 1
	//    [BinarySearch]: the result of input '20' is 4
	//    [BinarySearch]: the result of input '4' is -1
	//    [BinarySearch]: the result of input '15' is -1

	sList.replaceItem(12, 42);
	sList.printList();
	// [2 5 7 20 21 27 42 ]

	sList.replaceItem(10, 30);
	sList.printList();
	// [2 5 7 20 21 27 42 ]

	return 0;
}
