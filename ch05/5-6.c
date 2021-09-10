#include <stdio.h>

int move(int a, int &x, int &y, int x_size);
int xy2s(int x, int y, int x_size);

int main()
{
	int x_size=10;//x�������̖��H�̑傫���ix_size=10�̎��ɂ́Cx��0����9�̒l���Ƃ�)
	int y_size=9;
	int **maze;
	int i,j;

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
	
	printf("\n");

	int s;
	for(i=0;i<x_size;i++){
		for(j=0;j<y_size;j++){
			s=xy2s(i,j,x_size);
			printf("%3d",s);
		}
		printf("\n");
	}

	int x,y,a,sd;
	x=1;
	y=1;
	
	//�E
	a=0;
	sd = move(a,x,y,x_size);
	printf("x=%d,y=%d,sd=%d\n",x,y,sd);
	//��
	a=1;
	sd = move(a,x,y,x_size);
	printf("x=%d,y=%d,sd=%d\n",x,y,sd);
	//��
	a=2;
	sd = move(a,x,y,x_size);
	printf("x=%d,y=%d,sd=%d\n",x,y,sd);
	//��
	a=3;
	sd = move(a,x,y,x_size);
	printf("x=%d,y=%d,sd=%d\n",x,y,sd);

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

