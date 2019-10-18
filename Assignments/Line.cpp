#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include <opencv2\core\core.hpp>
#include<conio.h>
#include<math.h>
#include<queue>
#include<math.h>
using namespace cv;
using namespace std;
Mat img(500, 500, CV_8UC1, Scalar(255));
void displayimage(Mat image, String windowname)
{
	imshow(windowname, image);
}
Mat readimage(String filename)
{
	return imread(filename);
}
/*void flip(Mat im)
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
}*/
void imageline(Mat im, int r, int a)
{
	int x1 = im.rows - 1, x2 = 0, y1, y2, t = 1, lt = 8, sh = 0;
	y1 = r - (int)((x1*cos(a)) / sin(a));
	y2 = (int)(r / sin(a));
	Point p1, p2;
	p1.x = x1; p1.y = y1; p2.x = x2; p2.y = y2;
	line(im, p1, p2, Scalar(0));
	displayimage(im, "temp");
}
int main()
{
	
	imageline(img, 50, 1);
		waitKey(0);
	
		return 0;
	}
