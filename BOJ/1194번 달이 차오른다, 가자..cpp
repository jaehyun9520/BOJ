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
	int cnt;
	int key;
	
	state(int a, int b, int c,int d)
	{
		x=a;
		y=b;
		cnt=c;
		key=d;
	}
}; 

int main()
{
//freopen("input.txt", "rt", stdin);
int i,j,n,m,x,y,xx,yy,k,cnt,tmp;  
int map[51][51]={0};
int check[64][51][51]={0};
char a[51];
queue <state> Q;
scanf("%d %d",&n,&m);

for(i=1; i<=n; i++)
{
	scanf("%s",a);
	
	for(j=1; j<=m; j++)
	{
		map[i][j]=a[j-1];
		if(map[i][j]=='0') //��������  
		{
			map[i][j]='.';
			check[0][i][j]=1;    
			Q.push(state(i,j,0,0));
		}
	}
}

while(!Q.empty())
{
	x=Q.front().x;
	y=Q.front().y;
	cnt=Q.front().cnt; //�̵�Ƚ��  
	k=Q.front().key;  // Ű ���� ��Ȳ 
	Q.pop();

	for(i=0; i<=3; i++)
	{
		xx=x+dx[i];
		yy=y+dy[i];
		
		
		if(xx>=1&&xx<=n&&yy>=1&&yy<=m)
		{
			
			if(map[xx][yy]=='.'&&check[k][xx][yy]==0)  //������� ���  
			{
				
				check[k][xx][yy]=1;
				Q.push(state(xx,yy,cnt+1,k));
			}
			
			else if('a'<=map[xx][yy]&&map[xx][yy]<='f'&&check[k][xx][yy]==0)  //���踦 �߰��Ѱ��  
			{
				
				if( (k&(1<<(map[xx][yy]-97)))==0) // �����ϰ� ��������  ���ο� Ű�ΰ�? 
				{
				
					tmp=k|(1<<(map[xx][yy]-97));  // Ű ���� ��Ͽ� �߰�  
				
					check[tmp][xx][yy]=1;
				Q.push(state(xx,yy,cnt+1,tmp));
					
				}
				else{
				
				check[k][xx][yy]=1;          // �̹� �������̶�� �״�� ����  
				Q.push(state(xx,yy,cnt+1,k));
			}
			}
			
			
		   else if('A'<=map[xx][yy]&&map[xx][yy]<='F'&&check[k][xx][yy]==0) // ���߰�   
		   {
		 
		   	       if(k&(1<<(map[xx][yy]-65)))  // ���� �����ִ� Ű�� �����ϰ��ִ°�? 
		   	       {
		   	       	 
		   	       	  check[k][xx][yy]=1;   // �������̶�� ���� ����  
		   	       	  
		   	       	  Q.push(state(xx,yy,cnt+1,k));
					  }
			} 
			
			
			else if(map[xx][yy]=='1')    // �ⱸ�߰� 
			{
				printf("%d",cnt+1);
				exit(0);
			}
		}
	}
}
printf("-1 \n");   


return 0;
}
