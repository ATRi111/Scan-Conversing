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
	int times = 1;		//�����㷨���д��������Լ��а���100�������������������д���=times��100

	TestXScanlineAlgorithm(path, times);
	TestEdgeFlagAlgorithm(path, times);
}