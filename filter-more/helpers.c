#include "helpers.h"
#include<math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i=0;i<height;i++)
    {
        for(int j=0;j<width;j++)
        {
            float blue=image[i][j].rgbtBlue;
            float green=image[i][j].rgbtGreen;
            float red=image[i][j].rgbtRed;

            int average=round((red+blue+green)/3);

            image[i][j].rgbtBlue=image[i][j].rgbtGreen=image[i][j].rgbtRed=average;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i=0;i<height;i++)
    {
        for(int j=0;j<width/2;j++)
        {
            RGBTRIPLE temp=image[i][j];
            image[i][j]=image[i][width-(j+1)];
            image[i][width-(j+1)]=temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    for(int i=0;i<height;i++)
    {
        for(int j=0;j<width;j++)
        {
            temp[i][j]=image[i][j];
        }
    }

    for(int i=0;i<height;i++)
    {
        for(int j=0;j<width;j++)
        {
            float sum_red;
            float sum_blue;
            float sum_green;
            int counter;
            sum_red=sum_blue=sum_green=counter=0;

            for(int a=-1;a<2;a++)
            {
                for(int b=-1;b<2;b++)
                {
                    if(i+a<0 || i+a>=height)
                    {
                        continue;
                    }
                    if(j+b<0 || j+b>=width)
                    {
                        continue;
                    }

                    sum_red +=temp[i+a][j+b].rgbtRed;
                    sum_blue +=temp[i+a][j+b].rgbtBlue;
                    sum_green +=temp[i+a][j+b].rgbtGreen;
                    counter++;
                }

            }
            image[i][j].rgbtRed = round(sum_red/counter);
            image[i][j].rgbtGreen = round(sum_green/counter);
            image[i][j].rgbtBlue = round(sum_blue/counter);
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    for(int i=0;i<height;i++)
    {
        for(int j=0;j<width;j++)
        {
            temp[i][j]=image[i][j];
        }
    }
    int Gx[3][3]={{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int Gy[3][3]={{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    for(int i=0;i<height;i++)
    {
        for(int j=0;j<width;j++)
        {
            float Gx_red;
            float Gx_blue;
            float Gx_green;
            float Gy_red;
            float Gy_blue;
            float Gy_green;
            Gx_red=Gx_blue=Gx_green=Gy_red=Gy_blue=Gy_green=0;

            for(int a=-1;a<2;a++)
            {
                for(int b=-1;b<2;b++)
                {
                    if(i+a<0 || i+a>=height)
                    {
                        continue;
                    }
                    if(j+b<0 || j+b>=width)
                    {
                        continue;
                    }

                    Gx_red +=temp[i+a][j+b].rgbtRed * Gx[a+1][b+1];
                    Gx_green +=temp[i+a][j+b].rgbtGreen * Gx[a+1][b+1];
                    Gx_blue +=temp[i+a][j+b].rgbtBlue * Gx[a+1][b+1];
                    Gy_red +=temp[i+a][j+b].rgbtRed * Gy[a+1][b+1];
                    Gy_green +=temp[i+a][j+b].rgbtGreen * Gy[a+1][b+1];
                    Gy_blue +=temp[i+a][j+b].rgbtBlue * Gy[a+1][b+1];
                }
            }
            int red=round(sqrt(Gx_red * Gx_red+Gy_red * Gy_red));
            int green=round(sqrt(Gx_green * Gx_green+Gy_green * Gy_green));
            int blue=round(sqrt(Gx_blue * Gx_blue+Gy_blue * Gy_blue));

            if(red>255)
            {
                red=255;
            }
            if(green>255)
            {
                green=255;
            }
            if(blue>255)
            {
                blue=255;
            }

            image[i][j].rgbtRed=red;
            image[i][j].rgbtGreen=green;
            image[i][j].rgbtBlue=blue;
        }
    }
    return;
}
