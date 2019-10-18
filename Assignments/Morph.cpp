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
Mat temp2 = imread("E:\\My Pictures\\cr7.jpg", CV_LOAD_IMAGE_COLOR);
Mat im1 = imread("E:\\My Pictures\\messi.jpg", CV_LOAD_IMAGE_COLOR);
Mat im3(im1.rows, im1.cols, CV_8UC3);
struct pixel
{
	int p, q;
};
int x = 0;
void displayimage(Mat image, String windowname)
{
	imshow(windowname, image);
}
Mat readimage(String filename)
{
	return imread(filename);
}
/*void bfs(int a, int b)
{
	int i = a, j = b, k = 0;
	pixel A, B;
	A.p = a; A.q = b;
	//temp.at<uchar>(a, b) = 255 / c;
	queue <pixel>s; 
	s.push(A);
	while (!s.empty())
	{
		B = s.front();
		s.pop();
		for (i = (B.p - 1); i <= (B.p + 1); i++)
		{
			for (j = (B.q - 1); j <= (B.q + 1); j++)
			{
				if (i >= 0 && i < temp.rows && j >= 0 && j < temp.cols)
				{
					if ((temp2.at<Vec3b>(i, j)[2] != 255 || temp2.at<Vec3b>(i, j)[1] != 255 || temp2.at<Vec3b>(i, j)[0] != 255) && temp.at<uchar>(i, j) != (255 / c))
					{
						temp.at<uchar>(i, j) = 255 / c;
						A.p = i; A.q = j;
						s.push(A);
						temp2.at<Vec3b>(i, j)[2] = 255;
						temp2.at<Vec3b>(i, j)[1] = 255;
						temp2.at<Vec3b>(i, j)[0] = 255;
					}
				}
			}
		}
			
		}
		
	}*/
void morph(int pos, void* data)
{
	
	Mat *temp = (Mat*)data;
	Mat im3 = *temp;
	int i, j; 
	for (i = 0; i < im1.rows; i++)
	{
		for (j = 0; j < im1.cols; j++)
		{
			im3.at<Vec3b>(i, j)[2] = (int)((im1.at<Vec3b>(i, j)[2] * x + (100 - x)* temp2.at<Vec3b>(i, j)[2])/100);
			im3.at<Vec3b>(i, j)[1] = (int)((im1.at<Vec3b>(i, j)[1] * x + (100 - x)* temp2.at<Vec3b>(i, j)[1])/100);
			im3.at<Vec3b>(i, j)[0] = (int)((im1.at<Vec3b>(i, j)[0] * x + (100 - x) * temp2.at<Vec3b>(i, j)[0])/100);
		}
	}
	displayimage(im3, "Morph");
}

int main()
{
	displayimage(temp2, "Original1");
	displayimage(im1, "Original2");
	namedWindow("Morph", WINDOW_AUTOSIZE);
	createTrackbar("t", "Morph", &x, 100, morph, (void*)(&im3));

	waitKey(0);
	return 0;
}