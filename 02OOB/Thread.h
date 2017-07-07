#ifndef _THREAD_H_
#define _THREAD_H_

#include <pthread.h>
#include <functional>

class Thread
{
public:
	typedef std::function<void ()> ThreadFunc;

	Thread(ThreadFunc func);
	~Thread();

	void Start();
	void Join();

	void SetAutoDelete(bool autoDelete);
private:
	static void* ThreadRoutinue(void* arg);
	void Run();
	ThreadFunc func_;
	pthread_t threadId_;
	bool autoDelete_;
};

#endif 