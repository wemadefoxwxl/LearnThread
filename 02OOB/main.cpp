#include <iostream>
#include <functional>
#include <unistd.h>
#include "Thread.h"

using std::cout;
using std::endl;


void ThreadFunc()
{
	cout << "ThreadFunc" << endl;
}

void ThreadFunc2(int count)
{
	while(count--)
	{
		// cout << "ThreadFunc2" << "  " << count << endl;
		cout << "ThreadFunc2" << endl;
		sleep(1);
	}
}

class Foo
{
public:
	Foo(int count) : count_(count)
	{

	}

	void MemberFun()
	{
		while(count_--)
		{
			// cout << "MemberFun" << "  " << count_ << endl;
			cout << "MemberFun" << endl;
			sleep(1);
		}
	}

	void MemberFun2(int x)
	{
		while(count_--)
		{
			// cout << "MemberFun2" << "  " << count_ << "  " << x << endl;
			cout << "MemberFun2 " << endl;
			sleep(1); 
		}
	}

private:
	int count_;
};


int main()
{
	Thread t1(ThreadFunc);
	Thread t2(std::bind(ThreadFunc2,2));
	Foo foo(3);
	Thread t3(std::bind(&Foo::MemberFun,&foo));
	Foo foo2(3);
	Thread t4(std::bind(&Foo::MemberFun2,&foo2,100));

	t1.Start();
	t2.Start();
	t3.Start();
	t4.Start();

	t1.Join();
	t2.Join();
	t3.Join();
	t4.Join();

	return 0;
}