/*
 * right_angle.c
 *
 * Program: Right Angle Triangle Checker
 * Description: Reads two angles from the user, derives the third,
 *              then classifies the triangle as invalid, right-angled,
 *              or a valid non-right-angle triangle.
 */

#include <stdio.h>  /* Standard I/O library for printf() and scanf() */

int main() {
    /* Declare three float variables to hold the three angles of the triangle */
    float a;  /* First angle  — entered by the user */
    float b;  /* Second angle — entered by the user */
    float c;  /* Third angle  — derived from a and b  */

    /* ── Input ─────────────────────────────────────────────────────────── */

    /* Prompt the user and read the first angle */
    printf("Enter the first angle: ");
    scanf("%f", &a);

    /* Prompt the user and read the second angle */
    printf("Enter the second angle: ");
    scanf("%f", &b);

    /* ── Derive the third angle ─────────────────────────────────────────── */

    /*
     * The interior angles of any triangle always sum to 180°.
     * So the third angle is simply:  c = 180 - a - b
     */
    c = 180 - a - b;

    /* ── Validation & classification ────────────────────────────────────── */

    /*
     * A valid triangle requires all three angles to be strictly positive
     * (> 0) and their sum to equal exactly 180°.
     * If any angle is zero or negative the shape is not a triangle.
     *
     * Note: because c is derived arithmetically, (a + b + c) will always
     * equal 180 in exact arithmetic. The individual positivity checks are
     * the meaningful guards here.
     */
    if (a <= 0 || b <= 0 || c <= 0 || (a + b + c) != 180) {
        /* At least one angle is non-positive → invalid triangle */
        printf("Sorry, this is not a triangle!!\n");
        printf("A = %.2f, B = %.2f, C = %.2f\n", a, b, c);
    }
    /*
     * A right-angle triangle has exactly one 90° interior angle.
     * We check all three angles because the user only supplied two of them.
     */
    else if (a == 90 || b == 90 || c == 90) {
        printf("This is a right angle triangle!!\n");
        printf("A = %.2f, B = %.2f, C = %.2f\n", a, b, c);
    }
    else {
        /* All angles are positive, sum is 180°, but none is exactly 90° */
        printf("This is a valid triangle, but NOT a right angle triangle!!\n");
        printf("A = %.2f, B = %.2f, C = %.2f\n", a, b, c);
    }

    /* Return 0 to the OS to signal successful program termination */
    return 0;
}