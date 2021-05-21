#include <iostream>
using namespace std;

// defining the number of vertices
#define n 4

void printMatrix(int matrix[][n]);

void Warshall(int g[][n]) {
  int matrix[n][n], i, j, k;

  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
      matrix[i][j] = g[i][j];

  // Adding vertices individually
  for (k = 0; k < n; k++) {
    for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
        if (matrix[i][k] + matrix[k][j] < matrix[i][j])
          matrix[i][j] = matrix[i][k] + matrix[k][j];
      }
    }
  }
  printMatrix(matrix);
}

void printMatrix(int matrix[][n]) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (matrix[i][j] == 999)
        printf("%4s", "999");
      else
        printf("%4d", matrix[i][j]);
    }
    printf("\n");
  }
}

int main() {
  int g[n][n] = {{0, 3, 999, 5},
             {2, 0, 999, 4},
             {999, 1, 0, 999},
             {999, 999, 2, 0}};
  Warshall(g);
}
