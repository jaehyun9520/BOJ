#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int wind[4][10][2]= //�� ���⿡ ���� �𳯸��� ��ġ (�ۼ�Ʈ�� ���� �������ؼ� ������) 
{
{{1,0},{-1,0},{2,0},{-2,0},{-1,1},{1,1},{-1,-1},{1,-1},{0,-2},{0,-1}},  //����  
{{0,-1},{0,1},{0,2},{0,-2},{-1,-1},{-1,1},{1,-1},{1,1},{2,0},{1,0}},   //�Ʒ��� 
{{1,0},{-1,0},{2,0},{-2,0},{-1,-1},{1,-1},{-1,1},{1,1},{0,2},{0,1}},   //������ 
{{0,-1},{0,1},{0,2},{0,-2},{1,-1},{1,1},{-1,-1},{-1,1},{-2,0},{-1,0}}  //����   
};
double percent[9]={0.07,0.07,0.02,0.02,0.01,0.01,0.1,0.1,0.05}; // �𳯸��� ĭ��  �ۼ�Ʈ  

int dx[4]={0,1,0,-1};  //�������ϼ����� ����  
int dy[4]={-1,0,1,0}; 
int map[500][500]={0}; 
int main()
{
//freopen("input.txt", "rt", stdin);
ios_base :: sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
int n,i,j,move,cnt,x,y,ans=0,nx,ny,val,sum=0,direct;
cin>>n;
x=n/2+1;
y=x;
//������ġ ���� 

for(i=1; i<=n; i++)
   for(j=1; j<=n; j++)
       cin>>map[i][j];


move=1; cnt=0,direct=0; 


while(1)  
{
	 
	     for(int i=1; i<=move; i++)  // 1 1 2 2 3 3 4 4 5 5 �̷��� �����δ� 
     {
     	x=x+dx[direct];
     	y=y+dy[direct];
     
     	      sum=0;  
     	  for(int j=0; j<=9; j++)
     	  {
     	  	nx=x+wind[direct][j][0];   // a�� ������ ���� ������ �����ش�. 
     	  	ny=y+wind[direct][j][1];
     	  	
     	  	if(j!=9)  // a�� �ƴҰ�� ������ �ۼ�Ʈ��ŭ ���󰡰� �Ѵ�. 
     	  	{
			
     	  	val=map[x][y]*percent[j];
     	  	sum=sum+val;
     	    }
     	    
     	    if(j==9) // a�ϰ��  
     	    val=map[x][y]-sum;
     	    
     	    
     	  	if(nx<1||nx>n||ny<1||ny>n)  //���ư��� �𷡹ٶ��� ������ ������? 
     	  	{
     	        ans=ans+val;	
		   }
		   
		   else    // �������̶�� �ش���ġ��  �����ش�. 
		   {
		   	  map[nx][ny]+=val; 
		   	
		   }
	
     	  	
		   }
		   
		   map[x][y]=0;  //����̵��� ���� ��ü�� �� ���󰡴ϱ� �������� 0����
		   
		   
		   if(x==1&&y==1) 
		   {
		   cout<<ans; exit(0);
            }
     	
	 }
	
	cnt++;  direct++;
	
	if(direct==4) direct=0;
	
     if(cnt==2)  //move��ŭ �ι� �����̸�  move 1����  
	 {
	 cnt=0; move++;
     }
	
}
														   
return 0;
}
