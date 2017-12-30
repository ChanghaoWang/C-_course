
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#define MAX_DATE_NUM 1000
#define FACTOR_NUM 20

struct weatherStruct
{
	char date[FACTOR_NUM];
	int highestTem;
	int lowestTem;
	string weatherState;
	string windDir;
	string windLev;
};

int main(void)
{
    ifstream inFile;
    int dayNum=0;
    int i=0;
    
    inFile.open("weather.txt",ios::in);   //��ֻ����ʽ���ı�
    
    fstream outFile;
    outFile.open("result.txt",ios::out);
    
    if (inFile.fail())
    {
        cout << "���ļ�ʧ�ܣ�" << endl;
        return 0;
    }
    else
    {
        weatherStruct myWeatherStruct[MAX_DATE_NUM];  //����ṹ����
        
        
        /*��ȡ������Ϣ�������struct*/
        while(!inFile.eof())
        {
            //��ȡ�ı�
            inFile>>myWeatherStruct[i].date>>myWeatherStruct[i].highestTem>>myWeatherStruct[i].lowestTem>>myWeatherStruct[i].weatherState>>myWeatherStruct[i].windDir>>myWeatherStruct[i].windLev;
            i++;
        }
        inFile.close();
		dayNum = i - 1;
        
        
        int dayHighestTem;      //ͳ�����ÿ���������
        int dayLowestTem;       //ͳ�����ÿ���������
        float aveHighestTem;   //ƽ���������
        float aveLowestTem;    //ƽ���������
        string dirWind;         //����ɾ�������С�ת����������֮����ַ���
        string stateWeather;    //����ɾ�������С�ת����������֮����ַ���
        string levWind;         //����ɾ�������С�ת����������֮����ַ���
		
        int lowPos=0;
        int highPos=0;
        int highestSum = 0;
        int lowestSum = 0;
		
		/*ͳ�Ƹ���������Ӧ�������ı���*/
		int nwQing=0;
		int nwYin=0;
		int nwDuoyun=0;
		int nwXiaoyu=0;
		int nwZhongyu=0;
		int nwZhenyu=0;
		int nwLeizhenyu=0;
		int nwDayu=0;
		int nwYujiaxue=0;
		int nwXiaoxue=0;
		int nwBaoyu=0;
		int nwLeiyu=0;
		
		/*ͳ�Ƹ��ַ��Ӧ�������ı���*/
		int nfDongnan=0;
		int nfDong=0;
		int nfXi=0;
		int nfNan=0;
		int nfBei=0;
		int nfXinan=0;
		int nfXibei=0;
		int nfDongbei=0;
		int nfWeifeng=0;
		
		/*ͳ�Ƹ��ַ�����Ӧ�������ı���*/
		int nlLes3=0;
		int nl3to4=0;
		int nl4to5=0;
		
		
        /*ͳ�Ƹ�����Ϣ*/
        
        dayHighestTem = myWeatherStruct[0].highestTem;
        dayLowestTem = myWeatherStruct[0].lowestTem;
        for(int j = 0; j< dayNum; j++ )
        {
            /*���ÿ���������*/
            if(myWeatherStruct[j].highestTem > dayHighestTem)
            {
                dayHighestTem = myWeatherStruct[j].highestTem;
                highPos = j;
            }
            /*���ÿ���������*/
           if(myWeatherStruct[j].lowestTem < dayLowestTem)
		   {
			   dayLowestTem = myWeatherStruct[j].lowestTem;
			   lowPos = j;
		   }
            
            /*ÿ����������ܺ�*/
            highestSum += myWeatherStruct[j].highestTem;

            /*ÿ����������ܺ�*/
            lowestSum += myWeatherStruct[j].lowestTem;
          
            /*ɾ����ת����������֮����ַ���*/
            stateWeather = myWeatherStruct[j].weatherState;
			for(int k=0; k < stateWeather.length();k++)
			{
				if(!(strncmp(&stateWeather[k],"ת",2)) || stateWeather[k] == '~')
				{
					stateWeather = stateWeather.substr(0,k);
					break;
				}
			}
			myWeatherStruct[j].weatherState = stateWeather;
			
			dirWind = myWeatherStruct[j].windDir;
			for(int k=0; k < dirWind.length(); k++)
			{
				if(!(strncmp(&dirWind[k],"ת",2)) || dirWind[k] == '~')
				{
					dirWind = dirWind.substr(0,k);
					break;
				}
			}
			myWeatherStruct[j].windDir = dirWind;

			levWind = myWeatherStruct[j].windLev;
			for(int k=0; k < levWind.length(); k++)
			{
				if(!(strncmp(&levWind[k],"ת",2)) || levWind[k] == '~')
				{
					levWind = levWind.substr(0,k);
					break;
				}
			}
			myWeatherStruct[j].windLev = levWind;
			

			/*ͳ�Ƹ���״̬��Ӧ������*/
			if(myWeatherStruct[j].weatherState == "��")
			{
				nwQing++;
			}

			if(myWeatherStruct[j].weatherState == "��")
			{
				nwYin++;
			}

			if(myWeatherStruct[j].weatherState == "����")
			{
				nwDuoyun++;
			}

			if(myWeatherStruct[j].weatherState == "С��")
			{
				nwXiaoyu++;
			}

			if(myWeatherStruct[j].weatherState == "����")
			{
				nwZhongyu++;
			}

			if(myWeatherStruct[j].weatherState == "����")
			{
				nwZhenyu++;
			}

			if(myWeatherStruct[j].weatherState == "������")
			{
				nwLeizhenyu++;
			}

			if(myWeatherStruct[j].weatherState == "����")
			{
				nwDayu++;
			}

			if(myWeatherStruct[j].weatherState == "���ѩ")
			{
				nwYujiaxue++;
			}

			if(myWeatherStruct[j].weatherState == "Сѩ")
			{
				nwXiaoxue++;
			}

			if(myWeatherStruct[j].weatherState == "����")
			{
				nwBaoyu++;
			}

			if(myWeatherStruct[j].weatherState == "����")
			{
				nwLeiyu++;
			}
			
			if(myWeatherStruct[j].windDir == "���Ϸ�")
			{
				nfDongnan++;
			}

			if(myWeatherStruct[j].windDir == "����")
			{
				nfDong++;
			}

			if(myWeatherStruct[j].windDir == "����")
			{
				nfXi++;
			}

			if(myWeatherStruct[j].windDir == "�Ϸ�")
			{
				nfNan++;
			}

			if(myWeatherStruct[j].windDir == "����")
			{
				nfBei++;
			}

			if(myWeatherStruct[j].windDir == "���Ϸ�")
			{
				nfXinan++;
			}

			if(myWeatherStruct[j].windDir == "������")
			{
				nfXibei++;
			}

			if(myWeatherStruct[j].windDir == "������")
			{
				nfDongbei++;
			}

			if(myWeatherStruct[j].windDir == "΢��")
			{
				nfWeifeng++;
			}
			
			if(myWeatherStruct[j].windLev == "С��3��")
			{
				nlLes3++;
			}

			if(myWeatherStruct[j].windLev == "3-4��")
			{
				nl3to4++;
			}

			if(myWeatherStruct[j].windLev == "4-5��")
			{
				nl4to5++;
			}
        }

        aveHighestTem = (float)highestSum/dayNum;
        aveLowestTem = (float)lowestSum/dayNum;

        outFile<<"���ÿ���������:"<<dayHighestTem<<"\t"<<myWeatherStruct[highPos].date<<"\n";
        cout<<"���ÿ��������£�"<<dayHighestTem<<"\t"<<myWeatherStruct[highPos].date<<"\n";
        outFile<<"���ÿ���������:"<<dayLowestTem<<"\t"<<myWeatherStruct[lowPos].date<<"\n";
        cout<<"���ÿ��������£�"<<dayLowestTem<<"\t"<<myWeatherStruct[lowPos].date<<"\n";
        outFile<<"ƽ��ÿ��������£�"<<aveHighestTem<<endl;
        cout<<"ƽ��ÿ��������£�"<<aveHighestTem<<endl;
        outFile<<"ƽ��ÿ��������£�"<<aveLowestTem<<endl<<endl;
        cout<<"ƽ��ÿ��������£�"<<aveLowestTem<<endl<<endl;

		outFile<<"����״̬ͳ�ƣ�"<<endl;
		cout<<"����״̬ͳ�ƣ�"<<endl;

		outFile<<"�磺 "<<nwQing<<endl;
		cout<<"�磺 "<<nwQing<<endl;
		outFile<<"���� "<<nwYin<<endl;
		cout<<"���� "<<nwYin<<endl;
		outFile<<"���ƣ� "<<nwDuoyun<<endl;
		cout<<"���ƣ� "<<nwDuoyun<<endl;
		outFile<<"С�꣺ "<<nwXiaoyu<<endl;
		cout<<"С�꣺ "<<nwXiaoyu<<endl;
		outFile<<"���꣺ "<<nwZhongyu<<endl;
		cout<<"���꣺ "<<nwZhongyu<<endl;
		outFile<<"���꣺ "<<nwZhenyu<<endl;
		cout<<"���꣺ "<<nwZhenyu<<endl;
		outFile<<"���꣺ "<<nwDayu<<endl;
		cout<<"���꣺ "<<nwDayu<<endl;
		outFile<<"���ѩ�� "<<nwYujiaxue<<endl;
		cout<<"���ѩ�� "<<nwYujiaxue<<endl;
		outFile<<"Сѩ�� "<<nwXiaoxue<<endl;
		cout<<"Сѩ�� "<<nwXiaoxue<<endl;
		outFile<<"���꣺ "<<nwBaoyu<<endl;
		cout<<"���꣺ "<<nwBaoyu<<endl;
		outFile<<"���꣺ "<<nwLeiyu<<endl;
		cout<<"���꣺ "<<nwLeiyu<<endl;
		outFile<<"�����꣺ "<<nwLeizhenyu<<endl<<endl;
		cout<<"�����꣺ "<<nwLeizhenyu<<endl<<endl;
		
		outFile<<"����ͳ�ƣ�"<<endl;
		cout<<"����ͳ�ƣ�"<<endl;

		outFile<<"���磺 "<<nfDong<<endl;
		cout<<"���磺 "<<nfDong<<endl;
		outFile<<"���磺 "<<nfXi<<endl;
		cout<<"���磺 "<<nfXi<<endl;
		outFile<<"�Ϸ磺 "<<nfNan<<endl;
		cout<<"�Ϸ磺 "<<nfNan<<endl;
		outFile<<"���磺 "<<nfBei<<endl;
		cout<<"���磺 "<<nfBei<<endl;
		outFile<<"���Ϸ磺 "<<nfDongnan<<endl;
		cout<<"���Ϸ磺 "<<nfDongnan<<endl;
		outFile<<"�����磺 "<<nfDongbei<<endl;
		cout<<"�����磺 "<<nfDongbei<<endl;
		outFile<<"���Ϸ磺 "<<nfXinan<<endl;
		cout<<"���Ϸ磺 "<<nfXinan<<endl;
		outFile<<"�����磺 "<<nfXibei<<endl;
		cout<<"�����磺 "<<nfXibei<<endl;
		outFile<<"΢�磺 "<<nfWeifeng<<endl<<endl;
		cout<<"΢�磺 "<<nfWeifeng<<endl<<endl;

		outFile<<"����ͳ�ƣ�"<<endl;
		cout<<"����ͳ�ƣ�"<<endl;

		outFile<<"С��3���� "<<nlLes3<<endl;
		cout<<"С��3���� "<<nlLes3<<endl;
		outFile<<"3-4���� "<<nl3to4<<endl;
		cout<<"3-4���� "<<nl3to4<<endl;
		outFile<<"4-5���� "<<nl4to5<<endl;
		cout<<"4-5���� "<<nl4to5<<endl;
    }
    outFile.close();
    
    system("pause");
    return 0;
}
