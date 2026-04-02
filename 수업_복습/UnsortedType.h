#define MAX_SIZE 30

typedef int ItemType;
class UnsortedType
{
private:
    ItemType data[MAX_SIZE];
    int length;

public:
    UnsortedType();
    void appendItem(ItemType value);
    void insertItem(int pos, ItemType value);
    void removeItem(ItemType value);
    void updateItem(int pos, ItemType new_value);
    void clear();

    int size();
    bool isFull();
    bool isEmpty();
    bool findItem(ItemType item);
    ItemType getItem(int pos);
};
