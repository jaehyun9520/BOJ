#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;
char map[1024][1024];
void func(int n)
{
	int k;
	if(n==0)  map[0][0]='*';
	
	
	else{
	
	func(n-1);
	     
	     k=pow(2,n)/2;
	      
	       
	     for(int i=k; i<k+k; i++)   // �������  ���� ���� ����� ���� �Ʒ��� �ű��    
		 {
		 	for(int j=0; j<k; j++)
		 {
		 	map[i][j]=map[i-k][j];
		 }
		 
		   }
		   
		   for(int i=0; i<k; i++)    // ������� ���� ���� ����� ������ ���� �ű��  
		   {
		   	for(int j=k; j<k+k; j++)
		   	{
		   		map[i][j]=map[i][j-k];
			   }
			 }  
}
	       
}
int main()
{
//freopen("input.txt", "rt", stdin);

int n,i,j,k;
scanf("%d",&n);

k=pow(2,n);

for(i=0; i<k; i++)
{
	for(j=0; j<k; j++)
	{
		map[i][j]=' ';   // �ʱ�ȭ  
	}
}



func(n);

for(i=0; i<k; i++)
{
	for(j=0; j<k-i; j++) // ���ʿ��� ���� ���ֱ�  
	{
		printf("%c",map[i][j]);
	}
	


	printf("\n");

}
return 0;

}
