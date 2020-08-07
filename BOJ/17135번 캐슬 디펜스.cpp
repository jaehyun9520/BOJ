#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>


using namespace std;
int n,m,d,i,j,dis,x,y,xx,yy,cnt,s,ex,ey,result=0,answer=0,size=0;

int dx[3]={-1,0,0};
int dy[3]={0,1,-1};

int map[17][16]={0};
int test[17][16]={0};
int check[17][16]={0};
int archer[3]={0};

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



vector < pair < int , int > > del;
vector < pair < int, int > > used;

queue < state > Q;

void DFS(int count, int number)   // �ü��� ��ġ��ų ���� ����� �̾Ҵ��� 
{	

	if(count==3) // �ü��� 3�� �� ���� ��ġ�������� �ùķ��̼�  
	{ size=0;
		for(i=1; i<=n; i++)
		{
			for(j=1; j<=m; j++)
			{
				test[i][j]=map[i][j];
				
				if(test[i][j]==1)
				{
					size++;
				}
			}
		}
		
		 
		
		
		
		        result=0;
 	          while(size!=0) {   // ���� �ʿ� �ϳ��������� ����  
		
		for(i=0; i<=2; i++)
		{
			
			s=999;  // ���� ª�� �Ÿ� ����  
			ex=0; ey=0;  // ����ª���Ÿ��� �ִ� ���� ��ǥ  
			if(test[n][archer[i]]==1)  // �ü��ٷ� ���� ���� �ִ°�� 
			{
				
				
				del.push_back(make_pair(n,archer[i]));   
			}
			
			else if(test[n][archer[i]]==0){
			
			Q.push(state(n,archer[i],1));
		    check[n][archer[i]]=1;
		    used.push_back(make_pair(n,archer[i]));   // ���� Ž��  
			
			while(!Q.empty())
			{

				x=Q.front().x;
				y=Q.front().y;
				cnt=Q.front().cnt;
				Q.pop();
				 
			 
				for(j=0; j<=2; j++)
				{
				
					xx=x+dx[j];
					yy=y+dy[j];
					
					if(xx>=1&&yy>=1&&yy<=m)
					{
						
						if(check[xx][yy]==0&&cnt+1<=d)  
						{   
							used.push_back(make_pair(xx,yy));
							check[xx][yy]=1;
							if(test[xx][yy]==1)
							{
								
								if(s>cnt+1)
								{   
								   s=cnt+1;
								    ex=xx;
								 	ey=yy;
								}
								
								else if(s==cnt+1)  // ���� ��������� �����ϰ�� ���� ���ʿ� �ִ°� ���� �������ش�. 
								{
									if(ey>yy)
									{
										ex=xx;
										ey=yy;
									}
								}
							}
							else if(test[xx][yy]==0&&cnt+1<s)    // ���� �Ÿ��� �Ѿ�� �� Ž��  
							{
								Q.push(state(xx,yy,cnt+1));
							}
							  
							
						}
					}
				}
				
			}
			
			while(!used.empty())    // �湮ǥ�� Ǯ��  
			{
			
				x= used.back().first;
				y=used.back().second;
		
				check[x][y]=0;
				used.pop_back();
			}
			if(ex!=0&&ey!=0)    // ���� �� ���� ��ġ ���  
			{
				del.push_back(make_pair(ex,ey));
			 }
			
			
		}
		 	
			
		}   
		    while(!del.empty())  // �ü� 3������ ������ �� ������ ���� ����ª���Ÿ��� 3���� �� ����  
		    {
		    	x=del.back().first;
		    	y=del.back().second;
		       del.pop_back();
		    if(test[x][y]==1)   
		    {
			  
		    	test[x][y]=0;
		    	result++;
		    	
		    }
		    	
			}
		
			
			
			
			size=0;
			for(y=1; y<=m; y++)  //������ ��ĭ�� ������ �̵���Ű��  
			{
				test[n][y]=0;
			}
			for(x=n-1; x>=1; x--)
			{
				for(y=1; y<=m; y++)
				{
					if(test[x][y]==1)
					{
						size++;
						test[x][y]=0;
						test[x+1][y]=1;
					}
				}
			}
			
			
			
		
		
	}
		
		if(result>answer)
		{
			answer=result;
		}

	}
	
	
	
	else if(count<=2)   // �ü��� ���� �� ��ġ��������  
	{
		for(int z=number; z<=m; z++)
		{	
			if(map[n+1][z]==0)  // ���� �ü��� ���ٸ�? 
			{
				archer[count]=z;  // 1 �� 2 �� 3�� �ü��� ���° ���� �ִ��� ����  
				map[n+1][z]=2;  //  ���� �ü��� ��ġ  
				DFS(count+1,z+1);  
				map[n+1][z]=0;
				
			}
		}
		
	}
	
}


int main()
{
//freopen("input.txt", "rt", stdin);


scanf("%d %d %d",&n,&m,&d);

	

for(i=1; i<=n; i++)
{
	for(j=1; j<=m; j++)
	
	{
		scanf("%d",&map[i][j]);
	}
}


DFS(0,1);   // �ִ� 15���� �� �߿��� �ü��� ��ġ��ų 3���� �� �̱�  15*14*13/6   
printf("%d",answer);



return 0;

}

