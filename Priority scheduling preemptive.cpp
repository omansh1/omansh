#include<iostream>
#include<iomanip>
using namespace std;

class proc{
	public:
		int id,prior,bt,at;
};

int main(){
	int a;
	cout<<"Enter the number of process       ";
	cin>>a;
	proc process[a];
	cout<<endl<<"Enter the Burst time and there priority   "<<endl;
	for(int i=0; i<a; i++){
		cout<<"P["<<(i+1)<<"]       ";
		cin>>process[i].bt;
		cout<<"Piority       ";
		cin>>process[i].prior;
		process[i].at = i+1;
		process[i].id = i+1;
	}
	
	proc p[a];
	for(int i=0;i<a;i++){
		p[i] = process[i];
	}
	
	
	int complete =0 , t=0 , count[a] = {0};
	while(true){
		bool done =true;
		int max=0 , shortest=0;
		for(int i=0;i<t;i++){
			if(max > process[i].prior){
				max = process[i].prior;
				shortest = i;
			}
		}
		
		for(int i=0;i<=t;i++){
			if(p[i].bt>0 && process[i].at<=t){
				done =false;
				p[i].bt = p[i].bt-1;
				count[i]++;
			}
		}
		
		if(done==true){
			break;
		}
		t++;
		if(t==a){
			t=a-1;
		}
	}
	
	
	/*
	for(int i=0;i<a;i++){
		for(int j=0;j<a;j++){
			if(process[i].prior < process[j].prior){
				proc p;
				p = process[i];
				process[i] = process[j];
				process[j] = p;
			}
		}
	}
	*/
	int wait[a];
	for(int i=0; i<a;i++){
		wait[i]=count[i]-process[i].bt-process[i].at;
	}
	int ctime[a];
	for(int i=0; i<a;i++){
		ctime[i] = wait[i] + process[i].bt;
	}
	cout<<endl<<endl<<"Chart  :"<<endl;
	cout<<"Process      Burst time      Priority       Waiting time      Completion time"<<endl;
	for(int i=0; i<a;i++){
		cout<<"P["<<process[i].id<<"]"<<setw(17)<<process[i].bt<<setw(17)<<process[i].prior<<setw(17)<<wait[i]<<setw(17)<<ctime[i]<<endl;
	}
	double avew  = 0 , avec=0;
	cout<<endl;
	for(int i=0;i<a;i++){
		avew = avew + wait[i];
	}
	
	for(int i=0;i<a;i++){
		avec = avec + ctime[i];
	}
	cout<<"Average Waiting time is       :   "<<avew/a<<endl;
	cout<<"Average Completion time is    :   "<<avec/a<<endl;
	
	
}
