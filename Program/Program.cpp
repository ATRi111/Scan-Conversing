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

	//���������vertices�����¶�Ӧλ��buffer��ֵ
	void Scan(Vector2Int* vertices, int vertexCount, int** buffer, int rowSize, int columnSize) override
	{
		//����������
	}
};

int main()
{

}