#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

int length[40]={0};

void func(int i, int n)
{
	
	
if(i==0)   
{

	
	if(n==1) cout<<"m";
	
	else cout<<"o";
}
	
else{

	if(n<=length[i-1])   // n�� ����  s(i-1)�� ���ϴ� ��� 
	{
		func(i-1,n);
	}
	
	else if(length[i-1]<n&&n<=length[i-1]+i+3)  // n�� i+3 �κп� ���ϴ� ���  
	{
		if(n==length[i-1]+1)
		   cout<<"m";  
		   else cout<<"o";
	}
	
	else{
		
		func(i-1,n-(length[i-1]+i+3));  // ���� s(i-1)�� ���ϴ� ���  
	}
}
}

int main()
{
//freopen("input.txt", "rt", stdin);
ios_base :: sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
int i=0,n;

cin>>n;

length[0]=3;

if(n>=4)
{

for(i=1; i<=27; i++)    
	{
	    length[i]=length[i-1]+i+3+length[i-1];  // ������ ���� ���  
	    
	    if(n<=length[i]) break;  //���ǿ� �ش��ϸ� �������� 
	}
}
	func(i,n); 
												   											   
return 0;
}
