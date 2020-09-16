#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<queue>
using namespace std;

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};


int main()
{
//freopen("input.txt", "rt", stdin);
int t,h,w,i,j,k,x,y,xx,yy,z,answer=0,flag;
char a[101];
int map[101][101]={0};
int check[101][101]={0};
int key[123]={0};

queue < pair  < int , int > > Q;    
vector < pair < int , int > > list;
vector < pair < int , int > > use;
scanf("%d",&t);  // �׽�Ʈ ���̽� �� �Է�  

for(z=1;z<=t; z++)
{
	
	answer=0;
	scanf("%d %d",&h,&w);  // ���� ���� �ʺ� �Է�  
	
	for(j=1; j<=h; j++)
	{
		scanf("%s",a);  
		
		for(k=1; k<=w; k++)
		{
			map[j][k]=a[k-1];
			
			if(k==1||j==1||k==w||j==h)
			{
				if(map[j][k]=='.')      
				{
					list.push_back(make_pair(j,k));
				}
				
				if(65<=map[j][k]&&map[j][k]<=90)
				{
					list.push_back(make_pair(j,k));
				}
				
				if(map[j][k]=='$')  
				{    
				answer++;
				     map[j][k]='.';
					list.push_back(make_pair(j,k));
				}
			}
		}
		
	}
	
	for(i=0; i<=122; i++)
	{
		key[i]=0;
	}
	
	
	scanf("%s",a);
	for(i=0; a[i]!='\0'; i++)
	{
		x=a[i];
		key[x]++;
	}
	flag=1;
	
	
	

	
	

	
	
	
	
	
	
	
	

	
	while(flag!=0)   // ���ο� ���踦 �߰��ߴ���?  �߰��ߴٸ� �ٽ� Ž��  
	{
	flag=0;
	for(i=0; i<list.size(); i++ )   
	{
		x= list[i].first;
		y= list[i].second;
		
		
		if(map[x][y]=='.')  // ������̸� ť�� �־��� 
		{
			check[x][y]=1;
			use.push_back(make_pair(x,y));
			Q.push(make_pair(x,y));
		}
		
		else{
			if(key[map[x][y]+32]!=0)  
			{
				
				check[x][y]=1;
				use.push_back(make_pair(x,y));
				Q.push(make_pair(x,y));
			}
			
		}
	}
	


while(!Q.empty())
{
	
	x=Q.front().first;
	y=Q.front().second;
	

	Q.pop();
	
	for(i=0; i<=3; i++)
	{
		xx=x+dx[i];
		yy=y+dy[i];
		
		if(xx>=1&&xx<=h&&yy>=1&&yy<=w)
		{
			if(map[xx][yy]=='.'&&check[xx][yy]==0)  //�����  
			{
				check[xx][yy]=1;
				use.push_back(make_pair(xx,yy));
				
				Q.push(make_pair(xx,yy));
			}
			
			if(97<=map[xx][yy]&&map[xx][yy]<=122&&check[xx][yy]==0) // ����  
			{
				check[xx][yy]=1;
				use.push_back(make_pair(xx,yy));
				
				if(key[map[xx][yy]]==0)  // ���ο� ������ ������ ��� �ѹ��� BFSŽ��  
				{
					flag=1;
				}
				key[map[xx][yy]]++;
				map[xx][yy]='.';
				
				
				Q.push(make_pair(xx,yy));
			 }
			 
			 if(65<=map[xx][yy]&&map[xx][yy]<=92&&check[xx][yy]==0)  // ���̸� �´� ���谡 �ִ� Ȯ��  
			 {
			 	if(key[map[xx][yy]+32]!=0)
			 	{
			 		check[xx][yy]=1;
			 		use.push_back(make_pair(xx,yy));
			 		map[xx][yy]='.';
			 		
			 		Q.push(make_pair(xx,yy));
				 }
			 	
			  }
			  
			  if(map[xx][yy]=='$'&&check[xx][yy]==0) // ������ ���� �߰�  
			  {
			  	check[xx][yy]=1;
			  	map[xx][yy]='.';
			  	answer++;
			  	use.push_back(make_pair(xx,yy));
			  	
			  	Q.push(make_pair(xx,yy));
			   } 
			   
			
		}
	}
	
	
}

while(!use.empty())
{
	check[use.back().first][use.back().second]=0;
	use.pop_back();
}



}
printf("%d\n",answer);

while(!list.empty())
{
	list.pop_back();
}
}
return 0;


}
