#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int dx[9]={0,-1,-1,0,1,1,1,0,-1};
int dy[9]={0,0,-1,-1,-1,0,1,1,1};

int ans=0;

struct state{
	int x;
	int y;
	int dir;
	
	state(int a, int b, int c)
	{
		x=a;
		y=b;
		dir=c;
	}
	
	
};

void func(int sum,int pos[][4],int dir[][4])
{
	
	if(sum>ans)
	{
		
		ans=sum;
	}
	
	int i,j,k,x,y,xx,yy,dir2,tmp1,tmp2,flag,sx=0,sy=0,sdir=0,end=9;
	
	vector <state> fish[17]; // ����� 1������ ~16������ �����̰� �ϱ����� ����ü�� ����  
	
	int pos1[4][4]; // ��ȣ �迭 ���纻 

	int dir1[4][4]; // ���� �迭 ���纻  

		
	for(i=0; i<=3; i++)    
	{
		for(j=0; j<=3; j++)
		{
		
			pos1[i][j]=pos[i][j];
			dir1[i][j]=dir[i][j];
			if(pos[i][j]!=-1) // �����ϴ� ������� ��ġ�� ������ �־��ش�. 
			{
			
		     fish[pos[i][j]].push_back(state(i,j,dir[i][j]));  	
		}
		     if(pos[i][j]==0)  // ����� ���� ��ġ�� ������ ����  
		     {
		     	sx=i;
		     	sy=j;
		     	sdir=dir[i][j];
			 }
		}
	}

	for(i=1; i<=16; i++)   //����� 1������ ~16������ 1ȸ �̵�  
	{
		if(fish[i].size()!=0)  
		{
			flag=0;
			x= fish[i][0].x;   
			y=fish[i][0].y;  
			dir2=fish[i][0].dir;  
			end=9;
			
			for(j=dir2; j<end; j++)    //  ���� �������  ��(8��) ������� Ȯ��  
			{
			
			      
			xx=x+dx[j];    
			yy=y+dy[j];
			 
			
			if(pos1[xx][yy]!=0&&flag==0&&xx>=0&&xx<=3&&yy>=0&&yy<=3)  
			{
				flag=1; 
				
				
				if(pos1[xx][yy]!=-1)  // ���� �̵��� ĭ�� ����Ⱑ �����ϸ�? 
				{
				
				tmp1=pos1[xx][yy];  // �̵��� ĭ�� ������� ��ȣ�� ���Ⱚ�� ����  
			    tmp2=dir1[xx][yy];
				
				pos1[x][y]=tmp1; // �迭���� ������ ������ ����   
				dir1[x][y]=tmp2; 
				fish[tmp1][0].x=x;  
				fish[tmp1][0].y=y;
				
			     }
			     
			     else if(pos1[xx][yy]==-1)  // �̵��� ĭ�� ��������� ����ĭ�� ��ĭ���� ���� 
			     {
			     	pos1[x][y]=-1;
			     	dir1[x][y]=-1;
				 }
			     
			     
			     
				pos1[xx][yy]=i;   // ���� ����⸦ �̵���ĭ���� �ű�°���  
				dir1[xx][yy]=j;
				fish[i][0].x=xx;
				fish[i][0].y=yy;
				fish[i][0].dir=j;
			
			
			}
	
	    if(flag==0&&j==8)
	    {
	    	j=0;
	    	end=dir2-1;
		}
		}
		
		
		
		
		
		
	 } 
	
}
//////////////����� ��ü 1ȸ �̵� ����  

for(i=1; i<=3; i++) // ���� ���� �������ִ� �������� ����ĭ�� Ž���ϴ� *i 
{

xx=sx+dx[sdir]*i;
yy=sy+dy[sdir]*i; 

if(xx>=0&&xx<=3&&yy>=0&&yy<=3&&pos1[xx][yy]!=-1)  
{


	
	tmp1=pos1[xx][yy];  // �� �̵��Ϸ��� ���� ����Ⱑ �����ϸ� ��ġ , ���� ���纻 �迭 �� ����  
	pos1[xx][yy]=0;
	pos1[sx][sy]=-1;
	dir1[sx][sy]=-1;
	
  func(sum+tmp1,pos1,dir1);   
	pos1[xx][yy]=tmp1;  //�ٽ� ���󺹱� 
	dir1[sx][sy]=sdir;
	pos1[sx][sy]=0;
	
}

}


}

int main()
{
//freopen("input.txt", "rt", stdin);
int i,j,a,b;
int dir[4][4]={0};
int pos[4][4]={0};


for(i=0; i<=3; i++)
{
	for(j=0; j<=3; j++)
	{
		scanf("%d %d",&a,&b);
		
		
		pos[i][j]=a;  // ��ȣ�� ��Ÿ���� 2���� �迭  1~16 : �����  -1: ����ִ°� 0: ��� 
	
		dir[i][j]=b;  // ���� 
	}
}

a=pos[0][0]; // ��ó�� ����� ������ġ�� �ִ� ������� ��ȣ  
pos[0][0]=0;  

func(a,pos,dir);  // a: ������� �� ��Ƹ��� ������� ��ȣ ����, ��ȣ�迭, ����迭  

printf("%d",ans);
return 0;
}
