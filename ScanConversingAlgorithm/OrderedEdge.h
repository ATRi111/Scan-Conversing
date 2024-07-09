#pragma once
#include<iostream>
#include"Vector2Int.h"

struct OrderedEdge
{
	static bool Compare(OrderedEdge* x, OrderedEdge* y);
	static OrderedEdge* TryCreateOrderedEdge(Vector2Int& a, Vector2Int& b);
	int yMin, yMax;
	float deltaX;
	OrderedEdge* next;	//only used in linkedList
	int CurrentX() const;
	void MoveUp();
private:
	float currentX;
	OrderedEdge(Vector2Int from, Vector2Int to);
};