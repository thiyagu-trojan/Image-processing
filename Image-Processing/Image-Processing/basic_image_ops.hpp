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

class image_process: public image_fileops
{
    public:
        void rgb2gray(unsigned char *image, char dest[], int height, int width, char method[]);
        void rgb2cmyk(unsigned char *image, char dest[], int height, int width, char color[]);
};




#endif /* basic_image_ops_hpp */
