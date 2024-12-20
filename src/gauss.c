#include "gauss.h"

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b)
{
    int n = mat->r;
    for (int k = 0; k < n - 1; k++) {
        int max_row = k;
        for (int i = k + 1; i < n; i++) {
            if (fabs(mat->data[i][k]) > fabs(mat->data[max_row][k])) {
                max_row = i;
            }
        }

        if (max_row != k) {
            for (int j = 0; j < mat->c; j++) {
                double temp = mat->data[k][j];
                mat->data[k][j] = mat->data[max_row][j];
                mat->data[max_row][j] = temp;
            }
            double temp_b = b->data[k][0];
            b->data[k][0] = b->data[max_row][0];
            b->data[max_row][0] = temp_b;
        }

        if (mat->data[k][k] == 0) {
            return 1; 
        }

        for (int i = k + 1; i < n; i++) {
            double factor = mat->data[i][k] / mat->data[k][k];
            for (int j = k; j < mat->c; j++) {
                mat->data[i][j] -= factor * mat->data[k][j];
            }
            b->data[i][0] -= factor * b->data[k][0];
        }
    }
    return 0;
}

