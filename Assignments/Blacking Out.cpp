#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include <opencv2\core\core.hpp>

using namespace cv;
using namespace std;

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
	Mat temp2 = imread("E:\\My Pictures\\Barca.jpg", CV_LOAD_IMAGE_COLOR);
	for (int i =temp2.rows/2; i < temp2.rows; i++)
	{
		for (int j = 0; j < temp2.cols; j++)
		{
			temp2.at<Vec3b>(i, j)[2] = 0;
			temp2.at<Vec3b>(i, j)[1] = 0;
			temp2.at<Vec3b>(i, j)[0] = 0;
		}
	}
	displayimage(temp2, "random");
}

int main()
{
	createimagesampe();
	int iKey = waitKey(50);
	waitKey(0);
	return 0;
}