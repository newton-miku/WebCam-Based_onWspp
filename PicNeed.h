//#pragma once
#include "opencv2/opencv.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <highgui/highgui_c.h>

#include "iostream"
#include <windows.h>
#include <boost/asio/cancellation_signal.hpp>

using namespace std;
using namespace cv;
#pragma comment(lib,"opencv_world460.lib") 
#pragma comment(lib,"IlmImf.lib") 
#pragma comment(lib,"ippicvmt.lib") 
#pragma comment(lib,"ippiw.lib") 
#pragma comment(lib,"ittnotify.lib") 
#pragma comment(lib,"libopenjp2.lib") 
#pragma comment(lib,"libpng.lib") 
#pragma comment(lib,"libwebp.lib") 
#pragma comment(lib,"libjpeg-turbo.lib") 
#pragma comment(lib,"libtiff.lib") 
#pragma comment(lib,"zlib.lib") 




void cvMatToJPG(const cv::Mat& input, std::vector<uchar>& buf)
{
    // jpeg±àÂë
    std::vector<int> params;
    params.resize(3, 0);
    params[0] = cv::IMWRITE_JPEG_QUALITY;
    params[1] = 90;     // Ñ¹ËõÂÊ

    cv::imencode(".jpg", input, buf, params);
}
string MatToStr(const cv::Mat mat) {
    std::string str;
    std::vector<unsigned char> buff;
    cv::imencode(".jpg", mat, buff);
    str.resize(buff.size());
    memcpy(&str[0], buff.data(), buff.size());
    return str;
}