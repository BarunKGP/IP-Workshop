#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include <opencv2\core\core.hpp>
#include<conio.h>
using namespace cv;
using namespace std;
int v1 = 0;
Mat temp2 = imread("E:\\My Pictures\\lena.jpg", CV_LOAD_IMAGE_COLOR);

/*void imageupdate(int pos, void* data)
{
	Mat *img = (Mat*)data;
	*img = blur(temp2);
	imshow("Blur", *img);
}*/
void displayimage(Mat image, String windowname)
{
	printf("a");
	imshow(windowname, image);
}

Mat readimage(String filename)
{
	return imread(filename);
}
void blur(int v, void* data)
{
	Mat *temp1 = (Mat*)data;
	Mat temp3(temp1->rows, temp1->cols, CV_8UC3);
	int r = 0, g = 0, b = 0, s = 0;
	for (int i = 0; i < temp1->rows; i++)
	{
		for (int j = 0; j < temp1->cols; j++)
		{

			for (int k = i - v; k <= i + v; k++)
			{
				for (int l = j - v; l <= j + v; l++)
				{
					if (k >= 0 && l >= 0 && k < temp1->rows && l < temp1->cols)
					{
						s++;
						r = r + temp1->at<Vec3b>(k, l)[2];
						g = g + temp1->at<Vec3b>(k, l)[1];
						b = b + temp1->at<Vec3b>(k, l)[0];

					}

				}
			}

			temp3.at<Vec3b>(i, j)[2] = r / s;
			temp3.at<Vec3b>(i, j)[1] = g / s;
			temp3.at<Vec3b>(i, j)[0] = b / s;
			r = 0; s = 0; g = 0; b = 0;
		}
	}
	imshow("Blur", temp3);
}
/*void createimagesampe()
{

	Mat im1 = blur(temp2);
	displayimage(im1, "blur");
	displayimage(temp2, "original");
}
*/

int main()
{
	namedWindow("Blur", WINDOW_NORMAL);
	createTrackbar("t", "Blur", &v1, 6, blur, (void*)(&temp2));
	waitKey(0);
	return 0;
}