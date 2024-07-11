#include "ScanConversingAlgorithm.h"
using namespace std;

#pragma region ScanConversingAlgorithm
TestAnswer* ScanConversingAlgorithm::Run(TestCase* t, Stopwatch* timer)
{
	TestCase_ScanConversing* p = dynamic_cast<TestCase_ScanConversing*>(t);
	if (timer)
		timer->Start();
	Scan(p->vertices, p->vertexCount, p->buffer, p->width, p->height);
	if (timer)
		timer->Pause();
	return new TestAnswer_ScanConversing(p->buffer, p->width, p->height);
}
void ScanConversingAlgorithm::Scan(Vector2Int* vertices, int vertexCount, int** buffer, int width, int height)
{

}
#pragma endregion

#pragma region TestCase_ScanConversing
TestCase_ScanConversing::TestCase_ScanConversing(Vector2Int* vertices, int vertexCount, int width, int height)
	:vertexCount(vertexCount), width(width), height(height)
{
	this->vertices = new Vector2Int[vertexCount];
	for (int i = 0; i < vertexCount; i++)
	{
		this->vertices[i] = vertices[i];
	}
	buffer = new int* [width];
	for (int i = 0; i < width; i++)
	{
		buffer[i] = new int[height];
		for (int j = 0; j < height; j++)
		{
			buffer[i][j] = 0;
		}
	}
}
TestCase_ScanConversing::~TestCase_ScanConversing()
{
	delete[] vertices;
	for (int i = 0; i < width; i++)
	{
		delete[] buffer[i];
	}
	delete[] buffer;
}
void TestCase_ScanConversing::Print() const
{
	cout << "顶点序列:";
	for (int i = 0; i < vertexCount; i++)
	{
		cout << vertices[i] << " ";
	}
	cout << endl;
	cout << "缓冲区大小:" << width << "×" << height << endl;
}
#pragma endregion


#pragma region TestAnswer_ScanConversing
void TestAnswer_ScanConversing::PrintBuffer(int** buffer, int width, int height)
{
	char* line = new char[width + 1];
	for (int i = height - 1; i >= 0; i--)
	{
		for (int j = 0; j < width; j++)
		{
			line[j] = buffer[j][i] + '0';
		}
		line[width] = '\0';
		cout << line << endl;
	}
}

TestAnswer_ScanConversing::TestAnswer_ScanConversing(int** buffer,int width,int height)
	:buffer(buffer), width(width), height(height)
{
}
bool TestAnswer_ScanConversing::Match(TestAnswer* other) const
{
	TestAnswer_ScanConversing* p = dynamic_cast<TestAnswer_ScanConversing*>(other);
	if (!p || !buffer || !p->buffer)
		return false;
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			if (buffer[i][j] != p->buffer[i][j])
				return false;
		}
	}
	return false;
}
void TestAnswer_ScanConversing::Print() const
{
	PrintBuffer(buffer, width, height);
}
#pragma endregion