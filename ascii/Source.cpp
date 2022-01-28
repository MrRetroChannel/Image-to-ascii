#include <string>
#include <windows.h>
#include <fstream>
#include <locale>
#include <iostream>
#include <vector>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>

using namespace std;
using namespace cv;

int main()
{
	locale::global(locale("en_US"));
	vector <string> path;
	FILE* file = fopen("123.txt", "wb");
	string den = "#W-o/ ";
	den += (char)-2;
	glob("img/*.*", path);
	Mat a = imread(path[0], IMREAD_COLOR);
	
	resize(a, a, Size(), 0.3, 0.15);
	ofstream text("123.txt");
	den += (char)254; 
	for (int x = 0; x < a.rows; x++)
	{
		for (int y = 0; y < a.cols; y++)
		{
			int color = ((int)a.at<Vec3b>(Point(y, x))[0] + (int)a.at<Vec3b>(Point(y, x))[1] + (int)a.at<Vec3b>(Point(y, x))[2]) / 3;
			a.at<Vec3b>(Point(y, x))[0] = color;
			a.at<Vec3b>(Point(y, x))[1] = color;
			a.at<Vec3b>(Point(y, x))[2] = color;
			text << den[(int)(den.length()/255. * color)];
		}
		text << '\n';
	}
	fclose(file);
	text.close();
}