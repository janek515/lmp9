#include "gauss.h"
#include <math.h>

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b)
{
    int n = mat->r;
    for (int k = 0; k < n - 1; k++)
    {
        int iMaxAbs = k;
        int maxAbs = fabs(mat->data[k][k]);
        for (int i = k + 1; i < n; i++)
        {
            int curAbs = fabs(mat->data[i][k]);
            if (curAbs > maxAbs)
            {
                maxAbs = curAbs;
                iMaxAbs = i;
            }
        }

        if (iMaxAbs != k)
        {
            double *temp = mat->data[k];
            mat->data[k] = mat->data[iMaxAbs];
            mat->data[iMaxAbs] = temp;
        }

        if (mat->data[k][k] == 0)
        {
            return 1;
        }
        for (int i = k + 1; i < n; i++)
        {
            double factor = mat->data[i][k] / mat->data[k][k];
            for (int j = k; j < mat->c; j++)
            {
                mat->data[i][j] -= factor * mat->data[k][j];
            }
            b->data[i][0] -= factor * b->data[k][0];
        }
    }
    return 0;
}
