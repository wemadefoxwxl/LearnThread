#include <iostream>
#include <unistd.h>
#include "TestThread.h"

using std::cout;
using std::endl;


TestThread::TestThread(int count) : count_(count)
{
	cout << "TestThread(int count) ..." << endl;
}

TestThread::~TestThread()
{
	cout << "~TestThread..." << endl;
}

void TestThread::Run()
{
	while(count_--)
	{	
		cout << "this is a test ... " << "  " << count_ << endl;
		sleep(1);
	}
}