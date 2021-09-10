#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void one_point_crossover(int crossover_rate,int num, int length, int **population, int **pair);

int main()
{
	int **population;//�̏W��
	int **pair;//�̏W������בւ��C�ォ�珇�Ƀy�A�ɂ�������
	int num;//�̐�
	int length;//��`�q��
	int crossover_rate; //�ˑR�ψٗ�[%]
	int i,j;
	
	num=10;
	length=5;
	crossover_rate=50;
	//�̏W��
	population=new int*[num];
	for(i=0;i<num;i++){
		population[i]=new int[length];
	}

	pair=new int*[num];
	for(i=0;i<num;i++){
		pair[i]=new int[length];
	}

	
	//�����̏�����
	srand( (unsigned)time( NULL ) );
	
	//�e�X�g�p�ɏ����̂�S�ĂO�ɐݒ�
	printf("population=\n");
	for(i=0;i<num;i++){
		for(j=0;j<length;j++){
			population[i][j]=0;
			printf("%d ",population[i][j]);
		}
		printf("\n");
	}
	//�e�X�g�p��pair��ݒ�i�����Ԗڂ̌̂͂ɂ͑S�ĂO���C��Ԗڂ̌̂ɂ͑S�ĂP��ݒ�
	printf("pair=\n");
	for(i=0;i<num;i++){
		for(j=0;j<length;j++){
			pair[i][j]=i%2;
			printf("%d ",pair[i][j]);
		}
		printf("\n");
	}

	one_point_crossover(crossover_rate,num,length,population, pair);
	
	//�m�F
	printf("population=\n");
	for(i=0;i<num;i++){
		for(j=0;j<length;j++){
			printf("%d ",population[i][j]);
		}
		printf("\n");
	}
	
	for(i=0;i<num;i++){
		delete[] population[i];
		delete[] pair[i];
	}
	delete[] population;
	delete[] pair;
	
	return 0;
}

void one_point_crossover(int crossover_rate,int num, int length, int **population, int **pair){
	int i,j;
	int cross_point;
	
	for(i=0;i<(num-1);i=i+2){
		if(rand()%100 < crossover_rate){
			//�������s
			cross_point=rand()%(length-1)+1;
			printf("cross_point=%d \n",cross_point);
			for(j=0;j<cross_point;j++){
				population[i][j]=pair[i+1][j];
				population[i+1][j]=pair[i][j];
			}
			for(j=cross_point;j<length;j++){
				population[i][j]=pair[i][j];
				population[i+1][j]=pair[i+1][j];
			}

		}
		else{
			//�������s�킸�C���̂܂܁Cpair��population�ɃR�s�[
			for(j=0;j<length;j++){
				population[i][j]=pair[i][j];
				population[i+1][j]=pair[i+1][j];
			}
		}
	}
}
