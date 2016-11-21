#include "../headers/util.h"

#include <string>
#include <ctime>
#include <random>
#include <stdexcept>

#include "opencv2/highgui.hpp"
#include "opencv2/core.hpp"

namespace mag {
namespace util {

void showImage(cv::Mat imageToShow, std::string windowName) {
	cv::namedWindow(windowName);
	cv::imshow(windowName, imageToShow);
	cv::waitKey(0);
}

void addSaltAndPepperNoise(cv::Mat& imageToNoise, int numberOfPixelsToNoise) {
	srand(time(0));
	int row { }, col { }, valueOfNoise { };
	bool black;

	for (int i = 0; i < numberOfPixelsToNoise && i < imageToNoise.size().area();
			++i) {
		row = rand() % imageToNoise.size().height;
		col = rand() % imageToNoise.size().width;

		black = (rand() % 10) % 2 == 0 ? true : false;

		if (black) {
			valueOfNoise = 0;
		} else {
			valueOfNoise = 255;
		}

		if (imageToNoise.channels() == 1) {
			imageToNoise.at<uchar>(row, col) = valueOfNoise;

		} else if (imageToNoise.channels() == 3) {

			imageToNoise.at<cv::Vec3b>(row, col)[0] = valueOfNoise;
			imageToNoise.at<cv::Vec3b>(row, col)[1] = valueOfNoise;
			imageToNoise.at<cv::Vec3b>(row, col)[2] = valueOfNoise;
		} else {
			throw std::invalid_argument(
					"Image to noise was supposed to have 1 or 3 channels");
		}

	}

}
}
}
