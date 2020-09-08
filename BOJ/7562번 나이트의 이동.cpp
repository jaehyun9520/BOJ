#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
int dx[8]={-1,-2,-2,-1,1,2,2,1};
int dy[8]={-2,-1,1,2,-2,-1,1,2};

struct state{
	int x;
	int y;
	int cnt;
	
	state(int a, int b, int c)
	{
		x=a;
		y=b;
		cnt=c;
	}
};

using namespace std;

int main()
{
//freopen("input.txt", "rt", stdin);
int i,j,t,k,a,b,c,d,cnt,x,y,nx,ny,flag=0;
int map[300][300]={0};
int check[300][300]={0};
queue < state > Q;
vector < pair < int , int > > move;

scanf("%d",&t);

for(k=1; k<=t; k++)  // �׽�Ʈ ���̽��� �����  
{
	cnt=0;  
	scanf("%d",&i);  // ���� ũ��  
	scanf("%d %d",&a,&b);  // ����Ʈ�� ������ġ  
	Q.push(state(a,b,0));
	move.push_back(make_pair(a,b));
	check[a][b]=1;
	
	scanf("%d %d",&c,&d); // ��ǥ��ġ  
	
	if(a==c&&b==d)  // ��ġ�� ������  
	{
		printf("0\n");
	}
	
	
	else{
	
	flag=0;  
	while(!Q.empty()&&flag==0)  // BFS 
	{
		
		x=Q.front().x;
		y=Q.front().y;
		cnt=Q.front().cnt;
		
	
	
		Q.pop();
		
		for(j=0; j<=7; j++)  
		{
			nx=x+dx[j];
			ny=y+dy[j];
			
			if(nx>=0&&nx<=i-1&&ny>=0&&ny<=i-1&&check[nx][ny]==0)
			{
				
				
				check[nx][ny]=1;
				move.push_back(make_pair(nx,ny));
				if(nx==c&&ny==d)  // ��ǥ��ġ�� �����ϸ� �ߴ�  
				{ 
				     flag=1;
					printf("%d\n",cnt+1);
				}
				else
				{
					
					Q.push(state(nx,ny,cnt+1));
				}
			}
				
			
			
		}
		
	
	}
}

while(!Q.empty())
{
	Q.pop();
}
		while(!move.empty())
		{
			x= move.back().first;
			y=move.back().second;
			
			check[x][y]=0;
			move.pop_back();
		}
}

return 0;
}

