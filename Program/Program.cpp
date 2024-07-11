#include "Program.h"
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

	XScanlineAlgorithm algorithm = XScanlineAlgorithm();
	Vector2Int vertices[4] =
	{
		 Vector2Int(2, 4),
		 Vector2Int(4, 4),
		 Vector2Int(4, 8),
		 Vector2Int(2, 8),
	};
	TestCase* t = new TestCase_ScanConversing(vertices, 4, 10, 10);
	t->Print();
	TestAnswer* a = algorithm.Run(t, nullptr);
	a->Print();
}