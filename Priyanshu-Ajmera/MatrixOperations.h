#pragma once
#include <vector>
#include <iomanip>

/// This will define the size of matrix ///
std::vector<std::vector<double>> defineMatrix(int dimM, int dimN);
/// This will fill the matrix entered by the user ///
std::vector<std::vector<double>> fillMatrix(const std::initializer_list<std::initializer_list<double>> &mat);
/// This will perform the matrix multiplication logic of two matrices ///
std::vector<std::vector<double>> operator*(std::vector<std::vector<double>> &mat1, std::vector<std::vector<double>> &mat2);
/// This will perform Matrix Transposition on the matrix entered by the user///
std::vector<std::vector<double>> matTrans(std::vector<std::vector<double>> &matrix);
/// This will display the matrix using reference variable of two matrices ///
void printMatrix(std::vector<std::vector<double>> &&mat);
/// This will equate the rvalue and lvalue of the matrix and return the result to the above print_matrix function ///
void printMatrix(std::vector<std::vector<double>> &mat);
