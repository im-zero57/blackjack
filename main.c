#include <stdio.h>
#include <stdlib.h>

#define N_CARDSET		1
#define N_CARD			52
#define N_DOLLAR		50


#define	N_MAX_CARDNUM	13
#define N_MAX_USER		5
#define N_MAX_CARDHOLD	10
#define N_MAX_GO		17
#define N_MAX_BET		5

#define N_MIN_ENDCARD	3O

//ī�� Ʈ���̸� �迵�� �̿��ؼ�  ����
int CARDTRAY[N_CARDSET*N_CARD];
int cardIndex = 0;

//�÷��̾�� ���õ� ������ ���� 
int dollar[N_MAX_USER];		//������ �÷��̾ ���� �� �ִ� ���� �迭�� �̿��Ͽ� ���� 
int n_user; 

//�÷��� �� ����
int cardhold[N_MAX_USER+1][N_MAX_CARDHOLD];			//�÷��� �� ���� �ִ� �÷��̾ ������ ī���� ���� �迭�� �̿��Ͽ� ���� 
int cardSum[N_MAX_USER];							//�÷��� �� ���� �ִ� ī���� �� ��  
int bet[N_MAX_USER];								//��ǻ�� �÷��̾ ������ �� �ִ� ���ñݾ�  
int gameend = 0; 									//������ ������ ���� �ǹ�


//ī�� �Լ� ����----------
int getCardNum(int cardnum) {
	
	int real_number;
	if(cardnum = 'K'){
		real_number = 10;
	}
	if else(cardnum = 'Q'){
		real_number = 10;
	} 
	if else(cardnum = 'J'){
		real_number = 10; 
	}
	if else(cardnum = 'A'){
		if (cardnum)
	}
	else
		real_number = cardnum;
	
	return real_number;
} 

//�Ҵ�� ī�带 ������
void printCard(int cardnum) {
	
} 
//�÷��̾��� ����
int configUser(void){
	
	int with_player;
	printf("�Բ� �� �÷��̾��� ���� �Է����ּ���(�ִ� �ټ������ �� �� �ֽ��ϴ�): ");
	scanf("%d",&with_player);
	return with_player;
	
} 

int mixCardTray(void){
	int i;
	for(i=0;i<N_CARD;i++)
	{
		CardTray[i]=1+rand(%(N_CARD));
	}
	return 0;
}
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int roundIndex = 0;
	int max_user;
	int i;
	
	srand((unsigned)time(NULL));
	
	max_user = configUsre();
	//��
	for(i=0;i<max_user;i++){
		dollar[i] = 1+rand()%(N_DOLLAR);
		printf("�÷��̾� i�� ���� �ݾ��� %d �Դϴ�", i+1, d0llar[i]);
	} 
	//ī�� Ʈ����
	mixCardTray();
	 
	return 0;
}
