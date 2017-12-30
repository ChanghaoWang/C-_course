#include <iostream>
using namespace std;
#define N 4

/* 
	����һά������׵�ַ�����鳤�ȣ�ע���ά����Ԫ��
	���ڴ��еĴ��˳��ʵ��a[i][j] ��a[j][i]��ֵ����
*/
void transpose(int *a,int dim)
{
	int i,j,temp;
	for(i=0; i<dim; i++){
		for(j=i+1; j<dim; j++){
			temp = *(a+dim*i+j);
			*(a+dim*i+j) = *(a+dim*j+i);
			*(a+dim*j+i) = temp;
		}
	}
}

/*
	�����ά����Ԫ��
*/
void print(int *a,int dim)
{
	int i,j;
	for(i=0; i<dim; i++){
		for(j=0; j<dim; j++){
			cout<<*(a+dim*i+j)<<" ";
		}
		cout<<endl;
	}

}
int main()
{
	int i,j;
	int a[N][N];
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			a[i][j]=(i+1)*10+(j+1);	//����ֵ
		}
	}
	cout<<"ת��֮ǰ"<<endl;
	print(&a[0][0],N);
	transpose(&a[0][0],N);
	cout<<"ת��֮��"<<endl;
	print(&a[0][0],N);
	return 0;

}
