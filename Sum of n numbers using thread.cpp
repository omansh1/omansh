#include<iostream>
#include<pthread.h>
using namespace std;

struct twonum{
	int from ,to;
	twonum(int a,int b){
		from=a;
		to=b;
	}
};

void *sum(void * number){
      twonum *p = (twonum*)number;
      int *r = new int;
      *r=0;
	  for(int i=p->from  ; i<=p->to  ; i++){
      	*r = *r+i;
	  }
	  delete p;
      pthread_exit((void*)r);
}

int main(){
    pthread_t thread;
    twonum *p = new twonum(1,10);
    pthread_create(&thread,NULL,sum,(void*)p);
	int *sm;
	pthread_join(thread,(void**)&sm);
	cout<<"Result is  "<<*sm<<endl;
	delete sm;
	
}
