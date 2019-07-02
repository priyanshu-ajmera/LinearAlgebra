#include "MatrixOperations.h"
#include <iostream>
#include <vector>

int main()
{
    /// Enter the First Matrix here in the format: ({{},{},{},...}) ///
    std::vector<std::vector<double>> mat1 = fillMatrix({{1,2,3,4,5},{5,6,7,8,9},{1,3,5,7,0}});
    /// Enter the Second Matrix here in the format: ({{},{},{},...}) ///
    std::vector<std::vector<double>> mat2 = fillMatrix({{9,8,7},{6,5,4},{3,2,1},{0,5,1},{2,4,6}});
    /// Matrix Multiplication of the Multidimensional Matrices ///
    std::vector<std::vector<double>> mat3 = mat1*mat2;
    /// Either print the Resulting Matrix after Multiplication ///
    std::cout<<"Matrix Multiplication: "<<std::endl;
    printMatrix(mat3);
    std::vector<std::vector<double>> mat4 = fillMatrix({{1,2,3},{7,8,9},{4,5,6},{0,5.5,1}});
    /// Transposition of a matrix can be done by using the following format: mat4 = ({{},{},{},...}) ///
    std::cout<<std::endl<<"Transpose Matrix: "<<std::endl;
    ///printMatrix(matTrans(mat3));
    printMatrix(matTrans(mat4));
}
