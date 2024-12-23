#include <stdio.h>

// Function to add 3 integers, passed by reference
void add(int *a, int *b, int *c, int *result) {
    *result = *a + *b + *c;  // Dereference the pointers to get the values and add them
}

int main() {
    int num1, num2, num3, sum;

    // Ask the user for input
    printf("Enter three integers: ");
    scanf("%d %d %d", &num1, &num2, &num3);

    // Call the add function
    add(&num1, &num2, &num3, &sum);  // Pass the addresses of num1, num2, num3, and sum

    // Print the result
    printf("The sum of %d, %d, and %d is: %d\n", num1, num2, num3, sum);

    return 0;
}
