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
Mat temp2 = imread("E:\\My Pictures\\sampleimage.png", CV_LOAD_IMAGE_COLOR);
int vt = 0, vr = 0,vg = 0, vb = 0;
void displayimage(Mat image, String windowname)
{
	imshow(windowname, image);
}

Mat readimage(String filename)
{
	return imread(filename);
}
void extract(int pos, void* data)
{
	Mat *im = (Mat*)data;
	Mat temp4 = *im;
	Mat temp(temp4.rows, temp4.cols, CV_8UC3, Scalar(0));
	int t1 = 0, t2 = 0;
	int g1, g2;
	for (int i = 0; i < temp4.rows; i++)
	{
		for (int j = 0; j < temp4.cols; j++)
		{
			if (temp4.at<Vec3b>(i, j)[2] >= (vr - vt) && temp4.at<Vec3b>(i, j)[2] <= (vr + vt) && temp4.at<Vec3b>(i, j)[1] >= (vg - vt) && temp4.at<Vec3b>(i, j)[1] <= (vg + vt) && temp4.at<Vec3b>(i, j)[0] >= (vb - vt) && temp4.at<Vec3b>(i, j)[0] <= (vb + vt))
			{
				temp.at<Vec3b>(i, j)[2] = temp4.at<Vec3b>(i, j)[2];
				temp.at<Vec3b>(i, j)[1] = temp4.at<Vec3b>(i, j)[1];
				temp.at<Vec3b>(i, j)[0] = temp4.at<Vec3b>(i, j)[0];
			}
			else
			{
				temp.at<Vec3b>(i, j)[2] = 0;
				temp.at<Vec3b>(i, j)[1] = 0;
				temp.at<Vec3b>(i, j)[0] = 0;
			}
		}
	}
	displayimage(temp, "Edge");
}


int main()
{
	
	namedWindow("Edge", WINDOW_AUTOSIZE);
	
	createTrackbar("t", "Edge", &vt, 255, extract, (void*)(&temp2));
	createTrackbar("r", "Edge", &vr, 255, extract, (void*)(&temp2));
	createTrackbar("g", "Edge", &vg, 255, extract, (void*)(&temp2));
	createTrackbar("b", "Edge", &vb, 255, extract, (void*)(&temp2));
	displayimage(temp2, "Original");

	waitKey(0);
	return 0;
}