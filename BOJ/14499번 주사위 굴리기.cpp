#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>

using namespace std;



int main()
{
//freopen("input.txt", "rt", stdin);
int n,m,x,y,k,i,j,command,flag;
int dice[7]={0};  // 1~6�� ���� ���� ����  
int face[7]={0,6,5,4,3,2,1};   // ���ֺ��� �ִ� ��  1-6 2-5 3-4
int up=1 ,down=6 , west=4 , east=3 , south=5 , north=2;   // �ֻ��� ���� ����  
scanf("%d %d %d %d %d",&n,&m,&x,&y,&k);
 int map[n][m];
 for(i=0; i<n; i++)
 {
 	for(j=0; j<m; j++)
 	{
 		scanf("%d",&map[i][j]);
	}
 }
 
 for(i=1; i<=k; i++)
 {
 	scanf("%d",&command);
 
 	flag=0;
 
	 
	                   
	 	if(command==1&&y+1<m)  //��  
 	{              //���� ������ ����Ű�� ���� ���� ��ȭ����  
 		  y++;
 		  flag=1;
 		  down=east;                  
 		  east=up;
 		  up=face[down];
 		  west=face[east];
 		  	  
	 }
	 
	 
	 	if(command==2&&y-1>=0)  //��    
 	{              //���� ������ ����Ű�� ���� ���� ��ȭ����
 		  y--;
 		  flag=1;
 		  down=west;       
		  west=up;
		  east=face[west]; 	
		  up=face[down];	
 			
	 }
	 
	 
	 
	 	if(command==3&&x-1>=0)  //��   
 	{              //���� ������ ����Ű�� ���� ���� ��ȭ����
 		  x--;
 		  flag=1;
 		  down=north;
 		  north=up;
 		  up=face[down];
 		  south=face[north];
 		
 		
 	
 		
 		
 		
	 }
	 
	 
	 
	 	if(command==4&&x+1<n)  //��   
 	{                //���� ������ ����Ű�� ���� ���� ��ȭ����
 		  x++;
 		  flag=1;
 		  down=south;
 		  south=up;
 		  up=face[down];
 		  north=face[south];

		  
 		
 		
 		
	 }
	 
	 if(flag==1)
	 {
	 	if(map[x][y]==0)   
	    {
		    map[x][y]=dice[down];
		} 
		else if(map[x][y]!=0)
		{
			dice[down]=map[x][y];
			map[x][y]=0;
			
		} 
		  printf("%d\n",dice[up]);	
	 }
 		
 }
 

return 0;

}
