#ifndef UTIL_H

#define UTIL_H

#include <string>
#include "opencv2/core.hpp"

namespace mag{
namespace util {

	void showImage (cv::Mat imageToShow, std::string windowName);
	void addSaltAndPepperNoise (cv::Mat& imageToNoise, int numberOfPixelsToNoise);
}
}

#endif UTIL_H //UTIL_H
