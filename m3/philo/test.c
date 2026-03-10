#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
// #include <sys/time.h>
#define NUM_TIMES 5

/*
// gettimeofday
int	main(void)
{
	int				i;
	struct timeval	tv;

	for (i = 0; i < NUM_TIMES; i++)
	{
		gettimeofday(&tv, NULL);
		printf("%ld.%ld\n", (long)tv.tv_sec, (long)tv.tv_usec);
		sleep(1);
	}
	return (0);
}
*/

/* 
// pthread_create()
void	*foo(void *arg)
{
	printf("Created a new thread\n");
	printf("foo thread id: %lu\n", (unsigned long)pthread_self());
	return (NULL);
}

int	main(void)
{
	pthread_t	thread1;
	printf("main thread id: %lu\n", (unsigned long)pthread_self());
	pthread_create(&thread1, NULL, foo, NULL);
	pthread_join(thread1, NULL);
	return 0;
}
*/

/*
// pthread_join()
void	*foo(void *arg)
{
	printf("%s\n", (char *)arg);
	return (NULL);
}

int	main(void)
{
	pthread_t	thread1;
	pthread_t	thread2;

	pthread_create(&thread1, NULL, foo, (void *) "Thread1 is running.");
	pthread_create(&thread2, NULL, foo, (void *) "Thread2 is running.");

	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);

	printf("Both threads end.\n");

	return 0;

}
*/

/*
void	*my_thread_func(void *arg)
{
	printf("Thread1 is running\n");
	sleep(30);
	printf("Thread1 finished\n");
	return (NULL);
}

int	main(void)
{
	pthread_t	thread1;

	pthread_create(&thread1, NULL, my_thread_func, NULL);
	// pthread_detach(thread1);
	// sleep(100);
	// pthread_join(thread1, NULL);
	
	// printf("Main thread continues\n");
}
*/

/*
#include <stdio.h>
#include <unistd.h>

void *foo(void *arg)
{
	printf("foo thread id: %lu\n", (unsigned long)pthread_self());
	sleep(100);

    return NULL;
}

int main(void)
{
    int i = 0;
    while (1)
    {
        pthread_t t;
        int ret = pthread_create(&t, NULL, foo, NULL);
        if (ret != 0)
        {
            printf("pthread_create failed at %d\n", i);
			perror("error");
            break;
        }

        pthread_detach(t);
        i++;
    }
    sleep(100);
    return 0;
}
*/

/* 
// pthread_join
void	*foo(void *arg)
{
	printf("%s\n", (char *)arg);
	return (NULL);
}

int	main(void)
{
	pthread_t	thread1;
	pthread_t	thread2;

	pthread_create(&thread1, NULL, foo, (void *)"Thread1 is running.");
	pthread_create(&thread2, NULL, foo, (void *)"Thread2 is running.");

	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);

	printf("Both threads end\n");
	return (0);
}
*/
