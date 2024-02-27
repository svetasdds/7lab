#include <iostream>
#include <vector>

using namespace std;

int main() {
    int M, N;
    cout << "Enter the number of rows (M): ";
    cin >> M;
    cout << "Enter the number of columns (N): ";
    cin >> N;

    if (M % 2 != 0 || N % 2 != 0) {
        cout << "Both M and N should be even numbers." << endl;
        return 1;
    }

    vector<vector<int>> matrix(M, vector<int>(N));

    // Введення матриці
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }

    // Знаходження останнього стовпця з однаковою кількістю додатних і від'ємних елементів
    int last_column_index = 0;
    bool found = false;

    for (int j = 0; j < N; j++) {
        int positive_count = 0, negative_count = 0;
        for (int i = 0; i < M; i++) {
            if (matrix[i][j] > 0) {
                positive_count++;
            } else if (matrix[i][j] < 0) {
                negative_count++;
            }
        }
        if (positive_count == negative_count && positive_count + negative_count > 0) {
            last_column_index = j + 1;
            found = true;
        }
    }

    if (found) {
        cout << "The last column with equal positive and negative elements is: " << last_column_index << endl;
    } else {
        cout << "There are no columns with equal positive and negative elements." << endl;
    }

    // Поміняти місцями ліву верхню і праву нижню чверть матриці
    for (int i = 0; i < M / 2; i++) {
        for (int j = 0; j < N / 2; j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[i + M / 2][j + N / 2];
            matrix[i + M / 2][j + N / 2] = temp;
        }
    }

    // Виведення зміненої матриці
    cout << "Modified matrix:" << endl;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}