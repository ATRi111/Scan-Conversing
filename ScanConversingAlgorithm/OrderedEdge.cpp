#include "OrderedEdge.h"

bool OrderedEdge::Compare(OrderedEdge* x, OrderedEdge* y)
{
    if (x->currentX < y->currentX)
        return true;
    if (x->currentX > y->currentX)
        return false;
    if (x->deltaX < y->deltaX)
        return true;
    return false;
}
OrderedEdge* OrderedEdge::TryCreateOrderedEdge(Vector2Int& a, Vector2Int& b)
{
    if (a.y == b.y)
        return nullptr;
    if (a.y > b.y)
    {
        Vector2Int temp = a;
        a = b;
        b = temp;
    }
    return new OrderedEdge(a, b);
}
int OrderedEdge::CurrentX() const
{
	return lroundf(currentX);
}
OrderedEdge::OrderedEdge(Vector2Int from, Vector2Int to)
    :yMin(from.y), yMax(to.y - 1), next(nullptr)    //[down.up)
{
    deltaX = (to.x - from.x) / (float)(to.y - from.y);
    currentX = deltaX * (yMin - from.y - 1) + from.x;
}
void OrderedEdge::MoveUp()
{
    currentX += deltaX;
}