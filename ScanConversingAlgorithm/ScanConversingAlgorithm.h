#pragma once
#include"Testframework.h"
#include"Vector2Int.h"

class ScanConversingAlgorithm : public Algorithm
{
public:
	TestAnswer* Run(TestCase* t, Stopwatch* timer) override;
	virtual void Scan(Vector2Int* vertices, int vertexCount, int** buffer, int rowSize, int columnSize);
};

struct TestCase_ScanConversing : TestCase
{
	Vector2Int* vertices;
	int vertexCount;
	int** buffer;
	int rowSize, columnSize;
	TestCase_ScanConversing(Vector2Int* vertices, int vertexCount, int rowSize, int columnSize);
	~TestCase_ScanConversing();
	void Print() const override;
};

struct TestAnswer_ScanConversing : TestAnswer
{
	//this class do not takes ownership of buffer
	int** buffer;
	int rowSize;
	int columnSize;
	TestAnswer_ScanConversing(int** buffer, int rowSize, int columnSize);
	bool Match(TestAnswer* other) const override;
	void Print() const override;
};