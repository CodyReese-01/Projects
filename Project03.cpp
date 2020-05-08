// Cody Reese
#include <iostream>
#include "Project03.h"

Matrix::Matrix()
// default contructor
{
	rows = 3;
	cols = 3;
	mat = new int * [rows];
	
	std::cout << "Default constructor called" << std::endl;
	std::cout << "Size of matrix: 3x3" << std::endl;
	
	for(i = 0; i < rows; i++)
	{
		mat[i] = new int[cols];
	}
}

Matrix::Matrix(int numRows, int numCols)
// parameterized constructor
{
	rows = numRows;
	cols = numCols;
	mat = new int * [rows];
	
	std::cout << "Parameterized constructor called" << std::endl;
	std::cout << "Size of matrix: " << rows << "x" << cols << std::endl;
	
	for(i = 0; i < rows; i++)
	{
		mat[i] = new int[cols];
	}
}

Matrix::Matrix(const Matrix & x)
// copy constructor
{
	rows = x.rows;
	cols = x.cols;
	mat = new int * [x.rows];
	
	for(i = 0; i < rows; i++)
	{
		mat[i] = new int[x.cols];
		
		for(j = 0; j < cols; j++)
		{
			mat[i][j] = x.mat[i][j];
		}
	}
}

Matrix::~Matrix()
// destructor
{	
	for(i = 0; i < rows; i++)
	{
		delete [] mat[i];
	}
	
	delete [] mat;
}

void Matrix::InitializeMatrix()
{
	for(i = 0; i < rows; i++)
	{
		for(j = 0; j < cols; j++)
		{
			std::cout << "Enter matrix element[" << i << "][" << j << "]: ";
			std::cin >> mat[i][j];
			std::cout << std::endl;
		}
	}
}

void Matrix::PrintMatrix()
{	
	for(int i = 0; i < rows; i++)
	{
		std::cout << std::endl;
		 
		for(int j = 0; j < cols; j++)
		{
			std::cout << mat[i][j] << " ";
		}
	}
	std::cout << std::endl;
}

void Matrix::Resize(int numRows, int numCols)
{
	int** tempmat = new int * [numRows];
	
	for(i = 0; i < numRows; i++)
	{
		tempmat[i] = new int[numCols];
	}
	
	if(numRows > rows && numCols > cols) 
	// if rows and cols are expanding
	{
		for(i = 0; i < rows; i++)
		{
			for(j = 0; j < cols; j++)
			// assign current data
			{
				tempmat[i][j] = mat[i][j];
			}
		}
		
		for(i = 0; i < numRows; i++)
		{
			for(j = cols; j < numCols; j++)
			// for all new cols, assign 0
			{
				tempmat[i][j] = 0;
			}
		}
		
		for(i = rows; i < numRows; i++)
		{
			for(j = 0; j < numCols; j++)
			{
				tempmat[i][j] = 0;
			}
		}
	}
	
	else if(numRows > rows && numCols <= cols)
	// if rows are expanding and cols are shrinking
	{
		for(i = 0; i < rows; i++)
		// for every row
		{
			for(j = 0; j < numCols; j++)
			// assign current data
			{
				tempmat[i][j] = mat[i][j];
			}
		}
		
		for(i = rows; i < numRows; i++)
		{
			for(j = 0; j < numCols; j++)
			// for all new rows, assign 0
			{
				tempmat[i][j] = 0;
			}
		}
	}
	
	else if(numRows <= rows && numCols > cols)
	// if rows are shrinking and cols are expanding
	{
		for(i = 0; i < numRows; i++)
		// for every row
		{
			for(j = 0; j < cols; j++)
			// assign current data
			{
				tempmat[i][j] = mat[i][j];
			}
			
			for(j = cols; j < numCols; j++)
			// for every new col assign 0
			{
				tempmat[i][j] = 0;
			}
		}
	}
	
	for(i = 0; i < rows; i++)
	{
		delete [] mat[i];
	}
	
	delete [] mat;
	
	mat = new int * [numRows];
	
	for(i = 0; i < numRows; i++)
	{
		mat[i] = new int[numCols];
		
		for(j = 0; j < 3; j++)
		{
			mat[i][j] = tempmat[i][j];
		}
	}
	
	rows = numRows;
	cols = numCols;
}

int Matrix::GetRows()
{
	return rows;
}

int Matrix::GetCols()
{
	return cols;
}

Matrix Matrix::AddMatrix(const Matrix & x)
{
	if(x.rows > rows || x.cols > cols)
	{
		Resize(x.rows, x.cols);
	}

	for (i = 0; i < x.rows; i++)
	{
		for(j = 0; j < x.cols; j++)
		{
			mat[i][j] += x.mat[i][j];
		}
	}
	
	return *this;
}

void Matrix::operator + (Matrix const & x)
{	
	if(x.rows > rows || x.cols > cols)
	{
		Resize(x.rows, x.cols);
	}

	for (i = 0; i < x.rows; i++)
	{
		for(j = 0; j < x.cols; j++)
		{
			mat[i][j] += x.mat[i][j];
		}
	}
}

Matrix Matrix::SubtractMatrix(const Matrix & x) 
{
	if(x.rows > rows || x.cols > cols)
	{
		Resize(x.rows, x.cols);
	}

	for(i = 0; i < x.rows; i++)
	{
		for(j = 0; j < x.cols; j++)
		{
			mat[i][j] -= x.mat[i][j];
		}
	}
	
	return *this;
}

void Matrix::operator - (const Matrix & x)
{
	if(x.rows > rows || x.cols > cols)
	{
		Resize(x.rows, x.cols);
	}
	
	for(i = 0; i < x.rows; i++)
	{
		for(j = 0; j < x.cols; j++)
		{
			mat[i][j] -= x.mat[i][j];
		}
	}
}

Matrix Matrix::MultiplyMatrix(const Matrix & x)
{
	if(x.rows > rows || x.cols > cols)
	{
		Resize(x.rows, x.cols);
	}
	
	for(i = 0; i < x.rows; i++)
	{
		for(j = 0; j < x.cols; j++)
		{
			mat[i][j] *= x.mat[i][j];
		}
	}
	
	return *this;
}

void Matrix::operator * (const Matrix & x)
{
	if(x.rows > rows || x.cols > cols)
	{
		Resize(x.rows, x.cols);
	}
	
	for(i = 0; i < x.rows; i++)
	{
		for(j = 0; j < x.cols; j++)
		{
			mat[i][j] *= x.mat[i][j];
		}
	}
}

Matrix Matrix::Transpose()
// creates a temp matrix and re-arranges elements
{	
	Matrix temp(*this);
	
	for(i = 0; i < rows; i++)
	{
		for(j = 0; j < cols; j++)
		{
			mat[i][j] = temp.mat[j][i];
		}
	}
	
	return *this;
}
