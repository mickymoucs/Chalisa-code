/*โปรแกรมแปลงรูปภาพโดยใช้ filter ต่างๆ คือ grayscale,sepia,reflect,blur*/

#include "helpers.h"
#include<math.h>
#include<stdio.h>
#include<cs50.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for( int i=0;i < height; i++)
    {
        for (int j=0;j < width; j++)
        {
            RGBTRIPLE pixel = image[i][j];

        int avr = round((pixel.rgbtBlue+pixel.rgbtGreen+pixel.rgbtRed)/3.0);
        image[i][j].rgbtBlue=image[i][j].rgbtGreen=image[i][j].rgbtRed=avr;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
     for( int i=0;i < height; i++)
    {
        for (int j=0;j < width; j++)
        {
            RGBTRIPLE pixel = image[i][j];

         int sepiaRed = round(.393 * pixel.rgbtRed + .769 * pixel.rgbtGreen + .189 * pixel.rgbtBlue);
         int sepiaGreen = round(.349 * pixel.rgbtRed + .686 * pixel.rgbtGreen + .168 * pixel.rgbtBlue);
         int sepiaBlue = round(.272 * pixel.rgbtRed + .534 * pixel.rgbtGreen + .131 * pixel.rgbtBlue);


         if(sepiaBlue>255)
         {
             sepiaBlue=255;
         }
         if(sepiaGreen>255)
         {
             sepiaGreen=255;
         }
         if(sepiaRed>255)
         {
            sepiaRed=255;
         }

            image[i][j].rgbtBlue=sepiaBlue;
            image[i][j].rgbtGreen=sepiaGreen;
            image[i][j].rgbtRed=sepiaRed;

         }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
     for( int i=0;i < height; i++)
    {
        for (int j=0;j < (width/2.00) ; j++)
        {
            if( j < (width/2))
            {
                RGBTRIPLE temp = image[i][j];
                image[i][j] = image[i][width-(j+1)];
                image[i][width-(j+1)] = temp;
            }
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
     for( int i=0;i < height; i++)
    {
        for (int j=0;j < width; j++)
        {

              temp[i][j] = image[i][j];
        }
    }



     for( int i=0;i < height; i++)
    {
        for (int j=0;j < width; j++)
        {
            double sumRed=0;
            double sumBlue=0;
            double sumGreen=0;

            if(i==0 && j==0) //left up//
            {
            sumRed = temp[i][j].rgbtRed+temp[i][j+1].rgbtRed+temp[i+1][j].rgbtRed+temp[i+1][j+1].rgbtRed;
            sumGreen = temp[i][j].rgbtGreen+temp[i][j+1].rgbtGreen+temp[i+1][j].rgbtGreen+temp[i+1][j+1].rgbtGreen;
            sumBlue = temp[i][j].rgbtBlue+temp[i][j+1].rgbtBlue+temp[i+1][j].rgbtBlue+temp[i+1][j+1].rgbtBlue;


            int avrRed = round(sumRed/4);
            int avrGreen = round(sumGreen/4);
            int avrBlue = round(sumBlue/4);

             image[i][j].rgbtBlue=avrBlue;
             image[i][j].rgbtGreen=avrGreen;
             image[i][j].rgbtRed=avrRed;
            }

            else if(i==0 && j==width-1) //right up//
            {
                sumRed = temp[i][j].rgbtRed+temp[i][j-1].rgbtRed+temp[i+1][j].rgbtRed+temp[i+1][j-1].rgbtRed;
                sumGreen = temp[i][j].rgbtGreen+temp[i][j-1].rgbtGreen+temp[i+1][j].rgbtGreen+temp[i+1][j-1].rgbtGreen;
                sumBlue = temp[i][j].rgbtBlue+temp[i][j-1].rgbtBlue+temp[i+1][j].rgbtBlue+temp[i+1][j-1].rgbtBlue;

                int avrRed = round(sumRed/4);
                int avrGreen = round(sumGreen/4);
                int avrBlue = round(sumBlue/4);

                image[i][j].rgbtBlue=avrBlue;
                image[i][j].rgbtGreen=avrGreen;
                image[i][j].rgbtRed=avrRed;
            }
            else if(i==height-1 && j==0) //left down//
            {
                sumRed = temp[i][j].rgbtRed+temp[i][j+1].rgbtRed+temp[i-1][j].rgbtRed+temp[i-1][j+1].rgbtRed;
                sumGreen = temp[i][j].rgbtGreen+temp[i][j+1].rgbtGreen+temp[i-1][j].rgbtGreen+temp[i-1][j+1].rgbtGreen;
                sumBlue = temp[i][j].rgbtBlue+temp[i][j+1].rgbtBlue+temp[i-1][j].rgbtBlue+temp[i-1][j+1].rgbtBlue;

                int avrRed = round(sumRed/4);
                int avrGreen = round(sumGreen/4);
                int avrBlue = round(sumBlue/4);

                image[i][j].rgbtBlue=avrBlue;
                image[i][j].rgbtGreen=avrGreen;
                image[i][j].rgbtRed=avrRed;
            }
            else if(i==height-1 && j==width-1) // right down//
            {
                sumRed = temp[i][j].rgbtRed+temp[i][j-1].rgbtRed+temp[i-1][j].rgbtRed+temp[i-1][j-1].rgbtRed;
                sumGreen = temp[i][j].rgbtGreen+temp[i][j-1].rgbtGreen+temp[i-1][j].rgbtGreen+temp[i-1][j-1].rgbtGreen;
                sumBlue = temp[i][j].rgbtBlue+temp[i][j-1].rgbtBlue+temp[i-1][j].rgbtBlue+temp[i-1][j-1].rgbtBlue;

                int avrRed = round(sumRed/4);
                int avrGreen = round(sumGreen/4);
                int avrBlue = round(sumBlue/4);

                image[i][j].rgbtBlue=avrBlue;
                image[i][j].rgbtGreen=avrGreen;
                image[i][j].rgbtRed=avrRed;
            }
            else if( i==0 && (j>0 && j<width-1)) // edge up//
            {
                sumRed = temp[i][j].rgbtRed+temp[i][j-1].rgbtRed+temp[i][j+1].rgbtRed+temp[i+1][j-1].rgbtRed+temp[i+1][j].rgbtRed+temp[i+1][j+1].rgbtRed;
                sumGreen = temp[i][j].rgbtGreen+temp[i][j-1].rgbtGreen+temp[i][j+1].rgbtGreen+temp[i+1][j-1].rgbtGreen+temp[i+1][j].rgbtGreen+temp[i+1][j+1].rgbtGreen;
                sumBlue = temp[i][j].rgbtBlue+temp[i][j-1].rgbtBlue+temp[i][j+1].rgbtBlue+temp[i+1][j-1].rgbtBlue+temp[i+1][j].rgbtBlue+temp[i+1][j+1].rgbtBlue;

                int avrRed = round(sumRed/6);
                int avrGreen = round(sumGreen/6);
                int avrBlue = round(sumBlue/6);

                image[i][j].rgbtBlue=avrBlue;
                image[i][j].rgbtGreen=avrGreen;
                image[i][j].rgbtRed=avrRed;
            }
            else if( (i>0 && i<height-1) && j==0) // edge left //
            {
                sumRed = temp[i][j].rgbtRed+temp[i-1][j].rgbtRed+temp[i-1][j+1].rgbtRed+temp[i][j+1].rgbtRed+temp[i+1][j].rgbtRed+temp[i+1][j+1].rgbtRed;
                sumGreen = temp[i][j].rgbtGreen+temp[i-1][j].rgbtGreen+temp[i-1][j+1].rgbtGreen+temp[i][j+1].rgbtGreen+temp[i+1][j].rgbtGreen+temp[i+1][j+1].rgbtGreen;
                sumBlue = temp[i][j].rgbtBlue+temp[i-1][j].rgbtBlue+temp[i-1][j+1].rgbtBlue+temp[i][j+1].rgbtBlue+temp[i+1][j].rgbtBlue+temp[i+1][j+1].rgbtBlue;

                int avrRed = round(sumRed/6);
                int avrGreen = round(sumGreen/6);
                int avrBlue = round(sumBlue/6);

                image[i][j].rgbtBlue=avrBlue;
                image[i][j].rgbtGreen=avrGreen;
                image[i][j].rgbtRed=avrRed;
            }
            else if( (i>0 && i< height-1) && j== width-1) // edge right //
            {
                sumRed = temp[i][j].rgbtRed+temp[i-1][j-1].rgbtRed+temp[i-1][j].rgbtRed+temp[i][j-1].rgbtRed+temp[i+1][j-1].rgbtRed+temp[i+1][j].rgbtRed;
                sumGreen = temp[i][j].rgbtGreen+temp[i-1][j-1].rgbtGreen+temp[i-1][j].rgbtGreen+temp[i][j-1].rgbtGreen+temp[i+1][j-1].rgbtGreen+temp[i+1][j].rgbtGreen;
                sumBlue = temp[i][j].rgbtBlue+temp[i-1][j-1].rgbtBlue+temp[i-1][j].rgbtBlue+temp[i][j-1].rgbtBlue+temp[i+1][j-1].rgbtBlue+temp[i+1][j].rgbtBlue;

                int avrRed = round(sumRed/6);
                int avrGreen = round(sumGreen/6);
                int avrBlue = round(sumBlue/6);

                image[i][j].rgbtBlue=avrBlue;
                image[i][j].rgbtGreen=avrGreen;
                image[i][j].rgbtRed=avrRed;
            }
            else if(i==height-1 && (j>0 && j< width-1) ) // edge down //
            {
                sumRed = temp[i][j].rgbtRed+temp[i-1][j-1].rgbtRed+temp[i-1][j].rgbtRed+temp[i-1][j+1].rgbtRed+temp[i][j-1].rgbtRed+temp[i][j+1].rgbtRed;
                sumGreen = temp[i][j].rgbtGreen+temp[i-1][j-1].rgbtGreen+temp[i-1][j].rgbtGreen+temp[i-1][j+1].rgbtGreen+temp[i][j-1].rgbtGreen+temp[i][j+1].rgbtGreen;
                sumBlue = temp[i][j].rgbtBlue+temp[i-1][j-1].rgbtBlue+temp[i-1][j].rgbtBlue+temp[i-1][j+1].rgbtBlue+temp[i][j-1].rgbtBlue+temp[i][j+1].rgbtBlue;

                int avrRed = round(sumRed/6);
                int avrGreen = round(sumGreen/6);
                int avrBlue = round(sumBlue/6);

                image[i][j].rgbtBlue=avrBlue;
                image[i][j].rgbtGreen=avrGreen;
                image[i][j].rgbtRed=avrRed;
            }
            else
            {
                sumRed = temp[i-1][j-1].rgbtRed+temp[i-1][j].rgbtRed+temp[i-1][j+1].rgbtRed+temp[i][j-1].rgbtRed+temp[i][j].rgbtRed+temp[i][j+1].rgbtRed+temp[i+1][j-1].rgbtRed+temp[i+1][j].rgbtRed
                +temp[i+1][j+1].rgbtRed;

                sumGreen = temp[i][j].rgbtGreen+temp[i-1][j-1].rgbtGreen+temp[i-1][j].rgbtGreen+temp[i-1][j+1].rgbtGreen+temp[i][j-1].rgbtGreen+temp[i][j+1].rgbtGreen+temp[i+1][j-1].rgbtGreen+temp[i+1][j].rgbtGreen+temp[i+1][j+1].rgbtGreen;
                sumBlue = temp[i][j].rgbtBlue+temp[i-1][j-1].rgbtBlue+temp[i-1][j].rgbtBlue+temp[i-1][j+1].rgbtBlue+temp[i][j-1].rgbtBlue+temp[i][j+1].rgbtBlue+temp[i+1][j-1].rgbtBlue+temp[i+1][j].rgbtBlue+temp[i+1][j+1].rgbtBlue;

                int avrRed = round(sumRed/9);
                int avrGreen = round(sumGreen/9);
                int avrBlue = round(sumBlue/9);

                image[i][j].rgbtBlue=avrBlue;
                image[i][j].rgbtGreen=avrGreen;
                image[i][j].rgbtRed=avrRed;
            }

        }
    }
     return;
}
