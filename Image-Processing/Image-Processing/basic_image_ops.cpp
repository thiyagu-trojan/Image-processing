//
//  basic_image_ops.cpp
//  Image-Processing
//
//  Created by Thiyagarajan Ramanathan on 6/13/18.
//

#include "image_file_ops.hpp"
#include "basic_image_ops.hpp"


//conversion from rgb to gray scale

void color_conversion::rgb2gray(unsigned char *image, char dest[], int height, int width, char method[])
{
    image_fileops ops1;
    unsigned char *gray_image = new unsigned char [height*width];
    if (strcmp("average",method)==0)
    {
        for(int i=0;i<height;i++)
        {
            for(int j=0;j<width;j++)
            {
                gray_image[i*width+j]=(image[i*width*3+j*3+0]+image[i*width*3+j*3+1]+image[i*width*3+j*3+2])/3;
            }
        }
    }
    else if (strcmp("lightness",method)==0)
    {
        for(int i=0;i<height;i++)
        {
            for(int j=0;j<width;j++)
            {
                gray_image[i*width+j]=(max(max(image[i*width*3+j*3+0], image[i*width*3+j*3+1]),image[i*width*3+j*3+2])+min(min(image[i*width*3+j*3+0], image[i*width*3+j*3+1]),image[i*width*3+j*3+2]))/2;
            }
        }
    }
    else if (strcmp("luminosity",method)==0)
    {
        for(int i=0;i<height;i++)
        {
            for(int j=0;j<width;j++)
            {
                gray_image[i*width+j]=(0.21*image[i*width*3+j*3+0]+0.72*image[i*width*3+j*3+1]+0.07*image[i*width*3+j*3+2]);
            }
        }
    }
    else
    {
        printf("%s is not a valid method, enter the correct method\n",method);
        exit(EXIT_FAILURE);
    }
    ops1.save_image(gray_image,dest,height,width,1);
}


//Conversion from rgb to cmy

void color_conversion::rgb2cmyk(unsigned char *image, char dest[], int height, int width, char color[])
{
    image_fileops ops1;
    if (strcmp("cyan",color)==0)
    {
        unsigned char *cyan_image = new unsigned char [height*width];
        for(int i=0;i<height;i++)
        {
            for(int j=0;j<width;j++)
            {
                cyan_image[i*width+j]=255-image[i*width*3+j*3+0];
            }
        }
        ops1.save_image(cyan_image,dest,height,width,1);
    }
    else if (strcmp("magenta",color)==0)
    {
        unsigned char *magenta_image = new unsigned char [height*width];
        for(int i=0;i<height;i++)
        {
            for(int j=0;j<width;j++)
            {
                magenta_image[i*width+j]=255-image[i*width*3+j*3+1];
            }
        }
        ops1.save_image(magenta_image,dest,height,width,1);
    }
    else if (strcmp("yellow",color)==0)
    {
        unsigned char *yellow_image = new unsigned char [height*width];
        for(int i=0;i<height;i++)
        {
            for(int j=0;j<width;j++)
            {
                yellow_image[i*width+j]=255-image[i*width*3+j*3+2];
            }
        }
        ops1.save_image(yellow_image,dest,height,width,1);
    }
    else if (strcmp("all",color)==0)
    {
        unsigned char *cmy_image = new unsigned char [height*width*3];
        for(int i=0;i<height;i++)
        {
            for(int j=0;j<width;j++)
            {
                cmy_image[i*width*3+j*3+0]=255-image[i*width*3+j*3+0];
                cmy_image[i*width*3+j*3+1]=255-image[i*width*3+j*3+1];
                cmy_image[i*width*3+j*3+2]=255-image[i*width*3+j*3+2];
            }
        }
        ops1.save_image(cmy_image,dest,height,width,3);
    }
    else
    {
        printf("%s is not a valid method, enter the correct method\n",color);
        exit(EXIT_FAILURE);
    }
}

//Bilinear Interpolation
void interpolation::bilinear_interpolation(unsigned char *image, char dest[], int height, int width, int new_height, int new_width, int channels)
{
    image_fileops ops1;
    float row_ratio, col_ratio, dx,dy;
    row_ratio=(1.0*(height-1))/(new_height-1);
    col_ratio=(1.0*(width-1))/(new_width-1);
    float *temp_image = new float [new_height*new_width*channels];
    unsigned char *resize_image = new unsigned char [new_height*new_width*channels];
    int x,y;
    for(int k=0;k<channels;k++)
    {
        for(int i=0;i<new_height;i++)
        {
            for(int j=0;j<new_width;j++)
            {
                y=(int)(row_ratio*i);
                dy=((row_ratio*i)-y); //distance to the pixels above and below
                x=(int)(col_ratio*j);
                dx=((col_ratio*j)-x);// distance to the pixels to the left and right
                temp_image[i*new_width*channels+j*channels+k]=((1-dy)*(1-dx)*(float)image[y*width*channels+x*channels+k])+(dx*(1-dy)*(float)image[y*width*channels+(x+1)*channels+k])+(dy*(1-dx)*(float)image[(y+1)*width*channels+x*channels+k])+(dx*dy*(float)image[(y+1)*width*channels+(x+1)*channels+k]);
                resize_image[i*new_width*channels+j*channels+k]=(unsigned char)temp_image[i*new_width*channels+j*channels+k];
            }
        }
    }
    ops1.save_image(resize_image,dest,new_height,new_width,channels);
}



