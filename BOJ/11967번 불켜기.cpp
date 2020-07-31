#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;


int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};


int main()
{
//freopen("input.txt", "rt", stdin);
int n,m,i,j,x,y,a,b,xx,yy,flag=0,cnt=0;
vector < pair < int , int > > s[10001];  
queue < pair < int , int > > Q;   

 


scanf("%d %d",&n,&m);
int map[101][101]={0};  
int check[101][101]={0}; 
int sw[101][101]={0};  

map[1][1]=1;
check[1][1]=1;
Q.push(make_pair(1,1));





for(i=1; i<=m; i++)
{
    scanf("%d %d %d %d",&x,&y,&a,&b);
    
    s[(x-1)*n+y].push_back(make_pair(a,b));   // �� ���� ������ �ִ� ����ġ ���� ���� 
    
}

while(!Q.empty())
{
	x=Q.front().first;
	y=Q.front().second;
	Q.pop();
	
	
	
	if(sw[x][y]==0)       // �� ���� ������ �ִ� ����ġ�� �۵����״���?   
	{
		sw[x][y]=1;     
		flag=1;
		for(i=0; i<s[(x-1)*n+y].size(); i++)  // ó�� ���������� ����ġ�� �� �۵����Ѽ� �ٸ����� ���� ���ش�. 
		{
			a= s[(x-1)*n+y][i].first;
			b= s[(x-1)*n+y][i].second;
			
			map[a][b]=1;
		}
	 }
	 
	 for(i=0; i<=3; i++)
	 {
	 	xx=x+dx[i];
	 	yy=y+dy[i];
	 	
	 	if(xx>=1&&xx<=n&&yy>=1&&yy<=n)
	 	{
	 		if(map[xx][yy]==1&&check[xx][yy]==0)   
	 		{
	 			check[xx][yy]=1;
	 			
	 			Q.push(make_pair(xx,yy));
			 }
		 }
	  }
	  
	  
	  
	  
	  if(Q.empty()&&flag==1)      //  ���ݱ��� �ٴϸ鼭 ����ġ�� �۵����Ѽ� ���ο� ���� ���� �״���?  
	                                
		{
		  
			flag=0;
			for(i=1; i<=n; i++)    
			{
				for(j=1; j<=n; j++)
				{
					check[i][j]=0;
					
				}
			}
			
		
			check[x][y]=1;
		
			Q.push(make_pair(x,y));
		}
	   
}


for(i=1; i<=n; i++)
{
	for(j=1; j<=n; j++)
	{
		if(map[i][j]==1)
		{
			cnt++;
		}
	}
}

printf("%d",cnt);
return 0;
}
