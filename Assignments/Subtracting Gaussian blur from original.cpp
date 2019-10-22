#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include <opencv2\core\core.hpp>
#include<conio.h>
#include<math.h>
using namespace cv;
using namespace std;
Mat temp2 = imread("E:\\My Pictures\\lena.jpg", CV_LOAD_IMAGE_COLOR);
int A[3][3] = { 1, 2, 1, 2, 4, 2, 1, 2, 1 };
void displayimage(Mat image, String windowname)
{
	printf("a");
	imshow(windowname, image);
}

Mat readimage(String filename)
{
	return imread(filename);
}
void gauss_blur(Mat im)
{
	Mat temp4(im.rows, im.cols, CV_8UC3);
	int r = 0, g = 0, b = 0, s = 0;
	float r1, b1, g1;
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
						r1 = A[k - i + 1][l - j + 1] * im.at<Vec3b>(k, l)[2];
						g1 = A[k - i + 1][l - j + 1] * im.at<Vec3b>(k, l)[1];
						b1 = A[k - i + 1][l - j + 1] * im.at<Vec3b>(k, l)[0];
						r = r + r1;
						b = b + b1;
						g = g + g1;
					}

				}
			}

			temp4.at<Vec3b>(i, j)[2] = abs(temp2.at<Vec3b>(i, j)[2] - r/16);
			temp4.at<Vec3b>(i, j)[1] = abs(temp2.at<Vec3b>(i, j)[1] - g/16);
			temp4.at<Vec3b>(i, j)[0] = abs(temp2.at<Vec3b>(i,j)[0] - b/16);
			r = 0; g = 0; b = 0;
		}
	}
	displayimage(temp4, "gauss");
}
/*Mat blur(Mat im)
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
}*/
void createimagesampe()
{

	
	gauss_blur(temp2);
	displayimage(temp2, "original");
}


int main()
{
	createimagesampe();
	waitKey(0);
	return 0;
}