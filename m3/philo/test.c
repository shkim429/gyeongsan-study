#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/time.h>
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


// static t_fork_status	pickup_fork(t_fork *fork, t_philo *philo)
// {
//     if (pthread_mutex_lock(&fork->mutex) != 0) /*  공유 자원 접근을 위해 lock */
// 		return (FORK_FAILURE);
// 	if (fork->is_taken)
// 	{
// 		if (pthread_mutex_unlock(&fork->mutex) != 0)
// 			return (FORK_FAILURE);
// 		return (FORK_BUSY);
// 	}
// 	fork->is_taken = true; /*  포크 잡은 상태 */
// 	if (pthread_mutex_unlock(&fork->mutex) != 0)
// 		return (FORK_FAILURE);
// 	if (!print_philo_state(philo, "has taken a fork"))
// 		return (FORK_FAILURE);
// 	return (FORK_SUCCESS);
// }


// static t_fork_status	pickup_fork(t_fork *fork, t_philo *philo)
// {
// 	bool			is_end;
	
// 	while (true)
// 	{
// 		if (!check_philos_end(philo->data, &is_end))
// 			return (false);
// 		if (is_end)
// 			return (true);
// 		if (pthread_mutex_lock(&fork->mutex) != 0) /*  공유 자원 접근을 위해 lock */
// 			return (false);
// 		if (!fork->is_taken)
// 		{
// 			fork->is_taken = true;
// 			if (pthread_mutex_unlock(&fork->mutex) != 0)
// 				return (false);
// 			if (!print_philo_action(philo, "has taken a fork"))
// 				return (false); 
// 			return (true);
// 		}
// 		if (pthread_mutex_unlock(&fork->mutex) != 0)
// 			return (false);
// 		usleep(1000);
// 	}
// } 