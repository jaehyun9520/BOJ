#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;
int x,y,a,b;

char map[798][398];

void func(int n)
{

	if(n==1)
	{
		
		map[x][y]='*';

	}
	
	else if(n>1) {
		
		func(n-1);

		if(n==2)  // 2�϶��� ��Ÿ���� ���� 2ĭ �ö󰡱�  
		{
			
			for(int i=1; i<=2; i++)  
			{
				
				map[--x][y]='*';
				
			}

		}
		
		for(int i=1; i<=2; i++)   // ������ ��ĭ �� ���  
		{
			map[x][++y]='*';
	
		}

		for(int i=1; i<=4*(n-1); i++)     // N�� ũ�⿡ ���� ������ �������� �� ���  
		{
			
			map[++x][y]='*';
		
		}
	
		for(int i=1; i<=4*(n-1); i++)   // ���� �̵��ϸ� �� ���  
		{
			map[x][--y]='*';
			
		}

		for(int i=1; i<=4*n-2; i++)  // ���� �̵��ϸ� �� ���  
		{
			
			map[--x][y]='*';
		}
	
		for(int i=1; i<=4*(n-1); i++)  // ������ �̵��ϸ� �� ���  
		{
			map[x][++y]='*';
		}		
	}
}


int main()
{
//freopen("input.txt", "rt", stdin);

int n,i,j;
scanf("%d",&n);

a=4*(n-1)+3;   // N�� ���� ���� ��¹迭�� ����ũ��  
b=4*(n-1)+1;   // N�� ���� ���� ��¹迭�� ����ũ��  

for(i=1; i<=a; i++)
{
	for(j=1; j<=b; j++)
	{
		map[i][j]=' ';  // �������� �ʱ�ȭ  
	}
}

// N�� ũ�⿡ ���� �������� ��ġ ��� 
x=2*n+1;    
y=2*n-1;


if(n==1)  // N�� 1�϶��� �ٷ� ���  
{
	printf("*");
	
}

else
{
	
	func(n);  
	
			for(i=1; i<=a; i++)
{
	for(j=1; j<=b; j++)
	{
		if(i==2)     // 2��° ���� ������ ����  
		{
			if(map[i][j]=='*')
			printf("%c",map[i][j]);
		}
		
		
		else
		printf("%c",map[i][j]);
	}

	if(i!=a&&j!=b)
	printf("\n");
}	
	
}

return 0;

}
