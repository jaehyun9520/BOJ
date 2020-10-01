#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int dx[4]={0,0,1,1};
int dy[4]={0,1,0,1};
int n,ans=0;
int map[17][17]={0};


void DFS(int type, int x, int y)  
{
	int xx,yy,i,cnt=0;
	
		
	if(x==n&&y==n)  // n n �� �����ϸ� ����� �� �߰�  
	{
		ans++;
	}
	
	
else {

	for(i=1; i<=3; i++)  // ������ , ����,  ������ �밢�� ����  
	{
		
		xx=x+dx[i];
		yy=y+dy[i];
		
		if(xx<=n&&yy<=n)
		{
			
			if(map[xx][yy]==0)
			{  cnt++;
			
				if(i==1)  
				{
					if(type==1)  //���� �������� ���� ���� 
					{
					
					map[xx][yy]=2;
					map[x][y-1]=0; 
				    DFS(type,xx,yy);	
				    map[xx][yy]=0;
					map[x][y-1]=2;
				}
				 
				   if(type==3)    // ���� �������� ���� �밢��   
				   {
				   	map[xx][yy]=2;
					map[x-1][y-1]=0; 
				    DFS(1,xx,yy);	
				    map[xx][yy]=0;
					map[x-1][y-1]=2;
				   }
				
				 }
				 
				 else if(i==2)
				 {
				 	if(type==2)  //���� �������� ���� ����  
				 	{
				 		map[xx][yy]=2;
				 		map[x-1][y]=0;
				 		DFS(type,xx,yy);
				 		map[xx][yy]=0;
				 		map[x-1][y]=2;
				 		
					 }
					 
					 else if(type==3)
					 {
					 	map[xx][yy]=2;
					  map[x-1][y-1]=0; 
				       DFS(2,xx,yy);	
				      map[xx][yy]=0;
					   map[x-1][y-1]=2;
					 	
					 }
				 	
				  } 
				 
				 
			}
		}
		
	}
	
	
	if(cnt==3)   // ���� ������ , ������ �밢�� ���� ��� ����ִ°��  
	{
		if(type==1)
		{
			map[xx][yy]=2;
					map[x][y-1]=0; 
				    DFS(3,xx,yy);	
				    map[xx][yy]=0;
					map[x][y-1]=2;
		}
		
		else if(type==2)
		{	
		map[xx][yy]=2;
		map[x-1][y]=0;
		DFS(3,xx,yy);
		map[xx][yy]=0;
		map[x-1][y]=2;
				 		
			
		}
		
		else if(type==3)
		{
				map[xx][yy]=2;
					  map[x-1][y-1]=0; 
				       DFS(3,xx,yy);	
				      map[xx][yy]=0;
					   map[x-1][y-1]=2;
		}
	}
	
}
	
	
	
}

int main()
{
//freopen("input.txt", "rt", stdin);
int i,j;

scanf("%d",&n);

for(i=1; i<=n; i++)
{
	for(j=1; j<=n; j++)
	{
		scanf("%d",&map[i][j]);
	}
}
map[1][1]=2;     
map[1][2]=2;  //������ �ʱ���ġ  

DFS(1,1,2); // 1: �ʱ���� (����)    (1,2) ������ ��ġ  

printf("%d",ans);
return 0;
}
