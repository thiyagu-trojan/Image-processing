//
//  image_file_ops.hpp
//  Image-Processing
//
//  Created by Thiyagarajan Ramanathan on 6/13/18.
//

#ifndef image_file_ops_hpp
#define image_file_ops_hpp

#include <stdio.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class image_fileops {
    
public:
    unsigned char *read_image(char link[], int height, int width, int channels);
    void save_image(unsigned char *image, char link[], int height, int width, int channels);
    
};

#endif /* image_file_ops_hpp */
