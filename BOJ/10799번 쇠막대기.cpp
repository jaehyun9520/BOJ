#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>

using namespace std;



int main()
{
//freopen("input.txt", "rt", stdin);
int i=0,total=0,flag=0;
char a[100001];
stack <char> s;


scanf("%s",a);

for(i=0; a[i]!='\0'; i++)
{

	if(a[i]=='(') 
	{
		s.push(a[i]);
		
		
	}
	
	else if(a[i]==')')    
	{
		if(a[i-1]=='(')   // �ܵ����� �ִ� ���������� �踷��� ���� �ȿ� �ִ� ���������� 
		{
			if(s.size()>1)  // �踷��� ���� ������  
			{
				s.pop();        
				total=total+s.size(); // �������� ��� �踷����� �� ��ŭ �߸� �踷������ ���� ����� s.size()�� ��������   
			}
			
			
			
			else if(s.size()==1) //�ܵ����� ������ �׳� ����  
			s.pop();
	     }
	        if(a[i-1]==')') // �踷��� 
	        {
			s.pop();
			total=total+1;  // �þ ������ �������� �� ���������� ���� �踷����� ������ ������  
		     }
				
						
	}		 
}
	

printf("%d",total);


return 0;

}
