#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include<queue>
#include<stdlib.h>
#include<conio.h>
#include<vector>
int c = 0;
using namespace cv;
using namespace std;

Point largestblob(Mat im)
{
	Point q, v[480][640];
	//	vector<vector<Point> > v; // to store every white blob
	Point p;
	int i, j, m = 0, n = 0, k = 0, c = 0, count = 0, points = 0;
	for (i = 0; i < 480; i++)
	{
		for (j = 0; j < 640; j++)
		{
			v[i][j].x = 0; v[i][j].y = 0;
		}
	}
	for (i = 0; i < im.rows; i++)
	{
		for (j = 0; j < im.cols; j++)
		{
			if (im.at<uchar>(i, j) == 255)
			{
				v[k][c].x = j; v[k][c].y = i;
				c++;
			}
			if (im.at<uchar>(i, j) == 0 && im.at<uchar>(i, (j + 1)) == 255)
			{
				k++;

			}
		}
	}
	for (i = 0; i < im.rows; i++)
	{
		if (v[i][0].x != 0 && v[i][0].y != 0)
			count++;
	}
	for (i = 0; i < count; i++)
	{
		for (j = 0; j < im.cols; j++)
		{
			if (v[i][j].x != 0 && v[i][j].y != 0)
				points++;
		}
		if (m < points)
		{
			m = points;
			n = i;
		}
		points = 0;
	}
	return v[n][m / 2];
}
int main(int argc, char** argv)
{
	VideoCapture cap(0); //capture the video from web cam

	
	if (!cap.isOpened())  // if not success, exit program
	{
		cout << "Cannot open the web cam" << endl;
		return -1;
	}

	while (true)
	{
		Mat imgOriginal;
		
		bool bSuccess = cap.read(imgOriginal); // read a new frame from video
		if (!bSuccess) //if not success, break loop
		{
			cout << "Cannot read a frame from video stream" << endl;
			break;
		}
		cout << imgOriginal.rows << endl << imgOriginal.cols << endl;
		Mat imgHSV;

		cvtColor(imgOriginal, imgHSV, COLOR_BGR2HSV); //Convert the captured frame from BGR to HSV

		Mat imgThresholded;

		inRange(imgHSV, Scalar(0, 26, 109), Scalar(94, 255, 255), imgThresholded); //Threshold the image

		//morphological opening (remove small objects from the foreground)
		erode(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
		dilate(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));

		//morphological closing (fill small holes in the foreground)
		dilate(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
		erode(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
		//imshow("Thresholded Image", imgThresholded); //show the thresholded image
		imshow("Original", imgOriginal); //show the original image
	Point centre = largestblob(imgThresholded);
	if (centre.x < imgThresholded.cols / 3)
		cout << "Right";
	else if (centre.x > 2 * (imgThresholded.cols / 3))
		cout << "Left";
		
		if (waitKey(30) == 27) //wait for 'esc' key press for 30ms. If 'esc' key is pressed, break loop
		{
			cout << "esc key is pressed by user" << endl;
			break;
		}
	}
	
	return 0;

}

		




