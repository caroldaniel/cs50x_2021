#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // Go through every row of pixels
    for (int i = 0; i < height; i++)
    {
        // Go through every column of pixels
        for (int j = 0; j < width; j++)
        {
            // Get RGB values from that pixel
            float blue = image[i][j].rgbtBlue;
            float green = image[i][j].rgbtGreen;
            float red = image[i][j].rgbtRed;

            // Calculate average of RGB values
            int average = round((blue + green + red) / 3);

            // Assign RGB values as average of those values
            image[i][j].rgbtBlue = image[i][j].rgbtGreen = image[i][j].rgbtRed = average;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // Go through every row of pixels
    for (int i = 0; i < height; i++)
    {
        // Go through every column of pixels
        for (int j = 0; j < width / 2; j++)
        {
            // Reflect pixels
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - (j + 1)];
            image[i][width - (j + 1)] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Create temporary array with original values
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }

    // Go through every row of pixels
    for (int i = 0; i < height; i++)
    {
        // Go through every column of pixels
        for (int j = 0; j < width; j++)
        {
            // Initialize values of sum
            float sum_blue;
            float sum_green;
            float sum_red;
            int counter;

            sum_blue = sum_green = sum_red = counter = 0;

            // For each pixel, check how many adjecent ones are there
            for (int k = -1; k < 2; k++)
            {
                for (int l = -1 ; l < 2; l++)
                {
                    // Check if pixel is in outside rows
                    if (i + k < 0 || i + k >= height)
                    {
                        continue;
                    }
                    // Check if pixel is in outside columns
                    else if (j + l < 0 || j + l >= width)
                    {
                        continue;
                    }
                    // Otherwise, add to sum
                    else
                    {
                        sum_blue += temp[i + k][j + l].rgbtBlue;
                        sum_green += temp[i + k][j + l].rgbtGreen;
                        sum_red += temp[i + k][j + l].rgbtRed;
                        counter++;
                    }
                }
            }
            // Get average on adjecent pixels and blur
            image[i][j].rgbtBlue = round(sum_blue / counter);
            image[i][j].rgbtGreen = round(sum_green / counter);
            image[i][j].rgbtRed = round(sum_red / counter);
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    // Create temporary array with original values
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }

    // Initialize the Sobel Arrays
    int Gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int Gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    // Go through every row of pixels
    for (int i = 0; i < height; i++)
    {
        // Go through every column of pixels
        for (int j = 0; j < width; j++)
        {
            // Initialize every Gx and Gy in every pixel
            float Gx_blue;
            float Gx_green;
            float Gx_red;
            float Gy_blue;
            float Gy_green;
            float Gy_red;

            Gx_blue = Gx_green = Gx_red = Gy_blue = Gy_green = Gy_red = 0;

            // For every pixel, loop through adjecent cells
            for (int k = -1; k < 2; k++)
            {
                for (int l = -1 ; l < 2; l++)
                {
                    // Check if pixel is in outside rows
                    if (i + k < 0 || i + k >= height)
                    {
                        continue;
                    }
                    // Check if pixel is in outside columns
                    else if (j + l < 0 || j + l >= width)
                    {
                        continue;
                    }
                    // Otherwise, add to sums
                    else
                    {
                        Gx_blue += temp[i + k][j + l].rgbtBlue * Gx[k + 1][l + 1];
                        Gx_green += temp[i + k][j + l].rgbtGreen * Gx[k + 1][l + 1];
                        Gx_red += temp[i + k][j + l].rgbtRed * Gx[k + 1][l + 1];
                        Gy_blue += temp[i + k][j + l].rgbtBlue * Gy[k + 1][l + 1];
                        Gy_green += temp[i + k][j + l].rgbtGreen * Gy[k + 1][l + 1];
                        Gy_red += temp[i + k][j + l].rgbtRed * Gy[k + 1][l + 1];
                    }
                }
            }

            // Calculate Sobel Operator
            int blue = round(sqrt(Gx_blue * Gx_blue + Gy_blue * Gy_blue));
            int green = round(sqrt(Gx_green * Gx_green + Gy_green * Gy_green));
            int red = round(sqrt(Gx_red * Gx_red + Gy_red * Gy_red));

            // Make sure no value transcend 255
            if (blue > 255)
            {
                blue = 255;
            }
            if (green > 255)
            {
                green = 255;
            }
            if (red > 255)
            {
                red = 255;
            }

            // Assign new values to pixels
            image[i][j].rgbtBlue = blue;
            image[i][j].rgbtGreen = green;
            image[i][j].rgbtRed = red;
        }
    }
    return;
}