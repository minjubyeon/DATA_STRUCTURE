#include <iostream>

#include "SortedType.h"
#include "UnsortedType.h"

UnsortedType::UnsortedType() { length = 0; }

// 1. appendItem
void UnsortedType::appendItem(ItemType value) {
    if (isFull) {
        return;
    }

    data[length] = value;
}

//***********************************************************************************
//2. void insertItem(int pos, ItemType value);

void insertItem(int pos, ItemType value){
if (pos > MAX_SIZE){
    return;
}

}


//***********************************************************************************
//3. void removeItem(ItemType value);



//***********************************************************************************
//4. void updateItem(int pos, ItemType new_value);




//***********************************************************************************
//5. void clear();




//***********************************************************************************
//6.int size();
int UnsortedType::size() { return length; }

bool UnsortedType::isFull() {
    if (length == MAX_SIZE)
        return true;

    else
        return false;
}


//***********************************************************************************
//7. bool isFull();





//***********************************************************************************
//8. bool isEmpty();
bool UnsortedType::isEmpty() {
    if (length == 0)
        return true;

    else
        return false;
}



//***********************************************************************************
//9. bool findItem(ItemType item);
bool UnsortedType::findItem(ItemType item){
for (int i = 0; i < MAX_SIZE; i++) {
    if (data[i] == item)
        return true;
}
return false;
}

//***********************************************************************************
//10. ItemType getItem(int pos);


















