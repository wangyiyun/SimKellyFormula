#include <cstdio>
#include <ctime>
#include <iostream>
#include <algorithm>
using namespace std;

double prob = 0.25;//prob（0 <= prob <1）是决定整体输赢的概率，eg.prob = 0.4,  整体中有40%的概率赢，60%的概率输.

int temp; 
int n; //强制循环数 
double f; //下注资金比  
double b; //赔率 
double money = 10000;//当前资金数，初始资金一万元； 
int MAXN;
double mark = prob * RAND_MAX;

bool frand()
{
	 temp = rand();
	 if(temp < mark) return 1;
	 return 0; 
}

int main()
{
	srand((unsigned)time(NULL));//重置随机种子 
	cout<<"you have "<<money<<" now.\n";
	cout<<"The prob you win is "<<prob/10<<".\n";
	cout<<"This simulation will end when your own less than 1 cent or reach the max-round.\n"<<"Input f:\n";
	cin>>f;
	cout<<"Input b:\n";//赔率 
	cin>>b; 
	cout<<"Input max-round:\n";
	cin>>n;
	MAXN = n;
	int coin;
	while(n)
	{
		if(money <= 0.01) break;//余额小于一分 
//		cout<<MAXN-n+1<<"	";
		if(frand())	money = money + money*f*b;
		else money = money - money*f;
		cout<<money<<"\n";
		n--;
	}
	cout<<"END\n";
	return 0;

}
