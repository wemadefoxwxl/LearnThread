#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "threadpool.h"

// 任务
void* mytask(void *arg)
{
	printf("thread 0x%x is working on task %d\n", (int)pthread_self(), *(int*)arg);
	sleep(1);
	free(arg);
	return NULL;
}

void* mytask2(void* arg)
{
	printf("task is %d\n", *(int*)arg);	
	return NULL;
}

int main(void)
{
	threadpool_t pool;
	threadpool_init(&pool, 5);

	int i;
	for (i=0; i<100; i++)
	{
//		消费者线程
//		解决竟态问题
		int *arg = (int *)malloc(sizeof(int));
		*arg = i;
		threadpool_add_task(&pool,mytask2,arg);
		threadpool_add_task(&pool, mytask, arg);
	}

	//sleep(15);
	threadpool_destroy(&pool);
	return 0;
}
