#define _USE_MATH_DEFINES
#include "PolygonGenerator.h"
#include<cmath>
#include<unordered_set>
#include<chrono>
using namespace std;

namespace std 
{
	template <>
	struct hash<Vector2Int> 
	{
		size_t operator()(const Vector2Int& v) const 
		{
			return hash<int>()(v.x) ^ hash<int>()((v.y));
		}
	}; 
}

mt19937 PolygonGenerator::engine(std::chrono::system_clock::now().time_since_epoch().count());

void PolygonGenerator::Generate(Vector2Int* vertices,int vertexCount, int width, int height)
{
	unordered_set<Vector2Int> temp;
	Vector2Int center(width / 2, height / 2);
	VertexComparer comparer(center);

	uniform_int_distribution<int> dx(0, width - 1);
	uniform_int_distribution<int> dy(0, height - 1);
	for (int i = 0; i < vertexCount; i++)
	{
		Vector2Int v(dx(engine), dy(engine));
		if (v == center || temp.count(v))
			i--;
		else
			temp.insert(v);
	}
	int i = 0;
	for(Vector2Int v : temp)
	{
		vertices[i] = v;
		i++;
	}
	sort(vertices,vertices + i, 
		[&comparer] (const Vector2Int& a, const Vector2Int& b) {return comparer.Compare(a, b);} );
}

VertexComparer::VertexComparer(Vector2Int center)
	:center(center)
{

}

bool VertexComparer::Compare(Vector2Int a, Vector2Int b) const
{
	double aa = ToAngle(a - center);
	double ab = ToAngle(b - center);
	return aa < ab;
}

double VertexComparer::ToAngle(Vector2Int v)
{
	double angle = -atan2(v.x, v.y);
	double _2Pi = 2 * M_PI;
	angle += _2Pi;
	int i = (int)(angle / _2Pi);
	angle -= i * _2Pi;
	return angle;
}