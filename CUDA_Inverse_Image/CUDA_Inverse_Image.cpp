#include <iostream>
#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "opencv2/imgproc/imgproc.hpp"
#include "Inversion_CUDA.h"

using namespace std;
using namespace cv;

int main() {
	vector<cv::String> fn;
	string InputPath;

	printf("Enter Input Path (in end write *.png) \n");
	cin >> InputPath;

	glob(InputPath, fn, false);

	for (size_t i = 0; i < fn.size(); i++) {
		Mat Input_Image = imread(fn[i], IMREAD_UNCHANGED);
		Image_Inversion_CUDA(Input_Image.data, Input_Image.rows, Input_Image.rows, Input_Image.channels());
		imwrite(fn[i].c_str(), Input_Image);
	}
	return 0;
}