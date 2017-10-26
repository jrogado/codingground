#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define NTHREADS 4

void *compute(int);

int main()
{
  pthread_t thread[NTHREADS];
  int ret;
  long i;
  
	for (i = 0; i < NTHREADS; i++)
			  ret = pthread_create(&thread[i], NULL, (void *)(&compute), (int *)i);

		if (ret) {
			perror("thread create");
			exit(1);
		}
		// Wait for all threads to finish
		for (i = 0; i < NTHREADS; i++)
			pthread_join(thread[i], NULL);

    printf("All threads exited\n");

    return 0;
}

void *compute(int index)
{
  printf("This is thread %d\n", index);
}
