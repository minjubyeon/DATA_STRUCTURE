// SquareMatrix.cpp
//  Lab01
//
//  Modified by Jeman Park on 2026/03/23.
//

#include <iostream>
#include "SquareMatrix.h"




void SquareMatrix::storeValue(int i , int j , int value)
{
    matrix[i][j] = value;
}


SquareMatrix SquareMatrix::add(SquareMatrix m)
{
    SquareMatrix result;
    
    for (int i = 0; i < MATRIX_SIZE ; i++){
        for (int j = 0; j < MATRIX_SIZE; j++){
            result.matrix[i][j] = matrix[i][j] + m.matrix[i][j];
        }
    }
    
    return result;
}


SquareMatrix SquareMatrix::subtract(SquareMatrix m)
{
    SquareMatrix result;
    
    for (int i = 0; i < MATRIX_SIZE; i++){
        for (int j = 0; j < MATRIX_SIZE; j++){
            result.matrix[i][j] = matrix[i][j] - m.matrix[i][j];
        }
    }
    
    return result;
}


void SquareMatrix::copy(SquareMatrix m)
{
    for (int i = 0; i < MATRIX_SIZE; i++){
        for (int j = 0; j < MATRIX_SIZE; j++){
            matrix[i][j] =  m.matrix[i][j];
        }
    }
    
}

int SquareMatrix::multiplyDiagonal()
{
    int ret = 1;
    // Implement the function here (Lab01-2)
    // It returns the multipled value of diagonal elements
    // Diagonal elements (when the matrix size is N x N): matrix[0][0], matrix[1][1], matrix[2][2], ... matrix[N][N]
    
    for (int i = 0; i < MATRIX_SIZE; i++){
        ret *= matrix[i][i];
    }
    
    return ret;
}

int SquareMatrix::borderSum()
{
    int ret = 0;
    // Implement the function here (Lab01-2)
    // It returns the sum of border values
    // Refer to the figure in the slide

    int i = 0;
    int j = 1;

    for (i; i < MATRIX_SIZE; i++) {
        ret += matrix[0][i];
    }

    while (i == MATRIX_SIZE) {
        for (j; j < MATRIX_SIZE; j++) {
            ret += matrix[i][j];
        }
    }

    for (i; i < 0; i--) {
        ret += matrix[i][j];
    }

    while ((i == 0)) {
        for (j; j < 0; j--) {
            ret += matrix[i][j];
        }

        return ret;
    }
}

void SquareMatrix::makeEmpty()
{
    // Implement the function here (Lab01-2)
    // It sets all elements in the matrix to 0
    
    
    
    
    
    
}

void SquareMatrix::printMatrix()
{
    for (int i = 0; i < MATRIX_SIZE; i++)
    {
        for (int j = 0; j < MATRIX_SIZE; j++)
        {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }

}