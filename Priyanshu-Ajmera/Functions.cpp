#include "MatrixOperations.h"
#include <iostream>
#include <vector>

/// Define Matrix will generate a empty matrix of the size mentioned in the input of the matrices ///
std::vector<std::vector<double>>defineMatrix(int row, int col)
{
	std::vector<std::vector<double>>matrix(row);        /// This will resize the row: (matrix.resize(row);)///
	for (int i = 0;i < row;i++)                         /// This will resize the column for each row ///
		matrix[i].resize(col);
	return matrix;
}

/// Fill Matrix will initialize a list which will start filling the values with respect to the matrices entered ///
std::vector<std::vector<double>> fillMatrix(const std::initializer_list<std::initializer_list<double>> &mat)
{
    size_t n_rows = mat.size(), n_cols = mat.begin()->size();   /// Initialize the size of the rows and columns ///
    for(unsigned int i = 0; i<n_rows; ++i)                      /// Defining the size of the rows for the matrix entered///
    {
        if((mat.begin()+i)->size()!=n_cols)                     /// Check for the columns that each row contains the same no. of elements ///
        {
            std::cout << "Error: Object initialization failed. Number of elements in each row must be same." << std::endl;
            std::vector<std::vector<double>> matrix(n_rows);    /// Resizing an empty matrix if not true ///
            for(unsigned int i = 0; i<n_rows; ++i)
            {
                matrix[i].resize(n_cols);
            }
            break;
        }
    }

    std::vector<std::vector<double>> matrix(n_rows);            /// Creation of a vector for storing the values entered by the user ///
    for(unsigned int i = 0; i<n_rows; ++i)
    {
        matrix[i].resize(n_cols);
        for(unsigned int j = 0; j<n_cols; ++j)
        {
            matrix[i][j] = *((mat.begin()+i)->begin()+j);       /// This will store the row and column value to their respective positions ///
        }
    }

    return matrix;
}

/// This will perform matrix multiplication on two matrices and store in another matrix ///
std::vector<std::vector<double>> operator*(std::vector<std::vector<double>> &mat1, std::vector<std::vector<double>> &mat2)
{
    /// Initializing the row and column values for the matrices///
	int rowMat1 = mat1.size();
	int colMat1 = mat1[0].size();
	int rowMat2 = mat2.size();
	int colMat2 = mat2[0].size();

	std::vector<std::vector<double>>matRes = defineMatrix(rowMat1, colMat2);    /// Defining the matrix for resulting matrix ///
	if (colMat1 == rowMat2)                                                     /// The order for column of Matrix1 should be equal to the row of Matrix2 ///
	{
		for (int i = 0; i < rowMat1; i++)                                       /// Defining the row of the product matrix ///
			for (int j = 0; j < colMat2; j++)                                   /// Defining the column of the product matrix ///
				for (int k = 0; k < colMat1; k++)                               /// Check for the common order of the user entered matrices ///
					matRes[i][j] = matRes[i][j] + (mat1[i][k] * mat2[k][j]);    /// Logic for the multiplication matrix ///
	}
	else
        std::cout<<"The row and column of matrices are not same"<<std::endl;
	return matRes;
}

/// This will perform the matrix transposition entered by the user ///
std::vector<std::vector<double>>matTrans(std::vector<std::vector<double>> &matrix)
{
    size_t r = matrix.size();                                       /// Getting the row of the matrix entered ///
    size_t c = matrix[0].size();                                    /// Getting the column of the matrix entered ///

    std::vector<std::vector<double>> Trans = defineMatrix(c,r);     /// Defining the matrix size of the transposed matrix ///
    for (unsigned int i = 0; i < r; ++i)
		for (unsigned int j = 0; j < c; ++j)
		{
			Trans[j][i] = matrix[i][j];                             /// Logic for changing rows into columns and vice-versa ///
		}
    return Trans;
}

/// This will display the final matrix ///
void printMatrix(std::vector<std::vector<double>> &&mat)
{
    size_t n_rows = mat.size(), n_cols = mat[0].size();
    std::cout << std::scientific << std::setprecision(4);           /// This will set the precision value of the result up to 4 decimal places ///
    for(unsigned int i = 0; i<n_rows; ++i)
    {
        for(unsigned int j = 0; j<n_cols; ++j)
        {
            std::cout<<mat[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
}

/// This will equate the lvalue with rvalue of the matrix value using reference variable ///
void printMatrix(std::vector<std::vector<double>> &mat)
{
    return printMatrix(std::move(mat));
}
