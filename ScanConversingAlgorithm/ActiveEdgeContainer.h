#pragma once
#include<vector>
#include"OrderedEdge.h"
#include"OrderedEdgeContainer.h"

class ActiveEdgeContainer
{
public:
	std::vector<OrderedEdge*> edges;
	//this  class do not takes ownership of container
	OrderedEdgeContainer& container;
	int currentY;

	ActiveEdgeContainer(OrderedEdgeContainer& container);
	bool MoveUp(std::vector<int> ret);
};

