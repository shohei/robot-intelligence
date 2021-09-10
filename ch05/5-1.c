#include <stdio.h>

double vending_machine(int s, int a, int &sd); 

int main()
{
	int s,sd,a;
	double reward;
	
	s=0;
	a=0;
	sd=0;
	reward=vending_machine(s,a,sd);
	printf("s=%d sd=%d, a=%d, r=%lf\n",s,sd,a,reward);

	s=1;
	a=0;
	sd=0;
	reward=vending_machine(s,a,sd);
	printf("s=%d sd=%d, a=%d, r=%lf\n",s,sd,a,reward);

	s=0;
	a=1;
	sd=0;
	reward=vending_machine(s,a,sd);
	printf("s=%d sd=%d, a=%d, r=%lf\n",s,sd,a,reward);

	s=1;
	a=1;
	sd=0;
	reward=vending_machine(s,a,sd);
	printf("s=%d sd=%d, a=%d, r=%lf\n",s,sd,a,reward);

	

	return 0;
}


double vending_machine(int s, int a, int &sd){
	double reward;

	if(a==0){
		sd=!s;
		reward=0;
	}
	else{
		if(s==1){
			sd=s;
			reward=10;
		}
		else{
			sd=s;
			reward=0;
		}
	}

	return reward;
}

