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

int main(int argc, char* argv[])
{
	string path = argv[0];
	path = path.substr(0, path.find_last_of('\\')) + "\\Answer.txt";
	int times = 100;		//控制算法运行次数；测试集中包含100个测试用例，则总运行次数=times×100

	XScanlineAlgorithm algorithm1 = XScanlineAlgorithm();
	EdgeFlagAlgorithm algorithm2 = EdgeFlagAlgorithm();

	Vector2Int vs[4];
	PolygonGenerator::Generate(vs, 4, 10, 10);
	for (int i = 0; i < 4; i++)
	{
		cout << vs[i] << endl;
	}
	TestCase* t = new TestCase_ScanConversing(vs, 4, 10, 10);

	TestAnswer* a = algorithm1.Run(t, nullptr);
	a->Print();
}