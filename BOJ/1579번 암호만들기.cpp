#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int l,c;
vector <int> list;
int answer[15]={0};

void DFS(int cnt, int x)
{
	
	int i,t,a=0,b=0;
	
	if(cnt==l)
	{
		for(i=1; i<=cnt; i++)
		{
		   t=answer[i];
		   if(t=='a'||t=='e'||t=='i'||t=='o'||t=='u')  
		   	{ 
			   a++;
			}
			   else
			{
			   	b++;
			}	
		}
		
		if(a>=1&&b>=2)  // �ּ� ���� 1�� ����2���� �����ϴ� ��ȣ���� Ȯ��  
		{
			for(i=1; i<=cnt; i++)
			{
				printf("%c",answer[i]);
			}
			printf("\n");
		}
	}
	
	else if(cnt<l)
	   	{
		   for(i=x; i<c; i++)
		   {
				answer[cnt+1]=list[i];
			  	DFS(cnt+1,i+1);
		   }
	   	}
}



int main()
{
//freopen("input.txt", "rt", stdin);
int i;
char a;
scanf("%d %d",&l,&c);


for(i=1; i<=c; i++)
	{
	scanf(" %c",&a);
	list.push_back(a);
	}

sort(list.begin(),list.end());  // ���������� ���� ���� 



DFS(0,0);  // C���߿� L�� �̱�  

return 0;
}
