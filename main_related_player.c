#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int configUser(void){
	
	printf("�Բ� �� �÷��̾��� ���� �Է����ּ���(�ִ� �ټ������ �� �� �ֽ��ϴ�): ");
	scanf("%d",&with_player);
	return with_player;
	
void betDollar(void){
	
	int bet_money;									//���ð��� �Է� ���� ���� 
	
	printf("�󸶸� �����Ͻðڽ��ϱ�? : ");			//'��'���� ������ ���� ��� 
	scanf("%d",bet_money);							//��� ���ð��� ������ ���� 
	dollar[0]=bet_money;							//'��'�� ���ð��� ������ �迭�� 
	
	srand((unsigned)time(NULL));
	 
	int i;
	for(i=1;i<=with_player;i++){					//���� ������ ������ �÷��̾� ����� ���� ���Ƿ� �Է¹���, rand�Լ��� �����ϸ�	
		dollar[i] = 1+rand()%now_money[i];		//�� ���� ���� ������ �÷��̾��� ���ð��� ������ �迭�� ������. 
		printf("�÷��̾� %d�� ���� �ݾ��� %d �Դϴ�", i, dollar[i]);
	} 
	
int getAction(void){							//'GO'���� 'STOP'�� �� �����ؾ���. 
	
	char input;
	printf("go�Ͻðڽ��ϱ�? stop �Ͻðڽ��ϱ�? (Y / N) :  ");
	scanf("%c",input);							//�������� �ֽ� �Լ��� �ڲ� ������ ����... �׳� scanf�� �޾Ƽ� �߽��ϴ�. 
	return input;
}	

int checkWinner(int player)			//�ִ밪�� ���ϴ� ���. 
{
	int large[player];				//���� �ӽ÷� �����ϴ� �迭. �ִ밪�� ã�Ƴ��µ� �̿���, 
	int i;
	for(i=0;i<player;i++)
	{
		large[i]=now_money[i];		//�� �迭���� �÷��̾ ���� ���� ���� ������. 
	}
	int most_large = large[0];		//�⺻������ ù° �÷��̾��� ���� �ӽ÷� ���� ū ������ ����. 
	for(i=0;i<player;i++)
	{
		if(large[i]>most_large)		//�� ���Ŀ� �� �迭���� ���ϸ鼭 ���� ū ���� ã�ư�. 
		{
			most_large=large[i];
		}
	}
	return most_large;
}

int main(int argc, char *argv[]) {
	return 0;
}
