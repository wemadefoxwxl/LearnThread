#include <iostream>
#include "Thread.h"

using std::cout;
using std::endl;

Thread::Thread(ThreadFunc func): func_(func) ,autoDelete_(false)
{

}

Thread::~Thread()
{

}

void Thread::Start()
{
	pthread_create(&threadId_,NULL,ThreadRoutinue,this);
}

void Thread::Join()
{
	pthread_join(threadId_,NULL);
}

void* Thread::ThreadRoutinue(void *arg)
{
	Thread* thread = static_cast<Thread*>(arg);
	thread->Run();
	if(thread->autoDelete_)
		delete thread;
	return NULL;
}

void Thread::Run()
{
	func_();
}

void Thread::SetAutoDelete(bool autoDelete)
{
	autoDelete_ = autoDelete;
}
