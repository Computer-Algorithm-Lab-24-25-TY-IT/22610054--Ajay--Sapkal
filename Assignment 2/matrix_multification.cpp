#include <iostream>
#include <vector>

using namespace std;


vector<vector<int>> multiplyMatrices(const vector<vector<int>>& mat1, const vector<vector<int>>& mat2) {
    int rows1 = mat1.size();
    int cols1 = mat1[0].size();
    int rows2 = mat2.size();
    int cols2 = mat2[0].size();
    
    vector<vector<int>> result(rows1, vector<int>(cols2, 0));
    
    for (int i = 0; i < rows1; ++i) {
        for (int j = 0; j < cols2; ++j) {
            for (int k = 0; k < cols1; ++k) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
    
    return result;
}


void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    int rows1, cols1, rows2, cols2;

    cout << "Enter the number of rows and columns for the first matrix (rows cols): ";
    cin >> rows1 >> cols1;

    if (rows1 <= 0 || cols1 <= 0) {
        cerr << "Invalid dimensions for the first matrix." << endl;
        return 1;
    }

    vector<vector<int>> mat1(rows1, vector<int>(cols1));
    cout << "Enter the elements of the first matrix row by row:" << endl;
    for (int i = 0; i < rows1; ++i) {
        for (int j = 0; j < cols1; ++j) {
            cin >> mat1[i][j];
        }
    }

    cout << "Enter the number of rows and columns for the second matrix (rows cols): ";
    cin >> rows2 >> cols2;

    if (rows2 <= 0 || cols2 <= 0) {
        cerr << "Invalid dimensions for the second matrix." << endl;
        return 1;
    }

    if (cols1 != rows2) {
        cerr << "Matrix multiplication is not possible. Number of columns in the first matrix must be equal to the number of rows in the second matrix." << endl;
        return 1;
    }

    vector<vector<int>> mat2(rows2, vector<int>(cols2));
    cout << "Enter the elements of the second matrix row by row:" << endl;
    for (int i = 0; i < rows2; ++i) {
        for (int j = 0; j < cols2; ++j) {
            cin >> mat2[i][j];
        }
    }

    vector<vector<int>> result = multiplyMatrices(mat1, mat2);
    
    cout << "Result of matrix multiplication:" << endl;
    printMatrix(result);
    
    return 0;
}
