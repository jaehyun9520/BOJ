#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<stack>
using namespace std;
int main()
{	
//freopen("input.txt", "rt", stdin);
stack <int> s;   
char a[51];
int i,cnt=0,val=0,ans=0;
scanf("%s",a);
for(i=0; a[i]!='\0'; i++)
{
	if(a[i]>='0'&&a[i]<='9')
	{
		cnt++;   // ���� ī��Ʈ  
}
if(a[i]=='(')    
{
	if(cnt-1>0)
	{
		s.push(cnt-1);  //(�ٷξ��� ���ڴ� ��������ϴ� ���̴� -1 �ؼ� �־��ֱ�  
	}
	cnt=0;
	s.push(-(a[i-1]-48));  
	s.push(0);   //  '('�� 0���� ���  
		
}

if(a[i]==')')             
{
	val=cnt;
	while(1)
	{

		if(s.top()==0)  // ( �̶�� ����������  
		{
			
			s.pop();
			break;
		}
		
		
			else if(s.top()>0)    // ���ξ� ���ڿ��� ���� �����ֱ�  
			{
				
				val=s.top()+val;
				
				s.pop();
			 } 
		}
		cnt=0;
		val=val*-(s.top());  // ���� * ��������ϴ� ����  
		
		s.pop();
		if(val>0) s.push(val);  //���ÿ� �־��ֱ�  
		
	}
	
}

while(!s.empty()) 
{
	ans=ans+s.top();
	s.pop();
}

printf("%d",ans+cnt);  // 3(14)333   333�� ī��Ʈ�� �ǳ� ���ÿ� �ȵ��� ������ ���� �����ֱ�.. 
return 0;
}
