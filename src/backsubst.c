#include "backsubst.h"
#include <math.h>

/**
 * Zwraca 0 - wsteczne podstawienie zakonczone sukcesem
 * Zwraca 1 - błąd dzielenia przez 0 (element na diagonali = 0)
 * Zwraca 2 - błąd nieprawidłowych rozmiarów macierzy
 */
int backsubst(Matrix *x, Matrix *mat, Matrix *b)
{
	if (x->r != mat->c || b->r != mat->r || mat->r != mat->c)
	{
		return 2;
	}

	for (int i = x->r - 1; i >= 0; i--)
	{
		double *row = mat->data[i];
		double x_n = b->data[i][0];
		if (fabs(row[i]) < __FLT_EPSILON__)
		{
			return 1;
		}
		for (int j = mat->c - 1; j > i; j--)
		{
			x_n -= row[j] * x->data[j][0];
		}
		x_n /= row[i];
		x->data[i][0] = x_n;
	}

	return 0;
}
