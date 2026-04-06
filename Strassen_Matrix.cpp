#include <iostream>
#include <vector>

using namespace std;
// Function to add two matrices
vector<vector<int>> add_matrix(vector<vector<int>> A, vector<vector<int>> B, int n) {
    vector<vector<int>> C(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    return C;
}

// Function to subtract two matrices
vector<vector<int>> sub_matrix(vector<vector<int>> A, vector<vector<int>> B, int n) {
    vector<vector<int>> C(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
    return C;
}

// Strassen's algorithm for matrix multiplication
vector<vector<int>> strassen(vector<vector<int>> A, vector<vector<int>> B, int n) {
    vector<vector<int>> C(n, vector<int>(n));

    // Base case: 1x1 matrix
    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return C;
    }

    int k = n / 2;

    // Initialize sub-matrices
    vector<vector<int>> A11(k, vector<int>(k)), A12(k, vector<int>(k));
    vector<vector<int>> A21(k, vector<int>(k)), A22(k, vector<int>(k));
    vector<vector<int>> B11(k, vector<int>(k)), B12(k, vector<int>(k));
    vector<vector<int>> B21(k, vector<int>(k)), B22(k, vector<int>(k));

    // Divide matrices A and B into 4 sub-matrices each
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][k + j];
            A21[i][j] = A[k + i][j];
            A22[i][j] = A[k + i][k + j];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][k + j];
            B21[i][j] = B[k + i][j];
            B22[i][j] = B[k + i][k + j];
        }
    }

    // Calculate the 7 Strassen products
    // P1 = (A11 + A22) * (B11 + B22)
    vector<vector<int>> P1 = strassen(add_matrix(A11, A22, k), add_matrix(B11, B22, k), k);
    
    // P2 = (A21 + A22) * B11
    vector<vector<int>> P2 = strassen(add_matrix(A21, A22, k), B11, k);
    
    // P3 = A11 * (B12 - B22)
    vector<vector<int>> P3 = strassen(A11, sub_matrix(B12, B22, k), k);
    
    // P4 = A22 * (B21 - B11)
    vector<vector<int>> P4 = strassen(A22, sub_matrix(B21, B11, k), k);
    
    // P5 = (A11 + A12) * B22
    vector<vector<int>> P5 = strassen(add_matrix(A11, A12, k), B22, k);
    
    // P6 = (A21 - A11) * (B11 + B12)
    vector<vector<int>> P6 = strassen(sub_matrix(A21, A11, k), add_matrix(B11, B12, k), k);
    
    // P7 = (A12 - A22) * (B21 + B22)
    vector<vector<int>> P7 = strassen(sub_matrix(A12, A22, k), add_matrix(B21, B22, k), k);

    // Calculate the quadrants of the final matrix C
    // C11 = P1 + P4 - P5 + P7
    vector<vector<int>> C11 = add_matrix(sub_matrix(add_matrix(P1, P4, k), P5, k), P7, k);
    
    // C12 = P3 + P5
    vector<vector<int>> C12 = add_matrix(P3, P5, k);
    
    // C21 = P2 + P4
    vector<vector<int>> C21 = add_matrix(P2, P4, k);
    
    // C22 = P1 - P2 + P3 + P6
    vector<vector<int>> C22 = add_matrix(add_matrix(sub_matrix(P1, P2, k), P3, k), P6, k);

    // Combine quadrants back into matrix C
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            C[i][j] = C11[i][j];
            C[i][j + k] = C12[i][j];
            C[k + i][j] = C21[i][j];
            C[k + i][k + j] = C22[i][j];
        }
    }

    return C;
}

int main() {
    int n;
    cout << "Enter the dimension N of the matrices (must be a power of 2 locally, e.g., 2, 4, 8): ";
    cin >> n;

    vector<vector<int>> A(n, vector<int>(n));
    vector<vector<int>> B(n, vector<int>(n));

    cout << "\nEnter elements for Matrix A (" << n << "x" << n << "):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }

    cout << "\nEnter elements for Matrix B (" << n << "x" << n << "):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> B[i][j];
        }
    }

    vector<vector<int>> C = strassen(A, B, n);

    cout << "\nResultant Matrix C (A * B) using Strassen's Algorithm:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << C[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
