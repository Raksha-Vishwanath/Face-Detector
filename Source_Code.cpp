#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <iostream>

using namespace std;
using namespace cv;

void main() {

	VideoCapture video(0);
	CascadeClassifier detect;
	Mat img;
	detect.load("Resources/haarcascade_frontalface_default.xml");

	while (1)
	{
		video.read(img);
		vector<Rect> faces;
		detect.detectMultiScale(img, faces, 1.3, 5);

		for (int i = 0; i < faces.size(); i++)
		{
			rectangle(img, faces[i].tl(), faces[i].br(), Scalar(50, 50, 255), 3);
		}

		imshow("Frame", img);
		waitKey(1);
	}

}