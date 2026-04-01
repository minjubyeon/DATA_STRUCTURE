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
};