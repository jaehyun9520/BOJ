#include<iostream>
#include<algorithm>
#include<vector>


using namespace std;
int n,m,h,i,j,a,b,f=0;
int result=9999;
int map[31][11]={0};


int move(int y)    // ��ٸ��� ��ȣ �״�� �����ϴ��� Ȯ�� 
  {int x=1;
	while(1)
	{
		
		if(x==h+1)
		{
			return y;
		     break;
		}
		
		
		 
		if(map[x][y]==1)
		{
				x++;
				y++;
				
		}
		else if(y>=2&&map[x][y-1]==1)
		{
			y--;
			x++;
		}
		
		
		
		else if(map[x][y]==0)
		{
			x++;
		}
		
	}
	
}


void DFS(int x, int y, int cnt)    
{
	int i,j,flag=0;
	
	
	
	
	for(i=1; i<=n; i++)
	{
		 
		 
		 if(i!=move(i))     // i�� ��ٸ��� �ٸ� ��ȣ�� ��ٸ��� �����ϸ� ����   
		 {   
		     flag=1;
		     break;
		 }
	}
	
	if(flag==0)    // ��� ��ٸ��� ������ ��ٸ��� ���������� ��� ���μ��� �߰��ߴ��� Ȯ��
	{
		
		
	  	if(result>cnt)    
	  	{
	  		result=cnt;
	  		
		}
	}
	

	
	
	
	
	
	if(result>cnt&&cnt<3)    // ���μ� 1�� 2�� 3���� �������ִ� ��� ����� �� Ȯ��  
	{
		
			for(j=y+1; j<=n-1; j++)
			{
			  
				if(map[x][j-1]==0&&map[x][j+1]==0&&map[x][j]==0)
				{
					map[x][j]=1;
					DFS(x,j,cnt+1);
					map[x][j]=0;
				}		
	        }
						
						
	        for(i=x+1; i<=h; i++)
	        {
		        for(j=1; j<=n-1; j++)
		        {
			
				
				
			      if(map[i][j-1]==0&&map[i][j+1]==0&&map[i][j]==0)
				   {  
					map[i][j]=1;
					DFS(i,j,cnt+1);
					map[i][j]=0;
				    }
				
				
	         	}  			
	        }
	
						
											
	}
		
		
}
	
	


int main()
{
//freopen("input.txt", "rt", stdin);


scanf("%d %d %d",&n,&m,&h);



    for(i=1; i<=m; i++)
    {
	scanf("%d %d",&a,&b);
	map[a][b]=1;

	}




    if(m==0)  //���μ��� 0���� �״�� �������״� �ٷ� 0  
    {
	printf("0");
	exit(0);
    }


    DFS(1,0,0);
		
	if(result==9999)
	{
	   result=-1;
	}
	printf("%d",result);

return 0;

}
