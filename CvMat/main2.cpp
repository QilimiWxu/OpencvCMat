
#include <stdio.h>
#include <opencv2/core.hpp>

#include <iostream>

using namespace std;
using namespace cv;

/**************
*����3����������
*��������a,b,c ���a+2xb+3*c
*�������ֻ���þ�������������㣬�����з��򴫲���һ�����ӽ��ⷴ�򴫲��㷨
*/
int main() {
	int aInput[3] = { 0 };

	Mat m_fResultWeight(1, 3, CV_32FC1, Scalar(1));
	m_fResultWeight.at<float>(0, 0) = 1.0;
	m_fResultWeight.at<float>(0, 1) = 2.0;
	m_fResultWeight.at<float>(0, 2) = 3.0;
		
	Mat m_fLayerCell_a(2, 3, CV_32FC1, Scalar(1));//��������a�ľ��󣬲������������

	/*
	w11 w12 w13
	w21 w22 w23
	w31 w32 w33
	*/
	Mat m_fNable_w2(3, 3, CV_32FC1, Scalar(1));//����w2�������ݵľ���
	
	/*
	w11
	w21
	w31
	*/
	Mat m_fNable_w3(3, 1, CV_32FC1, Scalar(1));//����w4�������ݵľ���
	Mat m_fNable_w3_d(3, 1, CV_32FC1, Scalar(1));//����w4�������ݵľ���

	/*
	b21 b22 b23
	*/
	Mat m_fNable_b2(1, 3, CV_32FC1, Scalar(1));

	/*
	b31
	*/
	float m_fNable_b3 = 1;

	//�������ֵ��ֵ
	aInput[0] = aInput[1] = aInput[2] = 1;

	//�������ֵ��ֵ��m_fLayerCell_a�ĵ�һ��Ԫ��,��һ��
	m_fLayerCell_a.at<float>(0, 0) = (float)aInput[0];
	m_fLayerCell_a.at<float>(0, 1) = (float)aInput[1];
	m_fLayerCell_a.at<float>(0, 2) = (float)aInput[2];

	//�������
	cout << "m_fLayerCell_a=\n" << m_fLayerCell_a << endl << endl;
	cout << "m_fNable_w=\n" << m_fNable_w2 << endl << endl;

	//m_fLayerCell_a.col(1).copyTo((m_fLayerCell_a.colRange(0, 1) * m_fNable_w).col(0));
	m_fLayerCell_a.row(1) = (m_fLayerCell_a.row(0) * m_fNable_w2 + m_fNable_b2.row(0)).row(0);
	cout << "m_fLayerCell_a=\n" << m_fLayerCell_a << endl << endl;

	//��������ֵ����
	float y = Mat(m_fLayerCell_a.row(1) * m_fNable_w3 + m_fNable_b3).at<float>(0, 0);
	cout << "y = " << y << endl;

	system("pause");

	//�������������������,���ż���
	float diff3 = 0;

	//��=(C - Y)/4, ��������Ĵ��ۺ���ʹ��C - y(x)
	diff3 = (Mat(m_fResultWeight.row(0) * m_fLayerCell_a.col(0)).at<float>(0, 0) - y) / 4.0;
	cout << "diff3 = " << diff3 << endl;

	//b = b + ��;
	m_fNable_b3 = m_fNable_b3 + diff3;
	cout << "m_fNable_b3 " << m_fNable_b3 << endl;

	//w = w + �� * a;
	Mat  t_diffw3(m_fLayerCell_a.row(1) * diff3);
	t_diffw3.t();
	m_fNable_w3_d.col(0) = (t_diffw3.col(0) + m_fNable_w3.col(0)).col(0);
	cout << "m_fNable_w3_d " << m_fNable_w3_d << endl;

	//��(L) = ��(L + 1) * w(L + 1) * 1
	Mat diff2(m_fNable_w3.col(0) * diff3);
	cout << "diff2 " << diff2 << endl;

	//b = b + ��;
	Mat m_fNable_b2_diff(m_fNable_b2 + diff2);
	cout << "m_fNable_b2_diff " << m_fNable_b2_diff << endl;

	Mat m_fNable_w2_diffw2();




	return 0;
}



