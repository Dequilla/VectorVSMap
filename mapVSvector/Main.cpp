#include <chrono>

#include <map>
#include <vector>
#include <map>
#include <unordered_map>

#include <iostream>

typedef std::chrono::high_resolution_clock Timer;
typedef std::chrono::high_resolution_clock::time_point TimePoint;
typedef std::chrono::high_resolution_clock::duration TimeDuration;

#define ELEMENT unsigned int
#define TEST_NR 100
#define NR_OF_TESTS 1000

TimeDuration testVector()
{
	Timer timer;

	std::cout << "Checking std::vector iteration speed..." << std::endl;
	std::vector<ELEMENT> vector;

	ELEMENT index = 0;
	for (int i = 0; i < TEST_NR; i++)
	{
		vector.push_back(index++);
	}

	ELEMENT total = 0;
	TimePoint start = timer.now();
	for (auto& ele : vector)
	{
		total += ele;
	}
	return timer.now() - start;
}

TimeDuration testUMap()
{
	Timer timer;

	std::cout << "Checking std::unordered_map iteration speed..." << std::endl;
	std::unordered_map<unsigned int, ELEMENT> umap;

	ELEMENT index = 0;
	for (int i = 0; i < TEST_NR; i++)
	{
		umap.emplace(index, index++);
	}

	ELEMENT total = 0;
	TimePoint start = timer.now();
	for (auto& ele : umap)
	{
		total += ele.second;
	}
	return timer.now() - start;
}

TimeDuration testMap()
{
	Timer timer;

	std::cout << "Checking std::map iteration speed..." << std::endl;
	std::map<unsigned int, ELEMENT> map;

	ELEMENT index = 0;
	for (int i = 0; i < TEST_NR; i++)
	{
		map.emplace(index, index++);
	}

	ELEMENT total = 0;
	TimePoint start = timer.now();
	for (auto& ele : map)
	{
		total += ele.second;
	}
	return timer.now() - start;
}

int main(int argc, char** argv)
{
	std::cout << "Testing iteration speeds" << std::endl;
	std::cout << "Total elements: " << TEST_NR << std::endl;

	TimeDuration vectorT = TimeDuration::zero();
	for (int i = 0; i < NR_OF_TESTS; i++)
	{
		vectorT = (testVector() + vectorT) / 2;
	}

	TimeDuration mapT = TimeDuration::zero();
	for (int i = 0; i < NR_OF_TESTS; i++)
	{
		mapT = (testMap() + mapT) / 2;
	}

	TimeDuration umapT = TimeDuration::zero();
	for (int i = 0; i < NR_OF_TESTS; i++)
	{
		umapT = (testUMap() + umapT) / 2;
	}

	std::cout << "\n\nTesting finished" << std::endl;
	std::cout << "##################################" << std::endl;
	std::cout << "Total elements per container: " << TEST_NR << std::endl;
	std::cout << "Total tests per container:    " << NR_OF_TESTS << std::endl;
	std::cout << "##################################" << std::endl;
	std::cout << "Type   # Duration" << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << "Vector # " << vectorT.count() << "ns" << std::endl;
	std::cout << "UMap   # " << umapT.count() << "ns" << std::endl;
	std::cout << "Map    # " << mapT.count() << "ns" << std::endl;

	std::cin.get();
	return 0;
}