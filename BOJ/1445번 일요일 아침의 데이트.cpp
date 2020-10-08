#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

struct state
{
	int x;
	int y;
	int cnt1;
	int cnt2;
	int g; 
	
	state(int a, int b, int c, int d, int e)
	{
		x=a;
		y=b;
		cnt1=c;
		cnt2=d;
		g=e;
	}
 } ;

int main()
{	
//freopen("input.txt", "rt", stdin);
int n,m,i,j,fx,fy,x,y,nx,ny,cnt1,cnt2,flag=0,ans1=10000,ans2=10000,g=0,sx,sy;
char input[51];
int map[51][51]={0};
int check1[51][51]={0};  //�����⸦ ���Ƚ�� 
int check2[51][51]={0}; // ������ ������ ������Ƚ��  
queue <state> Q;
scanf("%d %d",&n,&m);


for(i=1; i<=n; i++)
{
	scanf("%s",input);
	
	for(j=1; j<=m; j++)
	{
		map[i][j]=input[j-1];
		
		check1[i][j]=-1;
		if(map[i][j]=='S')
		{
			sx=i;
			sy=j;
			check1[i][j]=0;
			Q.push(state(i,j,0,0,0));
		}
		
		if(map[i][j]=='F')
		{
			fx=i; fy=j;
		}
	}
}


while(!Q.empty())
{
	x=Q.front().x;
	y=Q.front().y;
	cnt1=Q.front().cnt1;
	cnt2=Q.front().cnt2;
	g=Q.front().g;
	flag=0;
	
	Q.pop();
	

if(sx!=x||sy!=y)
{
		
	if(g==0)
	{
	
	for(i=0; i<=3; i++)
	{
		nx=x+dx[i]; ny=y+dy[i];
		
		if(nx>=1&&nx<=n&&ny>=1&&ny<=m)
		{
			if(map[nx][ny]=='g')
			{
				flag=1;
				break;
			}
		}
	}
}
}
	// �����Ⱑ ���� �ִ��� Ȯ��
	
	if(flag==1) cnt2++;

	for(i=0; i<=3; i++)
	{
		nx=x+dx[i]; ny=y+dy[i];
		
		
		if(nx>=1&&nx<=n&&ny>=1&&ny<=m)
		{
			if(map[nx][ny]=='.')
			{
				if(check1[nx][ny]==-1||check1[nx][ny]>cnt1)
				{
					check1[nx][ny]=cnt1;
					check2[nx][ny]=cnt2;
					Q.push(state(nx,ny,cnt1,cnt2,0));
				}
				
				if(check1[nx][ny]==cnt1) // ������ ��� ������ Ƚ���� ���ٸ� ������ ����������� �� ����Ƚ��! 
				{
					if(cnt2<check2[nx][ny])
					{
						check2[nx][ny]=cnt2;
						Q.push(state(nx,ny,cnt1,cnt2,0));
						
											 } 
					
				}
				
			}
			
			
		 else if(map[nx][ny]=='g')
			{
				if(check1[nx][ny]==-1||check1[nx][ny]>cnt1+1)
				{
					check1[nx][ny]=cnt1+1;
					check2[nx][ny]=cnt2;
					Q.push(state(nx,ny,cnt1+1,cnt2,1));
				}
				
				if(check1[nx][ny]==cnt1+1) // ������ ��� ������ Ƚ���� ���ٸ� ������ ����������� �� ����Ƚ��! 
				{
					if(cnt2<check2[nx][ny])
					{
						check2[nx][ny]=cnt2;
						Q.push(state(nx,ny,cnt1+1,cnt2,1));
						
											 } 
					
				}
				
			}
			
			else if(map[nx][ny]=='F')
			{
				if(ans1>cnt1)
				{
					ans1=cnt1;
					ans2=cnt2;
				}
				
				else if(ans1==cnt1)
				{
					if(ans2>cnt2)
					ans2=cnt2;
				}
				
			}
	
		}
	 } 
	
	
}


printf("%d %d",ans1,ans2);

return 0;
}
