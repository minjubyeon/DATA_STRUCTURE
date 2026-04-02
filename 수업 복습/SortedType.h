#define MAX_SIZE 30

typedef int ItemType;
class SortedType {
 private:
  ItemType data[MAX_SIZE];
  int length;

 public:
  SortedType();
  void insertItem(ItemType value);
  void removeItem(ItemType value);
  void updateItem(ItemType old_value, ItemType new_value);
  void clear();

  int size();
  bool isFull();
  bool isEmpty();
  bool findItem(ItemType item);
  ItemType getItem(int pos);
};

