//#include "highgui.h"
//#include"string.h"
//#include <vector>
//#include<fstream>
//#include<cv.h>
//#include<sstream>
//
//#define N_IMAGE 8;
//
//using namespace std;
//
//template <class Type>  
//Type stringToNum(const string& str)  
//{  
//   istringstream iss(str);  
//   Type num;  
//   iss >> num;  
//   return num;      
//}; 
//
//const string camParaPath[] ={
//	"data\\camera parameters\\00.jpg",
//	"data\\camera parameters\\01.jpg",
//	"data\\camera parameters\\02.jpg",
//	"data\\camera parameters\\03.jpg",
//	"data\\camera parameters\\04.jpg",
//	"data\\camera parameters\\05.jpg",
//	"data\\camera parameters\\06.jpg",
//	"data\\camera parameters\\07.jpg",
//};
//
//void readCamPara()
//{	
//	vector<CvMat*> CamParaMat;
//	for(int i=0;i<8;i++)
//	{
//		CamParaMat.push_back(cvCreateMat(3,4,CV_32FC1));
//		ifstream in(camParaPath[i]);
//		
//		for(int r=0;r<3;r++)
//		{
//			for(int c=0;c<4;c++)
//			{
//				string str;
//				in>>str;
//				float temp=stringToNum<float>(str);
//			}
//		}
//	}
//	
//	
//}