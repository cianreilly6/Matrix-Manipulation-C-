#include <iostream>
#include "Matrix.h"
#include "Matrix.cpp"
using namespace std;

/**
 * Test Case 1: Default Constructor and toStr
 * This test checks if a matrix created with the default constructor has all elements initialized to 0
 */
void Test_Case_1_DefaultConstructor() {
    // Create a 2x3 matrix using the default constructor
    Matrix mat(2, 3);

    // Create an expected matrix with the same dimensions, also initialized to 0
    Matrix expected(2, 3);

    // Check if the created matrix is equal to the expected matrix
    if (mat == expected) {
        cout << "Test Case 1 - Passed\n";
    } else {
        cout << "Test Case 1 - Failed\n";
        cout << "Actual:\n" << mat.toStr() << "Expected:\n" << expected.toStr() << endl;
    }
}

/**
 * Test Case 2: Copy Constructor
 * This test verifies that the copy constructor creates an exact copy of the matrix
 */
void Test_Case_2_CopyConstructor() {
    // Create a 2x2 matrix and set some values
    Matrix mat1(2, 2);
    mat1.set(0, 0, 1);
    mat1.set(0, 1, 2);
    mat1.set(1, 0, 3);
    mat1.set(1, 1, 4);

    // Create a copy of mat1 using the copy constructor
    Matrix mat2 = mat1;

    // Check if mat2 is equal to mat1
    if (mat1 == mat2) {
        cout << "Test Case 2 - Passed\n";
    } else {
        cout << "Test Case 2 - Failed\n";
        cout << "Actual:\n" << mat2.toStr() << "Expected:\n" << mat1.toStr() << endl;
    }
}

/**
 * Test Case 3: 2D Array Constructor
 * This test checks if a matrix can be correctly initialized from a 2D array
 */
void Test_Case_3_ArrayConstructor() {
    // Define a 2x2 2D array
    int array[2][2] = {{1, 2}, {3, 4}};
    int* ptrArray[2] = {array[0], array[1]};

    // Create a matrix using the 2D array constructor
    Matrix mat(ptrArray, 2, 2);

    // Create the expected matrix
    Matrix expected(2, 2);
    expected.set(0, 0, 1);
    expected.set(0, 1, 2);
    expected.set(1, 0, 3);
    expected.set(1, 1, 4);

    // Check if the created matrix matches the expected matrix
    if (mat == expected) {
        cout << "Test Case 3 - Passed\n";
    } else {
        cout << "Test Case 3 - Failed\n";
        cout << "Actual:\n" << mat.toStr() << "Expected:\n" << expected.toStr() << endl;
    }
}

/**
 * Test Case 4: set() and get() Methods
 * This test verifies the correct behavior of the set() and get() methods
 */
void Test_Case_4_SetGet() {
    // Create a 2x2 matrix
    Matrix mat(2, 2);

    // Set specific values in the matrix
    mat.set(0, 0, 10);
    mat.set(1, 1, 20);

    // Check if the values retrieved with get() match the set values
    if (mat.get(0, 0) == 10 && mat.get(1, 1) == 20) {
        cout << "Test Case 4 - Passed\n";
    } else {
        cout << "Test Case 4 - Failed\n";
        cout << "Actual:\n" << mat.toStr() << endl;
    }
}

/**
 * Test Case 5: Matrix Addition
 * This test checks if two matrices can be correctly added together
 */
void Test_Case_5_Addition() {
    // Create two 2x2 matrices and set their values
    Matrix mat1(2, 2);
    Matrix mat2(2, 2);
    mat1.set(0, 0, 1);
    mat1.set(0, 1, 2);
    mat2.set(0, 0, 3);
    mat2.set(0, 1, 4);

    // Create the expected result of the addition
    Matrix expected(2, 2);
    expected.set(0, 0, 4);
    expected.set(0, 1, 6);

    // Perform the addition and check the result
    Matrix result = mat1 + mat2;
    if (result == expected) {
        cout << "Test Case 5 - Passed\n";
    } else {
        cout << "Test Case 5 - Failed\n";
        cout << "Actual:\n" << result.toStr() << "Expected:\n" << expected.toStr() << endl;
    }
}

/**
 * Test Case 6: Matrix Subtraction
 * This test verifies the correct behavior of matrix subtraction
 */
void Test_Case_6_Subtraction() {
    // Create two 2x2 matrices and set their values
    Matrix mat1(2, 2);
    Matrix mat2(2, 2);
    mat1.set(0, 0, 5);
    mat1.set(0, 1, 7);
    mat2.set(0, 0, 3);
    mat2.set(0, 1, 4);

    // Create the expected result of the subtraction
    Matrix expected(2, 2);
    expected.set(0, 0, 2);
    expected.set(0, 1, 3);

    // Perform the subtraction and check the result
    Matrix result = mat1 - mat2;
    if (result == expected) {
        cout << "Test Case 6 - Passed\n";
    } else {
        cout << "Test Case 6 - Failed\n";
        cout << "Actual:\n" << result.toStr() << "Expected:\n" << expected.toStr() << endl;
    }
}

/**
 * Test Case 7: Transpose
 * This test checks the transpose operation of a matrix
 */
void Test_Case_7_Transpose() {
    // Create a 2x3 matrix and set its values
    Matrix mat(2, 3);
    mat.set(0, 0, 1);
    mat.set(0, 1, 2);
    mat.set(0, 2, 3);

    // Create the expected transpose matrix (3x2)
    Matrix expected(3, 2);
    expected.set(0, 0, 1);
    expected.set(1, 0, 2);
    expected.set(2, 0, 3);

    // Compute the transpose and check the result
    Matrix result = ~mat;
    if (result == expected) {
        cout << "Test Case 7 - Passed\n";
    } else {
        cout << "Test Case 7 - Failed\n";
        cout << "Actual:\n" << result.toStr() << "Expected:\n" << expected.toStr() << endl;
    }
}

/**
 * Main function to run all test cases
 */
int main() {
    Test_Case_1_DefaultConstructor();
    Test_Case_2_CopyConstructor();
    Test_Case_3_ArrayConstructor();
    Test_Case_4_SetGet();
    Test_Case_5_Addition();
    Test_Case_6_Subtraction();
    Test_Case_7_Transpose();

    return 0;
}
