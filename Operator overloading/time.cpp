  
#include<iostream>
using namespace std;

class Time	{
	private:
		int h,m,s;
	public:
	// Arithmetic Operators....
	Time operator + (Time const &temp)	{
		Time x;
		x.h = h + temp.h;
		x.m = m + temp.m;
		x.s = s + temp.s;
		if(x.m>59)	{
			x.h = x.h + 1;
			x.m = x.m%60;
		}
		if(x.s>59)	{
			x.m = x.m + 1;
			x.s = x.s%60;
		}
		return x;
	}
	Time operator - (Time const &temp)	{
		Time x;
		int t1,t2,t;
		t1=3600*h+60*m+s;
		t2=3600*temp.h+60*temp.m+temp.s;
		t=t1-t2;
		x.h = t/3600;
		x.m = (t/60) - (x.h*60);
		x.s = t % 60;
		return x;
	}
	// Relational Operators....
	int operator > (Time const &temp)	{
		int s1,s2;
		s1 = 3600*h+60*m+s;
		s2 = 3600*temp.h+60*temp.m+temp.s;
		if(s1>s2) return 1;
		return 0;
	}
	int operator < (Time const &temp)	{
		int t1,t2;
		t1 = 3600*h+60*m+s;
		t2 = 3600*temp.h+60*temp.m+temp.s;
		if(t1<t2) return 1;
		return 0;
	}
	// Assignment Operators....
	Time operator = (Time const &temp)	{
		h=temp.h;
		m=temp.m;
		s=temp.s;
	}
	// Comp.Assign Operators....
	Time operator += (Time const &temp)	{
		h=h+temp.h;
		m=m+temp.m;
		s=s+temp.s;
		if(s>59)	{
			s=s%60;
			m=m+1;
		}
		if(m>59)	{
			m=m%60;
			h=h+1;
		}
	}
	Time operator -= (Time const &temp)	{
		int t,t2;
		t=3600*h+60*m+s;
		t2=3600*temp.h+60*temp.m+temp.s;
		t=t-t2;
		h = t/3600;
		m = (t/60) - (h*60);
		s = t % 60;
	}
	// Unary Operators....
	Time operator ++ ()	{
		this->s=this->s+1;
		if(s>59){
			m+=1;
			s=s/60;
		}
		if(m>59){
			h+=1;
			m=m/60;
		}
	}
	Time operator -- ()	{
		int t;
		t=3600*h+60*m+s;
		t=t-1;
		h = t/3600;
		m = (t/60) - (h*60);
		s = t % 60;
	}
	void get_time()	{
		do{
			cout<<"\nEnter Hour, Minute, Second Values : ";
			cin>>h>>m>>s;
			if(h<0||m<0||s<0) cout<<"\nNegative Value Found !\n";
			else if(m>59||s>59) cout<<"\nInvalid Time !\nEnter values from 0 to 60 ! \n";
		}while(h<0||m<0||s<0||m>59||s>59);
	}
	void print()	{
		printf("\nTime : %02d:%02d:%02d\n",h,m,s);
	}
};

main()
{
	Time t1,t2;
	t1.get_time(),t2.get_time();
	Time t3 = t1+t2, t4 = t1-t2;
	t1.print();
	t2.print();
	cout<<"\nSum :-\n";
	t3.print();
	cout<<"\nDifference :-\n";
	t4.print();
	if(t1>t2) cout<<"\nt1 > t2\n";
	if(t1<t2) cout<<"\nt1 < t2\n";
}
