#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include <opencv2\core\core.hpp>

using namespace cv;
using namespace std;
int a, b, c,g;
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
		Mat temp2 = imread("E:\\My Pictures\\Lena.jpg", CV_LOAD_IMAGE_COLOR);
		Mat temp3(temp2.rows, temp2.cols, CV_8UC1);
	for (int i = 0; i < temp2.rows; i++)
	{
		for (int j = 0; j < temp2.cols; j++)
		{
			a=temp2.at<Vec3b>(i, j)[2];
			b=temp2.at<Vec3b>(i, j)[1];
			c=temp2.at<Vec3b>(i, j)[0];
		    g = (a + b + c) / 3;
			temp3.at<uchar>(i, j) = g;
			
		}
	}
	displayimage(temp3, "random");
}

int main()
{
	Mat temp1 = imread("E:\\My Pictures\\Lena.jpg", CV_LOAD_IMAGE_COLOR);
	displayimage(temp1, "original");
	createimagesampe();
	int iKey = waitKey(50);
	waitKey(0);
	return 0;
}