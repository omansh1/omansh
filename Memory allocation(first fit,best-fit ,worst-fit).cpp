#include<iostream>
using namespace std;

void display(int b, int result[] , int process[]){
	cout<<"  Processes       Memory required       Result"<<endl;
	for(int i=0;i<b;i++){
		if(result[i]){
			cout<<"     p["<<i<<"]               "<<process[i]<<"               Allocated"<<endl;
		}else{
			cout<<"     p["<<i<<"]               "<<process[i]<<"               Not Allocated"<<endl;
			
		}
	}	
}

int main(){
	int a;
	cout<<"Enter the number of the contigues memory blocks       ";
	cin>>a;
	cout<<"Enter the size of each block"<<endl;
	int memory[a] , memory2[a] , memory3[a];
	for(int i=0; i<a;i++){
		cin>>memory[i];
		memory2[i] = memory[i];
		memory3[i] = memory[i];
	}
	
	int b;
	cout<<"Enter the number of the processes       ";
	cin>>b;
	cout<<"Enter the memory required for each process"<<endl;
	int process[b];
	for(int i=0; i<b;i++){
		cin>>process[i];
	}
	
	int result[b];
	
	//first- fit
	for(int i=0; i<b ; i++){
		for(int j=0;j<a;j++){
			result[i]=0;
			if(process[i] <= memory[j]){
				result[i] = 1;
				memory[j] = memory[j] - process[i];
				break; 
			}
		}
	}
	
	cout<<endl<<endl<<endl<<"                   FIRST FIT"<<endl;
	display(b , result, process);
	
	//best - fit
	for(int i=0; i<b ; i++){
		for(int j=0;j<a;j++){
	        for(int k=0;k<j;k++){
	        	if(memory2[j] < memory2[k]){
	        		int t = memory2[j];
	        		memory2[j] = memory2[k];
	        		memory2[k] = t;
				}
			}
	    }
		result[i]=0;
		for(int j=0; j<a;j++){
			if(process[i] <= memory2[j]){
				memory2[j] = memory2[j] - process[i];
				result[i] =1;
				break;
			}
		}
	}

	cout<<endl<<endl<<endl<<"                   BEST FIT"<<endl;
	display(b , result,process);	
	
	
	
	//Worst - fit
	for(int i=0; i<b ; i++){
		for(int j=0;j<a;j++){
	        for(int k=0;k<j;k++){
	        	if(memory3[j] > memory3[k]){
	        		int t = memory3[j];
	        		memory3[j] = memory3[k];
	        		memory3[k] = t;
				}
			}
	    }
		result[i]=0;
		for(int j=0; j<a;j++){
			if(process[i] <= memory3[j]){
				memory3[j] = memory3[j] - process[i];
				result[i] =1;
				break;
			}
		}
	}

	cout<<endl<<endl<<endl<<"                   WORST FIT"<<endl;
	display(b , result,process);	
	
}
