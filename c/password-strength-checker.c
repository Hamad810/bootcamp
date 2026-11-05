
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void checkPassword(char password[])
{
    int length = strlen(password);
    int hasUpper = 0, hasLower = 0, hasDigit = 0, hasSymbol = 0;
    int score = 0;
    int i;

    printf("\nPassword Length: %d\n", length);

    if (length >= 8)
    {
        printf("Length (at least 8 characters): Yes\n");
        score++;
    }
    else
    {
        printf("Length (at least 8 characters): No\n");
    }

    for (i = 0; password[i] != '\0'; i++)
    {
        unsigned char ch = (unsigned char)password[i];

        if (isupper(ch))
            hasUpper = 1;
        else if (islower(ch))
            hasLower = 1;
        else if (isdigit(ch))
            hasDigit = 1;
        else if (ispunct(ch))
            hasSymbol = 1;
    }

    if (hasUpper)
    {
        printf("Uppercase letter: Yes\n");
        score++;
    }
    else
        printf("Uppercase letter: No\n");

    if (hasLower)
    {
        printf("Lowercase letter: Yes\n");
        score++;
    }
    else
        printf("Lowercase letter: No\n");

    if (hasDigit)
    {
        printf("Number: Yes\n");
        score++;
    }
    else
        printf("Number: No\n");

    if (hasSymbol)
    {
        printf("Symbol: Yes\n");
        score++;
    }
    else
        printf("Symbol: No\n");

    printf("Total Score: %d/5\n", score);

    if (length < 8 || score <= 2)
        printf("Password Strength: Weak\n");
    else if (score <= 4)
        printf("Password Strength: Acceptable\n");
    else
        printf("Password Strength: Strong\n");
}

int main(void)
{
    char password[100];

    printf("Enter your password: ");

    if (scanf("%99s", password) != 1)
    {
        printf("Invalid input.\n");
        return 1;
    }

    checkPassword(password);

    return 0;
}
