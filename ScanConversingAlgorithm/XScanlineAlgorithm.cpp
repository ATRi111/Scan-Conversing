#include "XScanlineAlgorithm.h"
#include<vector>
using namespace std;

void XScanlineAlgorithm::Scan(Vector2Int* vertices, int vertexCount, int** buffer, int width, int height)
{
	vector<int> xs;
	orderedEdges = new OrderedEdgeContainer(vertices, vertexCount);
	activeEdges = new ActiveEdgeContainer(*orderedEdges);
	for (; activeEdges->MoveUp(xs);)
	{
		cout << xs.size() << endl;
		for (int i = 0; i < xs.size(); i+= 2)
		{
			for (int j = xs[i]; j < xs[i + 1]; j++)		//[left,right)
			{
				buffer[j][activeEdges->currentY] = 1;
			}
			xs.clear();
		}
	}
}