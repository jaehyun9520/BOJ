#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;

int dx[8]={-1,-1,0,1,1,1,0,-1};   // ���� 
int dy[8]={0,1,1,1,0,-1,-1,-1};


struct state{
	
	int x;
	int y;
	int m;
	int s;
	int d;
	state(int a, int b, int c, int e, int f)
	{
		x=a; y=b; m=c; s=e; d=f;
	}
	
};

int main()
{	
//freopen("input.txt", "rt", stdin);
int n,M,k,i; //��ũ��, ���̾����, ���̾ �̵���� Ƚ�� 
int r,c,m,s,d; // rc�࿭, m ���� s �ӵ� d ����  
int x,y,ans=0;
vector < pair < int , int > > div;
vector < state > f; 
int map[4][51][51]={0};  //0�� ���̾�� ���� , 1�� ���� 2�� �ӵ� 3�� ����  
int check[51][51]={0}; 
queue < state> Q;

scanf("%d %d %d",&n,&M,&k); 

for(i=1; i<=M; i++)
{
	scanf("%d %d %d %d %d",&r,&c,&m,&s,&d);

	Q.push(state(r,c,m,s,d));	 
}



for(i=1; i<=k; i++)
{

		while(!Q.empty())
	{
		x=Q.front().x; y=Q.front().y;  m=Q.front().m;  s=Q.front().s;  d=Q.front().d;
		 Q.pop();
	      x=x+(dx[d]*s);  //���⸸ŭ �ӷ����� �̵� 
	      y=y+(dy[d]*s);  
	      
	  	if(x>n)  {x=x%n;}  if(y>n) {y=y%n;}  //n�� �Ѿ�� �ٽ� ���ʺ���   
		  
		  
		if(x<1) {x=n-(abs(x)%n);}   if(y<1) { y=n-(abs(y)%n);} //
	  	
		
	  
		
		if(x>=1&&x<=n&&y>=1&&y<=n)
		{
		     map[0][x][y]++;  // �̵��� ��ġ�� ���̾ ���� +1 
		     map[1][x][y]+=m;   //���� �����ֱ� 
		     map[2][x][y]+=s;  //�ӵ� �����ֱ�  

			f.push_back(state(x,y,m,s,d)); 
			map[3][x][y]=map[3][x][y]+d%2; //¦������ Ȧ������ 
			
			if(map[0][x][y]>=2&&check[x][y]==0) // 2���̻��� ���̾�� �Ѱ��� ��ġ�ϴ°��  
			{
				check[x][y]=1;  
			
				div.push_back(make_pair(x,y));  //4���� ���̾�� ���������� �־��� 
			 } 
		}
		 
		
	}

	while(!f.empty())
	{
		x=f.back().x;
		y=f.back().y;
		m=f.back().m;
		s=f.back().s;
		d=f.back().d;
		if(map[0][x][y]==1) //2���̻��� ���� 4���� �������°����� ó�� ���⼭�� �Ѱ��ΰ͵鸸 ó��  
		
		{ map[0][x][y]=0;  //�����̵��� ������ ���̾���� üũ���� 0����  
			
			Q.push(state(x,y,m,s,d)); //���� �Ȱ��� �־��� 
		map[1][x][y]=0;  //���������� ���� �ӵ� ���⵵ �ʱ�ȭ 
		map[2][x][y]=0;
		map[3][x][y]=0;
		}
		
		f.pop_back();
	}

	while(!div.empty())   //4���� �����ֱ�  
	{
		x=div.back().first;
		y=div.back().second;
		check[x][y]=0;   
		m=floor(map[1][x][y]/5);   //���� 
	
		if(m>0)  //������ 0�̻��̸�  
		{
		   
			s=floor(map[2][x][y]/map[0][x][y]); // �ӷ� =������ �ӷ�/ ������ ���̾����  
			d=map[3][x][y];  
			
		
			if(d==0||d==map[0][x][y]) // ������ ���Ⱚ�� 0�̰ų�(���¦��)   ������ ���̾�� ������ ���ų�(���Ȧ��)
			  
		    {
		    
		    	d=0;
		    	while(d<=6)
		    	{
		    		 Q.push(state(x,y,m,s,d)); // 0 2 4 6 ����  
		    		 d+=2;
		    		
				}
			}
			
			else 
			{
				d=1;
				while(d<=7)
				{
					
					Q.push(state(x,y,m,s,d));
					d+=2;
				}
				
			}
			
		}
		map[0][x][y]=0;
		map[1][x][y]=0;
		map[2][x][y]=0;
		map[3][x][y]=0;
		div.pop_back(); 
	}
		
}

while(!Q.empty()) // �̵������ �� ������ ���� �����ִ� ���̾�� ���� �� 
{
	
	m=Q.front().m;
	ans+=m;
	Q.pop();
}

printf("%d",ans);
return 0;
}
