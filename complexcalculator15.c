/*
NAME: ANIRUDH P S
Roll No: CS03
DATE: 

**********Complex Number Calculator for Engineering Simulations**********

AIM: Develop a program that allows the user to input two complex numbers and calculates their sum and 
     difference. This program could be applied in simulations for electrical engineering or physics problems.
*/

/* **********ALGORITHM**********

Step 1: Start.
Step 2: Define a structure Complex with real and imag members.
Step 3: Declare four variables c1, c2, sum, and diff of type Complex.
Step 4: Read the real and imaginary parts of the first complex number.
Step 5: Read the real and imaginary parts of the second complex number.
Step 6: Calculate the real and imaginary parts of the sum.
Step 7: Calculate the real and imaginary parts of the difference.
Step 8: Display the sum of the two complex numbers.
Step 9: Display the difference of the two complex numbers.
Step 10: Stop.

*/

/* **********SOURCE CODE********** */

#include <stdio.h>

struct Complex {
    float real;
    float imag;
};

int main() {
    struct Complex c1, c2, sum, diff;

    printf("Enter real and imaginary parts of first complex number: ");
    scanf("%f %f", &c1.real, &c1.imag);

    printf("Enter real and imaginary parts of second complex number: ");
    scanf("%f %f", &c2.real, &c2.imag);

    sum.real = c1.real + c2.real;
    sum.imag = c1.imag + c2.imag;

    diff.real = c1.real - c2.real;
    diff.imag = c1.imag - c2.imag;

    printf("\nSum = %.2f + %.2fi", sum.real, sum.imag);
    printf("\nDifference = %.2f + %.2fi", diff.real, diff.imag);

    return 0;
}

/* **********OUTPUT**********

    Enter real and imaginary parts of first complex number: 5 3
Enter real and imaginary parts of second complex number: 2 1

Sum = 7.00 + 4.00i
Difference = 3.00 + 2.00i

*/    
