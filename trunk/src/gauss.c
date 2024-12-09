#include "gauss.h"

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */

int eliminate(Matrix *mat, Matrix *b) {
    int i, j, k;
    int n = mat->r;

    for (k = 0; k < n; k++) {
        if (mat->data[k][k] == 0.0) {
            return 1; // Dzielenie przez zero
        }

        for (i = k + 1; i < n; i++) {
            double factor = mat->data[i][k] / mat->data[k][k];
            for (j = k; j < n; j++) {
                mat->data[i][j] -= factor * mat->data[k][j];
            }
            b->data[i][0] -= factor * b->data[k][0];
        }
    }

		return 0;
}

