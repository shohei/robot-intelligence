#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int **population;//�̏W��
	int num;//�̐�
	int length;//��`�q��
	int i,j;
	
	num = 10;
	length = 5;
	//�̏W��
	population = new int*[num];
	for(i=0;i<num;i++){
		population[i] = new int[length];
	}

	//�����̏�����
	srand( (unsigned)time( NULL ) );

	for(i=0;i<num;i++){
		for(j=0;j<length;j++){
			population[i][j] = rand()%2;
			printf("%d ",population[i][j]);
		}
		printf("\n");
	}

	
	for(i=0;i<num;i++){
		delete[] population[i];
	}
	delete[] population;

	return 0;
}
