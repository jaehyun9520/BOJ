#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>

using namespace std;

int main()
{
//freopen("input.txt", "rt", stdin);

int i,x=1,answer=0;    
char a[31];

stack <char> s;
scanf("%s",a);


for(i=0; a[i]!='\0'; i++)
{
	
	
	if(a[i]=='('||a[i]=='[')      // ( [ ��ȣ�� ���� ���ÿ� �־��ְ� �� ��ȣ�� ���� �ϳ��� ������ ��� �����ֱ�        
	{
		s.push(a[i]);
		
		if(a[i]=='(')
		{
		
		  x=x*2;
	    }
		if(a[i]=='[')
		{
		
		x=x*3;
	    }
		
	}
	
	
	
	else if(a[i]==')')
	{
		if(s.empty()||s.top()=='[')
		{
			printf("0");
			exit(0);
		}
		
		else if(a[i-1]=='('&&s.top()=='(')  // ���� ��ȣ�� ¦�� �´� ���� ��ȣ��� ���±��� ������ X���� �����result�� �����ش�. 
		{
			s.pop();
			 answer=answer+x;
			 x=x/2;
		}
		
		else if(a[i-1]!='('&&s.top()=='(')  //    ���� ��ȣ�� �ݴ°�ȣ��� �̹� ���ÿ� �ִ� ��ȣ�� ������ ���ϴ°ɷ�  �������Ƿ�  
		{                                   // result�� x���� ���������ʰ� x���� �����ش�. 
			s.pop();
			x=x/2;
		}
		
	}
	else if(a[i]==']')
	{
		if(s.empty()||s.top()=='(')
		{
			printf("0");
			exit(0);
		}
		
		else if(a[i-1]=='['&&s.top()=='[')
		{
			s.pop();
			 answer=answer+x;
			 x=x/3;
		}
		
		else if(a[i-1]!='['&&s.top()=='[')
		{
			s.pop();
			 
			 x=x/3;
		}
		
	}
		
		
		
	}
	
	if(!s.empty())   // �迭�� �� ���Ҵµ��� ���ÿ� ��ȣ�� ������?  (({{{ �̷������� ���´� ¦�� �����ʾ� 0 ��� 
	{
		printf("0");
		exit(0);
		
	}
	
printf("%d",answer)	;
	
	

return 0;

}
