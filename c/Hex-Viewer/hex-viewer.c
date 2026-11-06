#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *file;
    unsigned char buffer[16];
    size_t bytesRead;
    size_t i;
    unsigned long offset = 0;

    if (argc != 2)
    {
        printf("Usage: HexViewer.exe <filename>\n");
        return 1;
    }

    file = fopen(argv[1], "rb");

    if (file == NULL)
    {
        printf("Error: Cannot open file.\n");
        return 1;
    }

    printf("Offset     Hexadecimal                                      ASCII\n");
    printf("--------------------------------------------------------------------------\n");

    while ((bytesRead = fread(buffer, 1, 16, file)) > 0)
    {
        printf("%08lX   ", offset);

        for (i = 0; i < 16; i++)
        {
            if (i < bytesRead)
                printf("%02X ", buffer[i]);
            else
                printf("   ");
        }

        printf(" ");

        for (i = 0; i < bytesRead; i++)
        {
            if (buffer[i] >= 32 && buffer[i] <= 126)
                printf("%c", buffer[i]);
            else
                printf(".");
        }

        printf("\n");
        offset += bytesRead;
    }

    if (ferror(file))
    {
        printf("Error: Failed to read file.\n");
        fclose(file);
        return 1;
    }

    fclose(file);

    return 0;
}
