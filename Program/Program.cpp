#include "Program.h"
#include<random>
using namespace std;

class MyAlgorithm : public ScanConversingAlgorithm
{
	//可以在这里定义成员变量和成员函数
public:
	static MyAlgorithm* CreateMyAlgorithm()
	{
		return new MyAlgorithm();
	}

	//buffer相当于颜色缓冲,左下角坐标为(0,0)，右上角坐标为(width-1,height-1)
	//根据输入的vertices,更新buffer,不在多边形内部的点保持默认值0，在多边形内部的点应设为1
	void Scan(Vector2Int* vertices, int vertexCount, int** buffer, int width, int height) override
	{
		//完成这个函数
	}
};

static void TestMyAlgorithm(std::string path, int times)
{
	std::cout << "我的扫描转换算法:" << std::endl;
	Test(path, times, MyAlgorithm::CreateMyAlgorithm);
}

int main(int argc, char* argv[])
{
	string path = argv[0];
	path = path.substr(0, path.find_last_of('\\')) + "\\Answer.txt";
	int times = 10000;		//控制算法运行次数；测试集中包含100个测试用例，则总运行次数=times×100

	//GenerateAnswers(path);
	TestXScanlineAlgorithm(path, times);
	TestEdgeFlagAlgorithm(path, times);
	TestMyAlgorithm(path, times);
}