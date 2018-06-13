//
//  main.cpp
//  Image-Processing
//
//  Created by Thiyagarajan Ramanathan on 6/13/18.
//

#include <stdio.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "image_file_ops.hpp"
#include "basic_image_ops.hpp"
using namespace std;
int main()
{
    image_process object1;
    char read_link[200], dest_link[200];
    int height, width, channels;
    strcpy(read_link,"/Users/thiyagarajanramanathan/Desktop/Image-processing/Images/Tiffany.raw");
    strcpy(dest_link,"/Users/thiyagarajanramanathan/Desktop/Tiffany_trial1.raw");
    unsigned char *image1=object1.read_image(read_link, height=512, width=512, channels=3);
    object1.rgb2gray(image1, dest_link, height, width, "luminosity");
    printf ("Conversion Done\n");
}
