#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;


char a[1501];
int map[1501][1501]={0};
int check[1501][1501]={0};
int r,c;


int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

struct state{
	
	int x;
	int y;
	int time;
	
	state(int a, int b, int c)
	{
		x=a;
		y=b;
		time=c;
		
	}
};

queue <state> Q;
queue <state> Q1;

void BFS()    
{
	int i,j,x,y,xx,yy,time;
	
	while(!Q1.empty())
{
	x=Q1.front().x;
	y=Q1.front().y;
	time=Q1.front().time;
	Q1.pop();
	
	
	for(i=0; i<=3; i++)
	{
		xx=x+dx[i];
		yy=y+dy[i];
		
		
		
		if(xx>=1&&xx<=r&&yy>=1&&yy<=c)
		{
			if(map[xx][yy]=='.'&&check[xx][yy]==1)
			{
				check[xx][yy]=time;
				Q1.push(state(xx,yy,time));
			}
		}
	}
	
}
}

int main()
{
//freopen("input.txt", "rt", stdin);
int i,j,time,x,y,xx,yy,nx,ny,cnt=0,lx1,lx2,ly1,ly2,flag=0;
scanf("%d %d",&r,&c);



for(i=1; i<=r; i++)
{
	scanf("%s",a);
	
	for(j=0; a[j]!='\0'; j++)
	{
		map[i][j+1]=a[j];
	
		
		if(a[j]=='.'||a[j]=='L')   // ���̳� ������ ������ ť�� �־��ش�.  
		{
			Q.push(state(i,j+1,0));
			check[i][j+1]=1;
		}
		
		if(a[j]=='L')
		{
			if(cnt==0)
			{
				lx1=i;
				ly1=j+1;
				cnt++;
			}
			else if(cnt==1)
			{
			
			lx2=i;
			ly2=j+1;
			cnt=0;
		}
		}
	}
}

// ������ �̵��Ҽ��ִ� ���� ������ üũ�迭�� ǥ�����ش�. 
Q1.push(state(lx1,ly1,2));   
Q1.push(state(lx2,ly2,3));
check[lx1][ly1]=2;
check[lx2][ly2]=3;
BFS();


while(!Q.empty())
{
	x= Q.front().x;
	y= Q.front().y;
	time=Q.front().time;
	Q.pop();
	

	if(time!=cnt)
	{
 
		cnt++;
		if(flag==1)
		{
			
			printf("%d",cnt);
			exit(0);
		}
		
		
	}
	
	for(i=0; i<=3; i++)    // ť�� ����ִ� ���� �ϳ��� ������ �����¿츦 Ȯ���ϸ� ������ �ִ��� Ȯ�� 
	{
		xx=x+dx[i];
		yy=y+dy[i];
		
		if(xx>=1&&xx<=r&&yy>=1&&yy<=c)
		{
			
			if(map[xx][yy]=='X')  // ������ �ִٸ�? ���� ����� üũ�迭�� ���� ��� ���ϴ��� �ٲ��ش�. 
			{
				check[xx][yy]=check[x][y];
				map[xx][yy]='.';
			
				Q.push(state(xx,yy,time+1));
							
		// ���� ������ �����¿츦  Ž���Ѵ�.  
		// 1 0 0 2  =>   1 1 2 2  �̷������� �Ǹ� 2 2 2 2 �� ������ֱ� ���ؼ� 	
		// �Ǵ� 1 0 2  => 1 1 2   => 2 2 2    		
					
					
					for(j=0; j<=3; j++)   
			{
			        nx=xx+dx[j];
			        ny=yy+dy[j];   
			
			
			if(check[xx][yy]==1)   // ������ �̵������� �ƴ� ���� ������ ���̸� ������������ 
			
			{
				if(check[nx][ny]==2||check[nx][ny]==3)   // ������ ���̰� ���� ������µ� �� �� �ֺ��� ������ �̵������϶� 
				{
				
				check[xx][yy]=check[nx][ny];     //  ���� ������ ������ �̵������� �ٲ��ش�. 
				Q1.push(state(xx,yy,check[nx][ny]));   
				BFS();
			}
			}
			
			if(check[xx][yy]==2||check[xx][yy]==3) //������ �̵������� ���� ������ ���̸� ������������ 
			{
				if(map[nx][ny]=='.'&&check[nx][ny]==1)  // ������ �̵������� �ƴ� �������� ������ �Ǹ� 
				{
					check[nx][ny]=check[xx][yy];   // �� �������� ������ �̵��������� ǥ�����ش�. 
					Q1.push(state(nx,ny,check[xx][yy]));
					BFS();
				}
		
			
				
			}
			
			if(check[xx][yy]==2)    // ����1�� �̵����� ������ 2�� �̵����� ������ ������ �Ǹ� ������ �ȰŴ� flag���� 1�� ���ش�. 
			{
				if(check[nx][ny]==3)
				{
					flag=1;
				}
			}
			
			if(check[xx][yy]==3)
			{
				if(check[nx][ny]==2)
				{
					flag=1;
				}
			}			
		}
						
			}
			
		}
	}
	
}
return 0;
}
