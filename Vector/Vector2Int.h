#pragma once
#include<string>
#include<iostream>
#include<vector>
#include<ctype.h>

inline std::vector<std::string> SplitVector(std::string s)
{
	if (!isdigit(s[0]))
		s = s.substr(1, s.length() - 2);
	std::vector<std::string> ret;
	size_t i = s.find_first_of(',');
	while (i != std::string::npos)
	{
		ret.emplace_back(s.substr(0, i));
		if (i + 1 >= s.length())
		{
			s = "";
			break;
		}
		else
			s = s.substr(i + 1);
		i = s.find_first_of(',');
	}
	if (s != "")
	{
		ret.push_back(s);
	}
	return ret;
}

struct Vector2Int
{
	static Vector2Int FromString(std::string s)
	{
		auto ss = SplitVector(s);
		int x = std::stoi(ss[0]);
		int y = std::stoi(ss[1]);
		return Vector2Int(x, y);
	}

	const static Vector2Int Zero;
	const static Vector2Int One;
	const static Vector2Int Up;
	const static Vector2Int Down;
	const static Vector2Int Right;
	const static Vector2Int Left;

	int x, y;
	Vector2Int()
		:x(0), y(0)
	{

	}
	Vector2Int(int x, int y)
		:x(x), y(y)
	{

	}
	Vector2Int& operator=(const Vector2Int& v)
	{
		x = v.x;
		y = v.y;
		return *this;
	}
	bool operator==(const Vector2Int& v) const
	{
		return x == v.x && y == v.y;
	}
	Vector2Int operator+(const Vector2Int& v) const
	{
		return Vector2Int(x + v.x, y + v.y);
	}
	Vector2Int operator-() const
	{
		return Vector2Int(-x, -y);
	}
	Vector2Int operator-(const Vector2Int& v) const
	{
		return Vector2Int(x - v.x, y - v.y);
	}
	Vector2Int operator*(int i) const
	{
		return Vector2Int(i * x, i * y);
	}

	int SqrMagnitude() const
	{
		return x * x + y * y;
	}
};

inline Vector2Int operator*(int i, const Vector2Int& v)
{
	return Vector2Int(i * v.x, i * v.y);
}
inline std::ostream& operator<<(std::ostream& stream, const Vector2Int& v)
{
	stream << "(" << v.x << "," << v.y << ")";
	return stream;
}

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