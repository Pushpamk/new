#include<stdio.h>

void main()
{
int bt[10], wt[10], tat[10], i, j, total=0, np, p[10], temp;
float avg_wt, avg_tat;

printf("\nEnter no. of processes: ");
scanf("%d",&np);

printf("\nEnter BT for each process:\n");
for(i=0; i<np; i++){
	scanf("%d", &bt[i]);
	p[i] = i;		// holds process number
	}

for(i=0; i<np-1; i++){
	for(j=0; j<np-i-1; j++){
		if(bt[j] > bt[j+1]){
			temp = bt[j+1];
			bt[j+1] = bt[j];
			bt[j] = temp;
			
			temp = p[j+1];
			p[j+1] = p[j];
			p[j] = temp;
			}
		}
	}
wt[0] = 0;

for(i=1; i<np; i++){
	wt[i] = 0;
	for(j=0; j<i; j++){
		wt[i] += bt[j];
		}
	total += wt[i];
	}
avg_wt = total*1.0/np;
total = 0;

for(i=0; i<np; i++){
	tat[i] = wt[i]+bt[i];
	total += tat[i];
	}
avg_tat = total*1.0/np;

printf("\nProcess\t\tTAT\t\tWT\t\tBT\n");
for(i=0; i<np; i++){
	printf("%d\t\t %d\t\t %d\t\t %d\n",p[i],tat[i], wt[i],bt[i]);
	}
printf("\nAvg WT: %lf",avg_wt);
printf("\nAvg TAT: %lf\n\n", avg_tat);
}
