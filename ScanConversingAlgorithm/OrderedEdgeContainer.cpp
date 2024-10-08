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
    int size = yMax - yMin + 1;
    list = new OrderedEdge * [size];
    for (int i = 0; i < size; i++)
    {
        list[i] = nullptr;
    }
    for (int i = 0; i < vertexCount; i++)
    {
        from = vertices[i];
        to = vertices[(i + 1) % vertexCount];
        OrderedEdge* edge = OrderedEdge::TryCreateOrderedEdge(from, to);
        if (edge)
            Add(edge);
    }
}

OrderedEdge* OrderedEdgeContainer::GetHead(int y) const
{
    return list[y - yMin];
}

OrderedEdge** OrderedEdgeContainer::GetHeadPtr(int y) const
{
    return list + (y - yMin);
}

void OrderedEdgeContainer::Add(OrderedEdge* edge) const
{
    OrderedEdge** headPtr = GetHeadPtr(edge->yMin);
    edge->next = *headPtr;  //insert to head
    *headPtr = edge;
}
