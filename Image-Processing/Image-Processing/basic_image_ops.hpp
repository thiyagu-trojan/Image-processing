//
//  basic_image_ops.hpp
//  Image-Processing
//
//  Created by Thiyagarajan Ramanathan on 6/13/18.
//

#ifndef basic_image_ops_hpp
#define basic_image_ops_hpp

#include <stdio.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include "image_file_ops.hpp"

class color_conversion: public image_fileops
{
    public:
        void rgb2gray(unsigned char *image, char dest[], int height, int width, char method[]);
        void rgb2cmyk(unsigned char *image, char dest[], int height, int width, char color[]);
};

class interpolation: public image_fileops
{
    public:
        void bilinear_interpolation(unsigned char *image, char dest[], int height, int width, int new_height, int new_width, int channels);
};

#endif /* basic_image_ops_hpp */
