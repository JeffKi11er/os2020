#include <stdio.h>
#include <pthread.h>
#include <iostream>
#include <unistd.h>
#include <stdlib.h>
void fibonacci(){
	int t1 = 1;
	int t2 = 2;
	for(int i = 0; i<100000;i++){
		sleep(1);
		std::cout<<t2<<" ";
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
			sleep(1);
			std::cout<<"prime number series is "<<a;
		}
	}
	std::cout<<""<<std::endl;
	return NULL;
}
int main(int argc, char const *argv[]){
	pthread_t  newthread;
	pthread_create(&newthread,NULL,findPrime,NULL);
	fibonacci();
	pthread_join(newthread,NULL);
}

