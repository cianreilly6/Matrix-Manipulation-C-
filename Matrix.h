#ifndef Matrix_h
#define Matrix_h

#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Matrix{
private:
    int ** data; //Pointer matrix elements
    unsigned int m, n;

public:
    Matrix(unsigned int m,unsigned int n);//Constructor
    ~Matrix();//Destructor
    Matrix(const Matrix &mat);//Copy constructor
    Matrix(int** array, unsigned int m,unsigned int n);//Matrix using a 2d array, size m*n
    unsigned int rows() const; //Returns number of rows
    unsigned int columns() const; //Returns number of columns
    int get(unsigned i, unsigned j) const; //Gets element at ith row and jth column
    void set(unsigned i, unsigned j, int value);// Update value at ith row and jth column
    Matrix operator+(const Matrix &mat);//Returns a matrix thaat has result of adding 2 matrices
    Matrix operator-(const Matrix &mat);//Returns a matrix that has the result of subtracting 2 matrices
    Matrix operator*(const Matrix &mat);//Returns a matrix that has the result of multiplying 2 matrices
    Matrix operator~() const; //Returns transpose of current matrix
    bool operator==(const Matrix &mat);//Returns true of 2 matrices are the same, else false
    string toStr() const;//Returns a string representation of the matrix
};
#endif //Matrix_h