#include<iostream>
#include<algorithm>
#include<vector>

int check[2000001];
int n;
int list[21];

void DFS(int x, int cnt,int sum)
{
	int i;

	if(sum>0) check[sum]=1; //��������� �κм����� �� üũ  
	
	
	if(cnt<n)
	{
	
	for(i=x+1; i<=n; i++)  //�κм��� ����� (����)  
	{
		sum=sum+list[i];
		DFS(i,cnt+1,sum);
		sum=sum-list[i];
	}
}
}


using namespace std;
int main()
{
//freopen("input.txt", "rt", stdin);	
int i;
scanf("%d",&n);

for(i=1; i<=n; i++)
{
	scanf("%d",&list[i]);
}

DFS(0,0,0); 
i=1;
while(1) //1���� �����ؼ� üũ�ȵ� ���ڸ� ã���ֱ�  
{
	if(check[i]==0) 
	{
	printf("%d",i); 
	break;
}
else i++;
}

return 0;
}
