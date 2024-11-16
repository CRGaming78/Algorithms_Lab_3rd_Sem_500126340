#include <iostream>
using namespace std;

void traditionalMultiplication(int A[64][64], int B[64][64], int C[64][64], int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n; k++)
                C[i][j] += A[i][k] * B[k][j];
        }
}

void addMatrix(int A[64][64], int B[64][64], int result[64][64], int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            result[i][j] = A[i][j] + B[i][j];
}

void subtractMatrix(int A[64][64], int B[64][64], int result[64][64], int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            result[i][j] = A[i][j] - B[i][j];
}

void strassenMultiplication(int A[64][64], int B[64][64], int C[64][64], int n) {
    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int newSize = n / 2;
    int A11[64][64], A12[64][64], A21[64][64], A22[64][64];
    int B11[64][64], B12[64][64], B21[64][64], B22[64][64];
    int C11[64][64], C12[64][64], C21[64][64], C22[64][64];
    int M1[64][64], M2[64][64], M3[64][64], M4[64][64], M5[64][64], M6[64][64], M7[64][64];
    int temp1[64][64], temp2[64][64];

    for (int i = 0; i < newSize; i++)
        for (int j = 0; j < newSize; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + newSize];
            A21[i][j] = A[i + newSize][j];
            A22[i][j] = A[i + newSize][j + newSize];
            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + newSize];
            B21[i][j] = B[i + newSize][j];
            B22[i][j] = B[i + newSize][j + newSize];
        }

    addMatrix(A11, A22, temp1, newSize);
    addMatrix(B11, B22, temp2, newSize);
    strassenMultiplication(temp1, temp2, M1, newSize);

    addMatrix(A21, A22, temp1, newSize);
    strassenMultiplication(temp1, B11, M2, newSize);

    subtractMatrix(B12, B22, temp2, newSize);
    strassenMultiplication(A11, temp2, M3, newSize);

    subtractMatrix(B21, B11, temp2, newSize);
    strassenMultiplication(A22, temp2, M4, newSize);

    addMatrix(A11, A12, temp1, newSize);
    strassenMultiplication(temp1, B22, M5, newSize);

    subtractMatrix(A21, A11, temp1, newSize);
    addMatrix(B11, B12, temp2, newSize);
    strassenMultiplication(temp1, temp2, M6, newSize);

    subtractMatrix(A12, A22, temp1, newSize);
    addMatrix(B21, B22, temp2, newSize);
    strassenMultiplication(temp1, temp2, M7, newSize);

    addMatrix(M1, M4, temp1, newSize);
    subtractMatrix(temp1, M5, temp2, newSize);
    addMatrix(temp2, M7, C11, newSize);

    addMatrix(M3, M5, C12, newSize);
    addMatrix(M2, M4, C21, newSize);

    addMatrix(M1, M3, temp1, newSize);
    subtractMatrix(temp1, M2, temp2, newSize);
    addMatrix(temp2, M6, C22, newSize);

    for (int i = 0; i < newSize; i++)
        for (int j = 0; j < newSize; j++) {
            C[i][j] = C11[i][j];
            C[i][j + newSize] = C12[i][j];
            C[i + newSize][j] = C21[i][j];
            C[i + newSize][j + newSize] = C22[i][j];
        }
}

int main() {
    int n;
    cout << "Enter the size of the matrix (power of 2, max 64): ";
    cin >> n;
    int A[64][64] = {0}, B[64][64] = {0}, C[64][64] = {0};
    cout << "Enter elements of matrix A:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> A[i][j];
    cout << "Enter elements of matrix B:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> B[i][j];
    cout << "\nTraditional Multiplication:\n";
    int T[64][64] = {0};
    traditionalMultiplication(A, B, T, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << T[i][j] << " ";
        cout << endl;
    }
    cout << "\nStrassen's Multiplication:\n";
    strassenMultiplication(A, B, C, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << C[i][j] << " ";
        cout << endl;
    }
    return 0;
}