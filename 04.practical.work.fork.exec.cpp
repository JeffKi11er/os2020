#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
using namespace std;
int main(int argc, char const *argv[]){
	int id = fork();
	if(id==0){
		id = fork();
		if(id==0){ 
			cout<<"This is the child process : launching ps -ef"<<endl;
			char *args[]={"/bin/ps","-ef",NULL};
			execvp("/bin/ps",args);
		}else{
		wait(NULL);
		cout<<"This is the parent after fork(),child is"<<id<<endl;
	}
	wait(NULL);
	cout<<"This is child after fork(), launching free -h"<<endl;
	char *args[]={"free","-h",NULL};
	execvp("free",args);
	}
	else{
		wait(NULL);
		cout<<"This is the parent after fork(), child is "<<id<<endl;
	}
	return 0;
}
