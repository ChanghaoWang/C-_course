#include <iostream>
using namespace std;
/* 
	move_around_one_step�Ĺ����ǽ������
	���һ���Ƶ���ǰ�棬��������˳��һ��λ��
*/
void move_around_one_step(int * vector,int length)
{
	int i;
	int last_item = *(vector + length - 1);
	for(i=length-1; i>=1; i--){
		vector[i] = vector[i-1];	
	}
	vector[0] = last_item;
}

int main()
{
	int i,m,n,a[20];
	cout<<"�������ĸ���(������20��)"<<endl;
	cin>>n;
	cout<<"��󼸸�������Ҫ�ƶ�����ǰ��"<<endl;
	cin>>m;
	cout<<"������"<<n<<"������"<<endl;
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	cout<<"����"<<n<<"������Ϊ"<<endl;	
	for(i=0;i<n;i++){
		cout<<a[i]<<'\t';
	}
	cout<<endl;
	//ÿ���ƶ�һ����Ҫ�ƶ�m��
	for(i=0;i<m;i++){
		move_around_one_step(a,n);
	}
	cout<<"�������"<<n<<"������Ϊ"<<endl;	
	for(i=0;i<n;i++)	
		cout<<a[i]<<'\t';
	cout<<endl;
	return 0;
}
