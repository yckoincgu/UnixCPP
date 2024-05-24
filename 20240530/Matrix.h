#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>

template <typename T>
class Matrix {
public:
    T **A;     // Pointer to a 2D array (matrix)
    int n, m;  // Rows = n, Columns = m

    // Constructor to initialize the matrix with dimensions n x m
    Matrix(int n, int m) : n(n), m(m) {
        A = new T*[n];
        for (int i = 0; i < n; ++i) {
            A[i] = new T[m];
        }
        int k = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                A[i][j] = k++;
            }
        }
    }

    // Destructor to delete dynamically allocated memory
    ~Matrix() {
        for (int i = 0; i < n; ++i) {
            delete[] A[i];
        }
        delete[] A;
    }

    // Print matrix dimensions
    void printMatrixDimension() {
        std::cout << "Matrix dimensions: n = " << n << ", m = " << m << std::endl;
    }

    // Print matrix elements
    void printMatrix() {
        std::cout << "Matrix elements:" << std::endl;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                std::cout << A[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
};

// Template class AxB that multiplies two Matrix objects
template<typename T>
class AxB {
public:
    T **C;    // Resultant matrix
    int n, m, p;    // Dimensions of the matrices involved

    // Constructor that multiplies two Matrix objects a and b
    AxB(Matrix<T>& a, Matrix<T>& b) : n(a.n), m(a.m), p(b.m) {
        // Check if matrices a and b can be multiplied
        if (a.m != b.n) {
            std::cout<< "Matrices cannot be multiplied: dimensions mismatch";
        }

        // Allocate memory for matrix C
        C = new T*[n];
        for (int i = 0; i < n; ++i) {
            C[i] = new T[p];
        }

        // Perform matrix multiplication and store result in C
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < p; ++j) {
                C[i][j] = 0;
                for (int k = 0; k < a.m; ++k) {
                    C[i][j] += a.A[i][k] * b.A[k][j];
                }
            }
        }
    }

    // Destructor to delete dynamically allocated memory
    ~AxB() {
        for (int i = 0; i < n; ++i) {
            delete[] C[i];
        }
        delete[] C;
    }
};

#endif // MATRIX_H