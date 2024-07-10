#include "OrderedEdgeContainer.h"
using namespace std;

OrderedEdgeContainer::OrderedEdgeContainer(Vector2Int* vertices, int vertexCount)
{
    yMin = INT_MAX;
    yMax = INT_MIN;
    Vector2Int from, to;
    for (int i = 0; i < vertexCount; i++)
    {
        yMin = min(yMin, vertices[i].y);
        yMax = max(yMax, vertices[i].y);
    }
    list = new OrderedEdge * [yMax - yMin + 1];
    for (int i = 0; i < vertexCount; i++)
    {
        from = vertices[i];
        to = vertices[(i + 1) % vertexCount];
        OrderedEdge* edge = OrderedEdge::TryCreateOrderedEdge(from, to);
        if (edge)
            Add(edge);
    }
}

OrderedEdge* OrderedEdgeContainer::GetHead(int y)
{
    return list[y - yMin];
}

OrderedEdge** OrderedEdgeContainer::GetHeadPtr(int y)
{
    return list + (y - yMin);
}

void OrderedEdgeContainer::Add(OrderedEdge* edge)
{
    OrderedEdge** headPtr = GetHeadPtr(edge->yMin);
    edge->next = *headPtr;  //insert to head
    *headPtr = edge;
}
