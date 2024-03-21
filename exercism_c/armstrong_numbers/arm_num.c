#include "arm_num.h"
#include <stdio.h>
#include <math.h>
#include <string.h>

bool is_armstrong_number(int n) {
    char num_str[20];
    sprintf(num_str, "%d", n);

    int num_len = strlen(num_str);

    int sum = 0, i = n;

    while (i != 0)
    {
        int digit = i % 10;
        sum += pow(digit, num_len);
        i /= 10;
    }

    return sum == n;
}

int main() {
    printf("%d\n", is_armstrong_number(9));
    printf("%d\n", is_armstrong_number(10));
    printf("%d\n", is_armstrong_number(153));
}