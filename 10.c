#include<stdio.h>
#include<stdlib.h>

void main()
{
int cylinder[20], n, i, t, current, j, start, range, total = 0;
printf("\nEnter no. of cylinders: ");
scanf("%d",&n);
printf("\nEnter range: ");
scanf("%d", &range);

printf("\nEnter the cylinder locations: ");
for(i = 0; i < n; i++){
	scanf("%d",&cylinder[i]);
	}

for(i = 0; i < n-1; i++){
	for(j = 0; j < n-i-1; j++){
		 if(cylinder[j] > cylinder[j+1]){
		 	t = cylinder[j];
		 	cylinder[j] = cylinder[j+1];
		 	cylinder[j+1] = t;
		 	}
		 }
	}

printf("\nEnter current location: ");
scanf("%d", &current);

t = current;
printf("%d ",current);

for(i = 0; i < n; i++){
	if(cylinder[i] > t){
		printf("--> %d ",cylinder[i]);
		total += cylinder[i] - t;
		t = cylinder[i];
		}
	}

total += range - cylinder[i-1];
printf("--> %d ", range);

for(i = 0; i < n; i++){
	if(cylinder[i] > current){
		start = i-1;
		break;
		}
	}

t = cylinder[start];
total += range - t;
printf("--> %d ", t);

for(i = start-1; i >= 0; i--){
	printf("--> %d", cylinder[i]);
	total += t - cylinder[i];
	t = cylinder[i];
	}
printf("\nTotal head movements: %d\n\n", total);
}
