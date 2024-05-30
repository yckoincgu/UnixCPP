#include <iostream>

class Matrix {
public:
    int** A;  // The 2D array
    int n, m; // Dimensions: rows (n) and columns (m)

    Matrix(int n, int m) : n(n), m(m) {
        A = new int*[n];
        for (int i = 0; i < n; ++i) {
            A[i] = new int[m];
        }
        int value = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                A[i][j] = value++;
            }
        }
    }

    void printMatrixDimension() const {
        std::cout << "The matrix dimensions n=" << n << " m= " << m << std::endl;
    }

    void printMatrix() const {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                std::cout << A[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    void deleteMatrix() {
        for (int i = 0; i < n; ++i) {
            delete[] A[i];
        }
        delete[] A;
    }

    ~Matrix() {
        deleteMatrix();
    }
};

int main() {
    Matrix a(6, 5);
    a.printMatrixDimension();
    a.printMatrix();

    // Matrix destructor will automatically clean up the allocated memory
    return 0;
}
