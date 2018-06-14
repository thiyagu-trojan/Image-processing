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
    
    /*
    This section is for converting an RGB image to a gray scale image
     There are three methods for performing this operation:
     1) Averaging method (method='average')
     2) Lightness method (method='lightness')
     3) Luminosity method (method='luminosity')
    Enter the method also when calling the function
     */
    char read_link[200], dest_link[200];
    int height, width, channels;
    strcpy(read_link,"/Users/thiyagarajanramanathan/Desktop/Image-processing/Images/Tiffany.raw");
    strcpy(dest_link,"/Users/thiyagarajanramanathan/Desktop/Tiffany_trial2.raw");
    unsigned char *image1=object1.read_image(read_link, height=512, width=512, channels=3);
    //object1.rgb2gray(image1, dest_link, height, width, "lightness"); //For converting from rgb to gray scale
    //object1.free_memory(image1);
    //printf ("Conversion Done\n");
    
    
    /*
     This section is for converting an RGB image to a CMYK scale image
     There are four methods for performing this operation:
     1) color: "cyan". For conversion from rgb to cyan
     2) color: "magenta". For conversion from rgb to magenta
     3) color: "yellow". For conversion from rgb to yellow
     4) color: "all". For conversion from rgb to cmyk
     Enter the method also when calling the function
     */
    //object1.rgb2cmyk(image1, dest_link, height, width, "all");
    //object1.free_memory(image1);
    //printf ("Conversion Done\n");
}
