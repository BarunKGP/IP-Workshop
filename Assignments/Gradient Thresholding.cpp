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
Mat temp2 = imread("E:\\My Pictures\\lena.jpg", CV_LOAD_IMAGE_GRAYSCALE);
int Gx[3][3] = { -1, 0, 1, -1, 0, 1, -1, 0, 1 };
int Gy[3][3] = { -1, -1, -1, 0, 0, 0, 1, 1, 1 };
int v = 0;
void displayimage(Mat image, String windowname)
{
	imshow(windowname, image);
}

Mat readimage(String filename)
{
	return imread(filename);
}
void edgedetect(int pos, void* data)
{
	Mat *im = (Mat*)data;
	Mat temp4 = *im;
	Mat temp(temp4.rows, temp4.cols, CV_8UC1);
	int t1 = 0, t2 = 0;
	int g1, g2;
	for (int i = 0; i < temp4.rows; i++)
	{
		for (int j = 0; j < temp4.cols; j++)
		{

			for (int k = i - 1; k <= i + 1; k++)
			{
				for (int l = j - 1; l <= j + 1; l++)
				{
					if (k >= 0 && l >= 0 && k < temp4.rows && l < temp4.cols)
					{
						g1 = Gx[k - i + 1][l - j + 1] * temp4.at<uchar>(k, l);
						g2 = Gy[k - i + 1][l - j + 1] * temp4.at<uchar>(k, l);
						t1 += g1; t2 += g2;
					}

				}
			}

			int t = abs(t1) + abs(t2);
			t1 = 0; t2 = 0;
			if (t > v)
				t = 255;
			else
				t = 0;
			temp.at<uchar>(i, j) = t;
		}
	}
	displayimage(temp, "Edge");
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
}
void createimagesampe()
{

	
	(temp2);
	displayimage(temp2, "original");
}
*/

int main()
{
	namedWindow("Edge", WINDOW_NORMAL);
	createTrackbar("t", "Edge", &v, 255, edgedetect, (void*)(&temp2));
	//createimagesampe();
	waitKey(0);
	return 0;
}