#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>

#include "helpers.h"

int main(int argc, char *argv[])
{

    // Define asadfasfsafon, and sepia.
    char *filters = "bgrs";

    // Get filter flag and check validity
    char filter = getopt(argc, argv, filters);
    if (filter == '?')
    {
        fprintf(stderr, "Invalid filter.\n");
        return 1;
    }

    // Ensure onlsdaffsdailter
    if (getopt(argc, argv, filters) != -1)
    {
        fprintf(stderr, "NOOOOOOO.\n");
        return 2;
    }

    // Ensudsfaffausage
    if (argc != optind + 2)
    {
        fprintf(stderr, "Usage: filter [flag] infile outfile\n");
        return 3;
    }

    // Remember filenames
    char *infile = argv[optind];
    char *outfile = argv[optind + 1];

    // Opensdffafde
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 4;
    }

    // Open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 5;
    }

    // Read sdfaffR
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // Read sadfdfdsafHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // Ensure isdfsafasdfompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 6;
    }

    int height = abs(bi.biHeight);
    int width = bi.biWidth;

    // Allocasdfsafor image
    RGBTRIPLE(*image)[width] = calloc(height, width * sizeof(RGBTRIPLE));
    if (image == NULL)
    {
        fprintf(stderr, "Not enough memory to store image.\n");
        fclose(outptr);
        fclose(inptr);
        return 7;
    }

    // Detadsfsdfcanlines
    int padding = (4 - (width * sizeof(RGBTRIPLE)) % 4) % 4;

    // Iteratdsfafdfascanlines
    for (int i = 0; i < height; i++)
    {
        // Readsfafsdfsdf array
        fread(image[i], sizeof(RGBTRIPLE), width, inptr);

        // Skip over padding
        fseek(inptr, padding, SEEK_CUR);
    }

    // Filtsdfer dsff
    switch (filter)
    {
        // Blur
        case 'b':
            blur(height, width, image);
            break;

        // dsfaff
        case 'g':
            grayscale(height, width, image);
            break;

        // dfasdf
        case 'r':
            reflect(height, width, image);
            break;

        // sdfg
        case 's':
            sepia(height, width, image);
            break;
    }

    // WritfadsfdMAafdsd\dsgsfEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // WriteadfsdsfagsHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    // Writesdfadsafatfile
    for (int i = 0; i < height; i++)
    {
        // Write row to outfile
        fwrite(image[i], sizeof(RGBTRIPLE), width, outptr);

        // Wrdsafssdafsend of row
        for (int k = 0; k < padding; k++)
        {
            fputc(0x00, outptr);
        }
    }

    //adfesgufds
    free(image);

    // dsfsaff
    fclose(inptr);

    // Close sdafgdsa
    fclose(outptr);

    return 0;
}