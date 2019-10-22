#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include <opencv2\core\core.hpp>

using namespace cv;
using namespace std;
int a; char ch;
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
	 namedWindow("win", WINDOW_NORMAL);
     createTrackbar("T", "win", &v, 255);
		Mat temp2 = imread("E:\\My Pictures\\Lena.jpg", CV_LOAD_IMAGE_GRAYSCALE);
		Mat temp3 = imread("E:\\My Pictures\\Lena.jpg", CV_LOAD_IMAGE_GRAYSCALE);
		while (1)
		{
			for (int i = 0; i < temp2.rows; i++)
			{
				for (int j = 0; j < temp2.cols; j++)
				{
					a = temp2.at<uchar>(i, j);
					if (a <= v)
						temp3.at<uchar>(i, j) = 0;
					else
						temp3.at<uchar>(i, j) = 255;

				}
			}
			displayimage(temp3, "win");
			ch = waitKey(5);
			if (ch == ' ')
				break;
		}
}

int main()
{
	Mat temp1 = imread("E:\\My Pictures\\Lena.jpg", CV_LOAD_IMAGE_GRAYSCALE);
	displayimage(temp1, "original");
	createimagesampe();

	int iKey = waitKey(50);
	waitKey(0);
	return 0;
}