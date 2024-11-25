#include "Matrix.h"
#include <iostream>
#include <stdexcept>
using namespace std;

/*
Constructor
Initialize matrix with size m*n
All elements are initialized to 0
*/
Matrix::Matrix(unsigned int m, unsigned int n) : m(m), n(n) {
    // Allocate memory for an array of pointers (each pointer represents a row)
    data = new int*[m];

    // Allocate memory for each row (initialize all elements to 0)
    for (unsigned int i = 0; i < m; i++) {
        data[i] = new int[n](); // Using () initializes all elements to 0
    }
}

/*
Copy Constructor
Creates a deep copy of the given matrix `mat`
*/
Matrix::Matrix(const Matrix &mat) : m(mat.m), n(mat.n) {
    // Allocate memory for the new matrix (same size as `mat`)
    data = new int*[m];
    for (unsigned int i = 0; i < m; i++) {
        data[i] = new int[n]; // Allocate memory for each row
        for (unsigned int j = 0; j < n; j++) {
            // Copy each element from the original matrix `mat`
            data[i][j] = mat.data[i][j];
        }
    }
}

/*
2D Array Constructor
Initialize matrix using a given 2D array with size m * n
*/
Matrix::Matrix(int** array, unsigned int m, unsigned int n) : m(m), n(n) {
    // Allocate memory for the matrix
    data = new int*[m];
    for (unsigned int i = 0; i < m; i++) {
        data[i] = new int[n]; // Allocate memory for each row
        for (unsigned int j = 0; j < n; j++) {
            // Copy elements from the provided 2D array
            data[i][j] = array[i][j];
        }
    }
}

/*
Destructor
Frees the dynamically allocated memory for the matrix
*/
Matrix::~Matrix() {
    // Loop through each row and delete the allocated memory
    for (unsigned int i = 0; i < m; i++) {
        delete[] data[i]; // Delete each row
    }
    delete[] data; // Delete the array of row pointers
}

// Get the number of rows in the matrix
unsigned int Matrix::rows() const {
    return m;
}

// Get the number of columns in the matrix
unsigned int Matrix::columns() const {
    return n;
}

/*
Get element at (i, j)
Returns the value at the specified row and column indices
Throws an exception if the indices are out of bounds
*/
int Matrix::get(unsigned int i, unsigned int j) const {
    // Check if the indices are within bounds.
    if (i >= m || j >= n) throw out_of_range("Out of bounds");
    return data[i][j]; // Return the element at (i, j)
}

/*
Change element at (i, j) with the given value
Throws an exception if the indices are out of bounds
*/
void Matrix::set(unsigned int i, unsigned int j, int value) {
    // Check if the indices are within bounds
    if (i >= m || j >= n) throw out_of_range("Out of bounds");
    data[i][j] = value; // Set the element at (i, j) to the given value
}

/*
Matrix Addition
Returns a new matrix that is the result of adding the current matrix with `mat`
*/
Matrix Matrix::operator+(const Matrix &mat) {
    // Create a result matrix with the same dimensions
    Matrix res(m, n);
    for (unsigned int i = 0; i < m; i++) {
        for (unsigned int j = 0; j < n; j++) {
            // Add corresponding elements of both matrices
            res.data[i][j] = data[i][j] + mat.data[i][j];
        }
    }
    return res; // Return the result matrix
}

/*
Matrix Subtraction
Returns a new matrix that is the result of subtracting `mat` from the current matrix
*/
Matrix Matrix::operator-(const Matrix &mat) {
    // Create a result matrix with the same dimensions
    Matrix res(m, n);
    for (unsigned int i = 0; i < m; i++) {
        for (unsigned int j = 0; j < n; j++) {
            // Subtract corresponding elements of both matrices
            res.data[i][j] = data[i][j] - mat.data[i][j];
        }
    }
    return res; // Return the result matrix
}

/*
Matrix Multiplication
Returns a new matrix that is the result of multiplying the current matrix with `mat`
*/
Matrix Matrix::operator*(const Matrix &mat) {
    // Create a result matrix 
    Matrix res(m, mat.n);
    // Perform matrix multiplication.
    for (unsigned int i = 0; i < m; i++) {
        for (unsigned int j = 0; j < mat.n; j++) {
            for (unsigned int k = 0; k < n; k++) {
                // Accumulate the product of corresponding elements
                res.data[i][j] += data[i][k] * mat.data[k][j];
            }
        }
    }
    return res; // Return the result matrix
}

/*
Matrix Transpose
Returns a new matrix that is the transpose of the current matrix
*/
Matrix Matrix::operator~() const {
    // Create a result matrix 
    Matrix res(n, m);
    for (unsigned int i = 0; i < m; i++) {
        for (unsigned int j = 0; j < n; j++) {
            // Assign the element at (j, i) in the result matrix from (i, j) in the current matrix
            res.data[j][i] = data[i][j];
        }
    }
    return res; // Return the transposed matrix
}

/*
Equality Check
Returns true if the current matrix is equal to `mat`, otherwise false
Two matrices are equal if they have the same dimensions and all elements are identical
*/
bool Matrix::operator==(const Matrix &mat) {
    // Check if the dimensions are different
    if (m != mat.m || n != mat.n) {
        return false;
    }
    // Compare each element of both matrices
    for (unsigned int i = 0; i < m; i++) {
        for (unsigned int j = 0; j < n; j++) {
            if (data[i][j] != mat.data[i][j]) {
                return false; // Return false if any element differs
            }
        }
    }
    return true; // Matrices are equal
}

/*
String Representation
Returns a string showing all elements of the matrix
Each row is on a new line
*/
string Matrix::toStr() const {
    string res;
    for (unsigned int i = 0; i < m; i++) {
        for (unsigned int j = 0; j < n; j++) {
            res += to_string(data[i][j]) + " "; // Append each element followed by a space
        }
        res += "\n"; // New line after each row
    }
    return res; // Return the string representation
}
