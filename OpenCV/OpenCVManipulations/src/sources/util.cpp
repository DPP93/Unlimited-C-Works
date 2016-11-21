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

void reduceColorUsingPointers (cv::Mat& image, int div) {
	int rows = image.rows;
	int colums = image.cols * image.channels();

	for (int x = 0; x < rows; ++x) {

		uchar* data = image.ptr<uchar>(x);

		for (int y = 0; y < colums; ++y) {
			data[y] = (data[y]/div) * div + (div/2);
		}
	}
}

void reduceColorUsingIterators (cv::Mat& image, int div) {

	if (image.channels() == 3) {
		cv::Mat_<cv::Vec3b>::iterator iterator = image.begin<cv::Vec3b>();
		cv::Mat_<cv::Vec3b>::iterator iteratorEnd = image.end<cv::Vec3b>();

		while ( iterator != iteratorEnd) {

			(*iterator)[0] = ((*iterator)[0] / div) * div + (div/2);
			(*iterator)[1] = ((*iterator)[1] / div) * div + (div/2);
			(*iterator)[2] = ((*iterator)[2] / div) * div + (div/2);

			++iterator;
		}

	} else {
		throw std::invalid_argument ("In this case image has to have 3 channels, sorry :( Try to use reduceColorUsingPointers");
	}

}

}
}
