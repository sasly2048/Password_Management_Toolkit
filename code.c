#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

void Strength_Check(const char password[]) 
{
    int score = 0;
    int len = strlen(password);
    
    int upper = 0, lower = 0, digit = 0, special = 0;

    if (len >= 8) 
    {
        score++;
    }

    for (int i = 0; i < len; i++) 
    {
        if (isupper(password[i]) && !upper) 
        {
            score++;
            upper = 1;
        } 
        else if (islower(password[i]) && !lower) 
        {
            score++;
            lower = 1; 
        } 
        else if (isdigit(password[i]) && !digit) 
        {
            score++;
            digit = 1; 
        }
        else if (!isalnum(password[i]) && !special) 
        {
            score++;
            special = 1; 
        }
    }
    
    printf("================================================================\n");
    printf("Password Strength: ");
    switch (score) 
    {
        case 0:
        case 1: printf("Very Weak\n"); 
        break;
        case 2: printf("Weak\n"); 
        break;
        case 3: printf("Moderate\n"); 
        break;
        case 4: printf("Strong\n"); 
        break;
        case 5: printf("Very Strong\n"); 
        break;
    }

    if (score < 5) 
    {
        printf("Suggestions to improve:\n");
        if (len < 8)  printf(" -> Should have at least 8 characters\n");
        if (!upper)   printf(" -> Should have at least 1 Uppercase letter\n");
        if (!lower)   printf(" -> Should have at least 1 Lowercase letter\n");
        if (!digit)   printf(" -> Should have at least 1 Digit\n");
        if (!special) printf(" -> Should have at least 1 Special Character\n");
    } 
    else 
    {
        printf("All conditions satisfied!\n");
    }
    printf("================================================================\n");
}

void generatePassword() 
{
    int length;
    printf("Enter desired password length (minimum 8): ");
    scanf("%d", &length);

    if (length < 8) 
    {
        printf("Length is too short. Setting to 8.\n");
        length = 8;
    }

    char password[length + 1]; 

    srand(time(NULL));

    char digits[]    = "0123456789";
    char uppercase[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char lowercase[] = "abcdefghijklmnopqrstuvwxyz";
    char symbols[]   = "!@#$^&%*?~()";

    int digits_len = strlen(digits);
    int upper_len = strlen(uppercase);
    int lower_len = strlen(lowercase);
    int symbols_len = strlen(symbols);

    // Ensure at least one of each type
    password[0] = digits[rand() % digits_len];
    password[1] = uppercase[rand() % upper_len];
    password[2] = lowercase[rand() % lower_len];
    password[3] = symbols[rand() % symbols_len];

    // Fill the remaining characters randomly
    for (int i = 4; i < length; i++) 
    {
        int char_type = rand() % 4;

        if (char_type == 0)
            password[i] = digits[rand() % digits_len];
        else if (char_type == 1)
            password[i] = uppercase[rand() % upper_len];
        else if (char_type == 2)
            password[i] = lowercase[rand() % lower_len];
        else
            password[i] = symbols[rand() % symbols_len];
    }

    // Shuffle the password to randomize character positions
    for (int i = 0; i < length; i++) 
    {
        int j = rand() % length;
        char temp = password[i];
        password[i] = password[j];
        password[j] = temp;
    }

    password[length] = '\0';

    printf("\nGenerated Password: %s\n\n", password);
    Strength_Check(password);
}

int main() 
{
    int choice;
    char password[100];

    printf("Select from the following:\n");
    printf("1. Generate a Random Password & Check its Strength\n");
    printf("2. Check the Strength of your own Password\n\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1) 
    {
        generatePassword();
    } 
    else if (choice == 2) 
    {
        printf("\nEnter your password: ");
        scanf("%99s", password);
        printf("\n");
        Strength_Check(password);
    }
    else 
    {
        printf("INVALID INPUT\n");
    }

    printf("\n-----------------------------END-----------------------------\n");
    return 0;
}