#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int n,bt[20],wt[20],tat[20],pr[20],temp;
	cout<<"enter number of processes";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"p["<<i<<"]";
		cout<<"enter burst time";
		cin>>bt[i];
		cout<<"enter priority";
		cin>>pr[i];
		cout<<endl;
	}//waintg time
	
	//sorting
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(pr[j]<pr[i])
			{
			
			
			
			 temp=pr[i];
			pr[i]=pr[j];
			pr[j]=temp;
			
			
	temp=bt[i];
	bt[i]=bt[j];
	bt[j]=temp;
}
	
		}
	}
	
	
	
	wt[0]=0;
	for(int i=1;i<n;i++)
	{
	wt[i]=0;
	for(int j=0;j<i;j++)
	{	wt[i]=bt[j]+wt[i];
	
	
	}
	}
	
	  int sum=0;
	for(int i=0;i<n;i++)
	{
	tat[i]=bt[i]+wt[i];
	sum+=tat[i];
	
};
	
	

		cout<<"priority"<<setw(13)<<"burst time"<<setw(13)<<setw(13)<<"waitng tme"<<setw(13)<<"tat time"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<pr[i]<<setw(13)<<bt[i]<<setw(13)<<wt[i]<<setw(13)<<tat[i]<<endl;
		

	}
	cout<<"average tat time"<<"\n"<<sum/n<<endl;
	
}

