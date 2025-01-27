#include <iostream>
#include <vector>
#include <fstream>
#include "MM_MV_Product.h"
#include "mmio.h"

// //to print the result of matrix matrix multiplication
// void m_m_product (const std::vector<std::vector<double>>& matrix) {
//     for (const auto& row : matrix) {
//         for (double result : row) {
//             std::cout << result << " ";
//         }
//         std::cout << std::endl;
//     }
// }

// //to print the result of matrix vector multiplication
// void m_v_product (const std::vector<double>& vector) {
//     for (double result : vector) {
//         std::cout << result << " ";
//     }
//     std::cout << std::endl;
// }
// function to read the matrix from the file
std::vector<std::vector<double>> readMatrix(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Could not open file: " << filename << std::endl;
        exit(1);
    }
    int I, J, val;
    // Ignore comments headers
    while (file.peek() == '%') file.ignore(2048, '\n');
    // Read number of rows and columns
    file >> I >> J >> val;
    // Create 2D array and fill with zeros
    std::vector<std::vector<double>> matrix(I, std::vector<double>(J, 0.0));
    // Fill the matrix with data
    for (int l = 0; l < val; l++) {
        double data;
        int row, col;
        file >> row >> col >> data;
        matrix[row - 1][col - 1] = data;
    }
    file.close();
    return matrix;
}

// function to read the vector from the file
std::vector<double> readVector(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Could not open file: " << filename << std::endl;
        exit(1);
    }
    int I, val;
    // Ignore comments headers
    while (file.peek() == '%') file.ignore(2048, '\n');
    // Read number of rows and columns
    file >> I >> val;
    // Create vector and fill with zeros
    std::vector<double> vector(val, 0.0);
    // Fill the vector with data
    for (int l = 0; l < val; l++) {
        double data;
        int row;
        file >> row >> data;
        vector[row - 1] = data;
    }
    file.close();
    return vector;
}

// function to write the matrix to the file
void writeMatrix(const std::string& filename, const std::vector<std::vector<double>>& matrix) {
    std::ofstream file(filename);
    // Check if file is open
    if (!file.is_open()) {
        std::cerr << "Could not open file: " << filename << std::endl;
        exit(1);
    }
    // Get the dimensions of the matrix
    int I= matrix.size();
    int J = matrix[0].size();
    int val = 0;
    for (const auto& row : matrix) {
        for (const auto& elem : row) {
            if (elem != 0.0) {
                val++;
            }
        }
    }
    // Write header
    file << "%%MatrixMarket matrix coordinate real general\n";
    file << I << " " << J << " " << val << "\n";
    // Write data
    for (int i = 0; i < I; i++) {
        for (int j = 0; j < J; j++) {
            if (matrix[i][j] != 0.0) {
                file << (i + 1) << " " << (j + 1) << " " << matrix[i][j] << "\n";
            }
        }
    }
    file.close();
}

// function to write the vector to the file
void writeVector(const std::string& filename, const std::vector<double>& vector) {
    std::ofstream file(filename);
    // Check if file is open
    if (!file.is_open()) {
        std::cerr << "Could not open file: " << filename << std::endl;
        exit(1);
    }
    // Get the dimensions of the vector
    int I = vector.size();
    int val = 0;
    // Count non-zero elements
    for (const auto& elem : vector) {
        if (elem != 0.0) {
            val++;
        }
    }
    // Write header
    file << "%%MatrixMarket matrix coordinate real general\n";
    file << I << " 1 " << val << "\n";
    // Write data
    for (int i = 0; i < val; i++) {
        if (vector[i] != 0.0) {
            file << (i + 1) << " " << vector[i] << "\n";
        }
    }
    file.close();
}

// main function
int main(int argc, char* argv[]) {
    // Check if the number of arguments is correct
    std::string file1 = argv[1];
    std::string file2 = argv[2];
    int comp_type = std::stoi(argv[3]);

    // Perform the computation
    if (comp_type == 0) {
        // Reading, calculating and writing the result of matrix-vector product
        std::vector<std::vector<double>> matrix = readMatrix(file1);
        std::vector<double> vector = readVector(file2);
        std::vector<double> m_v_result = M_V_Product(matrix, vector);
        writeVector("vector_result.mtx", m_v_result);
    }
    else if (comp_type == 1) {
        // Reading, calculating and writing the result of matrix-matrix product
        std::vector<std::vector<double>> matrixA = readMatrix(file1);
        std::vector<std::vector<double>> matrixB = readMatrix(file2);
        std::vector<std::vector<double>> m_m_result = M_M_Product(matrixA, matrixB);
        writeMatrix("matrix_result.mtx", m_m_result);
    }
    else {
        std::cerr << "Invalid computation type. Please enter 0 for matrix-vector product or 1 for matrix-matrix product." << std::endl;
        exit(1);
    }
    // Read matrices and vector from files
    // std::vector<std::vector<double>> matrixA = readMatrix("matrixA.mtx");
    // std::vector<std::vector<double>> matrixB = readMatrix("matrixB.mtx");
    // std::vector<double> vectorC = readVector("vectorC.mtx");

    // Dummy variables used in the beginning
    // std::vector<std::vector<double>> matrixA = {{1, 2}, {3, 4}};
    // std::vector<std::vector<double>> matrixB = {{1, 3}, {2, 4}};
    // std::vector<double> vectorC = {1, 2};

    // std::vector<std::vector<double>> m_m_result = M_M_Product(matrixA, matrixB);
    // std::cout << "MatrixA * MatrixB is:\n"; 
    // m_m_product(m_m_result); // used to print the results to check
    // std::vector<double> m_v_result = M_V_Product(matrixA, vectorC);
    // std::cout << "MatrixA * VectorC is:\n"; 
    // m_v_product(m_v_result);
    return 0;
}
