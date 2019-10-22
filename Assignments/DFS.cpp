#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include <opencv2\core\core.hpp>
#include<conio.h>
#include<math.h>
#include<stack>
using namespace cv;
using namespace std;
Mat temp2 = imread("E:\\My Pictures\\sampleimg2.png", CV_LOAD_IMAGE_COLOR);
Mat temp(temp2.rows, temp2.cols, CV_8UC1, Scalar(0));
struct pixel
{
	int p, q;
};
int c = 1,vt = 50, vr, vb, vg;
void displayimage(Mat image, String windowname)
{
	imshow(windowname, image);
}
Mat readimage(String filename)
{
	return imread(filename);
}
void dfs(int a, int b)
{
	int i = a, j = b, k = 0;
	pixel A, B;
	A.p = a; A.q = b;
	//temp.at<uchar>(a, b) = 255 / c;
	stack <pixel>s; 
	s.push(A);
	while (!s.empty())
	{
		B = s.top();
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
						/*temp2.at<Vec3b>(i, j)[2] = 255;
						temp2.at<Vec3b>(i, j)[1] = 255;
						temp2.at<Vec3b>(i, j)[0] = 255;*/
					}
				}
			}
		}
			
		}
		
	}


int main()
{
	displayimage(temp2, "Original");
	int i, j;
	for (i = 0; i < temp2.rows; i++)
	{
		for (j = 0; j < temp2.cols; j++)
		{
			vr = temp2.at<Vec3b>(i, j)[2] ;
			vg = temp2.at<Vec3b>(i, j)[1] ;
			vb = temp2.at<Vec3b>(i, j)[0] ;
			if ((vr != 255 || vb != 255 || vg != 255) && temp.at<uchar>(i, j) == 0)
			{
				dfs(i, j);
				c++;
				}
			
		}
	}
	displayimage(temp, "dfs");
	

	waitKey(0);
	return 0;
}