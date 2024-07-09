#include "Program.h"
using namespace std;

class MyAlgorithm : public ScanConversingAlgorithm
{
	//可以在这里定义成员变量和成员函数
public:
	static MyAlgorithm* CreateMyAlgorithm()
	{
		return new MyAlgorithm();
	}

	//根据输入的vertices，更新对应位置buffer的值
	void Scan(Vector2Int* vertices, int vertexCount, int** buffer, int rowSize, int columnSize) override
	{
		//完成这个函数
	}
};

int main()
{

}