#include <stdio.h>
#include <time.h>


int move(int a, int &x, int &y, int x_size);
int xy2s(int x, int y, int x_size);
int select_action(int s, int num_a, double** Qtable);
double max_Qval(int s, int num_a, double** Qtable);
int epsilon_greedy(int epsilon,int s, int num_a, double** Qtable);

int main()
{
	int x_size;//x�������̖��H�̑傫���ix_size=10�̎��ɂ́Cx��0����9�̒l���Ƃ�)
	int y_size;
	double alpha, gamma;
	int x, y, x_init, y_init;
	int **maze;
	int num_step;//�ꎎ�s�ɂ�����Q�l�̍X�V��
	int num_trial;//���s��
	int i,j;
	int a,s,sd;
	int num_a;
	int num_s;
	double **Qtable;
	int reward;
	double Qmax;
	int epsilon;
	
	//�p�����[�^�̐ݒ�
	alpha=0.5;
	gamma=0.9;
	epsilon=10;
	x_size=10;
	y_size=9;
	x_init=1;
	y_init=1;
	num_step=100;
	num_trial=300;
	num_a=4;
	num_s=x_size*y_size;

	//�����̏�����
	srand( (unsigned)time( NULL ) );

	//Q-table
	Qtable=new double*[num_s];
	for(i=0;i<num_s;i++){
		Qtable[i]=new double[num_a];
	}
	
	//Q-table�̏�����
	for(i=0;i<num_s;i++){
		for(j=0;j<num_a;j++){
			Qtable[i][j]=0;
		}
	}
	

	//���H
	maze=new int*[x_size];
	for(i=0;i<x_size;i++){
		maze[i]=new int[y_size];
	}
	
	//���H�̏������i���H�̎���ɕǂ�ݒ�j
	for(i=0;i<x_size;i++){
		for(j=0;j<y_size;j++){
			if(i==0 || j==0 || i==(x_size-1) || j==(y_size-1)){
				maze[i][j]=-1;
			}
			else{
				maze[i][j]=0;
			}
		}
	}
	
	//�ǂ̐ݒ�
	maze[2][2]=-1;
	maze[3][2]=-1;
	maze[6][3]=-1;
	maze[7][3]=-1;
	maze[8][3]=-1;
	maze[2][6]=-1;
	maze[2][7]=-1;
	maze[3][6]=-1;
	maze[6][7]=-1;

	//��V�̐ݒ�
	maze[8][6]=10;
	
	for(i=0;i<x_size;i++){
		for(j=0;j<y_size;j++){
			printf("%3d",maze[i][j]);
		}
		printf("\n");
	}

	//�����ݒ�
	x=x_init;
	y=y_init;
	s=xy2s(x,y,x_size);
	
	//�w�K�J�n
	for(i=0;i<num_trial;i++){
		printf("trial=%d\n",i);
		for(j=0;j<num_step;j++){
			a=epsilon_greedy(epsilon,s,num_a,Qtable);
			sd = move(a,x,y,x_size);
			reward=maze[x][y];
			Qmax=max_Qval(sd,num_a,Qtable);
			Qtable[s][a]=(1 - alpha) * Qtable[s][a] + alpha * ((double)reward + gamma * Qmax);

			if(reward<0){
				//���s
				x=x_init;
				y=y_init;
				s=xy2s(x,y,x_size);
				printf("���s\n");
				break;
			}
			else if(reward>0){
				//����
				x=x_init;
				y=y_init;
				s=xy2s(x,y,x_size);
				printf("����\n");
				break;
			}
			else{
				//���s
				s=sd;
			}
		}
	}


	for(i=0;i<num_s;i++){
		delete[] Qtable[i];
	}
	delete[] Qtable;

	for(i=0;i<x_size;i++){
		delete[] maze[i];
	}
	delete[] maze;


	return 0;
}

int move(int a, int &x, int &y, int x_size){

	if( a == 0){
		y = y + 1;
	}
	else if( a == 1 ){
		x = x + 1;
	}
	else if( a == 2 ){
        y = y - 1;
	}
	else{
        x = x - 1;
	}

	int sd;
	sd =  xy2s(x,y,x_size);
	
	return sd;
}

int xy2s(int x, int y, int x_size){
	int s;
	s = x + y * x_size;
	return s;
}

int select_action(int s, int num_a, double** Qtable){
	double max;
	int i=0;
	int* i_max = new int[num_a];
	int num_i_max=1;
	int a;

	i_max[0]=0;
	max=Qtable[s][0];

	for(i=1;i<num_a;i++){
		if (Qtable[s][i]>max){
			max=Qtable[s][i];
			num_i_max=1;
			i_max[0]=i;
		}
		else if(Qtable[s][i]==max){
			num_i_max++;
			i_max[num_i_max-1]=i;
		}
	}
	
		
	a= i_max[rand()%num_i_max];
	return a;
}

double max_Qval(int s, int num_a, double** Qtable){
	double max;
	int i=0;
	
	max=Qtable[s][0];
	for(i=1;i<num_a;i++){
		if (Qtable[s][i]>max){
			max=Qtable[s][i];
		}
	}
	return max;
}

int epsilon_greedy(int epsilon, int s, int num_a, double** Qtable){
	int a;
	if(epsilon > rand()%100){
		//����ׂɍs����I��
		a=rand()%num_a;
		//printf("����ׂɑI��\n");
	}
	else{
		//�ő�̂p�l�����s����I��
		a=select_action(s,num_a,Qtable);
	}
	return a;
}

