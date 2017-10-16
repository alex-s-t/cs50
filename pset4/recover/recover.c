#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[]) 
{
    if (argc != 2) {
        fprintf(stderr, "Usage: ./recover diskimage");
        return 1;
    }
    
    // open the card file
    FILE *inptr = fopen(argv[1], "r");
    if (inptr == NULL) {
        fprintf(stderr, "Could not open %s\n", argv[1]);
        return 2;
    }
    
    // buffer array to store blocks
    BYTE buffer[512];
    // namer/tracker
    int jpg_count = 0;
    char name[8];
    // declare file pointer
    FILE *outptr = NULL;    

    // commence iteration through card image
    while (fread(&buffer, 512, 1, inptr) == 1) {
    // read file (struct, size of element, number of elements to read, file pointer)

    // if it's a jpeg header...
    if ((buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)) {
        // close previous jpeg file if open
        if (outptr != NULL) {
            fclose(outptr);
        }
        // create new filename
        sprintf(name, "%03i.jpg", jpg_count); 
        
        jpg_count += 1;

        // open a new jpeg file
        outptr = fopen(name, "w");
        if (outptr == NULL) {
            fprintf(stderr, "Could not open new outfile %s\n", name);
            return 3;
        }
        }
    
    if (outptr != NULL) {
        // write the bytes of the jpeg
        fwrite(buffer, 512, 1, outptr);
        }
    
    }
    // end while loop
    
    // close files
    fclose(outptr);

    fclose(inptr);
    
    return 0;
}