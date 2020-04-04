#include <stdio.h>
#include <pthread.h>
#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <semaphore.h>
sem_t lock;
void fibonacci(){
	int t1 = 1;
	int t2 = 2;
	for(int i = 0; i<100000;i++){
		sem_wait(&lock);
		std::cout<<t2<<" ";
		sem_post(&lock);
		int next = t2+ t1;
		t1  = t2;
		t2 = next;
		if(t2>=100000){
			break;
		}
	}
}
void* findPrime(void * arg){
	for(int a=2;a<100000;a++){
		int count = 0;
		for(int b=2;b<=a;b++){
			if(a%b==0){
				count++;
			}
		}
		if(count==1){
			sem_wait(&lock);
			std::cout<<"prime number series is "<<a;
			sem_post(&lock);
		}
	}
	std::cout<<""<<std::endl;
	return NULL;
}
int main(int argc, char const *argv[]){
	sem_init(&lock,0,1);
	pthread_t  newthread_1;
	pthread_t  newthread_2;
	pthread_create(&newthread_1,NULL,findPrime,NULL);
	pthread_create(&newthread_2,NULL,fibonacci,NULL);
	pthread_join(newthread_1,NULL);
	pthread_join(newthread_2,NULL);
	sem_destroy(&lock);
	return 0;
}
