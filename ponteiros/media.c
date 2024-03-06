#include <stdio.h>

void media(double a, double b, double* m) {
    *m = (float)(a + b) / 2;
}

int main() {
    double a, b, m;
    printf("Digite dois(2) valores: ");
    // formato double %lf
    scanf("%lf %lf", &a, &b);

    media(a, b, &m);

    printf("Media = %.1lf\n", m);

    return 0;
}