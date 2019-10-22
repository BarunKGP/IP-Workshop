#include <stdio.h>
#include <iostream>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include <opencv2\core\core.hpp>
#include<conio.h>

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
	int r,g,b,k,l,s1=0, s2=0, s3=0;
	 	Mat temp2 = imread("E:\\My Pictures\\Lena.jpg", CV_LOAD_IMAGE_COLOR);
		Mat temp3(3 * temp2.rows, 3 * temp2.cols, CV_8UC3, 255);
		Mat temp4(temp3.rows / 2, temp3.cols / 2, CV_8UC3, 255);
		for (int i = 0; i < temp2.rows; i++)
			{
			for (int j = 0; j < temp2.cols; j++)
			{
				r = temp2.at<Vec3b>(i, j)[2];
				g = temp2.at<Vec3b>(i, j)[1];
				b = temp2.at<Vec3b>(i, j)[0];
				for (k = 3* i; k <=3 * i + 2; k++)
				{
					for (l = 3 * j; l <= 3 * j +2; l++)
					{
						temp3.at<Vec3b>(k, l)[2] = r;
						temp3.at<Vec3b>(k, l)[1] = g;
						temp3.at<Vec3b>(k, l)[0] = b;
					}
				}
			}
			}
		for (int i = 0; i < temp4.rows; i++)
		{
			for (int j = 0; j < temp4.cols; j++)
			{
				temp4.at<Vec3b>(i, j)[2] = s1 / 4;
				temp4.at<Vec3b>(i, j)[1] = s2 / 4;
				temp4.at<Vec3b>(i, j)[0] = s3 / 4;
				s1 = 0; s2 = 0; s3 = 0;
				for (k = 2 * i; k <= 2 * i + 1; k++)
				{
					for (l = 2 * j; l <= 2 * j + 1; l++)
					{
						r = temp3.at<Vec3b>(k,l)[2];
						g = temp3.at<Vec3b>(k, l)[1];
						b = temp3.at<Vec3b>(k,l)[0];
						s1 = s1 + r; s2 = s2 + g; s3 = s3 + b;
					}
				}
			}
		}
		displayimage(temp4, "Resized");
			
		}


int main()
{
	Mat temp1 = imread("E:\\My Pictures\\Lena.jpg", CV_LOAD_IMAGE_COLOR);
	displayimage(temp1, "original");
	createimagesampe();
	waitKey(0);
	return 0;
}
