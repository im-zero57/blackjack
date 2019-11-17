#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
int dollar[N_MAX_USER];		//������ �÷��̾ ������ ���� �Է¹��� �迭 
int now_money[N_MAX_USER];	//����� �ݾ��� �˷��� 
int bet_money;				//���ù��� �ݾ��� ���� 

//�÷��� �� ���� 
int cardhold[N_MAX_USER+1][N_MAX_CARDHOLD];			//�÷��� �� ���� �ִ� �÷��̾ ������ ī�带 �迭�� �̿��Ͽ� ���� 
int cardSum[N_MAX_USER+1];							//�� �÷��̾ ������ ī���� �� 
int gameend = 0; 									//������ ������ ���� �ǹ�
int cardNumber[N_MAX_USER+1];						//�� �÷��̾�� ������ ������ ī���� ���� 


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

//�Բ� �� �÷��̾��� ���� �Է¹޴� ���α׷� 
int configUser(void){
	
	int with_player;
	printf("�Բ� �� �÷��̾��� ���� �Է����ּ���(�ִ� �ټ������ �� �� �ֽ��ϴ�): ");
	scanf("%d",&with_player);
	return with_player;
	
} 

//ī�带 �ߺ� ���� ���� �Լ� 
int mixCardTray(void){
	
	int i;
	int player_i;
	
	
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

//������ �ݾ��� �Է¹��� 
void betDollar(void){
	
	int bet_money;
	
	printf("�󸶸� �����Ͻðڽ��ϱ�? : ");
	scanf("%d",bet_money);
	dollar[0]=bet_money;
	 
	int i;
	for(i=1;i<N_MAX_USER;i++){
		dollar[i] = 1+rand()%(now_money[i]);
		printf("�÷��̾� i�� ���� �ݾ��� %d �Դϴ�", i, dollar[i]);
	} 
	
}

//ī�带 ������ 
void offerCards(void){
	int i;
	
	for (i=0;i<N_MAX_USER;i++);
	{
		cardhold[i][0] = pullCard();
		cardhold[i][1] = pullCard();
		
	}
	cardhold[N_MAX_USER][0] = pullCard();
	cardhold[N_MAX_USER][1] = pullCard();
	
	return;
}

//�߰��� ������ ī�带 �˷��� 
void offerCardsplus(int player,int turn){
	int i;
	for (i=3;i<turn+2;i++)
		cardhold[player][i] = pullCard();
}

int pullCard(void){
	int card;
	card = CARDTRAY[rand()%N_CARD];
	return card;
}

void printCardInitialStatus(void){
	int i;
	printf("������ ī�� : ");
	printCard(cardhold[0][0]);
	printCard(cardhold[0][1]);
	printf("------------------------------------------");
	for (i=1;i<N_MAX_USER;i++)
	{
		printf("i �÷��̾��� ī��: ");
		printCard(cardhold[i][0]);
		printCard(cardhold[i][1]);
		printf("---------------------------------------");
	}
	printf("������ ī�� : ");
	printf("�� �� ����");
	printCard(cardhold[N_MAX_USER][0]);
}

void printUserCardStatus(int user, int cardcnt){
	int i;
	
	printf("   -> card : ");
	for (i=0;i<cardcnt;i++)
	{
		printCard(cardhold[user][i]);
	}
	printf("\t:::");
}

int calcStepResult(int user,int turn){
	int i;
	int step_result;
	int plus=0;
	for(i=0;i<=turn;i++)
		plus+=getCardNum(cardhold[0][i]);
		if(plus>=8000)
		{
			if((plus-8000)>10)
			{
				step_result=plus-8000+1;			
			}
			else if((plus-8000)<=10)
			{
				step_result=plus-8000+11;
			}
		}
		else if(plus<8000)
			step_result = plus;
	
	return step_result;
}

int getAction(void){
	
	char input;
	printf("go�Ͻðڽ��ϱ�? stop �Ͻðڽ��ϱ�? (Y / N) :  ");
	scanf("%c",input);
	return input;
}

int CheckResult(int player){
	if(cardSum[N_MAX_USER]>21&&cardSum[player]<21)
	{
		printf("������ ī�� ���� 21�� �ʰ��ϹǷ� �÷��̾�i���� ���ñݾ��� �ٽ� ���ư��ϴ�.",player);
		now_money[player]+=dollar[player];
	} 
	
	else if(cardSum[N_MAX_USER]==21&&cardSum[player]<21)
	{
		printf("������ ī�� ���� 21�̹Ƿ� �÷��̾�i�� ���ñݾ��� �ҽ��ϴ�.",player);
		now_money[player]-=dollar[player];
		
	}
	
	else if(cardSum[N_MAX_USER]<21)
	{
		if(cardSum[player]<cardSum[N_MAX_USER])
		{
			printf("�÷��̾�i�� ���� ī���� ���� ������ ���� ī���� �պ��� ũ�Ƿ� ���ñݾ��� �ٽ� �����޽��ϴ�.",player); 
			now_money[player]+=dollar[player];
		}
	}
	else if(cardSum[player]>cardSum[N_MAX_USER]&&cardSum[player]<21)
	{
		printf("�÷��̾�i�� ���� ī���� ���� ������ ���� ī���� �պ��� �����Ƿ� ���ñݾ��� �ҽ��ϴ�.",player);
		now_money[player]-=dollar[player];
	}
}        

int checkWinner(int player)
{
	int large[player];
	int i;
	for(i=0;i<player;i++)
	{
		large[i]=now_money[i];
	}
	int most_large = large[0];
	for(i=0;i<player;i++)
	{
		if(large[i]>most_large)
		{
			most_large=large[i];
		}
	}
	return most_large;
}

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int main(int argc, char *argv[]) {
	now_money[0]=50;
	now_money[1]=50;
	now_money[2]=50;
	now_money[3]=50;
	now_money[4]=50;
	
	int roundIndex = 0;
	int n_user;
	int i;

	int answer;
	
	int input=0;
	int until_cardnum=0;
	int round_try_for_me = 0;
	int round_try_for_player = 0;
	int round_try_for_dealer = 0;
	
	srand((unsigned)time(NULL));

	n_user = configUser()+1;
	//�� 
	printf("��� �÷��̾��� �ʱ� �ں����� %d �޷� �Դϴ�.",N_DOLLAR);
	
	//ī�� Ʈ����
	mixCardTray();
	
	do{
		betDollar();
		
		offerCards(); 
		
		printCardInitialStatus();
		
		printf("\n------------------------������ �����ϰڽ��ϴ�-------------------------\n");
		roundIndex++;
		
		printf("����� %d���� �Դϴ�.",roundIndex);
		
		printf("���� �ڻ� ����� ������ �����ϴ�.");
		for(i=0;i<n_user;i++)
		{
			printf("�÷��̾�i�� ���� �ڻ��� %d �Դϴ�",i,now_money[i]);
		}
		
		printf("\n---------------------------------------------------------\n");
		 
		printf(">>>���� �����Դϴ�---------------------------------------------------\n");		
		while(cardSum[0]<21&&input=='Y')
			
			
			round_try_for_me++;
			printUserCardStatus(0,round_try_for_me);
			
			cardSum[0]=calcStepResult(0,round_try_for_me);
			if(cardSum[0]==21)
				{
					printf("�����մϴ�! �����̳׿�:P ����� ��� �޾��� %d�� �Դϴ�",2*dollar[0]);
					now_money[0]+=2*dollar[0];
				}
			else if(cardSum[0]>21)
				{
					printf("���̽��ϴ�:( ����� ī���� ���� %d �Դϴ�. ����� ���� �ݾ��� %d ���Դϴ�",cardSum[0],dollar[0]);
					now_money[0]-=dollar[0];	
				}
			else
				{
					input = getAction();
					if(input=='Y')
					{
						offerCardsplus(0,round_try_for_me);
					}
					cardNumber[0]=round_try_for_me+1;	
				}
		for(i=1;i<n_user;i++)
		{	printf(">>>�÷��̾�i�� �����Դϴ�---------------------------------------\n",i);
			while((cardSum[i]<21&&cardSum[i]<17)){
				
				round_try_for_player++;
				printUserCardStatus(i,round_try_for_player);
				cardSum[i]=calcStepResult(i,round_try_for_player);
				if(cardSum[i]==21)
				{
					printf("�����մϴ�! �����̳׿�:P �÷��̾� i�� ��� �޾��� %d�� �Դϴ�",i,2*dollar[i]);
					now_money[i]+=2*dollar[i];
				}
				else if(cardSum[i]>21)
				{
					printf("���̽��ϴ�:( �÷��̾� i�� ī����  ���� %d �Դϴ�. �÷��̾� i�� ���� �ݾ��� %d ���Դϴ�",i,cardSum[i],i,dollar[i]);
					now_money[i]-=dollar[i];
				}
				else if(cardSum[i]<17)
				{
					printf("�÷��̾�i�� go�� �����߽��ϴ�.");
					offerCardsplus(i,round_try_for_player);
				}
				else if(cardSum[i]>=17)
				{
					printf("�÷��̾�i�� stop�� �����߽��ϴ�.");
				}
				cardNumber[i]=round_try_for_player+1;
			}
		}
		printf("������ ���� �Դϴ�!"); 
		while(cardSum[n_user]<17)
		{
			
			round_try_for_dealer++;
			printUserCardStatus(n_user,round_try_for_dealer);
			cardSum[n_user]=calcStepResult(n_user,round_try_for_dealer);
			if(cardSum[n_user]==21)
				break;
			else if(cardSum[n_user]>21)
				break;	
			else if(cardSum[n_user]<17)
			{
				printf("������ go��  �����߽��ϴ�.");
				offerCardsplus(n_user,round_try_for_dealer);
			}
			else if(cardSum[n_user]>17&&cardSum[n_user]<21)
			{
				printf("������ stop�� �����߽��ϴ�.");
			}
			cardNumber[n_user]=round_try_for_dealer+1;
		}
		printf("������ ���� %d �Դϴ�",cardSum[n_user]);
		for (i=0;i<n_user;i++)
		{
			CheckResult(i);
		}
		
		printf("��������� �ڻ� ����� ������ �����ϴ�.");
		for(i=0;i<n_user;i++)
		{
			printf("�÷��̾�i�� ���� �ڻ��� %d �Դϴ�",i,now_money[i]);
		}
		
		for(i=0;i<=n_user+1;i++)
		{
			until_cardnum+=cardNumber[i];
		}
		
		if(until_cardnum>=52)
		{
			gameend = 1;
		}
		else if(now_money[i]<=0)
		{
			gameend = 1;
		}
	}while(gameend == 0);
	
	int winner_money;
	winner_money = checkWinner(n_user);
	for(i=0;i<n_user;i++)
	{
		if(winner_money==now_money[i])
		{
			printf("���ڴ� �÷��̾�i�Դϴ�.",i);
			break;
		}
	}	
		
	return 0;
}
