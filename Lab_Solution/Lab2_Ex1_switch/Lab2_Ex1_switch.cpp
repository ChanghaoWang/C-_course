#include <iostream>
using namespace std;
int main()
{  long i;       //i Ϊ����
double bonus,bon1,bon2,bon4,bon6,bon10;
int c;
bon1=100000*0.1;          //10��Ľ���
bon2=bon1+100000*0.075;  //20��Ľ���
bon4=bon2+200000*0.05;  //40��Ľ���
bon6=bon4+200000*0.03;  //60��Ľ���
bon10=bon6+400000*0.015; //100��Ľ���
cout<<"��������:";
cin>>i;
c=i/100000;
switch (c)
{
case 0:
	bonus=0.1*i;
	break;
case 1 :
	bonus=bon1+(i-100000)*0.075;
	break;
case 2:
case 3:
	bonus=bon2+(i-200000)*0.05;
	break;
case 4:
case5:
	bonus=bon4+(i-400000)*0.03;
	break;
case 6:
case 7:
case 8:
case 9:
	bonus=bon6+(i-600000)*0.015;
	break;
default:
	bonus=bon10+(i-1000000)*0.01;  
	break;  }
cout<<"����Ϊ"<<bonus<<endl;
return 0;
}
