#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>

using namespace std;



int main()
{
//freopen("input.txt", "rt", stdin);
char a[2001];
int cnt=0,i,c;
stack <char> s;

while(1)
{
	
	c=0;   // ���ڿ��� ���������� �ٲٴµ� �ʿ��� �ּ����� ������ ��  
	cnt++;  // �׽�Ʈ ���̽� ��ȣ  
	scanf("%s",a);
	
	if(a[0]=='-')  // - ������ ����  
	{
		exit(0);
	}
	
	else
	{
	   for(i=0; a[i]!='\0'; i++)
	   {
	   	    if(a[i]=='{')  
	   	    {
	   	         s.push(a[i]);	
	   	    
			   }
			   
			   else if(a[i]=='}')
			   {
			   	   if(s.size()==0)   // ������ ����ִµ� } ������ �ٲ��ֱ�  
			   	   {
			   	   	     c++;
			   	   	    s.push('{');
					  }
					 
					else 
					{
						s.pop();  // ������ ������� ���� ���¶�� ������ { ��縸 ��������״� �ٷ� pop 
					  }  
					  
			   	
			   }
		   }
		   
		   while(!s.empty())   //  �� �����µ��� ��������ʴٸ�? { { { { �̷�����  �������״� { { { } �̷��� �ѹ� �ٲ��ְ� c++ 
		   {
		   	    c++;
		   	    s.pop();
		   	    s.pop();
			   }	
		
	}
	
	printf("%d. %d\n",cnt,c);
}

return 0;

}
