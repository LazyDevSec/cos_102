#include <stdio.h>
#include <string.h>

int main() {
    char input_value[40];
    printf("Enter a string or number: ");
    scanf("%s", input_value);

    int len = strlen(input_value);

    for (int i = 0; i < len / 2; i++) { // You only need to check halfway
        if (input_value[i] != input_value[len - 1 - i]) {
            printf("%s is not a Palindrome!!\n", input_value);
            return 0; // Found a mismatch, exit immediately
        }
    }

    // If the loop finishes without returning, it must be a palindrome
    printf("%s is a Palindrome!!\n", input_value);
    return 0;
}
