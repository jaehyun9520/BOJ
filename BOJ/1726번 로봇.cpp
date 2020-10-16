#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;

int dx1[5]={0,0,1,0,-1};     // �� �� �� �� ���� ����    
int dy1[5]={0,1,0,-1,0}; 

struct state{
	
	int x;
	int y;
	int dir;
	int cnt;
	 
	   state(int a, int b, int c , int d)
	   {
	   	x=a; y=b; dir=c; cnt=d;
	   }
	
};

int main()
{	
//freopen("input.txt", "rt", stdin);
int i,j,m,n,x,y,dir,cnt,xx,yy,dx,dy,ddir,flag=0,tmp,ans=10000,turn,turn1;
int map[101][101]={0};
int check[5][101][101]={0};

queue <state> Q;

scanf("%d %d",&m,&n);

for(i=1; i<=m; i++)
{
	for(j=1; j<=n; j++)
	{
		scanf("%d",&map[i][j]);
	}
}

for(i=1; i<=2; i++)
{
	scanf("%d %d %d",&dx,&dy,&ddir);
	if(i==1) {
		if(ddir==2) ddir=3;  else if(ddir==3)  ddir=2;
	
			Q.push(state(dx,dy,ddir,0)); 
	check[ddir][dx][dy]=1;
}
	if(ddir==2) ddir=3;  else if(ddir==3)  ddir=2;
	 
}

while(!Q.empty())
{
	x=Q.front().x;
	y=Q.front().y;
	dir=Q.front().dir;
	cnt=Q.front().cnt;
	Q.pop();

	if(x==dx&&y==dy) // �Ѵ� ���� ĭ�� �ִٸ�? 
	{
		if(abs(dir-ddir)==3) turn=1;    // 1 4  4 1 �� ��������  3���� �ƴ϶� �ѹ��� �����̸�   
		else                            //�ǹǷ� 1�� �ٲ��� 
		{
		  turn=abs(dir-ddir); }  // �׿ܿ��� �� ������ �� ���� ���밪�� �ָ� ��  
		tmp=cnt+turn;
		if(ans>tmp)  ans=tmp;
	 } 
	
	
	for(i=1; i<=4; i++) 
	{
	    xx=x; yy=y; 
	    flag=0;
	    
	    if(abs(dir-i)==3)  turn=1;  
	    else  {
		turn=abs(dir-i);}
	    
	   for(j=1; j<=3; j++)
	   {
	   
		xx=xx+dx1[i];
		yy=yy+dy1[i];
		
		
		if(xx>=1&&xx<=m&&yy>=1&&yy<=n&&flag==0)
		{
			flag=1;		
			if(map[xx][yy]==0)   
			{
				flag=0;
				if(check[i][xx][yy]==0||check[i][xx][yy]>cnt+1+turn)  //�ƿ� �湮���� ���ų� 
				{			                 // ��ϵ� ���Ƚ������ ���� �����Ϸ��� ����� ���Ƚ���� ������� ���� �� �湮  
				if(xx==dx&&yy==dy)
				{				
					if(abs(i-ddir)==3) turn1=1;
				   
				   
				   else  { turn1=abs(i-ddir); }
					
					tmp=cnt+1+turn+turn1;
					
					if(ans>tmp) ans=tmp;		
				}				
				else{
					check[i][xx][yy]=cnt+1+turn;
					
					Q.push(state(xx,yy,i,cnt+1+turn));
					
				}
			}
			}
		}
}
	}	
}
printf("%d",ans);

return 0;
}
