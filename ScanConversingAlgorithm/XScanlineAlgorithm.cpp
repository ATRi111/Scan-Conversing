#include "XScanlineAlgorithm.h"
#include<vector>
using namespace std;

XScanlineAlgorithm* XScanlineAlgorithm::CreateXScanlineAlgorithm()
{
	return new XScanlineAlgorithm();
}

XScanlineAlgorithm::XScanlineAlgorithm()
	:activeEdges(nullptr), orderedEdges(nullptr)
{
}

XScanlineAlgorithm::~XScanlineAlgorithm()
{
	delete activeEdges;
	delete orderedEdges;
}

void XScanlineAlgorithm::Scan(Vector2Int* vertices, int vertexCount, int** buffer, int width, int height)
{
	vector<int> xs;
	orderedEdges = new OrderedEdgeContainer(vertices, vertexCount);
	activeEdges = new ActiveEdgeContainer(*orderedEdges);
	for (; activeEdges->MoveUp(xs);)
	{
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