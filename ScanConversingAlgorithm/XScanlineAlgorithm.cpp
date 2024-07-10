#include "XScanlineAlgorithm.h"

void XScanlineAlgorithm::Scan(Vector2Int* vertices, int vertexCount, int** buffer, int rowSize, int columnSize)
{
	orderedEdges = OrderedEdgeContainer(vertices, vertexCount);
	activeEdges = ActiveEdgeContainer(orderedEdges);
}
