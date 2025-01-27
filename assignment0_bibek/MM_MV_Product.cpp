#include "MM_MV_Product.h"
#include <iostream>
#include <vector>

// Function to multiply two matrices
std::vector<std::vector<double>> M_M_Product(const std::vector<std::vector<double>>& matrixA, const std::vector<std::vector<double>>& matrixB){
    int rowsA = matrixA.size();
    int colsA = matrixA[0].size();
    int rowsB = matrixB.size();
    int colsB = matrixB[0].size();
    std::vector<std::vector<double>> result(rowsA, std::vector<double>(colsB, 0.0));
    // Check if the number of columns in the first matrix is equal to the number of rows in the second matrix
    if (colsA != rowsB) {
        throw std::invalid_argument("Matrix dimensions do not match for multiplication");
    }
    // Multiply the two matrices
    for (int i = 0; i < rowsA; ++i) {
        for (int j = 0; j < colsB; ++j) {
            for (int k = 0; k < colsA; ++k) {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }

    return result;
}

// Function to multiply a matrix and a vector
std::vector<double> M_V_Product(const std::vector<std::vector<double>>& matrix, const std::vector<double>& vector) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    int vectorSize = vector.size(); // denotes the rows
    // Check if the number of columns in the matrix is equal to the size of the vector
    if (cols != vectorSize) {
        throw std::invalid_argument("Matrix and vector dimensions do not match for multiplication");
    }
    // Multiply the matrix and the vector
    std::vector<double> result(rows, 0.0);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[i] += matrix[i][j] * vector[j];
        }
    }
    return result;
}
