#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
	int dx[4]={1,-1,0,0};
	int dy[4]={0,0,1,-1};
	
	struct state{
		
		int x;
		int y;
		int dis;
		int cnt;
		
		state(int a, int b, int c, int d)
		{
			x=a;
			y=b;
			dis=c;
			cnt=d;
		}
	};
	

			
int main()
{
	

	
//freopen("input.txt", "rt", stdin);
int map[51][51]={0};
int check[64][51][51]={0};  
queue <state> Q;
int i,j,n,m,ans=0,x,y,xx,yy,cnt,dis;
char a[51];
scanf("%d %d",&n,&m);

for(i=1; i<=m; i++)
{
	scanf("%s",a);
	
	for(j=1; j<=n; j++)
	{
		map[i][j]=a[j-1];
		
		if(map[i][j]=='X')  // ������ ��� ���Ƿ� ��ȣ �ο�  ������ 5������ ������������ �ִ� 5������  
		{
			map[i][j]=++ans;
		}
		if(map[i][j]=='S')   // ������ġ  
		{
			map[i][j]='.';
			check[0][i][j]=1;
			Q.push(state(i,j,0,0));
		}
	}
}

ans=(1<<ans)-1;


while(!Q.empty())
{
	x=Q.front().x;
	y=Q.front().y;
	dis=Q.front().dis;
	cnt=Q.front().cnt;  // ���� ���� ��Ȳ �ִ� 5����  
	Q.pop();

	for(i=0; i<=3; i++)
	{
		xx=x+dx[i];
		yy=y+dy[i];
		
		if(xx>=1&&xx<=m&&yy>=1&&yy<=n)
		{
			if(map[xx][yy]=='.'&&check[cnt][xx][yy]==0)  // ����� ���  
			{
				check[cnt][xx][yy]=1;
				Q.push(state(xx,yy,dis+1,cnt));
			}
			
			else if(1<=map[xx][yy]&&map[xx][yy]<=5&&check[cnt][xx][yy]==0) // ������ �������  
			{
				if((cnt&1<<(map[xx][yy]-1))==0)  // ���ο� ��������? 
				{
				
					check[cnt][xx][yy]=1;
					Q.push(state(xx,yy,dis+1,cnt|(1<<(map[xx][yy]-1)))); //���Ǻ�����Ȳ ���� �� ť�� �־���  
				}
				
				else {
					check[cnt][xx][yy]=1;      // ���ο� ������ �ƴҰ�� �׳� ������  
					Q.push(state(xx,yy,dis+1,cnt));
				}
			}
			
			else if(map[xx][yy]=='E'&&cnt==ans) // Ż�ⱸ�� �߰��߰� ���� ������ ��� �� ���������� Ż��  
			{
				printf("%d",dis+1);
				exit(0);
			}
			
		}
	}
	
}
return 0;
}
