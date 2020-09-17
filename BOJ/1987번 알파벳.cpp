#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int r,c,i,j,answer=0;
int map[21][21]={0};    
int check[91]={0};

void DFS(int x, int y,int cnt)  // x,y �� ��ǥ  cnt= ��ĭ ��������  
{
	int i,xx,yy,t;
	
	if(answer<cnt)  // ���� �亸�� �� ���� ĭ�� �������� ��ü  
	{
		answer=cnt;
	}
	
	
	
	for(i=0; i<=3; i++)
	{
		xx=x+dx[i];     
		yy=y+dy[i];
		
		if(xx>=1&&xx<=r&&yy>=1&&yy<=c)
		{
			t=map[xx][yy];     
			if(check[t]==0)    // ó�� ���� ���ĺ�����?  
			{
				check[t]=1;
				DFS(xx,yy,cnt+1);  
				check[t]=0;
			}
		}
	}
	
	
}



int main()
{

//freopen("input.txt", "rt", stdin);

char a[21];

scanf("%d %d",&r,&c);

for(i=1; i<=r; i++)
{
	scanf("%s",a);
	
	for(j=1; j<=c; j++)
	{
		map[i][j]=a[j-1];
	}
}

check[map[1][1]]=1;

DFS(1,1,1);   

printf("%d",answer);

return 0;


}
