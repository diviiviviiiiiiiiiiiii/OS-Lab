#include<stdio.h>
int main(){
    char pn[10][10];
    int arr[10], bur[10], star[10], finish[10], tat[10],wt[10],i,n;
    int totwt=0,tottat=0;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    for(i=0;i<n;i++){
        printf("Enter the process Name,Arrival Time &burst time:");
        scanf("%s%d%d",pn[i],&arr[i],&bur[i]);
    }
    for(i=0;i<n;i++){
        if(i==0){
            star[i] = arr[i];
            wt[i] = star[i]- arr[i];
            finish[i] = star[i] + bur[i];
            tat[i] = finish[i] - arr[i];
        }
        else{
            star[i]=finish[i-1];
            wt[i]=star[i]-arr[i];
            finish[i]=star[i]+bur[i];
            tat[i]=finish[i]-arr[i];
        }
    }
    printf("\nPName\tArrtime\tBurtime\tstart\tTAT Finish");
    for(i=0;i<n;i++){
        printf("\n%s\t%6d\t%6d\t%6d\t%6d\t%6d",pn[i],arr[i],bur[i],star[i],tat[i],finish[i]);
        totwt +=wt[i];
        tottat +=tat[i];
    }
    printf("\nAverage Waiting time: %f", (float)totwt/n);
    printf("\nAverage Turn Around Time: %f\n",(float)tottat/n);
}

#include<stdio.h>
int main()
{
char pn[10];
int arr[10],bur[10],star[10],finish[10],tat[10],wt[10],i,n;
int totwt=0,tottat=0;
printf("Enter the number of processes:");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("Enter the Process Name, Arrival Time & Burst Time:");
scanf("%s%d%d",&pn[i],&arr[i],&bur[i]);
}
for(i=0;i<n;i++)
{
if(i==0)
{
star[i]=arr[i];
wt[i]=star[i]-arr[i];
finish[i]=star[i]+bur[i];
tat[i]=finish[i]-arr[i];
}
else
{
star[i]=finish[i-1];
wt[i]=star[i]-arr[i];
finish[i]=star[i]+bur[i];
tat[i]=finish[i]-arr[i];
}
}
printf("\nPName Arrtime Burtime Start TAT Finish");
for(i=0;i<n;i++)
{
printf("\n%s\t%6d\t\t%6d\t%6d\t%6d\t%6d",pn[i],arr[i],bur[i],star[i],tat[i],finish[i]);
totwt+=wt[i];
tottat+=tat[i];
}
printf("\nAverage Waiting time:%f", (float)totwt/n);
printf("\nAverage Turn Around Time:%f", (float)tottat/n);
}


SOURCE CODE:
/* A program to simulate the SJF CPU scheduling algorithm */
#include<stdio.h>
#include<string.h>
main()
{
Int i=0,pno[10],bt[10],n,wt[10],temp=0,j,tt[10];
float sum,at;
printf("\n Enter the no of process ");
scanf(" %d",&n);
printf("\n Enter the burst time of each process");
for(i=0;i<n;i++)
{
printf("\n p%d",i);
scanf("%d",&bt[i]);
}
for(i=0;i<n-1;i++)
{
for(j=i+1;j<n;j++)
{
if(bt[i]>bt[j])
{
temp=bt[i];
bt[i]=bt[j];
bt[j]=temp;
temp=pno[i];
pno[i]=pno[j];
pno[j]=temp;
}
}
}
wt[0]=0;
for(i=1;i<n;i++)
{
wt[i]=bt[i-1]+wt[i-1];
sum=sum+wt[i];
}
printf("\n process no \t burst time\t waiting time \t turn around time\n");
for(i=0;i<n;i++)
{
tt[i]=bt[i]+wt[i];
at+=tt[i];
printf("\n p%d\t\t%d\t\t%d\t\t%d",i,bt[i],wt[i],tt[i]);
}
printf("\n\n\t Average waiting time%f\n\t Average turn around time%f", sum/n,at/n);
}


/*output
Enter the number of processes: 4
Enter the arrival time for process 1:0
Enter the Burst time for processes 1:5
Enter the arrival time for process 2:1
Enter the Burst time for processes 2:3
Enter the arrival time for process 3:2
Enter the Burst time for processes 3:4
Enter the arrival time for process 4:4
Enter the Burst time for processes 4:1
FCFS agorithm
Processes       AT      BT      WT      TAT     CT      RT
1               0       5       0       5       5       0
2               1       3       4       7       8       4
3               2       4       6       10      12      6
4               4       1       8       9       13      8
AVG waiting time: 4.500000
AVG turnaround time: 7.750000*/