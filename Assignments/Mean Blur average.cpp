#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include <opencv2\core\core.hpp>
#include<conio.h>
using namespace cv;
using namespace std;
Mat temp2 = imread("E:\\My Pictures\\lena.jpg", CV_LOAD_IMAGE_COLOR);
void displayimage(Mat image, String windowname)
{
	printf("a");
	imshow(windowname, image);
}

Mat readimage(String filename)
{
	return imread(filename);
}
Mat blur(Mat im)
{
	Mat temp3(im.rows, im.cols, CV_8UC3);
	int r = 0, g = 0, b = 0, s = 0;
	for (int i = 0; i < im.rows; i++)
	{
		for (int j = 0; j < im.cols; j++)
		{

			for (int k = i - 1; k <= i + 1; k++)
			{
				for (int l = j - 1; l <= j + 1; l++)
				{
					if (k >= 0 && l >= 0 && k < im.rows && l < im.cols)
					{
						s++;
						r = r + im.at<Vec3b>(k, l)[2];
						g = g + im.at<Vec3b>(k, l)[1];
						b = b + im.at<Vec3b>(k, l)[0];

					}

				}
			}

			temp3.at<Vec3b>(i, j)[2] = r / s;
			temp3.at<Vec3b>(i, j)[1] = g / s;
			temp3.at<Vec3b>(i, j)[0] = b / s;
			r = 0; s = 0; g = 0; b = 0;
		}
	}
	return temp3;
}
void createimagesampe()
{
	
	Mat im1 = blur(temp2);
	displayimage(im1, "blur");
		displayimage(temp2, "original");
	}
	

int main()
{
	createimagesampe();
	waitKey(0);
	return 0;
}