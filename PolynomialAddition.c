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
            sparse[k].exp = degree - i; // highest degree first
            k++;
        }
    }
    return k;
}

// Add two sparse polynomials
int addPoly(Term A[], int sizeA, Term B[], int sizeB, Term result[]) {
    int i = 0, j = 0, k = 0;

    while (i < sizeA && j < sizeB) {
        if (A[i].exp == B[j].exp) {
            int sum = A[i].coeff + B[j].coeff;
            if (sum != 0) {
                result[k].coeff = sum;
                result[k].exp = A[i].exp;
                k++;
            }
            i++; j++;
        } else if (A[i].exp > B[j].exp) {
            result[k++] = A[i++];
        } else {
            result[k++] = B[j++];
        }
    }

    while (i < sizeA) result[k++] = A[i++];
    while (j < sizeB) result[k++] = B[j++];

    return k;
}

// Display polynomial
void printPoly(Term poly[], int size) {
    for (int i = 0; i < size; i++) {
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
    Term poly1[50], poly2[50], result[100];

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

    int resultSize = addPoly(poly1, size1, poly2, size2, result);

    printf("\nPolynomial 1: ");
    printPoly(poly1, size1);

    printf("Polynomial 2: ");
    printPoly(poly2, size2);

    printf("Sum: ");
    printPoly(result, resultSize);

    return 0;
}