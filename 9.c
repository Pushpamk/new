#include<stdio.h>
#include<stdlib.h>

struct st{
	char dname[10];
	char sdname[10][10];
	char fname[10][10][10];
	int ds, sds[10];
	}dir[10];
	

void main()
{
int i, j ,k, n;
printf("\nEnter number of dir: ");
scanf("%d",&n);
for(i=0; i<n ;i++){
	printf("\nEnter dir name: ");
	scanf("%s",&dir[i].dname);
	
	printf("\nEnter dir size: ");
	scanf("%d",&dir[i].ds);
	
	for(j=0; j<dir[i].ds; j++){
		printf("\nEnter subdir name and size: ");
		scanf("%s",&dir[i].sdname[j]);
		scanf("%d",&dir[i].sds[j]);
		for(k=0; k<dir[i].sds[j]; k++){
			printf("\nEnter file name: ");
			scanf("%s",&dir[i].fname[j][k]);
			}
		}
	}
	
printf("\n\nDirectory\tSize\tSub-Directory\tSize\tFiles\n");
printf("*****************************************************************************\n\n");
for(i=0; i<n; i++){
	printf("%s\t\t%d",dir[i].dname, dir[i].ds);
	
	for(j=0; j<dir[i].ds; j++){
		printf("\t  %s\t\t%d\t", dir[i].sdname[j], dir[i].sds[j]);
		
	for(k=0; k<dir[i].sds[j]; k++){
		printf("%s ", dir[i].fname[j][k]);
		}
	printf("\n\t\t  ");
		}
	printf("\n\n");
	}
printf("\n");
}
