#pragma once
#include"Vector2Int.h"
#include"OrderedEdge.h"

class OrderedEdgeContainer
{
public:
	int yMin, yMax;
	OrderedEdge** list;
	OrderedEdgeContainer(Vector2Int* vertices, int vertexCount);
	OrderedEdge* GetHead(int y);
	OrderedEdge** GetHeadPtr(int y);
	void Add(OrderedEdge* edge);
};

