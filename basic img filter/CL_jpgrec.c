#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

int main(int argc, char *argv[])
{
    // Check if the program is executed with exactly one command-line argument
    if (argc != 2)
    {
        printf("Usage: %s IMAGE\n", argv[0]);
        return 1;
    }

    // Open the forensic image file for reading
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("Cannot open the forensic image for reading.\n");
        return 1;
    }

    // Define the block size
    int BLOCK_SIZE = 512;
    typedef uint8_t BYTE;
    BYTE buffd[BLOCK_SIZE];

    int count = 0;
    FILE *recv = NULL;
    while (fread(buffd, 1, BLOCK_SIZE, file) == BLOCK_SIZE)
    {
        if (buffd[0] == 0xff && buffd[1] == 0xd8 && buffd[2] == 0xff && (buffd[3] & 0xf0) == 0xe0)
        {
            if (recv != NULL)
            {
                fclose(recv);
            }

            char namegen[20];
            sprintf(namegen, "%03d.jpg", count);
            recv = fopen(namegen, "wb");
            if (recv == NULL)
            {
                printf("Cannot create the recovered file.\n");
                fclose(file);
                return 1;
            }

            fwrite(buffd, 1, BLOCK_SIZE, recv);
            count++;
        }
        else if (recv != NULL)
        {
            fwrite(buffd, 1, BLOCK_SIZE, recv);
        }
    }

    if (recv != NULL)
    {
        fclose(recv);
    }

    fclose(file);

    printf("Recovered %d JPEG files.\n", count);

    return 0;
}
