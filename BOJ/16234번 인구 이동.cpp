#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<math.h>
using namespace std;

int dx[4]={1,-1,0,0};
int dy[4]={0,0,-1,1};

int main()
{
//freopen("input.txt", "rt", stdin);
int n,l,r,i,j,x,y,xx,yy,val,result=0,k;
int u=0,cnt,total;     // cnt= ������ ���� ��    total= ������ �� �α���  
queue < pair < int , int > > Q;
scanf("%d %d %d",&n,&l,&r);
int map[51][51]={0};    
int check[51][51]={0};    // �湮 üũ  
vector < pair < int, int > > country;  // ���տ� �ش��ϴ� ����� ��ġ ����  
   
for(i=1; i<=n; i++)
{
	for(j=1; j<=n; j++)
	
	{
		scanf("%d",&map[i][j]);
	}
}


while(1)

{
   if(u==1)     
   {
   	   result++;
   	   u=0;
   }

for(i=1; i<=n; i++)
{
	for(j=1; j<=n; j++)
	{
	
	
	if(check[i][j]==result)
	{
		cnt=1,total=map[i][j];            
		check[i][j]=result+1;                 
		Q.push(make_pair(i,j));
		country.push_back(make_pair(i,j));     
		  
		while(!Q.empty())
	  {
	  	x=Q.front().first;
	  	y=Q.front().second;
	  	Q.pop();
	  		
	  	
	  	for(k=0; k<=3; k++)    
	  	{
	  		xx=x+dx[k];
	  		yy=y+dy[k];
	  		
	  		if(xx>=1&&xx<=n&&yy>=1&&yy<=n)
	  		{
	  			val=abs(map[x][y]-map[xx][yy]);    
	  			if(l<=val&&val<=r&&check[xx][yy]==result)
	  			{
	  				if(u==0)                             
	  				{
	  					u=1;
					  }
	  				
	  				
	  				check[xx][yy]=result+1;
	  				cnt++;
	  				total=total+map[xx][yy];   
	  				country.push_back(make_pair(xx,yy));
	  			
				Q.push(make_pair(xx,yy));
				  }
	  			
			  }
		  }
		  		  		  		 		  
	  }
	  
            
			
			
		        	  
		  total=total/cnt;
		  while(!country.empty())    // �α��̵�  
		  {
		  	
		  	
		  	x=country.back().first;
		  	y=country.back().second;
		  	
		  	map[x][y]=total;
		  	country.pop_back();
		  }
	  
	  
	 }
}
}
   
   if(u==0)   // �α��̵��� �Ͼ����? ���Ͼ����  �� 
   {
   	   printf("%d",result);
   	   break;
   }
}

return 0;

}
