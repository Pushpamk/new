//--------------DINING PHILOSOPHER PROBLEM----------------//

#include<stdio.h>
#include<stdlib.h>

enum {thinking, hungry, eating} state[5];
int self[5];

int wait()
{
return hungry;
}

int signal()
{
return eating;
}

void init(int n)
{
int i;
for(i=0;i<n;i++){
	state[i] = thinking;
	}
}

void test(int i, int n)
{
// Don't write like if(state[(i+n-1)%n]==thinking ----) bcz if left/right side is hungry, 'i'th phil can still eat
if(state[(i+n-1)%n]!=eating && state[i]==hungry  && state[(i+1)%n]!=eating){
	state[i] = eating;
	self[i] = signal();
	}
}


void pickup(int i, int n)
{
state[i] = hungry;
test(i, n);
if(state[i]!=eating){
	self[i] = wait();
	printf("\nPhilosopher %d is hungry\n",i+1);
	}
else{
	printf("\nPhilosopher %d is eating\n",i+1);
	}
}


void putdown(int i, int n)
{
state[i] = thinking;
test((i+n-1)%n, n);
test((i+1)%n, n);
}


void showState(int n)
{
int i=0;
for(i=0;i<n;i++){
	if(state[i]==thinking)
		printf("\nPhilosopher %d is thinking\n",i+1);
	else if(state[i]==hungry)
		printf("\nPhilospher %d is hungry\n",i+1);
	else
		printf("\nPhilosopher %d is eating\n",i+1);
	}
}


void main()
{
int n = 5;
int i;
int choice;
init(5);
printf("1:Pickup\n2:Putdown\n3:Show State\n4:Exit\n");
while(1){
	printf("\nEnter your choice: ");
	scanf("%d",&choice);
	switch(choice){
		case 1:  printf("\nEnter philosopher number: ");
			 scanf("%d",&i);
			 pickup(i-1 , n);
			 break;
		case 2:	printf("\nEnter philosopher number: ");
			scanf("%d",&i);
			putdown(i-1, n);
			break;
			
		case 3: showState(n);
			break;
		case 4: exit(0);
			break;
		
		default: printf("\nEnter a valid choice\n");
		}
	}
}
