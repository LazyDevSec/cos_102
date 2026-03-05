#include <stdio.h>

int main() {
    float a;
    float b;
    float c;

    printf("Enter the first angle: ");
    scanf("%f", &a);
    printf("Enter the second angle: ");
    scanf("%f", &b);

    // Calculate the third angle first for clarity
    c = 180 - a - b;

    // Check if the sum is valid (angles must be positive and sum to 180)
    // Note: a + b >= 180 would mean the third angle is 0 or negative
    if (a <= 0 || b <= 0 || c <= 0 || (a + b + c) != 180) {
        printf("Sorry, this is not a triangle!!\n");
        printf("A = %.2f, B = %.2f, C = %.2f\n", a, b, c);
    }
    else if (a == 90 || b == 90 || c == 90) {
        printf("This is a right angle triangle!!\n");
        printf("A = %.2f, B = %.2f, C = %.2f\n", a, b, c);
    }
    else {
        printf("This is a valid triangle, but NOT a right angle triangle!!\n");
        printf("A = %.2f, B = %.2f, C = %.2f\n", a, b, c);
    }

    return 0;
}