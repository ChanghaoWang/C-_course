#include < iostream >
#include < cmath >
using namespace std;

class Line	//�߶λ���
{
protected:
	double sizeA;
public   :	
	Line()
	{
		cout<<"input line length��"<< endl;
		cin>>sizeA;
	}
	Line(double a)
	{
		sizeA = a;
	}
	double getLength()
	{
		return sizeA;
	}
};

class Triangle : public Line//
 {
protected:	double sizeB, sizeC;
public   :	Triangle()
			{
				cout<<"input line length��"<< endl;
				cin>>sizeB;
				sizeC = sqrt( sizeB * sizeB + sizeA * sizeA );
			}
			void printSize()
			{				cout<<"for right triangle��three lines are��";
			cout<<"A: "<< sizeA << ", b: "<< sizeB << ", C: "<< sizeC << endl;
			}
};

class Rectangle : public Triangle//
{
protected:
	double sizeD;
public   :	
	Rectangle()
	{
		sizeC = sizeA;
		sizeD = sizeB;
	}
	void printSize()
	{
		cout<<"for rectangle��four lines are��";
		cout<<"A: "<< sizeA << ", b: "<< sizeB << ", C: "<< sizeC << ", D: "<< sizeD << endl;
	}

};

void main()
{
	Line *l = new Line();
	cout<<"line legth:"<< l->getLength() << endl;
	cout<<"*****************"<<endl;
	Triangle *t = new Triangle();
	t->printSize();
	cout<<"*****************"<<endl;
	Rectangle *r = new Rectangle();
	r->printSize();
}
