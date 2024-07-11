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

	XScanlineAlgorithm algorithm1 = XScanlineAlgorithm();
	EdgeFlagAlgorithm algorithm2 = EdgeFlagAlgorithm();
	Vector2Int vertices[4] =
	{
		 Vector2Int(2, 4),
		 Vector2Int(4, 4),
		 Vector2Int(4, 8),
		 Vector2Int(2, 8),
	};
	TestCase* t1 = new TestCase_ScanConversing(vertices, 4, 10, 10);
	t1->Print();
	TestAnswer* a1 = algorithm1.Run(t1, nullptr);
	a1->Print();
	cout << endl;

	TestCase* t2 = new TestCase_ScanConversing(vertices, 4, 10, 10);
	TestAnswer* a2 = algorithm2.Run(t2, nullptr);
	a2->Print();
}