
#include <iostream>
#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

int main(void) {

	VideoCapture cap("test.mp4"); //Read Video File
	if (!cap.isOpened()) // If it cannot open close app
		return -1;

	Mat frame, org_frame;
	int count = -1;
	int new_height = 480; //New Size for resizing
	int new_width = 640; //New Size for resizing

	//If you don't set any height and width, extract just frame
	new_height = (new_height > 0) ? new_height : cap.get(CV_CAP_PROP_FRAME_HEIGHT);
	new_width = (new_width > 0) ? new_width : cap.get(CV_CAP_PROP_FRAME_WIDTH);


	for (;;)
	{
		cap >> org_frame; //Get Orjinal Frame

		if (org_frame.empty())break; //If all frame extracted, close the program


		cv::Size new_size(new_width, new_height);

		++count; //Add count for loop

		resize(org_frame, frame, new_size);

		string name = "frame_" + std::to_string(count) + ".png"; //Create name
		imwrite("./Output/Orjinal/" + name, org_frame); //Extract orjinal frame to output
		imwrite("./Output/Resized/" + name, frame); //Extract resized frame to output

		if (waitKey(1) >= 0) break;
	}
	return 0;
}