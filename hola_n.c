#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>



void *do_something(void*);

int main(int argc, char *argv[]) {
	pthread_t tid[1000];
	int j,i;

	for ( j = 0; j < 1000; j++) {
		pthread_create(&tid[j], NULL, do_something, NULL);
		pthread_join(tid, NULL);
	}
for (i = 0; i < 1000; i++) {
		pthread_join(tid[i],NULL);
	}



	return 0;
}

void *do_something(void *null) {
	
	printf("Hola %d\n",pthread_self());
	pthread_exit(NULL);
}
