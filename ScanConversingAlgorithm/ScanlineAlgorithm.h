#pragma once
#include"Testframework.h"
#include"Vector2Int.h"

class ScanlineAlgorithm : public Algorithm
{
	TestAnswer* Run(TestCase* t, Stopwatch* timer) override;
	virtual void Scan(Vector2Int* vertices, int vertexCount, int*** buffer, int width, int height);
};