//
//  SortedType.h
//  Lab02
//
//  Modified by Jeman Park on 2026/03/31.
//


#ifndef SORTEDTYPE_H
#define SORTEDTYPE_H

#define MAX_ITEMS 50

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
    void        clear( );
    
    int         size( );
    bool        isFull( );
    bool        isEmpty( );
    ItemType    getItem(int pos);
    bool        findItem(ItemType & item);
    int         BinarySearch(ItemType item);
    int         BinarySearchNearestSmaller(ItemType item);

    void PrintList();
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
void SortedType<ItemType>::insertItem(ItemType value){
    if (isFull( )){
        cout << "[ERROR] List is FULL" << endl;
        return;
    }
    int location = 0;
    while (location < length){
        if(value > data[location]){
            location ++;
        }
        else{
            break;
        }
    }
    
    for ( int i = length; i > location; i-- ){
        data[ i ] = data[i-1];
    }
    data[location] = value;
    length ++;
}

template <class ItemType>
void SortedType<ItemType>::removeItem(ItemType value){
    if (isEmpty( )){
        cout << "[ERROR] List is EMPTY" << endl;
        return;
    }
    int location = 0;
    while (location < length){
        if(value > data[location]){
            location ++;
        }
        else{
            break;
        }
    }
    for ( int i = location + 1; i < length; i++ ){
        data[i-1] = data[i];
    }
    length --;
}

template <class ItemType>
void SortedType<ItemType>::clear( ){
    length = 0;
}

template <class ItemType>
ItemType SortedType<ItemType>::getItem(int pos){
    if (pos >= length){
        cout << "[ERROR] Invalid Position (pos >= length)" << endl;
        return -1;
    }
    
    return data[pos];
}

template <class ItemType>
bool SortedType<ItemType>::findItem(ItemType & item){
    int location = 0;
    
    while(location < length){
        if(data[location] == item){
            item = data[location];
            return true;
        }
        location ++;
    }
    return false;
}

template <class ItemType>
int SortedType<ItemType>::BinarySearch(ItemType item){
   
    int ret = -1;
    
    int mid;
    int first = 0;
    int last = length - 1;
    while(first <= last){
        mid = (first + last) / 2;
        if( item < data[mid]){
            last = mid - 1;
        }
        else if(item > data[mid]){
            first = mid + 1;
        }
        else{
            item = data[mid];
            return mid;
        }
    }
    
    return ret;
}

template <class ItemType>
int SortedType<ItemType>::BinarySearchNearestSmaller(ItemType item){
    int nearest = -1;
    if(item < data[0]){
        return -1;
    }
    
    int mid;
    int first = 0;
    int last = length - 1;
    while(first <= last){
        mid = (first + last) / 2;
        if (item == data[mid]){
            item = data[mid];
            return mid;
        }
        
        if (nearest == -1 || ((abs(data[nearest] - item) > abs(data[mid] - item)) && data[mid] < item)){
            nearest = mid;
        }
        
        if( item < data[mid]){
            last = mid - 1;
        }
        else if(item > data[mid]){
            first = mid + 1;
        }
    }
    
    return nearest;

}

template <class ItemType>
void SortedType<ItemType>::PrintList()
{
    if(length == 0){
        cout << "[EMPTY LIST]" << endl;;
        return;
    }
    cout << "[";
    for(int i=0; i < length; i++){
        cout << getItem(i) << " ";
    }
    cout << "]" << endl;
}


#endif
