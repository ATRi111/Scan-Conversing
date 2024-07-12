#pragma once
#include"ScanConversingAlgorithm.h"

class EdgeFlagAlgorithm : public ScanConversingAlgorithm
{
	const static int MARK;
public:
	static EdgeFlagAlgorithm* CreateEdgeFlagAlgorithm();
	int xMin, xMax, yMin, yMax;
	int currentY;
	//this class does not take ownership of buffer
	int** buffer;

	EdgeFlagAlgorithm();
	void Scan(Vector2Int* vertices, int vertexCount, int** buffer, int width, int height) override;
	void Discrete(Vector2Int from, Vector2Int to);
};