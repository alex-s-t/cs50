#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE; /* ensure standard byte allocation */

#define CMD_ARGUMENTS 2

#define JPEG_BLOCK 512
#define MAX_RECOVERY 10000 /* maximum number of jpeg files to recover */
#define MAX_RECOVERY_NAME 10 /* limit for file names, must be in sync with MAX_RECOVERY */

#define OPEN_FILE_ERROR 2
#define OPEN_OUTFILE_ERROR 3
#define FAILURE 1
#define SUCCESS 0


/* where it all happens */
int main(int argc, char *argv[])
{
    if (argc != CMD_ARGUMENTS) {
        fprintf(stderr, "Usage: ./recover diskimage\n");
        return FAILURE;
    }

    // open the card file
    FILE *inptr = fopen(argv[1], "r");
    if (inptr == NULL) {
        fprintf(stderr, "Could not open %s\n", argv[1]);
        return OPEN_FILE_ERROR;
    }

    // buffer array to store blocks
    BYTE buffer[JPEG_BLOCK];
    // namer/tracker
    int jpg_count = 0;
    char name[MAX_RECOVERY_NAME];
    // declare file pointer
    FILE *outptr = NULL;

    // commence iteration through card image
    while ((fread(&buffer, JPEG_BLOCK, 1, inptr) == 1) && jpg_count < MAX_RECOVERY) {
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
            return OPEN_OUTFILE_ERROR;
        }
    }

    if (outptr != NULL) {
        // write the bytes of the jpeg
        fwrite(buffer, JPEG_BLOCK, 1, outptr);
        }
    }
    /* end while loop */

    /* close files */
    fclose(outptr);
    fclose(inptr);

    /* files should be recovered! */
    return SUCCESS;
}