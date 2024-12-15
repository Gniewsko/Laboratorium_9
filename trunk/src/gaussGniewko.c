#include "gauss.h"

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b)
{
    int n = mat->r; // Liczba wierszy macierzy
    int m = mat->c; // Liczba kolumn macierzy

    for (int ko = 0; ko < m; ko++) 
	{
        // Znajdowanie wiersza z maksymalną wartością w kolumnie ko
        int maxRow = ko;
        for (int i = ko; i < n; i++) {
            if (fabs(mat->data[i][ko]) > fabs(mat->data[maxRow][ko])) 
			{
                maxRow = i;
            }
        }

        // Zamiana wierszy w macierzy mat
        if (maxRow != ko) 
		{
            for (int j = 0; j < m; j++) 
			{
                double temp = mat->data[ko][j];
                mat->data[ko][j] = mat->data[maxRow][j];
                mat->data[maxRow][j] = temp;
            }

            // Zamiana wierszy w macierzy b
            double temp = b->data[ko][0];
            b->data[ko][0] = b->data[maxRow][0];
            b->data[maxRow][0] = temp;
        }

        // Sprawdzanie dzielenia przez 0
        if (fabs(mat->data[ko][ko]) < 1e-10) 
		{
            return 1; // Macierz osobliwa
        }

        // Eliminacja Gaussa
        for (int i = ko + 1; i < n; i++) 
		{
            double factor = mat->data[i][ko] / mat->data[ko][ko];

            for (int j = ko; j < m; j++) 
			{
                mat->data[i][j] -= factor * mat->data[ko][j];
            }

            b->data[i][0] -= factor * b->data[ko][0];
        }
    }

    return 0; // Eliminacja zakończona sukcesem
}