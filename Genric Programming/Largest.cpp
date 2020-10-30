#include<iostream>
using namespace std;

template <typename T>
T Largest(T n1,T n2,T n3)	{
	cout<<"\n\nThe Largest Value : ";
	n1>n2 ? (n1 > n3 ? cout<<n1 : cout<<n3) : (n2 > n3 ? cout<<n2 : cout<<n3);
}

main()	{
	Largest(1, 2, 3);
	Largest(7.54, 8.26, 9.11);
	Largest('a','Z','z');
}
