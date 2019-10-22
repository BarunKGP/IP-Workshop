#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include <opencv2\core\core.hpp>
#include<conio.h>
#include<math.h>
#include<queue>
using namespace cv;
using namespace std;
VideoCapture vc(0);
Mat frame;
void displayimage(Mat image, String windowname)
{
	imshow(windowname, image);
}
Mat readimage(String filename)
{
	return imread(filename);
}
void flip(Mat im)
{
	int i, j;
	Mat flip(im.rows, im.cols, CV_8UC3);
	for (i = 0; i < im.rows; i++)
	{
		for (j = 0; j < im.cols / 2; j++)
		{
			flip.at<Vec3b>(i, (im.cols - 1 - j))[2] = im.at<Vec3b>(i, j)[2];
			flip.at<Vec3b>(i, (im.cols - 1 - j))[1] = im.at<Vec3b>(i, j)[1];
			flip.at<Vec3b>(i, (im.cols - 1 - j))[0] = im.at<Vec3b>(i, j)[0];

			flip.at<Vec3b>(i, j)[2] = im.at<Vec3b>(i, j)[2];
			flip.at<Vec3b>(i, j)[1] = im.at<Vec3b>(i, j)[1];
			flip.at<Vec3b>(i, j)[0] = im.at<Vec3b>(i, j)[0];
		}
	}
	displayimage(flip, "Mirror");
}
int main()
{
	
	while (1)
	{
		vc >> frame;
		if (frame.data)
			flip(frame);
		waitKey(50);
	}
		return 0;
	}
