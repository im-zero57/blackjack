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
int bet_dollar[N_MAX_USER];
int now_money[N_MAX_USER];
	
now_money[0]=50;
now_money[1]=50;
now_moeny[2]=50;
now_money[3]=50;
now_money[4]=50;

//�÷��� �� ����
int cardhold[N_MAX_USER+1][N_MAX_CARDHOLD];			//�÷��� �� ���� �ִ� �÷��̾ ������ ī���� ���� �迭�� �̿��Ͽ� ���� 
int cardSum[N_MAX_USER+1];							//�÷��� �� ���� �ִ� ī���� �� ��  
int bet[N_MAX_USER];								//��ǻ�� �÷��̾ ������ �� �ִ� ���ñݾ�  
int gameend = 0; 									//������ ������ ���� �ǹ�
int cardNumber[N_MAX_USER+1];

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
		CardTray[i]=1+rand(%(N_MAX_CARDNUM));
	}
	return 0;
}

void bet Dollar(void){
	
	int bet_money
	printf("�󸶸� �����Ͻðڽ��ϱ�? : ");
	scnaf("%d",bet_money);
	dollar[0]=bet_money;
	 
	int i;
	for(i=1;i<max_user;i++){
		dollar[i] = 1+rand()%(N_DOLLAR);
		printf("�÷��̾� i�� ���� �ݾ��� %d �Դϴ�", i, dollar[i]);
	} 
	
}

void offerCards(void){
	int i;
	for (i=0;i<n_user;i++);
	{
		cardhold[i][0] = pullCard();
		cardhold[i][1] = pullCard();
	}
	cardhold[n_user][0] = pullCard();
	cardhold[n_user][1] = pullCard();
	
	return;
}

void offerCardsplus(int player,int turn){
	int i;
	for (i=3;i<turn+2;i++)
		cardhold[player][i] = pullCard();
}

int pullCard(void){
	int card
	card = cardTray[rand()%(N_CARD)];
	return card;
}

void printCardInitialStatus(void){
	int i;
	printf("������ ī�� : %d , %d",cardhold[0][0],cardhold[0][1]);
	for (i=1;i<(n_user-1);i++)
	{
		printf("i �÷��̾��� ī��: %d , %d",i,cardhold[i][0],cardhold[i][0])
	}
	printf("������ ī�� : <���> , %d ",cardhold[n_user][0]);
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
	
	int step_result;
	int i;
	for(i=0;i<turn;i++)
		step_result += cardhold[user][i];
	return step_result;
}

int getAction(void){
	
	int input;
	printf("go�Ͻðڽ��ϱ�? stop �Ͻðڽ��ϱ�? (Y-0 / N-others) :  ");
	input=getIntegerInput();
	return input;
}

