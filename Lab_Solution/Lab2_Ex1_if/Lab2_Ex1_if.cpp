#include <iostream>
using namespace std;
int main()
{ 
	long i;                   //i Ϊ����
	double bonus,bon1,bon2,bon4,bon6,bon10;
	bon1=100000*0.1;          //10��Ľ���
	bon2=bon1+100000*0.075;   //20��Ľ���
	bon4=bon2+200000*0.05;    //40��Ľ���
	bon6=bon4+200000*0.03;    //60��Ľ���
	bon10=bon6+400000*0.015;  //100��Ľ���
	cout<<"��������:";
	cin>>i;
	if (i<100000)
	{	  bonus=0.1*i; }
	else if (i<=200000)
	{	  bonus=bon1+(i-100000)*0.075;  }
	else if (i<=400000)
	{	  bonus=bon2+(i-200000)*0.05;  }
	else if (i<=600000)
	{    bonus=bon4+(i-400000)*0.03;  }
	else if (i<=1000000)
	{	  bonus=bon6+(i-600000)*0.015;  }
	else 
	{    bonus=bon10+(i-1000000)*0.01; }
	cout<<"����="<<bonus<<endl;
	return 0;
}