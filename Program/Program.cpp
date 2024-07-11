#include "Program.h"
#include<random>
using namespace std;

class MyAlgorithm : public ScanConversingAlgorithm
{
	//���������ﶨ���Ա�����ͳ�Ա����
public:
	static MyAlgorithm* CreateMyAlgorithm()
	{
		return new MyAlgorithm();
	}

	//buffer�൱����ɫ����,���½�����Ϊ(0,0)�����Ͻ�����Ϊ(width-1,height-1)
	//���������vertices,����buffer,���ڶ�����ڲ��ĵ㱣��Ĭ��ֵ0���ڶ�����ڲ��ĵ�Ӧ��Ϊ1
	void Scan(Vector2Int* vertices, int vertexCount, int** buffer, int width, int height) override
	{
		//����������
	}
};

int main(int argc, char* argv[])
{
	string path = argv[0];
	path = path.substr(0, path.find_last_of('\\')) + "\\Answer.txt";
	int times = 100;		//�����㷨���д��������Լ��а���100�������������������д���=times��100

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