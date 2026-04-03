//
//  test.cpp
//
//  Test file for SortedType::insertItem, removeItem, updateItem
//

#include <iostream>
#include "SortedType.h"

using namespace std;

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

    /*
    // ================================================
    // insertItem 테스트
    // ================================================

    cout << "=== insertItem Case 1: 빈 리스트에 삽입 ===" << endl;
    sList.insertItem(10);
    PrintList(sList);
    // Expected: [ 10 ]

    cout << "=== insertItem Case 2: 가장 작은 값 삽입 (맨 앞) ===" << endl;
    sList.insertItem(3);
    PrintList(sList);
    // Expected: [ 3 10 ]

    cout << "=== insertItem Case 3: 가장 큰 값 삽입 (맨 뒤) ===" << endl;
    sList.insertItem(20);
    PrintList(sList);
    // Expected: [ 3 10 20 ]

    cout << "=== insertItem Case 4: 중간 값 삽입 ===" << endl;
    sList.insertItem(7);
    sList.insertItem(15);
    PrintList(sList);
    // Expected: [ 3 7 10 15 20 ]

    cout << "=== insertItem Case 5: 중복 값 삽입 ===" << endl;
    sList.insertItem(10);
    PrintList(sList);
    // Expected: [ 3 7 10 10 15 20 ] (중복 허용 시)
    //        OR [ 3 7 10 15 20 ]    (중복 불허 시)

    */

    // ================================================
    // removeItem 테스트
    // ================================================

    cout << "\n=== removeItem Case 1: 중간 값 제거 ===" << endl;
    sList.clear();
    sList.insertItem(3);
    sList.insertItem(7);
    sList.insertItem(10);
    sList.insertItem(15);
    sList.insertItem(20);
    PrintList(sList);
    // Expected: [ 3 7 10 15 20 ]
    sList.removeItem(10);
    PrintList(sList);
    // Expected: [ 3 7 15 20 ]

    cout << "=== removeItem Case 2: 맨 앞 값 제거 ===" << endl;
    sList.removeItem(3);
    PrintList(sList);
    // Expected: [ 7 15 20 ]

    cout << "=== removeItem Case 3: 맨 뒤 값 제거 ===" << endl;
    sList.removeItem(20);
    PrintList(sList);
    // Expected: [ 7 15 ]

    cout << "=== removeItem Case 4: 존재하지 않는 값 제거 ===" << endl;
    sList.removeItem(99);
    PrintList(sList);
    // Expected: [ 7 15 ] (변화 없음, 에러 메시지 출력 가능)

    cout << "=== removeItem Case 5: 빈 리스트에서 제거 ===" << endl;
    sList.clear();
    sList.removeItem(5);
    PrintList(sList);
    // Expected: [ EMPTY LIST ] (에러 메시지 출력 가능)

    // ================================================
    // updateItem 테스트
    // ================================================

    /*
    cout << "\n=== updateItem Case 1: 중간 값 변경 (정렬 유지 확인) ===" << endl;
    sList.clear();
    sList.insertItem(3);
    sList.insertItem(7);
    sList.insertItem(10);
    sList.insertItem(15);
    sList.insertItem(20);
    PrintList(sList);
    // Expected: [ 3 7 10 15 20 ]
    sList.updateItem(7, 12);
    PrintList(sList);
    // Expected: [ 3 10 12 15 20 ]

    cout << "=== updateItem Case 2: 맨 앞 값 변경 ===" << endl;
    sList.updateItem(3, 1);
    PrintList(sList);
    // Expected: [ 1 10 12 15 20 ]

    cout << "=== updateItem Case 3: 맨 뒤 값 변경 ===" << endl;
    sList.updateItem(20, 25);
    PrintList(sList);
    // Expected: [ 1 10 12 15 25 ]

    cout << "=== updateItem Case 4: 존재하지 않는 값 변경 ===" << endl;
    sList.updateItem(99, 50);
    PrintList(sList);
    // Expected: 변화 없음 (에러 메시지 출력 가능)

    cout << "=== updateItem Case 5: 정렬 순서가 깨지는 값으로 변경 ===" << endl;
    sList.updateItem(10, 30);
    PrintList(sList);
    // Expected: [ 1 12 15 25 30 ] (정렬 유지 시)
    //        OR [ 1 30 12 15 25 ] (정렬 미유지 시 — 구현 오류 케이스)

    */
    return 0;
}