//
//  UnsortedType.h
//  Lab01
//
//  Modified by Jeman Park on 2026/03/23.
//

#ifndef UNSORTEDTYPE_H
#define UNSORTEDTYPE_H

#define MAX_ITEMS 30

typedef int ItemType;

class UnsortedType 
{
private:
    ItemType data[MAX_ITEMS];
    int length;
    
public:
    UnsortedType( );
    void        appendItem(ItemType value);
    void        insertItem(int pos, ItemType value);
    void        removeItem(ItemType value);
    void        updateItem(int pos, ItemType new_value);
    void        clear( );
    
    void        swapItems(int firstItemIndex, int secondItemIndex);
    int         removeLargestItem();
    
    int         size( );
    bool        isFull( );
    bool        isEmpty( );
    ItemType    getItem(int pos);
    bool        findItem(ItemType item);

    void PrintList();
};


#endif
