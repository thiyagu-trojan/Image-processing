//
//  image_file_ops.cpp
//  Image-Processing
//
//  Created by Thiyagarajan Ramanathan on 6/13/18.
//

#include "image_file_ops.hpp"

//For reading the image file

unsigned char *image_fileops::read_image(char link[], int height, int width, int channels)
{
    FILE *file;
    unsigned char *image = new unsigned char [height*width*channels];
    
    
    if (!(file=fopen(link,"rb"))) {
        cout << "Cannot open file: " << link <<endl;
        exit(1);
    }
    fread(image, sizeof(unsigned char), height*width*channels, file);
    fclose(file);
    
    return image;
}


//For Saving the image file
void image_fileops::save_image(unsigned char *image, char link[], int height, int width, int channels)
{
    FILE *file;
    if (!(file=fopen(link,"wb"))) {
        cout << "Cannot open file: " << link << endl;
        exit(1);
    }
    fwrite(image, sizeof(unsigned char), height*width*channels , file);
    fclose(file);
}
