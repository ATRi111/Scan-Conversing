#include "ScanlineAlgorithm.h"

TestAnswer* ScanConversingAlgorithm::Run(TestCase* t, Stopwatch* timer)
{
	return nullptr;
}

void ScanConversingAlgorithm::Scan(Vector2Int* vertices, int vertexCount, int** buffer, int width, int height)
{

}


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
