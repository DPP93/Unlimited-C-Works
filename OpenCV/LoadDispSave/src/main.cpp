#include <iostream>
#include <cstdio>

#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

using namespace std;

int main (int argc, char* argv[]) {

	cv::Mat image {};

	cout << "Actual size of image height: " << image.size().height << " width: " << image.size().width << endl;

	//Read image send as parameter
	image = cv::imread(argv[1]);

	if (!image.data) {
        cout << "No image found" << endl;
        return 0;
    }
	cout << "After load actual size of image height: " << image.size().height << " width: " << image.size().width << endl;

	cv::namedWindow("Lena");
	cv::imshow("Lena", image);

	cv::Mat flippedLena {};
	cv::flip(image, flippedLena, 1);

	cv::namedWindow("Flipped Lena");
	cv::imshow("Flipped Lena", flippedLena);

	cv::waitKey(0);

//	cv::imwrite("Saved Lena.bmp", flippedLena);
}
