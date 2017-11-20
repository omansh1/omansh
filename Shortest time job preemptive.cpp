#include<iostream>
using namespace std;
 
 class Process {
    public :
	int pid , bt,art;
};

void findWaitingTime(Process proc[], int n,int wt[])
{
    int rt[n];
	for (int i = 0; i < n; i++)
        rt[i] = proc[i].bt;

    int complete = 0, t = 0, minm = INT_MAX;
     int shortest = 0,finish_time;

    bool check = false;

while (complete != n) {
        for (int j = 0; j < n; j++) {
            if ((proc[j].art <= t) && (rt[j] < minm) && rt[j] > 0){
                minm = rt[j];
				shortest = j;
				check = true;
            }
        }

        if (check == false) {
            t++;
            continue;
        }

        rt[shortest]--;
        minm = rt[shortest];
        if (minm == 0)
            minm = INT_MAX;

        if (rt[shortest] == 0) {
           complete++;
 
            finish_time = t + 1;

            wt[shortest] = finish_time - proc[shortest].bt- proc[shortest].art;
            
            if (wt[shortest] < 0)
                wt[shortest] = 0;

        }

        t++;
    }
}

void findTurnAroundTime(Process proc[], int n,int wt[], int tat[])
{
    for (int i = 0; i < n; i++)
        tat[i] = proc[i].bt + wt[i];
}

 
void findavgTime(Process proc[], int n)
{
   int wt[n], tat[n], total_wt = 0,total_tat = 0;

    findWaitingTime(proc, n, wt);
    findTurnAroundTime(proc, n, wt, tat);

   cout << "Processes "<< " Burst time "<< " Waiting time "<< " Turn around time\n";

    for (int i = 0; i < n; i++) {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        cout << " " << proc[i].pid << "\t\t"<< proc[i].bt << "\t\t " << wt[i]<< "\t\t " << tat[i] << endl;
    }
    cout << "\nAverage waiting time = "<< (float)total_wt / (float)n;
    cout << "\nAverage turn around time = "<< (float)total_tat / (float)n;
}

int main()
{
    cout<<"Enter the number of process    ";
    int p;
    cin>>p;
    Process proc[p];
    cout<<"Enter Burst time of process   "<<endl;
    for(int i=0;i<p;i++){
    	cin>>proc[i].bt;
    	proc[i].art = i+1;
    	proc[i].pid = i+1;
	}
    int n = sizeof(proc) / sizeof(proc[0]); 
    findavgTime(proc, n);
    return 0;
}

