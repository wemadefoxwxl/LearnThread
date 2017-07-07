#ifndef  _TESTTHREAD_H_
#define  _TESTTHREAD_H_

#include "Thread.h"

class TestThread : public Thread
{
public:
	explicit TestThread(int count = 0);
	~TestThread();

private:
	void Run();

	int count_;
};

#endif
