// Cody Reese
#ifndef PROJECT03_H
#define PROJECT03_H

class Matrix
{
	public:
		Matrix();
		Matrix(int numRows, int numCols);
		Matrix(const Matrix & x);
		~Matrix();
		
		void InitializeMatrix();
		void PrintMatrix();
		
		void Resize(int numRows, int numCols);
		
		int GetRows();
		int GetCols();
		
		Matrix AddMatrix(const Matrix & x);
		void operator + (const Matrix & x);
		
		Matrix SubtractMatrix(const Matrix & x);
		void operator - (const Matrix & x);
		
		Matrix MultiplyMatrix(const Matrix & x);
		void operator * (const Matrix & x);
		
		Matrix Transpose();
		
	private:
		int ** mat;
		int rows;
		int cols;
		unsigned int i, j;
};
#endif
