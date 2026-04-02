//
//  test.cpp
//
//  Test file for SortedType::insertItem
//  Verifies that insertItem maintains sorted (ascending) order at all times.
//

#include <iostream>
#include "SortedType.h"

using namespace std;

// Helper: SortedType에 PrintList가 없으므로 직접 출력
void PrintList(SortedType& list) {
    if (list.isEmpty()) {
        cout << "[ EMPTY LIST ]" << endl;
        return;
    }
    cout << "[ ";
    for (int i = 0; i < list.size(); i++) {
        cout << list.getItem(i) << " ";
    }
    cout << "]" << endl;
}

int main() {

    SortedType sList;

    // --------------------------------------------------
    // Case 1: 빈 리스트에 첫 번째 원소 삽입
    // --------------------------------------------------
    cout << "=== Case 1: Insert into empty list ===" << endl;
    sList.insertItem(10);
    PrintList(sList);
    // Expected: [ 10 ]

    // --------------------------------------------------
    // Case 2: 현재 최솟값보다 작은 값 삽입 (맨 앞에 들어가야 함)
    // --------------------------------------------------
    cout << "=== Case 2: Insert smaller value (goes to front) ===" << endl;
    sList.insertItem(5);
    PrintList(sList);
    // Expected: [ 5 10 ]

    // --------------------------------------------------
    // Case 3: 현재 최댓값보다 큰 값 삽입 (맨 뒤에 들어가야 함)
    // --------------------------------------------------
    cout << "=== Case 3: Insert larger value (goes to back) ===" << endl;
    sList.insertItem(20);
    PrintList(sList);
    // Expected: [ 5 10 20 ]

    // --------------------------------------------------
    // Case 4: 중간 위치에 삽입
    // --------------------------------------------------
    cout << "=== Case 4: Insert in the middle ===" << endl;
    sList.insertItem(15);
    PrintList(sList);
    // Expected: [ 5 10 15 20 ]

    sList.insertItem(7);
    PrintList(sList);
    // Expected: [ 5 7 10 15 20 ]

/*
    // --------------------------------------------------
    // Case 5: 중복 값 삽입 (동일한 값이 이미 있을 때)
    // --------------------------------------------------
    cout << "=== Case 5: Insert duplicate value ===" << endl;
    sList.insertItem(10);
    PrintList(sList);
    // Expected: [ 5 7 10 10 15 20 ]  (중복 허용 시)
    //        OR [ 5 7 10 15 20 ]     (중복 불허 시)
*/
    // --------------------------------------------------
    // Case 6: 여러 값을 순서 없이 삽입해도 항상 정렬 유지되는지
    // --------------------------------------------------
    cout << "=== Case 6: Insert multiple values out of order ===" << endl;
    sList.clear();
    PrintList(sList);
    // Expected: [ EMPTY LIST ]

    sList.insertItem(30);
    sList.insertItem(1);
    sList.insertItem(50);
    sList.insertItem(25);
    sList.insertItem(3);
    PrintList(sList);
    // Expected: [ 1 3 25 30 50 ]


/*
    // --------------------------------------------------
    // Case 7: 음수 값 삽입
    // --------------------------------------------------
    cout << "=== Case 7: Insert negative values ===" << endl;
    sList.clear();
    sList.insertItem(-5);
    sList.insertItem(10);
    sList.insertItem(-20);
    sList.insertItem(0);
    PrintList(sList);
    // Expected: [ -20 -5 0 10 ]
*/


    // --------------------------------------------------
    // Case 8: MAX_SIZE(30)까지 채운 뒤 추가 삽입 시도 (isFull 처리 확인)
    // --------------------------------------------------
    cout << "=== Case 8: Insert until full ===" << endl;
    sList.clear();
    for (int i = 1; i <= 30; i++) {
        sList.insertItem(i);
    }
    cout << "size: " << sList.size() << endl;
    // Expected: size: 30
    PrintList(sList);
    // Expected: [ 1 2 3 ... 30 ]

    cout << "Inserting into full list:" << endl;
    sList.insertItem(99);   // 꽉 찼을 때 에러 처리 확인
    // Expected: [ERROR] or similar message, list unchanged

    return 0;
}