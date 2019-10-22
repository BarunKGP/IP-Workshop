#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include <opencv2\core\core.hpp>

using namespace cv;
using namespace std;int A[26];
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
		Mat temp3 = imread("E:\\My Pictures\\Lena.jpg", CV_LOAD_IMAGE_GRAYSCALE);
		for (v = 0; v < 256; v++)
		{
			for (int i = 0; i < temp2.rows; i++)
			{
				for (int j = 0; j < temp2.cols; j++)
				{
					if (v == temp2.at<uchar>(i, j))
						A[v]++;
					

				}
			}
			
		}
}

int main()
{
	Mat temp1 = imread("E:\\My Pictures\\Lena.jpg", CV_LOAD_IMAGE_GRAYSCALE);
	displayimage(temp1, "original");
	for (int i = 0; i < 26; i++)
		A[i] = 0;
	createimagesampe();
	for (int j = 0; j < 26; j++)
	{
		cout << endl;
		for (int k = 0; k < A[j]; k++)
			cout << "*";
	}

	int iKey = waitKey(50);
	waitKey(0);
	return 0;
}