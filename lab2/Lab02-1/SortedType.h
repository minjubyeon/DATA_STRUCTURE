//
//  SortedType.h
//  Lab02
//
//  Modified by Jeman Park on 2026/03/31.
//

#ifndef SORTEDTYPE_H
#define SORTEDTYPE_H

#define MAX_ITEMS 30

using namespace std;

template <class ItemType>
class SortedType
{
private:
	ItemType data[MAX_ITEMS];
	int length;

public:
	SortedType();
	void        insertItem(ItemType value);
	void        removeItem(ItemType value);
	void        clear();
	void        replaceItem(ItemType old_item, ItemType new_item);

	int         size();
	bool        isFull();
	bool        isEmpty();
	ItemType    getItem(int pos);
	bool        findItem(ItemType& item);
	int         binarySearch(ItemType item);

	void printList();
};


template <class ItemType>
SortedType<ItemType>::SortedType()
{
	length = 0;
}

template <class ItemType>
int SortedType<ItemType>::size()
{
	return length;
}

template <class ItemType>
bool SortedType<ItemType>::isFull()
{
	return (length == MAX_ITEMS);
}

template <class ItemType>
bool SortedType<ItemType>::isEmpty()
{
	return (length == 0);
}


template <class ItemType>
void SortedType<ItemType>::insertItem(ItemType value) {
	if (isFull()) {
		cout << "[ERROR] List is FULL" << endl;
		return;
	}
	int location = 0;
	while (location < length) {
		if (value > data[location]) {
			location++;
		}
		else {
			break;
		}
	}

	for (int i = length; i > location; i--) {
		data[i] = data[i - 1];
	}
	data[location] = value;
	length++;
}

template <class ItemType>
void SortedType<ItemType>::removeItem(ItemType value) {
	if (isEmpty()) {
		cout << "[ERROR] List is EMPTY" << endl;
		return;
	}
	int location = 0;
	while (location < length) {
		if (value > data[location]) {
			location++;
		}
		else {
			break;
		}
	}
	for (int i = location + 1; i < length; i++) {
		data[i - 1] = data[i];
	}
	length--;
}

template <class ItemType>
void SortedType<ItemType>::clear() {
	length = 0;
}

template <class ItemType>
ItemType SortedType<ItemType>::getItem(int pos) {
	if (pos >= length) {
		cout << "[ERROR] Invalid Position (pos >= length)" << endl;
		return -1;
	}

	return data[pos];
}

template <class ItemType>
bool SortedType<ItemType>::findItem(ItemType& item) {
	int location = 0;

	while (location < length) {
		if (data[location] == item) {
			item = data[location];
			return true;
		}
		location++;
	}
	return false;
}

template <class ItemType>
int SortedType<ItemType>::binarySearch(ItemType item) {

	int ret = -1;
	/* Implement the function here (Lab 02-1 (1)) */
	// This function performs "binary search" on the sorted list
	// It returns the "index" if "value" exists
	// Otherwise, it returns -1
	// For example, suppose that test_sorted_list = [ 1, 3, 4, 10, 12, 14]
	// binarySearch(4) will return (2)  -- (the index of "4" is [2])
	// binarySearch(5) will return (-1) -- ("5" does not exist)

	int low = 0;
	int high = length;
	int mid = (low + high) / 2;

	while (mid < length) {
		if (data[mid] < item) {
			low = mid;
			mid = (mid + high) / 2;
			if (mid == low) return ret;
		}

		else if (data[mid] == item) {
			return mid;
		}

		else if (data[mid] > item) {
			high = mid;
			mid = (mid + low) / 2;
			if (mid == high) return ret;
		}
	}
}



template <class ItemType>
void SortedType<ItemType>::replaceItem(ItemType old_item, ItemType new_item) {
	/* Implement the function here (Lab 02-1 (2)) */
	// This function replaces "old_item" in the list with "new_item"
	// If "old_item" does not exist in the list, it does NOTHING
	// After "replaceItem()" the list must remain sorted

	if (findItem(old_item)) {
		removeItem(old_item);
		insertItem(new_item);
	}
	else return;

	/*
	int i = 0;
	for (i; i < length; i++) {
		if (data[i] == old_item) {
			data[i] = new_item;
			break;
		}
	}

	if (data[i] == new_item() {
		if (i == 0 or i == (length - 1)) {
			return void;
		}

		else if (data[i - 1] < data[i] && data[i] < data[i + 1]) {
			return void;
		}

		else if (data[i - 1] > data[i]) {
			
			}
	}
	*/



}


template <class ItemType>
void SortedType<ItemType>::printList()
{
	if (length == 0) {
		cout << "[EMPTY LIST]" << endl;;
		return;
	}
	cout << "[";
	for (int i = 0; i < length; i++) {
		cout << data[i] << " ";
	}
	cout << "]" << endl;
}


#endif
