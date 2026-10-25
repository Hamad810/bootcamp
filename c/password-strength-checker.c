#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    char password[25];
    int hasUpper = 0, hasLower = 0, hasDigit = 0, hasSymbol = 0;
    int i;

    printf("Enter your password: ");
    scanf("%s", password);   

    if (strlen(password) <= 8)
    {
        printf("Error: Password must be more than 8 characters.\n");
        return 1;
    }

    for (i = 0; password[i] != '\0'; i++)
    {
        if (isupper(password[i]))
            hasUpper = 1;
        else if (islower(password[i]))
            hasLower = 1;
        else if (isdigit(password[i]))
            hasDigit = 1;
        else
            hasSymbol = 1;   
    }

    if (!hasUpper)  printf("Error: Must contain an uppercase letter (A-Z).\n");
    if (!hasLower)  printf("Error: Must contain a lowercase letter (a-z).\n");
    if (!hasDigit)  printf("Error: Must contain a number (0-9).\n");
    if (!hasSymbol) printf("Error: Must contain a symbol (e.g. !@#$%%^&*).\n");

    if (hasUpper && hasLower && hasDigit && hasSymbol)
        printf("Strong password \n");
    else
        printf("Weak password \n");

    return 0;
}
