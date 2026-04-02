//
//  test_insertItem.cpp
//
//  Test file for SortedType::insertItem
//

#include <iostream>
#include "SortedType.h"

using namespace std;

int main() {

    // -----------------------------------------------
    // Test 1: 빈 리스트에 삽입
    // -----------------------------------------------
    SortedType s1;
    s1.insertItem(5);

    cout << "[Test 1] 빈 리스트에 삽입" << endl;
    cout << "  getItem(0): " << s1.getItem(0) << endl;
    // Correct Output:
    // [Test 1] 빈 리스트에 삽입
    //   getItem(0): 5

    // -----------------------------------------------
    // Test 2: 정렬 순서 유지 (무작위 삽입 후 오름차순 확인)
    // -----------------------------------------------
    SortedType s2;
    s2.insertItem(30);
    s2.insertItem(10);
    s2.insertItem(50);
    s2.insertItem(20);
    s2.insertItem(40);

    cout << "[Test 2] 정렬 순서 유지 (기대값: 10 20 30 40 50)" << endl;
    cout << "  Result: ";
    for (int i = 0; i < s2.size(); i++)
        cout << s2.getItem(i) << " ";
    cout << endl;
    // Correct Output:
    // [Test 2] 정렬 순서 유지 (기대값: 10 20 30 40 50)
    //   Result: 10 20 30 40 50

    // -----------------------------------------------
    // Test 3: 최솟값 삽입 (맨 앞에 위치해야 함)
    // -----------------------------------------------
    SortedType s3;
    s3.insertItem(10);
    s3.insertItem(20);
    s3.insertItem(30);
    s3.insertItem(1);

    cout << "[Test 3] 최솟값 삽입 - getItem(0) (기대값: 1)" << endl;
    cout << "  getItem(0): " << s3.getItem(0) << endl;
    // Correct Output:
    // [Test 3] 최솟값 삽입 - getItem(0) (기대값: 1)
    //   getItem(0): 1

    // -----------------------------------------------
    // Test 4: 최댓값 삽입 (맨 뒤에 위치해야 함)
    // -----------------------------------------------
    SortedType s4;
    s4.insertItem(10);
    s4.insertItem(20);
    s4.insertItem(30);
    s4.insertItem(99);

    cout << "[Test 4] 최댓값 삽입 - getItem(last) (기대값: 99)" << endl;
    cout << "  getItem(" << s4.size() - 1 << "): " << s4.getItem(s4.size() - 1) << endl;
    // Correct Output:
    // [Test 4] 최댓값 삽입 - getItem(last) (기대값: 99)
    //   getItem(3): 99

    // -----------------------------------------------
    // Test 5: 중복 값 삽입
    // -----------------------------------------------
    SortedType s5;
    s5.insertItem(10);
    s5.insertItem(20);
    s5.insertItem(20);
    s5.insertItem(30);

    cout << "[Test 5] 중복 값 삽입 (기대값: 10 20 20 30)" << endl;
    cout << "  Result: ";
    for (int i = 0; i < s5.size(); i++)
        cout << s5.getItem(i) << " ";
    cout << endl;
    // Correct Output:
    // [Test 5] 중복 값 삽입 (기대값: 10 20 20 30)
    //   Result: 10 20 20 30

    // -----------------------------------------------
    // Test 6: findItem 연동 - 삽입 후 findItem 확인
    // -----------------------------------------------
    SortedType s6;
    s6.insertItem(7);
    s6.insertItem(3);
    s6.insertItem(15);

    cout << "[Test 6] findItem 연동" << endl;
    cout << "  findItem(7):  " << (s6.findItem(7)  ? "true" : "false") << endl;
    cout << "  findItem(3):  " << (s6.findItem(3)  ? "true" : "false") << endl;
    cout << "  findItem(15): " << (s6.findItem(15) ? "true" : "false") << endl;
    cout << "  findItem(99): " << (s6.findItem(99) ? "true" : "false") << endl;
    // Correct Output:
    // [Test 6] findItem 연동
    //   findItem(7):  true
    //   findItem(3):  true
    //   findItem(15): true
    //   findItem(99): false

    return 0;
}
