#include "EdgeFlagAlgorithm.h"
#include"OrderedEdge.h"
using namespace std;

const int EdgeFlagAlgorithm::MARK = 2;

EdgeFlagAlgorithm* EdgeFlagAlgorithm::CreateEdgeFlagAlgorithm()
{
	return new EdgeFlagAlgorithm();
}

EdgeFlagAlgorithm::EdgeFlagAlgorithm()
	:xMin(0), yMin(0), xMax(0), yMax(0), buffer(nullptr), currentY(0)
{
}

void EdgeFlagAlgorithm::Scan(Vector2Int* vertices, int vertexCount, int** buffer, int width, int height)
{
	this->buffer = buffer;
	xMin = yMin = INT_MAX;
	xMax = yMax = INT_MIN;
	for (int i = 0; i < vertexCount; i++)
	{
		int x = vertices[i].x;
		int y = vertices[i].y;
		xMin = min(xMin, x);
		xMax = max(xMax, x);
		yMin = min(yMin, y);
		yMax = max(yMax, y);
		Discrete(vertices[i], vertices[(i + 1) % vertexCount]);
	}

	yMax--;
	currentY = yMin - 1;
	while (true)
	{
		currentY++;
		if (currentY > yMax)
			break;

		bool flag = false;
		for (int x = xMin; x <= xMax; x++)
		{
			if (buffer[x][currentY] == MARK)
				flag = !flag;
			buffer[x][currentY] = flag;
		}
	}
}

void EdgeFlagAlgorithm::Discrete(Vector2Int from, Vector2Int to)
{
	OrderedEdge* edge = OrderedEdge::TryCreateOrderedEdge(from, to);
	if (!edge)
		return;
	for (int y = edge->yMin; y <= edge->yMax; y++)
	{
		edge->MoveUp();
		buffer[edge->CurrentX()][y] = MARK - buffer[edge->CurrentX()][y]; //0→MARK,MARK→0
	}
}