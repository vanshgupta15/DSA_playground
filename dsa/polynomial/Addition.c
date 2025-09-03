#include <stdio.h>

int main() {
    int n1, n2;

    // Input polynomial 1
    printf("Enter the highest power of the 1st polynomial: ");
    scanf("%d", &n1);
    int A[n1+1];
    for (int i = 0; i <= n1; i++) {
        printf("Enter coefficient for x^%d: ", i);
        scanf("%d", &A[i]);
    }

    // Input polynomial 2
    printf("\nEnter the highest power of the 2nd polynomial: ");
    scanf("%d", &n2);
    int B[n2+1];
    for (int i = 0; i <= n2; i++) {
        printf("Enter coefficient for x^%d: ", i);
        scanf("%d", &B[i]);
    }

    // Decide size of result
    int n = (n1 > n2 ? n1 : n2);
    int C[n+1];

    // Initialize all elements of result with 0
    for (int i = 0; i <= n; i++) {
        C[i] = 0;
    }

    // Copy coefficients of A into C
    for (int i = 0; i <= n1; i++) {
        C[i] = A[i];
    }

    // Add coefficients of B into C
    for (int i = 0; i <= n2; i++) {
        C[i] = C[i] + B[i];
    }

    // Print Polynomial 1
    printf("\nPolynomial 1: ");
    for (int j = n1; j >= 0; j--) {
        if (A[j] != 0) {
            printf("%d", A[j]);
            if (j > 0) printf("x^%d", j);
            if (j > 0 && A[j-1] >= 0) printf(" + ");
        }
    }

    // Print Polynomial 2
    printf("\nPolynomial 2: ");
    for (int j = n2; j >= 0; j--) {
        if (B[j] != 0) {
            printf("%d", B[j]);
            if (j > 0) printf("x^%d", j);
            if (j > 0 && B[j-1] >= 0) printf(" + ");
        }
    }

    // Print Result Polynomial (C)
    printf("\nSum: ");
    for (int j = n; j >= 0; j--) {
        if (C[j] != 0) {
            printf("%d", C[j]);
            if (j > 0) printf("x^%d", j);
            if (j > 0 && C[j-1] >= 0) printf(" + ");
        }
    }

    return 0;
}
