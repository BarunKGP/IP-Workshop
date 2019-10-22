#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include <opencv2\core\core.hpp>
#include<conio.h>

using namespace cv;
using namespace std;
int A[260];
int m = 0;
void displayimage(Mat image, String windowname)
{
	imshow(windowname, image);
}

Mat readimage(String filename)
{
	return imread(filename);
}

	


void createimagesampe()
{
	int v = 0;
	 	Mat temp2 = imread("E:\\My Pictures\\Lena.jpg", CV_LOAD_IMAGE_GRAYSCALE);
		
		for (v = 0; v < 256; v++)
		{
			for (int i = 0; i < temp2.rows; i++)
			{
				for (int j = 0; j < temp2.cols; j++)
				{
					if (v == temp2.at<uchar>(i, j))
						A[v]++;
					if (A[v] > m)
					{
					m = A[v];
					}
				}
			}
			
		}
}

int main()
{
	Mat temp1 = imread("E:\\My Pictures\\Lena.jpg", CV_LOAD_IMAGE_GRAYSCALE);
	displayimage(temp1, "original");
	for (int i = 0; i < 260; i++)
		A[i] = 0;
	createimagesampe();
	Mat img(600, 600, CV_8UC1, Scalar(0));
	int i, j;
	for (i = 0; i < 256; i++)
	{
		for (j = 0; j < (600 - A[i]); j++)
			img.at<uchar>(j, i) = 255;
	}
	displayimage(img, "histogram");
	waitKey(0);
	getch();
	return 0;
}