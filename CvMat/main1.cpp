
#include <stdio.h>
#include <opencv2/core.hpp>

#include <iostream>

using namespace std;
using namespace cv;

int main1() {
	Mat m_mMat1 = Mat::ones(2, 3, CV_32FC1);
	Mat m_mMat2 = Mat::ones(3, 2, CV_32FC1);

	Mat ab;

	m_mMat1.at<float>(0, 0) = 1;

	m_mMat1.at<float>(0, 0) = 1;
	m_mMat1.at<float>(0, 1) = 2;
	m_mMat1.at<float>(0, 2) = 3;
	m_mMat1.at<float>(1, 0) = 4;
	m_mMat1.at<float>(1, 1) = 5;
	m_mMat1.at<float>(1, 2) = 6;

	m_mMat2.at<float>(0, 0) = 1;
	m_mMat2.at<float>(0, 1) = 2;
	m_mMat2.at<float>(1, 0) = 3;
	m_mMat2.at<float>(1, 1) = 4;
	m_mMat2.at<float>(2, 0) = 5;
	m_mMat2.at<float>(2, 1) = 6;

	ab = m_mMat1 * m_mMat2;

	cout << "m_mMat1=\n" << m_mMat1 << endl << endl;
	cout << "B=\n" << m_mMat2 << endl << endl;
	cout << "AB=\n" << ab << endl << endl;

	system("pause");

	return 0;
}



