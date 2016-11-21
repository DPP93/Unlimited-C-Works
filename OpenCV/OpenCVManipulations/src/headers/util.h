#ifndef UTIL_H

#define UTIL_H

#include <string>
#include "opencv2/core.hpp"

namespace mag{
namespace util {

	void showImage (cv::Mat imageToShow, std::string windowName);
	void addSaltAndPepperNoise (cv::Mat& imageToNoise, int numberOfPixelsToNoise);
	void reduceColorUsingPointers (cv::Mat& image, int div = 64);

	/**
	 * WARNING!!!
	 * Work only with 3 - channel images
	 */
	void reduceColorUsingIterators (cv::Mat& image, int div = 64);
}
}

#endif UTIL_H //UTIL_H
