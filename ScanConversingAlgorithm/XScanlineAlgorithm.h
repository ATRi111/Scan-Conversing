#pragma once
#include"ScanConversingAlgorithm.h"
#include"OrderedEdge.h"
#include"OrderedEdgeContainer.h"
#include"ActiveEdgeContainer.h"

class XScanlineAlgorithm : public ScanConversingAlgorithm
{
public:
	static XScanlineAlgorithm* CreateXScanlineAlgorithm();
	OrderedEdgeContainer* orderedEdges;
	ActiveEdgeContainer* activeEdges;
	XScanlineAlgorithm();
	~XScanlineAlgorithm();
	void Scan(Vector2Int* vertices, int vertexCount, int** buffer, int width, int height) override;
};