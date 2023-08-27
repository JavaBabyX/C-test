#include "helpers.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void copy(int height, int width, RGBTRIPLE source[height][width], RGBTRIPLE destination[height][width])
{
    for (int x = 0; x < width; x++)
    {
        for (int y = 0; y < height; y++)
        {
            destination[x][y] = source[x][y];
        }
    }
}

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Calculate average of red, green, and blue values
            int average = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);

            // Set red, green, and blue values to the calculated average
            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtBlue = average;
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            // Swap pixels on the left side with pixels on the right side
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = temp;
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{

    RGBTRIPLE(*copy)[width] = calloc(height, width * sizeof(RGBTRIPLE));
    if (copy == NULL)
    {
        printf("Not enough memory to store copy of image.\n");
        return;
    }

    for (int x = 0; x < width; x++)
    {
        for (int y = 0; y < height; y++)
        {
            int redSum = 0;
            int greenSum = 0;
            int blueSum = 0;
            int count = 0;

            for (int i = -1; i <= 1; i++)
            {
                for (int j = -1; j <= 1; j++)
                {
                    if (x + i >= 0 && x + i < width && y + j >= 0 && y + j < height)
                    {
                        redSum += image[x + i][y + j].rgbtRed;
                        greenSum += image[x + i][y + j].rgbtGreen;
                        blueSum += image[x + i][y + j].rgbtBlue;
                        count++;
                    }
                }
            }

            copy[x][y].rgbtRed = round((float) redSum / count);
            copy[x][y].rgbtGreen = round((float) greenSum / count);
            copy[x][y].rgbtBlue = round((float) blueSum / count);
        }
    }

    for (int x = 0; x < width; x++)
    {
        for (int y = 0; y < height; y++)
        {
            image[x][y] = copy[x][y];
        }
    }

    free(copy);
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    memcpy(temp, image, sizeof(RGBTRIPLE) * height * width);

    int gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int gxRed = 0, gxGreen = 0, gxBlue = 0;
            int gyRed = 0, gyGreen = 0, gyBlue = 0;

            for (int k = -1; k <= 1; k++)
            {
                for (int l = -1; l <= 1; l++)
                {
                    int ni = i + k;
                    int nj = j + l;

                    if (ni >= 0 && ni < height && nj >= 0 && nj < width)
                    {
                        gxRed += temp[ni][nj].rgbtRed * gx[k + 1][l + 1];
                        gxGreen += temp[ni][nj].rgbtGreen * gx[k + 1][l + 1];
                        gxBlue += temp[ni][nj].rgbtBlue * gx[k + 1][l + 1];

                        gyRed += temp[ni][nj].rgbtRed * gy[k + 1][l + 1];
                        gyGreen += temp[ni][nj].rgbtGreen * gy[k + 1][l + 1];
                        gyBlue += temp[ni][nj].rgbtBlue * gy[k + 1][l + 1];
                    }
                }
            }

            int finalRed = round(sqrt(gxRed * gxRed + gyRed * gyRed));
            int finalGreen = round(sqrt(gxGreen * gxGreen + gyGreen * gyGreen));
            int finalBlue = round(sqrt(gxBlue * gxBlue + gyBlue * gyBlue));

            image[i][j].rgbtRed = finalRed > 255 ? 255 : finalRed;
            image[i][j].rgbtGreen = finalGreen > 255 ? 255 : finalGreen;
            image[i][j].rgbtBlue = finalBlue > 255 ? 255 : finalBlue;
        }
    }
    return;
}
