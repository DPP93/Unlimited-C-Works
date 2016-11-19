#include <cstdio>
#include <core.hpp>
#include <imgproc.hpp>
#include <highgui.hpp>

int main( int argc, char** argv )
{
  cv::Mat image;
  image = cv::imread(argv[1], cv::IMREAD_COLOR);

  if( argc != 2 || !image.data )
    {
      printf( "No image data \n" );
      return -1;
    }
  cv::Mat image2(image, cv::Rect(100, 100, 200, 200));
  cv::namedWindow( "Display Image", cv::WINDOW_AUTOSIZE );
  cv::imshow( "Display Image", image2 );
  cv::waitKey(0);

  return 0;
}
