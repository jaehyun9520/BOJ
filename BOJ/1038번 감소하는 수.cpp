#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int n; 
int list[11];
int number=-1;
int flag=0;

void DFS(int x, int cnt)  //X�� ���� � �̾Ҵ��� , CNT�� ��̾ƾ��ϴ���  
{
	
	if(x==cnt)  
	{
		number++;
		if(number==n) 
		{
		
		for(int i=1; i<=cnt; i++)
		{
			printf("%d",list[i]);
		}
		flag=1;
	}
	}
	
	
	for(int i=0; i<=9; i++)
	{
		
			if(list[x]>i||x==0) //ù��° �̴� ���ڰų�  ���� ���ں��� ������� �� ����  
			{
				list[x+1]=i;
				DFS(x+1,cnt);
			}
		
	}
	
	
	
	
}



int main()
{	
//freopen("input.txt", "rt", stdin);
scanf("%d",&n);
int i=1;

	for(i=1; i<=10; i++)
	{
		  DFS(0,i);  //1�ڸ� ������ 10�ڸ� ������ �����ϴ� ���� �̰� �Ѵ� .    
		   
	}
	
if(flag==0) printf("-1");

 

return 0;
}
