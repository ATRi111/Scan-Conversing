#include "ScanlineAlgorithm.h"
using namespace std;

#pragma region ScanConversingAlgorithm
TestAnswer* ScanConversingAlgorithm::Run(TestCase* t, Stopwatch* timer)
{
	return nullptr;
}
void ScanConversingAlgorithm::Scan(Vector2Int* vertices, int vertexCount, int** buffer, int rowSize, int columnSize)
{

}
#pragma endregion

#pragma region TestCase_ScanConversing
TestCase_ScanConversing::TestCase_ScanConversing(Vector2Int* vertices, int vertexCount, int rowSize, int columnSize)
	:vertexCount(vertexCount), rowSize(rowSize), columnSize(columnSize)
{
	this->vertices = new Vector2Int[vertexCount];
	for (int i = 0; i < vertexCount; i++)
	{
		this->vertices[i] = vertices[i];
	}
	buffer = new int* [rowSize];
	for (int i = 0; i < rowSize; i++)
	{
		buffer[i] = new int[columnSize];
	}
}
TestCase_ScanConversing::~TestCase_ScanConversing()
{
	delete[] vertices;
	for (int i = 0; i < rowSize; i++)
	{
		delete[] buffer[i];
	}
	delete[] buffer;
}
#pragma endregion


#pragma region TestAnswer_ScanConversing
TestAnswer_ScanConversing::TestAnswer_ScanConversing(int** buffer,int rowSize,int columnSize)
	:buffer(buffer), rowSize(rowSize), columnSize(columnSize)
{
}
bool TestAnswer_ScanConversing::Match(TestAnswer* other) const
{
	TestAnswer_ScanConversing* p = dynamic_cast<TestAnswer_ScanConversing*>(other);
	if (!p || !buffer || !p->buffer)
		return false;
	for (int i = 0; i < rowSize; i++)
	{
		for (int j = 0; j < columnSize; j++)
		{
			if (buffer[i][j] != p->buffer[i][j])
				return false;
		}
	}
	return false;
}
void TestAnswer_ScanConversing::Print() const
{
	cout << endl;
	char* line = new char[columnSize + 1]; 
	for (int i = 0; i < rowSize; i++)
	{
		for (int j = 0; j < columnSize; j++)
		{
			line[j] = buffer[i][j] + '0';
		}
		line[columnSize] = '\0';
		cout << line << endl;
	}
}
#pragma endregion