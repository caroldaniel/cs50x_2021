#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <cs50.h>

// Define struct BYTE
typedef uint8_t BYTE;

const int BLOCK_SIZE = 512;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }
    
    // Open file to recover from
    FILE *file = fopen(argv[1], "r");
    
    // Check if file is readable
    if (file == NULL)
    {
        printf("Could not open file.\n");
        return 2;
    }
    
    // Initialize buffer for read bytes in file
    BYTE buffer[BLOCK_SIZE];
    
    // Initialize counter variable for number of images recovered
    int file_counter = 0;
    
    // Initialize a bool for whether jpeg was found or not
    bool image_found = false;
    
    // Initialize pointer to the output file
    FILE *image = NULL;
    
    // Initialize variable to store JPEGs name
    char filename[8];
    
    int buffer_size = BLOCK_SIZE * sizeof(BYTE);

    // Repeat until end of file
    while (fread(&buffer, buffer_size, 1, file) == 1)
    {
        // Check the first 4 bytes for JPEG footprint
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] >= 0xe0 && buffer[3] <= 0xef))
        {
            // If it starts on a new JPEG, close previous image
            if (image_found == true)
            {
                fclose(image);
            }
            else
            {
                image_found = true;
            }
            
            // Open, name and write an output file
            sprintf(filename, "%03i.jpg", file_counter); 
            image = fopen(filename, "w");
            file_counter++;
        }
        
        if (image_found == true)
        {
            fwrite(&buffer, buffer_size, 1, image);
        }
    }
    
    // Close images after done
    fclose(file);
    fclose(image);
    
    return 0;    
}