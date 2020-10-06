#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

int n , m; 
int map[101][101]={0};
int check[101][101]={0};    
queue < pair < int , int > > Q1;  // �ܺ� ���� �־��ִ°�
queue < pair < int , int > > Q2; // �ܺΰ���� ���˵� ġ�� �־��ִ°�  

vector <pair <int , int > > del;  // �̹� �Ͽ� ���� ġ�� ����  
vector <pair <int , int > > re;  // �������� ġ������  �ٽ� ��� 

void air()   //�ܺΰ��� ������ �ϰ� �ֺ��� ġ� �ִ��� üũ! 
{
	int x,y,xx,yy;
    while(!Q1.empty()) 
	{
		x=Q1.front().first;
		y=Q1.front().second;
		Q1.pop();
		
		for(int i=0; i<=3; i++)
		{
			xx=x+dx[i];
			yy=y+dy[i];
			
			
			if(xx>=1&&xx<=n&&yy>=1&&yy<=m)
			{
				if(map[xx][yy]==0&&check[xx][yy]==0)  // �ܺΰ���� ���˵� ����� ? �ܺΰ��� 
				{
					check[xx][yy]=1;
					Q1.push(make_pair(xx,yy));
				 }
				 
				 else if(map[xx][yy]==1&&check[xx][yy]==0)  // �ܺΰ���� ���˵� ġ��  
				 {
				 	check[xx][yy]=1;
				 	Q2.push(make_pair(xx,yy));
				  } 
			}
		}
		
		
	   }   
		
}

int main()
{	
//freopen("input.txt", "rt", stdin);
int i,j,x,y,xx,yy,cnt,cheeze=0,time=0;

scanf("%d %d",&n,&m);

for(i=1; i<=n; i++)
{
	for(j=1; j<=m; j++)
	{
		scanf("%d",&map[i][j]);
		if(map[i][j]==1) cheeze++;
	}
}

check[1][1]=1;
Q1.push(make_pair(1,1)) ;  // �����ڸ����� ġ� �������� ������ 1,1�� �־ �ܺΰ��� Ž��  
air(); // �ܺΰ��� ������ ���˵� ġ�� Ȯ��


while(cheeze!=0)
{


while(!Q2.empty())
{
	
	x=Q2.front().first;
	y=Q2.front().second;
	cnt=0;
	Q2.pop();
	for(i=0; i<=3; i++)
	{
		xx=x+dx[i];
		yy=y+dy[i];
		
		if(xx>=1&&xx<=n&&yy>=1&&yy<=m)
		{
			if(check[xx][yy]==1&&map[xx][yy]==0)  // �ܺΰ���� ���� 
			{
				cnt++ ;  //Ƚ�� �߰�  
			}		
		}
	 } 
	 if(cnt>=2)   del.push_back(make_pair(x,y));  // �̹��Ͽ�  2���̻� ���˵� ġ��
	else   re.push_back(make_pair(x,y));
	if(Q2.size()==0)  // �ܺο� ���˵� ġ����� �� Ȯ�������� 
	{
		while(!del.empty())
		{
			cheeze--;
			x= del.back().first;
			y= del.back().second;
			map[x][y]=0 ;// ����� �ٲ���
			check[x][y]=1; // �ܺ� ���� ǥ�õ� ���� 
			del.pop_back();
			Q1.push(make_pair(x,y)); // �ܺΰ���� ���Ӱ� ���˵� ġ�� �� ���ΰ��� Ȯ������  
		 }
	 
		 if(cheeze==0)  printf("%d",time+1);
		 
		 else time++; 
		
	}  
 } 
         air();
         
         while(!re.empty())
         {
         	Q2.push(make_pair(re.back().first,re.back().second));
         	re.pop_back();
		 }

}




return 0;
}
