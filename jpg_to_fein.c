#include <stdio.h>
#define STB_IMAGE_IMPLEMENTATION
#include "lib/stb_image.h"

const char* OUTPUT = "image.fein";

int main() {
    int width, height, channels;
    unsigned char* image_data = stbi_load("image.jpg", &width, &height, &channels, 0);

    if (image_data == NULL) {
        printf("Error loading image\n");
        return 1;
    }

    FILE *fptr;
    fptr = fopen(OUTPUT, "w");

    fprintf(fptr, "%d %d\n", width, height);

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int index = (y * width + x) * channels;

            unsigned char red = image_data[index];
            unsigned char green = image_data[index + 1];
            unsigned char blue = image_data[index + 2];

            fprintf(fptr, "%c%c%c", red, green, blue);
        }
    }

    fclose(fptr);
    stbi_image_free(image_data);

    return 0;
}