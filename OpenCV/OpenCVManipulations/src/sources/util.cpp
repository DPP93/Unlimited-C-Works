#include "../headers/util.h"
#include <string>
#include "opencv2/highgui.hpp"
#include "opencv2/core.hpp"

namespace mag {
namespace util {
	void showImage(cv::Mat imageToShow, std::string windowName) {
		cv::namedWindow(windowName);
		cv::imshow(windowName, imageToShow);
		cv::waitKey(0);
	}
}
}
