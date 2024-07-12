#include "ScanConversingAlgorithm.h"
using namespace std;

#pragma region ScanConversingAlgorithm
TestAnswer* ScanConversingAlgorithm::Run(TestCase* t, Stopwatch* timer)
{
	TestCase_ScanConversing* p = dynamic_cast<TestCase_ScanConversing*>(t);
	if (timer)
		timer->Start();
	Scan(p->vertices, p->vertexCount, p->buffer, p->width, p->height);
	if (timer)
		timer->Pause();
	return new TestAnswer_ScanConversing(p->buffer, p->width, p->height);
}
void ScanConversingAlgorithm::Scan(Vector2Int* vertices, int vertexCount, int** buffer, int width, int height)
{

}
#pragma endregion

#pragma region TestCase_ScanConversing
TestCase_ScanConversing::TestCase_ScanConversing(Vector2Int* vertices, int vertexCount, int width, int height)
	:vertexCount(vertexCount), width(width), height(height)
{
	this->vertices = new Vector2Int[vertexCount];
	for (int i = 0; i < vertexCount; i++)
	{
		this->vertices[i] = vertices[i];
	}
	buffer = new int* [width];
	for (int i = 0; i < width; i++)
	{
		buffer[i] = new int[height];
		for (int j = 0; j < height; j++)
		{
			buffer[i][j] = 0;
		}
	}
}
TestCase_ScanConversing::~TestCase_ScanConversing()
{
	delete[] vertices;
	for (int i = 0; i < width; i++)
	{
		delete[] buffer[i];
	}
	delete[] buffer;
}
TestCase_ScanConversing* TestCase_ScanConversing::Clone() const
{
	return new TestCase_ScanConversing(vertices, vertexCount, width, height);
}
void TestCase_ScanConversing::Print() const
{
	cout << "顶点序列:";
	for (int i = 0; i < vertexCount; i++)
	{
		cout << vertices[i] << " ";
	}
	cout << endl;
	cout << "缓冲区大小:" << width << "×" << height << endl;
}
#pragma endregion


#pragma region TestAnswer_ScanConversing
void TestAnswer_ScanConversing::PrintBuffer(int** buffer, int width, int height)
{
	char* line = new char[width + 1];
	for (int i = height - 1; i >= 0; i--)
	{
		for (int j = 0; j < width; j++)
		{
			line[j] = buffer[j][i] + '0';
		}
		line[width] = '\0';
		cout << line << endl;
	}
}

TestAnswer_ScanConversing::TestAnswer_ScanConversing(int** buffer,int width,int height)
	:buffer(buffer), width(width), height(height)
{
}
bool TestAnswer_ScanConversing::Match(TestAnswer* other) const
{
	TestAnswer_ScanConversing* p = dynamic_cast<TestAnswer_ScanConversing*>(other);
	if (!p || !buffer || !p->buffer)
		return false;
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			if (buffer[i][j] != p->buffer[i][j])
				return false;
		}
	}
	return false;
}
void TestAnswer_ScanConversing::Print() const
{
	PrintBuffer(buffer, width, height);
}
#pragma endregion

void TestSerializer_ScanConversing::Serialize(std::ofstream& stream, const TestSet& set) const
{
	for (int i = 0; i < set.cases.size(); i++)
	{
		TestCase_ScanConversing* c = dynamic_cast<TestCase_ScanConversing*>(set.cases[i]);
		TestAnswer_ScanConversing* a = dynamic_cast<TestAnswer_ScanConversing*>(set.answers[i]);
		if (c && a)
		{
			stream << c->vertexCount << " ";
			for (int i = 0; i < c->vertexCount; i++)
			{
				stream << c->vertices[i] << " ";
			}
			stream << c->width << " ";
			stream << c->height << " ";
			for (int i = 0; i < c->width; i++)
			{
				for (int j = 0; j < c->height; j++)
				{
					stream << c->buffer[i][j];
				}
			}
			stream << endl;
		}
	}
}

TestSet TestSerializer_ScanConversing::Deserialize(std::ifstream& stream) const
{
	std::vector<TestCase*> cases;
	std::vector<TestAnswer*> answers;
	string s;
	while (getline(stream, s))
	{
		int vertexCount, width, height;
		Vector2Int* vertices;
		vector<string> ss = Split(s, ' ');
		int i = 0;
		try
		{
			vertexCount = stoi(ss[i]);
			i++;
			vertices = new Vector2Int[vertexCount];
			for (int j = 0; j < vertexCount; j++)
			{
				vertices[j] = Vector2Int::FromString(ss[i]);
				i++;
			}
			width = stoi(ss[i]);
			i++;
			height = stoi(ss[i]);
			i++;
			cases.emplace_back(new TestCase_ScanConversing(vertices, vertexCount, width, height));

			int** buffer = new int* [width];
			string sbuffer = ss[i];
			i = 0;
			for (int j = 0; j < width; j++)
			{
				buffer[j] = new int[height];
			}
			for (int j = 0; j < width; j++)
			{
				for (int k = 0; k < height; k++)
				{
					buffer[j][k] = stoi(ss[i]);
					i++;
				}
			}
			answers.emplace_back(new TestAnswer_ScanConversing(buffer, width, height));
		}
		catch (...)
		{
			continue;
		}
	}
	return TestSet(cases, answers, Algorithm::CreateDefault);
}