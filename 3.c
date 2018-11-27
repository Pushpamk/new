#include<stdio.h>
#include<stdlib.h>

void main()
{
int i, j, at[10], bt[10], time, flag=0, count=0, rt[10], tq, remain, np;
float avg_wt, avg_tat;
printf("\nEnter no. of processes: ");
scanf("%d",&np);
remain = np;

printf("\nEnter arrival time of each process: ");
for(i=0; i<np; i++){
	scanf("%d",&at[i]);
	}

printf("\nEnter burst time of each process: ");
for(i=0; i<np; i++){
	scanf("%d",&bt[i]);
	rt[i] = bt[i];
	}

printf("\nEnter time quantum: ");
scanf("%d", &tq);

printf("\nProcess\t\tTAT\t\tWT\n\n");

for(count=0, time=0; remain!=0; ){
	if(rt[count] <= tq && rt[count]>0){
		time += rt[count];
		rt[count] = 0;
		flag = 1;
		}
	else if(rt[count]>0){
		rt[count] -= tq;
		time += tq;
		}
	
	if(rt[count]==0 && flag==1){
		--remain;
		
		printf("%d\t\t %d\t\t %d\n",count+1, time-at[count], time-at[count]-bt[count]);
		avg_wt += time-at[count]-bt[count];
		avg_tat += time-at[count];
		flag = 0;	
		}
	
	if(count == np-1){
		count = 0;
		}
	else if(at[count+1] <= time){
		count++;
		}
	else{
		count = 0;
		}
	}
printf("\nAverage WT : %lf\n", avg_wt*1.0/np);
printf("\nAverage TAT : %lf\n", avg_tat*1.0/np);
}
