#pragma once
#include"Testframework.h"
#include"Vector2Int.h"

class ScanConversingAlgorithm : public Algorithm
{
public:
	TestAnswer* Run(TestCase* t, Stopwatch* timer) override;
	virtual void Scan(Vector2Int* vertices, int vertexCount, int** buffer, int width, int height);
};

struct TestCase_ScanConversing : TestCase
{
	Vector2Int* vertices;
	int vertexCount;
	int** buffer;
	int width, height;
	TestCase_ScanConversing(Vector2Int* vertices, int vertexCount, int width, int height);
	~TestCase_ScanConversing();
	void Print() const override;
};

struct TestAnswer_ScanConversing : TestAnswer
{
	static void PrintBuffer(int** buffer, int width, int height);
	//this class do not takes ownership of buffer
	int** buffer;
	int width;
	int height;
	TestAnswer_ScanConversing(int** buffer, int width, int height);
	bool Match(TestAnswer* other) const override;
	void Print() const override;
};