//
//  Lab01_2.cpp
//  Lab01
//
//  Modified by Jeman Park on 2026/03/23.
//

#include <iostream>
#include "SquareMatrix.h"

using namespace std;

int main() {
    SquareMatrix A;
    
    
    for (int i = 0; i < MATRIX_SIZE; i++){
        for (int j = 0; j < MATRIX_SIZE; j++){
            A.storeValue(i, j, i+1);
        }
    }
        
    
    /* Feel free to edit codes below (test with more cases) */
    
    cout << "A: " << endl;
    A.printMatrix();
    //    ---- n ----
    //  | 1  1 .... 1  1
    //  | 2  2 .... 2  2
    //  n ... .... ...
    //  | 9  9 .... 9  9
    //  |10 10.... 10 10
    
    
    cout << "[multiplyDiagonal]: " << A.multiplyDiagonal() << endl;
    // [multiplyDiagonal]: 3628800
    
    
    cout << "[borderSum]: " << A.borderSum() << endl;
    // [borderSum]: 198
    
    
    //A.makeEmpty();
    //A.printMatrix();
    //    ---- n ----
    //  | 0 0 .... 0  0
    //  | 0 0 .... 0  0
    //  n ... .... ...
    //  | 0 0 .... 0  0
    //  | 0 0 .... 0  0
    
    return 0;
}
