#include <iostream>
using namespace std;

int main()
{
	char password[]="sjtuc++";		//Ԥ�������
	char c,input[20];				//c������ŵ����ַ���input��������ַ���
	int i;

	cout<<"�����벻����20���ַ�������\n";
	i=0;
	while((c=getchar()) !='\n' && i<20){	//'\n'��Ϊ���������ַ�������־
		*(input+i)=c;
		i++;
	}
	input[i]='\0';							// �ַ������һ��Ԫ��
	cout<<"�����������Ϊ"<<input<<endl;


	for(i=0;i<20,password[i]!='\0';i++){	//С��20���ַ�������password�ַ�����û�н���
		if( *(input+i) != *(password+i)){	//����Ƚ��ַ�
			cout<<"����������벻��ȷ\n";	
			return 0;
		}
	}
	cout<<"������ȷ����ӭ��\n";
	return 0;


}

