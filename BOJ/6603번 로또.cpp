#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int k;
int list[14]={0};
int check[7]={0};

void DFS(int cnt, int x)  // ����� �� ���ϱ�  
{
	int i;

	if(cnt==6)  // 6�� �� �̾����� ���  
	{
		for(i=1; i<=6; i++)
		{
			printf("%d ",check[i]);
		}
		printf("\n");
	}
		
	else
	{
		
		for(i=x; i<=k; i++)
		{
			check[cnt+1]=list[i];  
			DFS(cnt+1,i+1);
		}
	}
}

int main()
{
//freopen("input.txt", "rt", stdin);
int i;
while(1)   // 0�� ���ö����� �׽�Ʈ���̽� �ݺ� �Է�  
 { 

scanf("%d",&k); 

if(k==0)  // K�� 0�̸� �׽�Ʈ ���̽� ����  
  {
	break;
  }  

for(i=1; i<=k; i++)   // K����ŭ�� ���� �Է�  
  {
	scanf("%d",&list[i]);
  }

DFS(0,1);   // K���� ���߿��� 6�� �̴� ����Ǽ� (����)  

printf("\n");
 }

return 0;
}
