#include "pch.h"
#include "CppUnitTest.h"
#include "..\second_work\node.h"
#include "..\second_work\line.h"
#include "..\second_work\lise.h"
#include "..\second_work\Cycle.h"
#include "..\second_work\rays.h"
#include "..\second_work\second_work.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			node a(1, 1), b(1, 1);
			Assert::AreEqual(a==b,true);
		}
		TEST_METHOD(TestMethod2)
		{
			node a(1, 1), b(-1, -1), c(0, 0);
			lise s(a, c);
			rays r(c, b);
			Assert::AreEqual(findIntersectionrs(r, s)==c,true);
		}
		TEST_METHOD(TestMethod3)
		{
			read_file("test1.txt");
			Assert::AreEqual(node_set.size()==999001,true);
			
		}
		TEST_METHOD(TestMethod4)
		{
			read_file("test2.txt");
			
			Assert::AreEqual(countn==249501,true);
			
		}
		TEST_METHOD(TestMethod5)
		{
			read_file("test3.txt");
			Assert::AreEqual(countn, 5);
			
		}
		TEST_METHOD(TestMethod6)
		{
			read_file("test4.txt");
			Assert::AreEqual(countn, 1);
			
		}
		TEST_METHOD(TestMethod7)
		{
			read_file("test5.txt");
			Assert::AreEqual(countn, 2);
			
		}
		TEST_METHOD(TestMethod8)
		{
			read_file("test5.txt");
			Delete("R 1 1 2 2");
			Assert::AreEqual(countn, 1);
			
		}
		TEST_METHOD(TestMethod9)
		{
			read_file("test5.txt");
			Delete("S 0 0 -1 -1");
			Assert::AreEqual(countn, 1);
			
		}
		TEST_METHOD(TestMethod10)
		{
			read_file("test5.txt");
			Delete("S 0 0 1 1");
			Assert::AreEqual(countn, 0);
			
		}
		TEST_METHOD(TestMethod11)
		{
			read_file("test5.txt");
			Delete("S 0 0 1 1");
			Add("S -1 -1 -2 -2");
			Assert::AreEqual(countn, 1);
			
		}
	};
}
