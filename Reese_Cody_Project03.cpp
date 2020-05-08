// Cody Reese
#include <iostream>
#include "Project03.h"

int main()
{
	Matrix a;
	a.InitializeMatrix();
	
	Matrix b(2, 2);
	b.InitializeMatrix();
	
	std::cout << "Matrix a: " << std::endl;
	a.PrintMatrix();
	
	std::cout << std::endl << "Matrix b: " << std::endl;
	b.PrintMatrix();
	
	std::cout << std::endl << "Adding matrix a to matrix b" << std::endl;
	b + a;
	// b.AddMatrix(a); provides the same result
	
	std::cout << "Result: " << std::endl;
	b.PrintMatrix();
	
	std::cout << std::endl << "Subtracting matrix a from matrix b" << std::endl;
	b - a;
	// b.SubtractMatrix(a); provides the same result
	
	std::cout << "Result: " << std::endl;
	b.PrintMatrix();
	
	std::cout << std::endl << "Transposing matrix a" << std::endl;
	a.Transpose();
	
	std::cout << "Result:" << std::endl;
	a.PrintMatrix();
	
	std::cout << std::endl << "Re-transposing matrix a" << std::endl;
	a.Transpose();
	
	std::cout << "Result:" << std::endl;
	a.PrintMatrix();
	
	std::cout << std::endl << "Multiplying matrix a by matrix b" << std::endl;
	a * b;
	// a.MultiplyMatrix(b); provides the same result
	
	std::cout << "Result: " << std::endl;
	a.PrintMatrix();
	
	return 0;
}
