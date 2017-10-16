/**
 * Copies a BMP piece by piece, just because.
 */
       
#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        fprintf(stderr, "Usage: ./resize n infile outfile\n");
        return 1;
    }

    // remember filenames
    char *infile = argv[2];
    char *outfile = argv[3];
    
    // remember scaling factor
    int scaling_factor = atoi(argv[1]);

    // open input file 
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);
    BITMAPFILEHEADER out_file_head = bf;

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);
    BITMAPINFOHEADER out_info_head = bi;

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || 
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }



    // scale info in the out file INFO header by n
    out_info_head.biWidth *= scaling_factor;
    out_info_head.biHeight *= scaling_factor;
    // determine outfile padding 
    int padding_out_file = (4 - (out_info_head.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    // total size of image
    out_info_head.biSizeImage = ((sizeof(RGBTRIPLE) * out_info_head.biWidth) + padding_out_file) * abs(out_info_head.biHeight);
    
    
    // write outfile's BITMAPFILEHEADER
    // to do; write out new dsize
    out_file_head.bfSize = out_info_head.biSizeImage + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);
    fwrite(&out_file_head, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    // to do; ensure that the info here (e.g. height/width is scaled by n)
    fwrite(&out_info_head, sizeof(BITMAPINFOHEADER), 1, outptr);

    // determine padding for scanlines of INfile
    int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    // container array for rows
    RGBTRIPLE *row = malloc(out_info_head.biWidth * sizeof(RGBTRIPLE));

    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    
    // to do; remember each line (in an array or something?)
    {
        // tracker variable to scale this array by whatever n is
        int tracker = 0;
        
        // iterate over pixels in scanline
        for (int j = 0; j < bi.biWidth; j++)
        {
            // temporary storage
            RGBTRIPLE triple;

            // read RGB triple from infile
            fread(&triple, sizeof(RGBTRIPLE), 1, inptr);
            
            // scale horizontally
            for (int k = 0; k < scaling_factor; k++) {
            
            // update array with triple    
            *(row + tracker) = triple;
            tracker++;
            }

            }
        
        // write out row to out file    
        for (int j = 0; j < scaling_factor; j++) {
        fwrite(row, sizeof(RGBTRIPLE), out_info_head.biWidth, outptr);
        
        // add padding to out file (has to be enclosed in loop above for scaling)
            for (int k = 0; k < padding_out_file; k++) {
            fputc(0x00, outptr);
             }
        
        }
        // skip over padding (in the infile), if any
        fseek(inptr, padding, SEEK_CUR);
        
}
    // free memory
    free(row);
    
    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;
}
