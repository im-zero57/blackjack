#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//���� ���ڰ� �ǹ��ϴ� ī���� ��¥ ���ڸ� ����---------
int getCardNum(int card) {
	
	int real_number;
	
	if(card>1&&card<11){
		real_number=card;
	}
	else if(card&&card<14){
		real_number=10;
	} 
	else if(card&&card<24){
		real_number=card-13; 
	}
	else if(card>=24&&card<27)
		real_number=10;
	else if(card>27&&card<37)
		real_number=card-26;
	else if(card>=37&&card<40)
		real_number=10;
	else if(card>40&&card<50)
		real_number=card-39;	
	else if(card==1||card==14||card==27||card==40)
		real_number=8000;
	return real_number;
} 

//�Ҵ�� ���ڰ� �ǹ��ϴ� ī���� ���� ���ڸ� �˷��� 

void printCard(int card) {
	
	int ch_card;
	if(card==1)
	{
		printf("��ACE"); 
	}
	else if(card>1&&card<11)
	{
		printf("��%d",card-1);
	}
	else if(card==11)
	{
		printf("��king");	
	}
	else if(card==12)
	{
		printf("��Queen");
	} 
	else if(card==13)
	{
		printf("��Jack");
	}
	else if(card==14)
	{
		printf("��ACE");
	}
	else if(card>14&&card<24)
	{
		printf("��%d",card-13);
	}
	else if(card==24)
	{
		printf("��King");
	}
	else if(card==25)
	{
		printf("��Queen");
	}
	else if(card==26)
	{
		printf("��Jack");
	}
	else if(card==27)
	{
		printf("��ACE");
	}
	else if(card>27&&card<37)
	{
		printf("��%d",card-28);
	}
	else if(card==37)
	{
		printf("��King");
	}
	else if(card==38)
	{
		printf("��Queen");
	}
	else if(card==39)
	{
		printf("��Jack");
	}
	else if(card==40)
	{
		printf("��ACE");
	}
	else if(card>40&&card<50)
	{
		printf("��%d",card-39);
	}
	else if(card==50)
	{
		printf("��King");
	}
	else if(card==51)
	{
		printf("��Queen");
	}
	else if(card==52)
	{
		printf("��Jack");												 
	} 	
}

int mixCardTray(void){
	
	int i;
	int player_i;
	
	srand((unsigned)time(NULL));
	
	for(i=0;i<N_CARD;i++)
	{	
		CARDTRAY[i]=1+rand()%(N_CARD);
		
		for(player_i=0;player_i<i;player_i++)
		{
			if(CARDTRAY[i]==CARDTRAY[player_i])
			{	
				i--;
				break;
			}	
		} 
	}
	return 0;
}

void offerCards(void){
	int i;
	int number;
	
	for (i=0;i<=with_player;i++);
	{
		cardhold[i][0] = pullCard(i);				//�÷��̾� ��ο��� �����Ǵ� �ΰ��� ī�� �� ù��° ī��. 
		cardhold[i][1] = pullCard(i+5);				//�÷��̾� ��ο��� �����Ǵ� �ΰ��� ī�� �� �ι�° ī��. 
	}
	cardhold[N_MAX_USER][0] = pullCard(N_MAX_USER-1);	//�������� �����ϴ� �ΰ��� ī�� �� ù��° ī��. 
	cardhold[N_MAX_USER][1] = pullCard(N_MAX_USER);		//�������� �����ϴ� �ΰ��� ī�� �� �ι�° ī��. 
	
	return;
}

//�÷��̾ 'go'�� ������ ��� �����Ǵ� �߰��� ī�� 
void offerCardsplus(int player,int turn){
	int i;
	for (i=3;i<turn+2;i++)							 
		cardhold[player][i] = pullCard(i+10);		//�÷��̾�� �����Ǵ� ��,��,,, �� �̻��� ī��. �� ��� ī��� pullCard �Լ��� �޴´�. 
}

//ī�带 ������ 
int pullCard(int number){
	int i, check_number, return_number, card;
	
	do{												//�÷��̾�� �����Ǵ� ī�带 �ǹ���. 
		Number[number]=rand()%N_CARD;				//CARDTRAY�� ���Ƿ� ���� �Ҵ��ϰ� pullcard�Լ������� �� CARDTRAY�� �迭�̸��� ���Ƿ� �Ҵ��ؼ� ������. 
		for(i=0;i<number;i++)						//�� ��� �ߺ��� ���ϰ��� �ӽ÷� Number�迭�� ���Ƿ� �Ҵ�� ���ڸ� �����ϰ� ���� ���Ƿ� �Ҵ�� 
		{											 
			if(Number[number]=Number[i])
			{
				check_number=1;						//���ڰ� ���� ��� �ٽ� �Ҵ�޵��� ��.  
			}
			else
			{
				check_number=2;
			}
		}
	}while(check_number==1);

	card = CARDTRAY[Number[number]];				//���������� ���ڰ� �ٸ� ��쿡�� CARDTRAY�� �� �� ����. 
	return card;
}

void printCardInitialStatus(void){					//�ʱ��� ī�带 �˷��ִ� �Լ�. 
	int i;											//'��'�� ī�带 �˷���. 
	printf("������ ī�� : ");
	printCard(cardhold[0][0]);
	printCard(cardhold[0][1]);
	printf("------------------------------------------");
	for (i=1;i<with_player;i++)						//�Բ� �� �÷��̾� ī�带 �˷���. 
	{
		printf("i �÷��̾��� ī��: ");
		printCard(cardhold[i][0]);
		printCard(cardhold[i][1]);
		printf("---------------------------------------");
	}
	printf("������ ī�� : ");						//������ ī�带 �˷���. 
	printf("�� �� ����");							//������ ī��� �Ѱ����� �˷��� �� ����. 
	printCard(cardhold[N_MAX_USER][0]);
}

void printUserCardStatus(int user, int cardcnt){
	int i;											//�� �ܰ迡�� ���� ���� ī�带 �߰��ؼ� �˷���. 
	
	printf("   -> card : ");
	for (i=0;i<cardcnt;i++)
	{
		printCard(cardhold[user][i]);
	}
	printf("\t:::");
}

int main(int argc, char *argv[]) {
	
	return 0;
}
