#include<iostream>
#include<algorithm>
#include<vector>
#include<deque>
#include<math.h>
using namespace std;


deque <int> d;

char p[100001];   // ��ɾ� �޴� �迭 
char x[400001];    //�迭�� ����ִ� ���� 
int rev=0;  // ������ �������� �ƴ��� Ȯ���� ����  

int main()
{
//freopen("input.txt", "rt", stdin);
int t,i,j,n,k,cnt=-1,total=0,error;

int num[4]={0};

scanf("%d",&t);

for(i=1; i<=t; i++)
{
    scanf("%s",p);
	
	scanf("%d",&n);
	
    scanf("%s",x);
	rev=0;
	cnt=0;
	error=0;
	for(j=0; x[j]!='\0'; j++)
	{
		if(48<=x[j]&&x[j]<=57)
		{
			cnt++;
		     num[cnt]=x[j]-48;
			 	
		}
		
		if(x[j]==','||x[j]==']')
		{
			for(k=1; k<=cnt; k++ )
			{
				total=total+num[k]*pow(10,cnt-k);
			}
			
			if(cnt>=1)
			{
			
			d.push_back(total);
			
			total=0;
		}
			cnt=0;
			
			
		}
		
			}		
			
			
		for(j=0; p[j]!='\0'; j++)
		{
			if(p[j]=='R')
			{        
				if(rev==0)
				  rev=1;
				  
				else if(rev==1)
				rev=0;
				
			}
			
			if(p[j]=='D')
			{
				if(d.size()==0)
				{
					error=1;
					break;
				}
				
				else{
				
				if(rev==1)   // ������ ���´�  �ڸ� ������ �����ϰ� pop_back���ֱ�  
				{
					d.pop_back();
				}
				
				else{
				
				d.pop_front();   // �������´� �տ��� ���ֱ�  
			}
			}
			}
			}
			
			if(error==1)   
			{
				printf("error\n");
			}
			
			
			else 
			{
			
			
			
			
			
			
			
			printf("[");
			
			
			if(d.size()==1)   
			{
				printf("%d]\n",d.front());
				d.pop_front();
			}
			
			
			 else{
			 
			
			
		while(!d.empty())
		{
		
		   if(rev==0)
		   {
		   
				printf("%d,",d.front());
				d.pop_front();
	      }
	      
	      else if(rev==1)
	      {
	      	printf("%d,",d.back());
				d.pop_back();
		  }
				if(d.size()==1)
				break;
			
	}
	
	if(!d.empty())
	{
		
		printf("%d]\n",d.front());
			d.pop_front();

	}
	
	else
	{
		printf("]\n");
			}
			
			
		}
					     
			 }
			 
			 
	
}
return 0;

}
