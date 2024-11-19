#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Hàm tạo ma trận ngẫu nhiên kích thước n*n
void generate_matrix(int n, int **matrix) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = rand() % 10;  // Giá trị ngẫu nhiên từ 0 đến 9
        }
    }
}

// Hàm nhân 2 ma trận 2 chiều với nhau
void multiply_matrices(int n, int **matrix1, int **matrix2, int **result) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = 0;  // Khởi tạo giá trị ban đầu là 0
            for (int k = 0; k < n; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

// Hàm in ma trận
void print_matrix(int n, int **matrix) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}


int main() {
    int n = 20;  // Kích thước ma trận
    srand(time(0));  // Khởi tạo seed cho hàm rand

    // Cấp phát động cho 3 ma trận
    int **matrix1 = (int **)malloc(n * sizeof(int *));
    int **matrix2 = (int **)malloc(n * sizeof(int *));
    int **result = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        matrix1[i] = (int *)malloc(n * sizeof(int));
        matrix2[i] = (int *)malloc(n * sizeof(int));
        result[i] = (int *)malloc(n * sizeof(int));
    }

    // Tạo ma trận ngẫu nhiên
    generate_matrix(n, matrix1);
    generate_matrix(n, matrix2);

    // // In ra ma trận 1 và ma trận 2
    // printf("Matrix 1:\n");
    // print_matrix(n, matrix1);
    // printf("Matrix 2:\n");
    // print_matrix(n, matrix2);

    // Nhân 2 ma trận
    multiply_matrices(n, matrix1, matrix2, result);

    // In kết quả
    // printf("Resultant Matrix:\n");
    // print_matrix(n, result);

    // Giải phóng bộ nhớ đã cấp phát
    for (int i = 0; i < n; i++) {
        free(matrix1[i]);
        free(matrix2[i]);
        free(result[i]);
    }
    free(matrix1);
    free(matrix2);
    free(result);

    return 0;
}
