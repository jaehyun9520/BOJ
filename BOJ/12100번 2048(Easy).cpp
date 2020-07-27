#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string.h>

using namespace std;
int map[21][21]={0};
int n,ans=-10;



void up(int x, int y, int arr[][21])  //���� �̵� 
{
	int i,j;
	
	for(i=x+1; i<=n; i++)    // �������� ��ġ��  
	{
		if(arr[i][y]!=0) 
		{
			if(arr[x][y]==arr[i][y])
			{
				arr[x][y]=arr[x][y]+arr[i][y];
				arr[i][y]=0;
			}
			
			break;
			 }	 
			   
		 }
		 
		 
		 for(i=1; i<=x-1; i++) // ���ʿ� 0�� ������ �÷��ֱ�  
		 {
		 	 if(arr[i][y]==0)
		 	 {
		 	 	arr[i][y]=arr[x][y];
		 	 	arr[x][y]=0;
		 	 	
		 	 	break;
			  }
		 }
	}
		 
		 
void down(int x, int y, int arr[][21])   
{ 
	int i,j;
	
	for(i=x-1; i>=1; i--)    
	{
		if(arr[i][y]!=0)
		{
			if(arr[x][y]==arr[i][y])
			{
				arr[x][y]=arr[x][y]+arr[i][y];
				arr[i][y]=0;
			}
			
			break;
			
		}
	}
	
	for(i=n; i>=x+1; i--)    
	{
		if(arr[i][y]==0)
		{
			arr[i][y]=arr[x][y];
			arr[x][y]=0;
			
			
			break;
		}
	}
	
		 		 
		 
		 	
	
		  
	 } 
	
	

void left(int x, int y, int arr[][21])  
{
	int i,j;
	
	for(j=y+1; j<=n; j++)    
	{
		if(arr[x][j]!=0)
		{
			if(arr[x][y]==arr[x][j])
			{
				arr[x][y]=arr[x][y]+arr[x][j];
				arr[x][j]=0;
			}
			break;
		}
		
	}
	
	for(j=1; j<=y-1 ;j++)  
	{
		if(arr[x][j]==0)
		{
			arr[x][j]=arr[x][y];
			arr[x][y]=0;
			
			break;
		}
	}
}


void right(int x, int y,int arr[][21])  
{
	int i,j;
	
for(j=y-1; j>=1 ;j--)   
{
	if(arr[x][j]!=0)
	{
		if(arr[x][y]==arr[x][j])
		{
			arr[x][y]=arr[x][y]+arr[x][j];
			arr[x][j]=0;
			
			
		}
		break;
	}
}


for(j=n;  j>=y+1; j-- )   
{
	if(arr[x][j]==0)
	{
		arr[x][j]=arr[x][y];
		arr[x][y]=0;
		break;
	}
 } 
	
	
}




void DFS(int map[][21], int cnt) 
{int i,j,x,y;
int tmp[21][21]; 



memcpy(tmp,map,sizeof(tmp));    

	if(cnt==5) // 5�� �� �ϸ� ū�� ã��  
	{
		for(i=1; i<=n; i++)
		{
			for(j=1; j<=n; j++)
			{
				if(ans<tmp[i][j])
				{
					ans=tmp[i][j];
				} 
			}
		}
	}
	
	
	
	else    
	{
		for(i=1; i<=4; i++)
		{
			if(i==1)   // ���� �̵�  
			{
				
				for(y=1; y<=n; y++)           
				{
					for(x=1; x<=n; x++)
					{
						
						 
						if(tmp[x][y]!=0) 
						{
					    	
						 up(x,y,tmp); 
					}
						
					}
				 } 
				 
				 DFS(tmp,cnt+1);
				
			
			}
			
			
		
memcpy(tmp,map,sizeof(tmp));




			if(i==2)   // �Ʒ��� �̵�  
			{
				for(y=1; y<=n;  y++ )
				{
					for(x=n; x>=1 ;x--)
					{
						
						if(tmp[x][y]!=0)
						{
							down(x,y,tmp);
						}
					}
				}
				
				DFS(tmp,cnt+1);
				
			}
			
			memcpy(tmp,map,sizeof(tmp));
			
			
			if(i==3) // ���� �̵�  
			{
				
				for(x=1; x<=n; x++)
				{
					for(y=1; y<=n; y++)
					{
						if(tmp[x][y]!=0)
						{
							left(x,y,tmp);
						}
					}
				}
				DFS(tmp,cnt+1);
			 } 
			 
			 
memcpy(tmp,map,sizeof(tmp));			
			
			
			if(i==4) //������ �̵�  
           {
           	for(x=1; x<=n; x++)
           	{
           		
           		for(y=n; y>=1; y--)
           		{
           			
           			if(tmp[x][y]!=0)
           			{
           				right(x,y,tmp);
					   }
				   }
			   }
			   
			   DFS(tmp,cnt+1);
           	
           	
					   }			
		}
		
		
	 } 
	 
	 
	 

	
	
	
}






int main()
{
//freopen("input.txt", "rt", stdin);
 
 int i,j;
 scanf("%d",&n);

for(i=1; i<=n; i++)
{
	for(j=1; j<=n; j++)
	{
		scanf("%d",&map[i][j]);
	}
}


DFS(map,0);

printf("%d",ans);
return 0;
}
