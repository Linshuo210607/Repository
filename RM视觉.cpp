#include<iostream>
#include<fstream> 
#include<cstring>
#include<iomanip>
#include<cmath>
#include<vector>
using namespace std;
class Robot
{
	friend class team;
protected:
	int number;
	char team;
	int blood_vol;
	bool dead_flag;

public:
	Robot(int n,char t,int b)
	{
		number=n;
		team=t;
		blood_vol=b;
		dead_flag=0;
	}
};

class B_robot:public Robot
{
protected:
	int s_gun;
	int cur_heat;
public:
	B_robot(int n,char t,int b=100,int s=200,int h=0):Robot(n,t,b),s_gun(s),cur_heat(h)
	{
		cout<<"�Ѵ���";
		cout<<(t='R') ? "�췽":"����";
		cout<<n<<"�Ų��������ˣ�\n";
	}
	void shoot(int n)
	{
		if(team='R')
			cout<<"�췽";
		else
			cout<<"����";
		cout<<number<<"�ŷ���"<<n<<"��17mm���裡����"<<n*15<<"��������\n";

		cur_heat+=n*15;
		if(cur_heat>s_gun)
		{
			cout<<"�����������ޣ�"<<number<<"�Ż�����������\n";
			blood_vol=0;
			die();
		}
	}
	void attacked(int injure)
	{
		blood_vol-=injure;
		if(blood_vol<=0)
		{
			cout<<"Ѫ����0��"<<number<<"�Ż�����������\n";
			blood_vol=0;
			die();
		}
	}
	void die()
	{
		s_gun = 0;
		dead_flag=true;
	}
};

class S_robot:public Robot
{
protected:
	int s_gun;
	int cur_heat;
public:
	S_robot(int n,char t,int b=200,int s=300,int h=0):Robot(n,t,b),s_gun(s),cur_heat(h)
	{
		cout<<"�Ѵ���";
		cout<<(t='R') ? "�췽":"����";
		cout<<n<<"���ڱ������ˣ�\n";
	}
};

class Y_robot:public Robot
{
protected:
	int l_gun;
	int cur_heat;
public:
	Y_robot(int n,char t,int b=200,int l=300,int h=0):Robot(n,t,b),l_gun(l),cur_heat(h)
	{
		cout<<"�Ѵ���";
		cout<<(t='R') ? "�췽":"����";
		cout<<n<<"��Ӣ�ۻ����ˣ�\n";
	}
};

class G_robot:public Robot
{
protected:
	
public:
	G_robot(int n,char t,int b=200):Robot(n,t,b)
	{
		cout<<"�Ѵ���";
		cout<<(t='R') ? "�췽":"����";
		cout<<n<<"�Ź��̻����ˣ�\n";
	}
};

class team
{
protected:
	vector<B_robot> B_mem;
	vector<S_robot> S_mem;
	vector<Y_robot> Y_mem;
	vector<G_robot> G_mem;
	vector<Robot> mem;
public:
	void A_B(B_robot m)
	{
		B_mem.push_back(m);
		mem.push_back(m);
	}
	void A_S(S_robot m)
	{
		S_mem.push_back(m);
		mem.push_back(m);
	}
	void A_Y(Y_robot m)
	{
		Y_mem.push_back(m);
		mem.push_back(m);
	}
	void A_G(G_robot m)
	{
		G_mem.push_back(m);
		mem.push_back(m);
	}
	char rearch(int number)
	{
		vector<Robot>::iterator p = mem.begin();
	    while(p!=mem.end()) 
		{
			if(p->number==number)
				return p->team;
		}
	}
}B,R;

class Order
{
protected:

public:
	void A(char team,char kind,unsigned int number)
	{
		if(team=='R')
			switch(kind)
			{
				case 'B':
					R.A_B(B_robot(number,team));
					break;
				case 'S':
					R.A_S(S_robot(number,team));
					break;
				case 'Y':
					R.A_Y(Y_robot(number,team));
					break;
				case 'G':
					R.A_G(G_robot(number,team));
					break;
			}
		else
			switch(kind)
			{
				case 'B':
					B.A_B(B_robot(number,team));
					break;
				case 'S':
					B.A_S(S_robot(number,team));
					break;
				case 'Y':
					B.A_Y(Y_robot(number,team));
					break;
				case 'G':
					B.A_G(G_robot(number,team));
					break;
			}
	}
	void F(char team,int number,int injure)
	{
		if(team=='R')
		{
			switch()
				R.F_B(number,injure);

		}
	}
	void H()
	{

	}
}

int main()
{
	ifstream infile;
	infile.open("data.txt");
	return 0;
}