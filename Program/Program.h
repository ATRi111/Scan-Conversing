#pragma once
#include"ScanConversing.h"
#include"Testframework.h"
#include"Vector2Int.h"

std::mt19937 engine(std::chrono::system_clock::now().time_since_epoch().count());
std::uniform_int_distribution<int> distrbution(3, 8);

TestCase_ScanConversing* GenerateTestCase()
{
	int width = 10;
	int height = 10;
	int vertexCount = distrbution(engine);
	Vector2Int* vertices = new Vector2Int[vertexCount];
	PolygonGenerator::Generate(vertices, vertexCount, width, height);
	return new TestCase_ScanConversing(vertices, vertexCount, width, height);
}

void Test(std::string path, int times, const std::function<Algorithm* ()>& CreateSolution)
{
	TestSerializer_ScanConversing serializer;
	TestSet set = TestSet(serializer.DeserializeFrom(path));
	set.CreateSolution = CreateSolution;

	set.AccuracyTest(3);
	set.TimeTest(times);

	set.DeleteAnswers();
	set.DeleteCases();
	std::cout << std::endl;
}

void TestXScanlineAlgorithm(std::string path, int times)
{
	std::cout << "X扫描线算法:" << std::endl;
	Test(path, times, XScanlineAlgorithm::CreateXScanlineAlgorithm);
}

void TestEdgeFlagAlgorithm(std::string path, int times)
{
	std::cout << "边标志算法:" << std::endl;
	Test(path, times, EdgeFlagAlgorithm::CreateEdgeFlagAlgorithm);
}

//调用此函数会导致存放答案的文件被修改
void GenerateAnswers(std::string path)
{
	std::vector<TestCase*> cases;
	std::vector<TestAnswer*> answers;
	for (int i = 0; i < 100; i++)
	{
		cases.push_back(GenerateTestCase());
	}
	TestSet set(cases, answers, XScanlineAlgorithm::CreateXScanlineAlgorithm);
	set.GenerateAnswers();
	TestSerializer_ScanConversing s;
	s.SerializeTo(path, set);
}