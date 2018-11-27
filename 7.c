#include<stdio.h>
int main()
{
int i, j, np, nb, p[10], b[10], c[10], d[10], alloc[10], choice, flag[10], temp;

printf("\nEnter number of processes: ");
scanf("%d",&np);

printf("\nEnter number of blocks: ");
scanf("%d",&nb);

printf("\nEnter each process size: ");
for(i=0; i<np; i++){
	scanf("%d",&p[i]);
	}

printf("\nEnter each block size: ");
for(i=0; i<nb; i++){
	scanf("%d",&b[i]);
	c[i] = b[i];
	d[i] = b[i];
	}

if(np <= nb){
	do{
		printf("\n\n1:First Fit\n2:Best Fit\n3:Worst Fit\n4:Exit");
		printf("\nEnter your choice: ");
		scanf("%d",&choice);
		switch(choice){
			case 1: printf("\n-----First Fit-----\n");
				for(i=0; i<np; i++){
					for(j=0; j<nb; j++){
						if(p[i] <= b[j]){
							alloc[j] = p[i];
							printf("\nAlloc[%d]", alloc[j]);
							printf("\nProcess %d, size=%d is allocated to block %d, size=%d",
								i+1, p[i], j+1, b[j]);
							flag[i] = 0;
							b[j] = 0;
							break;
							}
						else{
							flag[i] = 1;
							}
						}
					}
				for(i=0; i<np; i++){
					if(flag[i] != 0){
						printf("\nProcess %d, size=%d is not allocated", i+1, p[i]);
						}
					}
				break;
			
			case 2:	printf("\n-----Best Fit-----\n");
				for(i=0; i<nb-1; i++){
					for(j=0; j<nb-i-1; j++){
						if(c[j] > c[j+1]){
							temp = c[j+1];
							c[j+1] = c[j];
							c[j] = temp;
							}
						}
					}
				printf("\nSorted block sizes are: ");
				for(i=0; i<nb; i++){
					printf("%d  ", c[i]);
					}
				
				for(i=0; i<np; i++){
					for(j=0; j<nb; j++){
						if(p[i] <= c[j]){
							alloc[j] = p[i];
							printf("\nAlloc[%d]", alloc[j]);
							printf("\nProcess %d, size=%d is allocated block %d, size=%d",
								i+1, p[i], j+1, c[j]);
							
							flag[i]=0;
							c[j] = 0;
							break;
							}
						else{
							flag[i] = 1;
							}
						}
					}
				for(i=0; i<np; i++){
					if(flag[i] != 0){
						printf("\nProcess %d, size=%d not allocated", i+1, p[i]);
						}
					}
				break;
			
			case 3: printf("\n-----Worst Fit-----\n");
				for(i=0; i<nb-1; i++){
					for(j=0; j<nb-i-1; j++){
						if(d[j] < d[j+1]){
							temp = d[j+1];
							d[j+1] = d[j];
							d[j] = temp;
							}
						}
					}
				printf("\nSorted block sizes are: ");
				for(i=0; i<nb; i++){
					printf("%d  ", d[i]);
					}
				
				for(i=0; i<np; i++){
					for(j=0; j<nb; j++){
						if(p[i] <= d[j]){
							alloc[j] = p[i];
							printf("\nAlloc[%d]", alloc[j]);
							printf("\nProcess %d, size=%d is allocated block %d, size=%d",
								i+1, p[i], j+1, d[j]);
							
							flag[i] = 0;
							d[j] = 0;
							break;
							}
						else{
							flag[i] = 1;
							}
						}
					}
				for(i=0; i<np; i++){
					if(flag[i] != 0){
						printf("\nProcess %d, size=%d not allocated", i+1, p[i]);
						}
					}
				break;
			
			default: printf("\nEnter a valid choice\n");
			}
		}while(choice!=4);
	}
}
