#include <cblas.h>
#include <stdlib.h>
#include <time.h>

void init(double* matrix, int row, int column) {
  for (int j = 0; j < column; j++) {
    for (int i = 0; i < row; i++) {
      matrix[j * row + i] = ((double)rand()) / RAND_MAX;
    }
  }
}

int main(int argc, char* argv[]) {
  int rowsA, colsB, common;
  int i, j, k;
  clock_t start, end;
  double cpu_time_used;

  if (argc != 4) {
    printf("3 arguments needed.\n");
    return 1;
  } else {
    rowsA = atoi(argv[1]);
    colsB = atoi(argv[2]);
    common = atoi(argv[3]);
  }

  double A[rowsA * common];
  double B[common * colsB];
  double C[rowsA * colsB];

  srand(time(NULL));

  printf("Run,Time\n");

  for (i = 0; i < 100; i++) {
    init(A, rowsA, common);
    init(B, common, colsB);
    start = clock();
    cblas_dgemm(CblasColMajor, CblasNoTrans, CblasNoTrans, rowsA, colsB, common,
                1.0, A, rowsA, B, common, 0.0, C, rowsA);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("%u,%f\n", i, cpu_time_used);
  }

  return 0;
}