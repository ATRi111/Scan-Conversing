#include "XScanlineAlgorithm.h"
#include<vector>
using namespace std;

void XScanlineAlgorithm::Scan(Vector2Int* vertices, int vertexCount, int** buffer, int rowSize, int columnSize)
{
	vector<int> xs;
	orderedEdges = new OrderedEdgeContainer(vertices, vertexCount);
	activeEdges = new ActiveEdgeContainer(*orderedEdges);
	for (; activeEdges->MoveUp(xs);)
	{
		for (int i = 0; i < xs.size(); i+= 2)
		{
			for (int j = xs[i]; i < xs[i + 1]; i++)		//[lfet,right)
			{
				buffer[j][activeEdges->currentY] = 1;
			}
		}
	}
}