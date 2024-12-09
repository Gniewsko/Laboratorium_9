#include "backsubst.h"
#include <stdio.h>
/**
 * Zwraca 0 - wsteczne podstawienie zakonczone sukcesem
 * Zwraca 1 - błąd dzielenia przez 0 (element na diagonali = 0)
 * Zwraca 2 - błąd nieprawidłowych rozmiarów macierzy
 */
#include "backsubst.h"

int backsubst(Matrix *x, Matrix *mat, Matrix *b) {
    // Sprawdzanie poprawności wejścia
    if (!x || !mat || !b) {
        fprintf(stderr, "Błąd: Jeden z wskaźników (x, mat, b) jest NULL.\n");
        return 2; // Kod błędu: Nieprawidłowe rozmiary macierzy
    }
    if (mat->r != mat->c || mat->r != b->r || x->r != mat->r || x->c != 1 || b->c != 1) {
        fprintf(stderr, "Błąd: Nieprawidłowe rozmiary macierzy.\n");
        return 2; // Kod błędu: Nieprawidłowe rozmiary macierzy
    }

    int n = mat->r; // Liczba równań (rozmiar macierzy)
    
    // Zerowanie wynikowego wektora x
    for (int i = 0; i < x->r; i++) {
        x->data[i][0] = 0.0;
    }

    // Wykonywanie podstawienia wstecznego
    for (int i = n - 1; i >= 0; i--) {
        double sum = 0.0;
        for (int j = i + 1; j < n; j++) {
            sum += mat->data[i][j] * x->data[j][0];
        }
        if (mat->data[i][i] == 0.0) {
            fprintf(stderr, "Błąd: Element diagonalny mat[%d][%d] wynosi 0.0.\n", i, i);
            return 1; // Kod błędu: Dzielenie przez 0
        }
        x->data[i][0] = (b->data[i][0] - sum) / mat->data[i][i];
    }

    return 0; // Sukces
}