int getIntegerInput(void) {
    int input, num;
    
    num = scanf("%d", &input);
    fflush(stdin);
    if (num != 1) //if it fails to get integer
        input = -1;
    
    return input;
        
int CheckResult(int player){
	if(cardSum[n_user]>21&&cardSum[player]<21)
	{
		printf("������ ī�� ���� 21�� �ʰ��ϹǷ� �÷��̾�i���� ���ñݾ��� �ٽ� ���ư��ϴ�.",player);
		now_money[player]+=dollar[player];
	} 
	
	else if(cardSum[n_user]==21&&cardSum[player]<21)
	{
		printf("������ ī�� ���� 21�̹Ƿ� �÷��̾�i�� ���ñݾ��� �ҽ��ϴ�.",player);
		now_money[player]-=dollar[player];
		
	}
	
	else if(cardSum[n_user]<21)
	{
		if(cardSum[player]<cardSum[n_user])
		{
			printf("�÷��̾�i�� ���� ī���� ���� ������ ���� ī���� �պ��� ũ�Ƿ� ���ñݾ��� �ٽ� �����޽��ϴ�.",player); 
			now_money[palyer]+=dollar[palyer];
		}
	}
	else if(cardSum[player]>cardSum[n_user]&&cardSum[palyer]<21)
	{
		printf("�÷��̾�i�� ���� ī���� ���� ������ ���� ī���� �պ��� �����Ƿ� ���ñݾ��� �ҽ��ϴ�."i);
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
	int roundIndex = 0;
	int n_user;
	int i;
	
	int now_money;
	int answer;
	int now_cardsum = 0;
	int round_try_for_me = 0;
	int round_try_for_player = 0;
	int round_try_for_dealer = 0;
	int input=0;
	int until_cardnum;
	
	srand((unsigned)time(NULL));

	n_user = configUser()+1;
	//�� 
	printf("��� �÷��̾��� �ʱ� �ں����� %d �޷� �Դϴ�.",N_DOLLAR);
	
	//ī�� Ʈ����
	mixCardTray();
	
	do{
		bet dollar();
		printf("�󸶸� �����Ͻðڽ��ϱ�? : ");
		scnaf("%d",&bet_money);
		offerCards(); 
		
		printCardInitialStatus();
		printf("\n------------------------������ �����ϰڽ��ϴ�-------------------------\n");
		roundIndex++;
		
		printf(">>>���� �����Դϴ�---------------------------------------------------\n")		
		while(cardSum[0]<21&&input==0)
			int round_try_for_me = 0;
			round_try_for_me++
			printUserCardStatus(0,round_try_for_me);
			cardSum[0]=calcStepResult(0,round_try_for_me);
			if(cardSum[0]==21)
				printf("�����մϴ�! �����̳׿�:P ����� ��� �޾��� %d�� �Դϴ�",2*dollar[0]);
				now_money[0]+=2*dollar[0];
			else if(cardSum[0]>21)
				printf("����ϼ̽��ϴ�:( ����� ī���� ���� %d �Դϴ�. ����� ���� �ݾ��� %d ���Դϴ�",cardSum[0],dollar[0]);
				now_money-=dollar[0];	
			else
				input = getAction();
				if(input==0)
				{
					offerCardsplus(0,round_try_for_me)
				}
			card_number[0]=round_try_for_me+1;	
	
		for(i=1;i<n_user;i++)
		{	printf(">>>�÷��̾�i�� �����Դϴ�---------------------------------------\n",i);
			while((cardSum[i]<21&&cardSum[i]<17){
				int round_try_for_player = 0;
				round_try_for_player++
				printUserCardStatus(i,round_try_for_player);
				cardSum[i]=calcStepResult(i,round_try_for_player);
				if(cardSum[i]==21)
				{
					printf("�����մϴ�! �����̳׿�:P �÷��̾� i�� ��� �޾��� %d�� �Դϴ�",i,2*dollar[i]);
					now_money[i]+=2*dollar[i];
				}
				else if(cardSum[i]>21)
				{
					printf("����ϼ̽��ϴ�:( �÷��̾� i�� ī����  ���� %d �Դϴ�. �÷��̾� i�� ���� �ݾ��� %d ���Դϴ�",i,i,cardSum[0],);
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
				card_number[i]=round_try_for_player+1;
			}
		}
		printf("������ ���� �Դϴ�!") 
		while(cardSum[n_user]<17)
		{
			int round_try_for_dealer = 0;
			round_try_for_dealer++
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
				printf("������ stop�� �����߽��ϴ�.")
			}
			card_number[i]=round_try_for_player+1
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
			until_cardnum+=card_number[i];
		}
		
		if(cardnum>=52)
		{
			gameend = 1;
		}
		if else(now_money[i]<=0)
		{
			gameend = 1;
		}
	}while(gameend == 0);
	
	int winner_money;
	winner_money = checkWinner(n_user)
	for(i=0;i<n_user;i++)
	{
		if(winner_money==now_money[i])
		{
			printf("���ڴ� �÷��̾�i�Դϴ�.",i);
			break;
		}
	}	
		
	}
	return 0;
}
