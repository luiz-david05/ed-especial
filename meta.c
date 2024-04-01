#include <stdio.h>

int main() {
    float r1, r2;
    printf("meta 2023 / resultado 2023: ");
    scanf("%f %f", &r1, &r2);

    printf("meta = %0.f / %0.f = %.2f porcento", r1, r2, r2 / r1 * 100);

    return 0;
}