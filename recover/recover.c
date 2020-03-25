#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;
int jpg_count = 0;
FILE *open_file(int jpg);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "r"); // Opens the card file.
    FILE *output_file = NULL;

    while (feof(file) == 0)
    {
        BYTE *buffer = malloc(512); // Allocates memory for the block.
        int no_read = fread(buffer, 1, 512, file); // Reads the file.
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0) // If start of a JPEG.
        {
            if (jpg_count == 0) // If first JPEG found.
            {
                output_file = open_file(jpg_count);
                jpg_count++;
                fwrite(buffer, no_read, 1, output_file);
                free(buffer);
                continue;
            }
            else
            {
                fclose(output_file);
                output_file = open_file(jpg_count);
                jpg_count++;
                fwrite(buffer, no_read, 1, output_file);
                free(buffer);
                continue;
            }
        }
        else // If a block does not start with the signature.
        {
            if (jpg_count == 0) // If no JPEG yet.
            {
                continue;
            }
            else
            {
                fwrite(buffer, no_read, 1, output_file);
                free(buffer);
                continue;
            }
        }
    }
    return 0;
}



FILE *open_file(int jpg)
{
    char *output_name = malloc(7 * sizeof(char));
    sprintf(output_name, "%03i.jpg", jpg);
    FILE *output_file = fopen(output_name, "w");
    free(output_name);
    return (output_file);
}