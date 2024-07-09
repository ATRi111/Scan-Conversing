#pragma once
#include<iostream>

struct OrderedEdge
{
	static bool Compare(OrderedEdge x, OrderedEdge y)
	{
		
	}
	int yMin, yMax;
	OrderedEdge* next;	//only used in linkedlist

	int CurrentX() const
	{
		return std::lroundf(currentX);
	}
private:
	float currentX;
};