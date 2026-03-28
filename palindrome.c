/*
 * palindrome.c
 *
 * Program: Palindrome Checker
 * Description: Reads a string or number from the user and determines
 *              whether it reads the same forwards and backwards (a palindrome).
 *              Examples of palindromes: "racecar", "madam", "12321".
 */

#include <stdio.h>   /* Standard I/O — printf(), scanf() */
#include <string.h>  /* String utilities — strlen() */
#include <ctype.h>   /* Character utilities — tolower() */

int main() {
    /* Buffer to hold the user's input — supports up to 39 characters + null terminator */
    char input_value[40];

    /* ── Input ──────────────────────────────────────────────────────────── */

    /* Prompt the user and read a single word/number (no spaces) */
    printf("Enter a string or number: ");
    scanf("%s", input_value);

    /* ── Normalise to lowercase ─────────────────────────────────────────── */

    /*
     * Convert every character to lowercase so the check is case-insensitive.
     * e.g. "Racecar" → "racecar", "MadAm" → "madam"
     * tolower() only affects alphabetic characters; digits are left unchanged.
     */
    for (int j = 0; input_value[j] != '\0'; j++) {
        input_value[j] = (char)tolower((unsigned char)input_value[j]);
    }

    /* ── Setup ──────────────────────────────────────────────────────────── */

    /* Calculate and store the length of the input string once,
     * so we don't call strlen() on every loop iteration */
    int len = strlen(input_value);

    /* ── Palindrome check ───────────────────────────────────────────────── */

    /*
     * A palindrome mirrors around its centre.
     * Strategy: compare characters from the outside inward.
     *   - Left pointer  → starts at index 0       (first character)
     *   - Right pointer → starts at index len-1   (last character)
     * We only need to iterate up to the midpoint (len / 2).
     * If the string has an odd length the middle character is always
     * equal to itself, so it does not need to be checked.
     */
    for (int i = 0; i < len / 2; i++) {
        /*
         * Compare the character at position i (from the left)
         * with its mirror at position (len - 1 - i) (from the right).
         * Example for "racecar" (len = 7):
         *   i=0 → input[0]='r' vs input[6]='r'  ✓
         *   i=1 → input[1]='a' vs input[5]='a'  ✓
         *   i=2 → input[2]='c' vs input[4]='c'  ✓
         *   (i=3 is the centre 'e', loop stops before it)
         */
        if (input_value[i] != input_value[len - 1 - i]) {
            /* Mismatch found — the string is NOT a palindrome.
             * Return immediately; no need to check further. */
            printf("%s is not a Palindrome!!\n", input_value);
            return 0;
        }
    }

    /* ── Result ─────────────────────────────────────────────────────────── */

    /* If the loop completed without finding any mismatch,
     * every character matched its mirror → it IS a palindrome. */
    printf("%s is a Palindrome!!\n", input_value);

    /* Return 0 to the OS to signal successful program termination */
    return 0;
}
