#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int calc_fitness(int individual, int length, int** population);
void roulette_selection(int num, int length, int** population, int *fitness);


int main()
{
	int **population;//�̏W��
	int num;//�̐�
	int length;//��`�q��
	int *fitness;//�K���x 

	int i,j,k;
	
	num=10;
	length=5;

	//�̏W��
	population=new int*[num];
	for(i=0;i<num;i++){
		population[i]=new int[length];
	}

	//�K���x
	fitness=new int[num];

	//�����̏�����
	srand( (unsigned)time( NULL ) );
	//�����̂̐���
	for(i=0;i<num;i++){
		for(j=0;j<length;j++){
			population[i][j]=rand()%2;
			printf("%d ",population[i][j]);
		}
		
		fitness[i]=calc_fitness(i,length,population);
		printf(" fitness = %d\n",fitness[i]);
	}
	
	for(k=0;k<10;k++){
		roulette_selection(num,length, population, fitness);

		for(i=0;i<num;i++){
			fitness[i]=calc_fitness(i,length,population);
			for(j=0;j<length;j++){
				printf("%d ",population[i][j]);
			}
			printf("%d \n", fitness[i]);
		}
	}
		
	for(i=0;i<num;i++){
		delete[] population[i];
	}
	delete[] population;
	delete[] fitness;
	
	return 0;
}

int calc_fitness(int individual, int length, int** population){
	int i;
	int fitness =0;
	for(i=0;i<length;i++){
		fitness=fitness+population[individual][i];
	}
	return fitness;

}

void roulette_selection(int num, int length, int **population, int *fitness){
	int i,j,k;
	int sum_fitness;//�K���x�̘a������
	int **new_population;//�I�΂ꂽ�̂�����
	double *roulette;//�I�������m��������
	double *ac_roulette;//roulette�̐ώZ�l������
	double r;//���[���b�g�Ŏg������

	new_population=new int*[num];
	for(i=0;i<num;i++){
		new_population[i]=new int[length];
	}
	
	roulette=new double[num];
	ac_roulette=new double[num];

	//fitness�̘a�����߂�
	sum_fitness=0;
	for(i=0;i<num;i++){
		sum_fitness=sum_fitness+fitness[i];
	}
	
	//���[���b�g�����
	roulette[0]=(double)fitness[0]/(double)sum_fitness;
	ac_roulette[0]=roulette[0];
	printf("roulette[%d]=%lf ac_roulette[%d]=%lf \n",0,roulette[0],0,ac_roulette[0]);
	for(i=1;i<num;i++){
		roulette[i]=(double)fitness[i]/(double)sum_fitness;
		ac_roulette[i]=ac_roulette[i-1]+roulette[i];
		printf("roulette[%d]=%lf ac_roulette[%d]=%lf \n",i,roulette[i],i,ac_roulette[i]);

	}

	//���[���b�g���g���đI������
	for(i=0;i<num;i++){
		r=(double)rand()/(double)RAND_MAX;
		for(j=0;j<num;j++){
			if(r<=ac_roulette[j]){
				printf("r=%lf ac_roulette[%d]=%lf \n",r,j,ac_roulette[j]);
				for(k=0;k<length;k++){
					new_population[i][k]=population[j][k];
				}
				break;
			}
		}
	}

	//new_population��population�ɃR�s�[
	for(i=0;i<num;i++){
		for(k=0;k<length;k++){
			population[i][k]=new_population[i][k];
		}
	}

	delete[] roulette;
	delete[] ac_roulette;

	for(i=0;i<num;i++){
		delete[] new_population[i];
	}

	delete[] new_population;

}
