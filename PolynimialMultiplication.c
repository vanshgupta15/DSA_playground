#include <stdio.h>

typedef struct {
    int coeff;
    int exp;
} Term;

// Convert full polynomial to sparse form
int toSparse(int coeffs[], int degree, Term sparse[]) {
    int k = 0;
    for (int i = 0; i <= degree; i++) {
        if (coeffs[i] != 0) {
            sparse[k].coeff = coeffs[i];
            sparse[k].exp = degree - i;
            k++;
        }
    }
    return k;
}

// Multiply two sparse polynomials
int multiplyPoly(Term A[], int sizeA, Term B[], int sizeB, Term result[]) {
    Term temp[200];
    int k = 0;

    // Multiply each term of A with each term of B
    for (int i = 0; i < sizeA; i++) {
        for (int j = 0; j < sizeB; j++) {
            temp[k].coeff = A[i].coeff * B[j].coeff;
            temp[k].exp = A[i].exp + B[j].exp;
            k++;
        }
    }

    // Combine like terms
    int finalSize = 0;
    for (int i = 0; i < k; i++) {
        int found = 0;
        for (int j = 0; j < finalSize; j++) {
            if (result[j].exp == temp[i].exp) {
                result[j].coeff += temp[i].coeff;
                found = 1;
                break;
            }
        }
        if (!found) {
            result[finalSize++] = temp[i];
        }
    }

    return finalSize;
}

// Display polynomial
void printPoly(Term poly[], int size) {
    for (int i = 0; i < size; i++) {
        if (poly[i].coeff == 0) continue;
        printf("%d", poly[i].coeff);
        if (poly[i].exp != 0)
            printf("x^%d", poly[i].exp);
        if (i != size - 1)
            printf(" + ");
    }
    printf("\n");
}

int main() {
    int deg1, deg2;
    int coeffs1[50], coeffs2[50];
    Term poly1[50], poly2[50], result[200];

    printf("Enter highest degree of first polynomial: ");
    scanf("%d", &deg1);
    printf("Enter coefficients from x^%d to x^0:\n", deg1);
    for (int i = 0; i <= deg1; i++)
        scanf("%d", &coeffs1[i]);

    printf("Enter highest degree of second polynomial: ");
    scanf("%d", &deg2);
    printf("Enter coefficients from x^%d to x^0:\n", deg2);
    for (int i = 0; i <= deg2; i++)
        scanf("%d", &coeffs2[i]);

    int size1 = toSparse(coeffs1, deg1, poly1);
    int size2 = toSparse(coeffs2, deg2, poly2);

    int resultSize = multiplyPoly(poly1, size1, poly2, size2, result);

    printf("\nPolynomial 1: ");
    printPoly(poly1, size1);

    printf("Polynomial 2: ");
    printPoly(poly2, size2);

    printf("Product: ");
    printPoly(result, resultSize);

    return 0;
}