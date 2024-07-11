#include "ActiveEdgeContainer.h"
#include<algorithm>

ActiveEdgeContainer::ActiveEdgeContainer(OrderedEdgeContainer& container)
	:container(container)
{
	currentY = container.yMin - 1;
}

bool ActiveEdgeContainer::MoveUp(std::vector<int>& ret)
{
    currentY++;
    for (int i = 0; i < edges.size(); i++)
    {
        if (currentY > edges[i]->yMax)
        {
            edges.erase(edges.begin() + i);
            i--;
        }
    }
    OrderedEdge* p = container.GetHead(currentY);
    for (;p; p = p->next)
    {
        edges.push_back(p);
    }
    if (edges.size() == 0)
        return false;

    std::sort(edges.begin(), edges.end(), OrderedEdge::Compare);
    for (int i = 0; i < edges.size(); i++)
    {
        ret.push_back(edges[i]->CurrentX());
    }
    return true;
}
