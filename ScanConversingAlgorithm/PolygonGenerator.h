#pragma once
#include"Vector2Int.h"
#include<vector>
#include<random>

class PolygonGenerator
{
public:
	static std::mt19937 engine;
	static void Generate(Vector2Int* vertices, int vertexCount, int width, int height);
};

class VertexComparer
{
public:
	double static ToAngle(Vector2Int v);

	Vector2Int center;

	VertexComparer(Vector2Int center);
	bool Compare(Vector2Int a, Vector2Int b) const;
};