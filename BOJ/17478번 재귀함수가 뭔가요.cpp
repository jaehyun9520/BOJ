#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

int n;

void func2(int x)
{
	int i;
	for(i=1; i<=x*4; i++)
	 {
	 	printf("_");
	 }
}


void func3(int x)
{
	    func2(x);
	    printf("��� �亯�Ͽ���.\n");
	    
	    if(x>0)
	    {
	    	func3(x-1);
		}
	
}

void func(int x)  
{
	int i;
	if(x>0)    // ��� Ƚ���� 0���� ũ�� 0�̵ɶ�����  
	{
		func(x-1);
	}
	
	if(x==0) 
	     {
		 printf("��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n");  // �ѹ��� ���Ǵ� ��ù��  
	 }
	 if(x!=n) // 0���� N-1���� �ݺ��ؼ� ���  
	 {
	 
	    func2(x);  // x�� ���� ���� �տ� _ �� ���  
	    printf("\"����Լ��� ������?\"\n"); 
	    func2(x);
		printf("\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n");
		func2(x);
		printf("���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n");
		func2(x);
		printf("���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n"); 
      }
      if(x==n)   
      {
      	func2(x);
	    printf("\"����Լ��� ������?\"\n"); 
	    func2(x);
	    printf("\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"\n");
	    func2(x);
	    printf("��� �亯�Ͽ���.\n");
	    
	    func3(x-1);  // n-1���� 0�� �ɶ����� _�ٿ��� �ݺ� ���  
	  }
	 
}


	


int main()
{
//freopen("input.txt", "rt", stdin);


scanf("%d",&n);  // ���Ƚ�� �Է�  

func(n);
return 0;

}
