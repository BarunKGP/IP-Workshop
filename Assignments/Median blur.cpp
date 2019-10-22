#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include <opencv2\core\core.hpp>
#include<conio.h>
#include<algorithm>
using namespace cv;
using namespace std;
int A[9];

Mat temp2 = imread("E:\\My Pictures\\lena.jpg", CV_LOAD_IMAGE_GRAYSCALE);
void displayimage(Mat image, String windowname)
{
	printf("a");
	imshow(windowname, image);
}

Mat readimage(String filename)
{
	return imread(filename);
}
void blur(Mat im)
{
	for (int p = 0; p < 9; p++)
	{
		A[p] = 0;
	}
	Mat temp3(im.rows, im.cols, CV_8UC1);
	int r = 0;
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
						A[r] = im.at<uchar>(k, l);
						r++;
					}
				}
				sort(A, A + r);
				temp3.at<uchar>(i, j) = A[r / 2];
				r = 0;
			}
		}
		imshow("blur",temp3);
	}
}
void createimagesampe()
{
	
	blur(temp2);
	displayimage(temp2, "original");
	}
	

int main()
{
	createimagesampe();
	waitKey(0);
	return 0;
}