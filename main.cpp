#include "highgui.h"
#include"string.h"
#include <vector>
#include<fstream>
#include<cv.h>
#include<sstream>

#define N_IMAGE 8;

using namespace std;
template <class Type>  
Type stringToNum(const string& str)  
{  
   istringstream iss(str);  
   Type num;  
   iss >> num;  
   return num;      
}; 
typedef struct LINE
{
	float x[4];
}LINE;
typedef vector<LINE> VECLINES;
const string camParaPath[] ={
	"D:\\PROGRAM\\VH\\data\\camera parameters\\00.jpg.txt",
	"D:\\PROGRAM\\VH\\data\\camera parameters\\01.jpg.txt",
	"D:\\PROGRAM\\VH\\data\\camera parameters\\02.jpg.txt",
	"D:\\PROGRAM\\VH\\data\\camera parameters\\03.jpg.txt",
	"D:\\PROGRAM\\VH\\data\\camera parameters\\04.jpg.txt",
	"D:\\PROGRAM\\VH\\data\\camera parameters\\05.jpg.txt",
	"D:\\PROGRAM\\VH\\data\\camera parameters\\06.jpg.txt",
	"D:\\PROGRAM\\VH\\data\\camera parameters\\07.jpg.txt",
};
const string conImagePath[] ={
	"D:\\PROGRAM\\VH\\data\\contour\\00.jpg",
	"D:\\PROGRAM\\VH\\data\\contour\\01.jpg",
	"D:\\PROGRAM\\VH\\data\\contour\\02.jpg",
	"D:\\PROGRAM\\VH\\data\\contour\\03.jpg",
	"D:\\PROGRAM\\VH\\data\\contour\\04.jpg",
	"D:\\PROGRAM\\VH\\data\\contour\\05.jpg",
	"D:\\PROGRAM\\VH\\data\\contour\\06.jpg",
	"D:\\PROGRAM\\VH\\data\\contour\\07.jpg",
};
const string conPointPath[] ={
	"D:\\PROGRAM\\VH\\data\\dinosaur-contour\\00.jpg.txt",
	"D:\\PROGRAM\\VH\\data\\dinosaur-contour\\01.jpg.txt",
	"D:\\PROGRAM\\VH\\data\\dinosaur-contour\\02.jpg.txt",
	"D:\\PROGRAM\\VH\\data\\dinosaur-contour\\03.jpg.txt",
	"D:\\PROGRAM\\VH\\data\\dinosaur-contour\\04.jpg.txt",
	"D:\\PROGRAM\\VH\\data\\dinosaur-contour\\05.jpg.txt",
	"D:\\PROGRAM\\VH\\data\\dinosaur-contour\\06.jpg.txt",
	"D:\\PROGRAM\\VH\\data\\dinosaur-contour\\07.jpg.txt",
};
void readCamPara()
{	
	vector<CvMat*> CamParaMat;
	for(int i=0;i<8;i++)
	{
		ifstream campar_in(camParaPath[i]);
		if (!campar_in.is_open())
		{
        cout << "Unable to open file"; 
		}
		else
		{
			CamParaMat.push_back(cvCreateMat(3,4,CV_32FC1));
			for(int r=0;r<3;r++)
			{
				for(int c=0;c<4;c++)
				{
					string camparastr;
					campar_in>>camparastr;
					float camtemp=stringToNum<float>(camparastr);
					cvmSet(CamParaMat[i],r,c,camtemp);
				}
			}
		}
	}
	//float temp;
	//temp = cvmGet(CamParaMat[0],1,0);
	//
	//
}
void readContour()
{
	vector<IplImage*>ConImage;
	for(int i=0;i<8;i++)
	{
		ifstream conimg_in(conImagePath[i]);
		if (!conimg_in.is_open())
		{
        cout << "Unable to open file"; 
		}
		else
		ConImage.push_back(cvLoadImage(conImagePath[i].c_str()));
	}


	//cvNamedWindow("test");
	//cvShowImage("test",ConImage[1]);
	//cvWaitKey();
}
void readContourPointImage()
{
	float temp1,temp2,temp3,temp4;
	vector<VECLINES> ConPoint;
	vector<LINE> ConPointImage;
	int pointNum,flag=0;
	string conpointimgstr;
	for(int i=0;i<8;i++)
	{
		ifstream conpointimg_in(conPointPath[i]);
		if (!conpointimg_in.is_open())
		{
			cout << "Unable to open file"; 
		}
		else 
		{	
			LINE line;
			conpointimg_in>>conpointimgstr;
			pointNum=stringToNum<int>(conpointimgstr);
			for(int m=0;m<pointNum;m++)
			{


				//将第一个 x y 读入temp1,temp2


				//将第二个 x y 读入temp3,temp4


				//将temp1--temp4  存入第一个 LINE

				//push  LINE


				//将temp3和temp4的值分别给temp1和temp2


				//将第3个 x y 读入temp3,temp4


				//将temp1--temp4  存入第二个 LINE

				//push  LINE

				//将temp3和temp4的值分别给temp1和temp2


				//将第4个 x y 读入temp3,temp4


				//将temp1--temp4  存入第三个 LINE

				//push  LINE
				
				// 。。。。。

				// 直到结束

				//!!!!没有处理首尾相接的线段




				for(int n=0;n<2;n++)
				{
					conpointimg_in>>conpointimgstr;
					line.x[n]=stringToNum<int>(conpointimgstr);
					flag++;
				}
				ConPointImage.push_back(line);
			}

		}
		ConPoint.push_back(ConPointImage);
	}
	
}
	





int main()
{
	readCamPara();
	readContour();
	readContourPointImage();

	//计算基础矩阵

	//计算光心

	//计算极点



	return 0;
}