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
	int r,g,b,k,l;
	 	Mat temp2 = imread("E:\\My Pictures\\Lena.jpg", CV_LOAD_IMAGE_COLOR);
		Mat temp3(2 * temp2.rows, 2 * temp2.cols, CV_8UC3, 255);
		for (int i = 0; i < temp2.rows; i++)
			{
			for (int j = 0; j < temp2.cols; j++)
			{
				r = temp2.at<Vec3b>(i, j)[2];
				g = temp2.at<Vec3b>(i, j)[1];
				b = temp2.at<Vec3b>(i, j)[0];
				for (k = 2 * i; k <=2 * i + 1; k++)
				{
					for (l = 2 * j; l <= 2 * j + 1; l++)
					{
						temp3.at<Vec3b>(k, l)[2] = r;
						temp3.at<Vec3b>(k, l)[1] = g;
						temp3.at<Vec3b>(k, l)[0] = b;
					}
				}
			}
			}
		displayimage(temp3, "Resized");
			
		}


int main()
{
	Mat temp1 = imread("E:\\My Pictures\\Lena.jpg", CV_LOAD_IMAGE_COLOR);
	displayimage(temp1, "original");
	createimagesampe();
	waitKey(0);
	return 0;
}
