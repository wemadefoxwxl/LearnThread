#include <iostream>
#include <unistd.h>
#include "TestThread.h"

using std::cout;
using std::endl;

int main()
{
	// TestThread t(5);
	// t.Start();
	// t.Join();

	//设置线程的自动销毁
	TestThread* t2 = new TestThread(5);
	t2->SetAutoDelete(true);
	t2->Start();
	t2->Join();

	return 0;
}