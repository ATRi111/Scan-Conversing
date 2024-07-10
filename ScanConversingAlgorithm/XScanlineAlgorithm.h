#pragma once
#include"ScanConversingAlgorithm.h"
#include"OrderedEdge.h"
#include"OrderedEdgeContainer.h"
#include"ActiveEdgeContainer.h"

class XScanlineAlgorithm : public ScanConversingAlgorithm
{
public:
	OrderedEdgeContainer* orderedEdges;
	ActiveEdgeContainer* activeEdges;
	void Scan(Vector2Int* vertices, int vertexCount, int** buffer, int rowSize, int columnSize) override;
};