#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n,answer;
int map[16][16]={0};
void func(int cnt)
{ int i,j,x,y;
   vector < pair <int , int > > use;

	if(cnt==n)
	{
		answer++;
	}
	
	else
	{
		for(i=1; i<=n; i++)
	    {
	    	if(map[cnt+1][i]==0)  
	    	{
	    		map[cnt+1][i]=1;   // ���� �������ִ°�? 
	    		
	    		
	    		for(j=cnt+2; j<=n; j++)   // ���� ���� �ؿ��� ���ݹ��� ǥ��  
	    	      {
	    	      	if(map[j][i]==0)   // �̹� ������ ���� ���� ǥ�õǾ������� �Ѿ  
	    	      	{
					  
	    	      	map[j][i]=1;  
	    	      	use.push_back(make_pair(j,i));  
	    	      }
				  }
	    	
	    	    for(j=1; j<=n; j++)       // ������ �� �밢�� ���ݹ��� ǥ��  
	    	    {
	    	    	if((x=cnt+1+j)<=n&&(y=i+j)<=n)
	    	    	{
	    	    		
	    	    		if(map[x][y]==0)
	    	    		{
						map[x][y]=1;
						
						use.push_back(make_pair(x,y));
	    	    	}
	    	    		
	    	    		
					}
				}
				for(j=1; j<=n; j++)     //���� �� �밢�� ���ݹ��� ǥ��  
				{
					if((x=cnt+1+j)<=n&&(y=i-j)>=1)
					{
						if(map[x][y]==0)
						{
						
						map[x][y]=1;
						use.push_back(make_pair(x,y));
					}
					}
				}				
				func(cnt+1);  //�����ܰ�� 
	    		
	    		map[cnt+1][i]=0;  // �� ���ݹ����� ��ġ ����  
	    		
	    		while(!use.empty())
	    		{
	    			map[use.back().first][use.back().second]=0;
	    			
	    			use.pop_back();
				}
	    		
	    		
			}
	    	
		}
		
		
	}
	
}
int main()
{
	
	scanf("%d",&n);
	
	func(0);
//freopen("input.txt", "rt", stdin);
printf("%d",answer);
return 0;
}
