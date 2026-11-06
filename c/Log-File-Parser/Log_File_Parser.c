#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    FILE *file;
    char line[512];
    char *keyword;
    int lineNumber = 0;
    int alertCount = 0;

    if (argc != 3)
    {
        printf("Usage: LogParser.exe <logfile> <keyword>\n");
        return 1;
    }

    keyword = argv[2];

    file = fopen(argv[1], "r");

    if (file == NULL)
    {
        printf("Error: Cannot open log file.\n");
        return 1;
    }

    printf("Searching for: %s\n", keyword);
    printf("----------------------------------------\n");

    while (fgets(line, sizeof(line), file) != NULL)
    {
        lineNumber++;

        if (strstr(line, keyword) != NULL)
        {
            alertCount++;
            printf("Alert %d | Line %d: %s", alertCount, lineNumber, line);

            if (strchr(line, '\n') == NULL)
                printf("\n");
        }
    }

    if (ferror(file))
    {
        printf("\nError: Failed to read log file.\n");
        fclose(file);
        return 1;
    }

    printf("\n----------------------------------------\n");
    printf("Search completed.\n");
    printf("Keyword: %s\n", keyword);
    printf("Total suspicious records: %d\n", alertCount);

    fclose(file);

    return 0;
}
