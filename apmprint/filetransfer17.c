/*
NAME: ANIRUDH P S
Roll No: CS03
EX NO: 17
DATE: 06-08-2026 

**********File Data Transfer Utility**********

AIM:Write a program that copies the contents of one file into another, using command-line arguments for file names.
    This utility could be used for backup or migration tasks in system administration.
*/

/* **********ALGORITHM**********

Step 1: Start.
Step 2: Define a function palindrome() to check whether a product code is a palindrome.
Step 3: Declare a 2D character array code[20][30] to store the product codes.
Step 4: Read the number of product codes n.
Step 5: Read all the product codes from the user.
Step 6: For each product code, call the palindrome() function.
Step 7: Find the length of the product code using strlen().
Step 8: Compare the characters from the beginning and end of the string.
Step 9: If any pair of characters is different, return 0, indicating that the code is not a palindrome.
Step 10: If all corresponding characters are equal, return 1, indicating that the code is a palindrome.
Step 11: Display each product code and whether it is a Palindrome or Not Palindrome.
Step 12: Stop.

*/

/* **********SOURCE CODE********** */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <source_file> <destination_file>\n", argv[0]);
        return 1;
    }

    FILE *source = fopen(argv[1], "r");
    if (source == NULL) {
        perror("Error opening source file");
        return 1;
    }

    FILE *destination = fopen(argv[2], "w");
    if (destination == NULL) {
        perror("Error opening destination file");
        fclose(source);
        return 1;
    }

    char ch;
    while ((ch = fgetc(source)) != EOF) {
        fputc(ch, destination);
    }

    printf("File data successfully transferred from '%s' to '%s'.\n", argv[1], argv[2]);

    fclose(source);
    fclose(destination);

    return 0;
}

/*  OUTPUT



*/
