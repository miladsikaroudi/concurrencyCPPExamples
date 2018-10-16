//// Concurrency_Presentation.cpp : Defines the entry point for the console application.
////
//
#include "stdafx.h"
//#include <iosfwd>
//#include <string>
//#include <iostream>
//#include <future>
//#include <numeric>
//
//
//void called_from_async()
//{
//	std::cout << "Async call" << std::endl;
//}
//
//int twice(int m)
//{
//	return 2 * m;
//}
//
//template <typename RandomIt>
//int parallel_sum(RandomIt beg, RandomIt end)
//{
//	auto len = end - beg;
//	if (len < 1000)
//		return std::accumulate(beg, end, 0);
//
//	RandomIt mid = beg + len / 2;
//	auto handle = std::async(std::launch::async,
//		parallel_sum<RandomIt>, mid, end);
//	int sum = parallel_sum(beg, mid);
//	return sum + handle.get();
//}
//
//int main(int argc, char* argv[])
//{
//	int testNUmber = std::stoi(argv[1]);
//	switch (testNUmber)
//	{
//	case 1:
//	{
//		std::future<void> result(std::async(called_from_async));
//		std::cout << "Message from main." << std::endl;
//		//ensure that called_from_async is launched synchronously
//		//if it wasn't already launched
//		result.get();
//	}
//	case 2:
//	{
//		std::future<int> result(std::async([](int m, int n) { return m + n; }, 2, 4));
//		std::cout << "Message from main." << std::endl;
//		//retrive and print the value stored in the future
//		std::cout << result.get() << std::endl;
//	}
//	case 3:
//	{
//		std::vector<std::future<int>> futures;
//
//		for (int i = 0; i < 10; ++i)
//		{
//			futures.push_back(std::async(twice, i));
//		}
//		//retrive and print the value stored in the future
//		for (auto &e : futures)
//		{
//			std::cout << e.get() << std::endl;
//		}
//	}
//	case 4:
//	{
//		std::vector<int> v(10000, 1);
//		std::cout << "The sum is " << parallel_sum(v.begin(), v.end()) << '\n';
//	}
//	}
//	return 0;
//}
//
