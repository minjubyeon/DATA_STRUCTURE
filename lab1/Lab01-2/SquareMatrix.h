//
//  SquareMatrix.h
//  Lab01
//
//  Modified by Jeman Park on 2026/03/23.
//

#ifndef SQUAREMATRIX_H
#define SQUAREMATRIX_H

#define MATRIX_SIZE 10
// You can change the value of "MATRIX_SIZE" above
// But do NOT change the definition of the class below

class SquareMatrix
{
    
public:
    void makeEmpty();
    void printMatrix();
    void storeValue(int, int, int);
    SquareMatrix add(SquareMatrix m);
    SquareMatrix subtract(SquareMatrix m);
    void copy(SquareMatrix m);
    
    
    int multiplyDiagonal();
    int borderSum();
    
    
private:
    int matrix[MATRIX_SIZE][MATRIX_SIZE];
};

#endif
