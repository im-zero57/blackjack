#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N_CARDSET		1
#define N_CARD			52
#define N_DOLLAR		50


#define	N_MAX_CARDNUM	13
#define N_MAX_USER		6
#define N_MAX_CARDHOLD	10
#define N_MAX_GO		17
#define N_MAX_BET		6

#define N_MIN_ENDCARD	3O

//ī�� Ʈ���̸� �迵�� �̿��ؼ�  ����
int CARDTRAY[N_CARDSET*N_CARD];
int cardIndex = 0;

//�÷��̾�� ���õ� ������ ���� 
int dollar[N_MAX_USER];		//������ �÷��̾ ������ ���� �Է¹��� �迭 
int now_money[N_MAX_USER];	//����� �ݾ��� �˷��� 
int bet_money;				//���ù��� �ݾ��� ���� 
int with_player; 			//�Բ� �÷����� �÷��̾ �Է¹޴� ��   

//�÷��� �� ���� 
int cardhold[N_MAX_USER+1][N_MAX_CARDHOLD];			//�÷��� �� ���� �ִ� �÷��̾ ������ ī�带 �迭�� �̿��Ͽ� ���� 
int cardSum[N_MAX_USER+1];							//�� �÷��̾ ������ ī���� �� 
int gameend = 0; 									//������ ������ ���� �ǹ�
int cardNumber[N_MAX_USER+1];						//�� �÷��̾�� ������ ������ ī���� ���� 
int Number[N_CARD];									//���Ƿ� �Ҵ���� ���� �����ϴ� �迭. �ܼ��� ���ڸ� �迭�������� ������ ū �ǹ̴� ����. 

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
	
	printf("�Բ� �� �÷��̾��� ���� �Է����ּ���(�ִ� �ټ������ �� �� �ֽ��ϴ�): ");
	scanf("%d",&with_player);
	return with_player;
	
} 

//ī�带 �ߺ� ���� ���� �Լ� 
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

//������ �ݾ��� �Է¹��� 
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
	
}

//�÷��̾�鿡�� �����Ǵ� �ʱ��� �ΰ� ī��  
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

int calcStepResult(int user,int turn){				//�� �ܰ��� ������� �˷���. 
	int i;
	int step_result;
	int plus=0;
	for(i=0;i<=turn;i++)
		plus+=getCardNum(cardhold[0][i]);		
		if(plus>=8000)								//ACE�� ��� 1�� 11 �ΰ����� �ǹ��� �� �ֱ� ������ �ʱ⿡ ACE ī���� ��� 8000���� �ް� 
		{											//���� ī�忡 ACE�� �ִ� ��츣 Ȯ����. 
			if((plus-8000)>10)						//ī���� �տ��� 8000�� ���� �� 10 ���� Ŭ ��� ACE�� 1�� �ǹ��ϵ��� ��.  
			{
				step_result=plus-8000+1;			
			}
			else if((plus-8000)<=10)				//ī���� �տ��� 8000�� ���� ��, 10���� ���� ��� ACE�� 11�� �ǹ��ϵ��� ��. 
			{
				step_result=plus-8000+11;
			}
		}
		else if(plus<8000)
			step_result = plus;
	
	return step_result;
}

int getAction(void){							//'GO'���� 'STOP'�� �� �����ؾ���. 
	
	char input;
	printf("go�Ͻðڽ��ϱ�? stop �Ͻðڽ��ϱ�? (Y / N) :  ");
	scanf("%c",input);							//�������� �ֽ� �Լ��� �ڲ� ������ ����... �׳� scanf�� �޾Ƽ� �߽��ϴ�. 
	return input;
}

int CheckResult(int player){
	if(cardSum[N_MAX_USER]>21&&cardSum[player]<21)		//������ ī�� ���� �������� �ٸ� �÷��̾���� �¸� Ȥ�� �й踦 �����ϱ� ���ؼ� �����ϴ� �Լ�. 
	{													//������ ���� 21�� �Ѱ� �÷��̾��� ���� 21 ������ ��쿡�� ����. 21 �ʰ��̸� ���ӿ��� �й�/21�̸� �����̹Ƿ� �� �����ְų� ���ִ� ���� �ǹ� ���� 
		printf("������ ī�� ���� 21�� �ʰ��ϹǷ� �÷��̾�%i���� ���ñݾ��� �ٽ� ���ư��ϴ�.",player);
		now_money[player]+=dollar[player];
	} 
	
	else if(cardSum[N_MAX_USER]==21&&cardSum[player]<21)	//�հ� ���������� 21�� �� ��� ������ �¸���. �� ��쿡�� �÷��̾��� ���� 
	{														//21�� ���� 21���� Ŭ ���� �ǹ̰� ����. 
		printf("������ ī�� ���� 21�̹Ƿ� �÷��̾�%i�� ���ñݾ��� �ҽ��ϴ�.",player);
		now_money[player]-=dollar[player];
		
	}
	
	else if(cardSum[N_MAX_USER]<21)						//�� ��� ������ �÷��̾� ������ �� �񱳰� �¸��� �����ϴµ� ������ ��. 
	{
		if(cardSum[player]<cardSum[N_MAX_USER])			//������ �պ��� �÷��̾��� ���� �������. 
		{												//���ʿ� ������ �պ��� �����Ƿ� �÷��̾ 21�̻��� ���� ����� �ʿ䰡 ����. 
			printf("�÷��̾�%i�� ���� ī���� ���� ������ ���� ī���� �պ��� �����Ƿ� ���ñݾ��� �ҽ��ϴ�.",player); 
			now_money[player]-=dollar[player];
		}
	}
	else if(cardSum[player]>cardSum[N_MAX_USER]&&cardSum[player]<21)		//������ �պ��� �÷��̾��� ���� ū ���. 
	{																		//�� ��� �÷��̾��� ���� 21�̻��� ���ɼ��� �����Ƿ� �� ��츦 ������. 
		printf("�÷��̾�%i�� ���� ī���� ���� ������ ���� ī���� �պ��� ũ���Ƿ� ���ñݾ��� �ҽ��ϴ�.",player);
		now_money[player]+=dollar[player];
	}
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

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int main(int argc, char *argv[]) {
	now_money[0]=50;		//�ʱ� ��� �÷��̾ ���� �� �ִ� ���� ������ �迭. 
	now_money[1]=50;
	now_money[2]=50;
	now_money[3]=50;
	now_money[4]=50;
	now_money[5]=50;
	
	int roundIndex = 0;			//��� ���带 �ߴ����� �˷��� ��. 
	int n_user;					//�Բ� �����ϴ� �÷��̾��� ��. 
	int i;						//for ���� ����� �ӽ� ��. 
	
	int input=0;				//go �Ұ����� stop�� �������� ���� ��. 
	int until_cardnum=0;		//��������� ī�� ���� ���� �ǹ���. 
	int round_try_for_me = 0;	//���� �̶����� ���� ī����� ����� �� ����� ��. 
	int round_try_for_player = 0;//�÷��̾ �̶����� ���� ī����� ����� ��, ����� ��. 
	int round_try_for_dealer = 0;//������ �̶����� ���� ī����� ����� �� ����� ��. 
	
	srand((unsigned)time(NULL));

	n_user = configUser()+1;	//�Բ� �� �÷��̾��� ���� ������ ���� ���� ��. 
	//�� 
	printf("��� �÷��̾��� �ʱ� �ں����� %d �޷� �Դϴ�.",N_DOLLAR); //�ʱ� �ں����� �˷���. 
	
	//ī�� Ʈ����
	mixCardTray();					//ī�带 ����. 
	
	do{
		betDollar();			//���ù��� ī�带 �Է���. 
		
		offerCards();			//ī�带 ������. 
		
		printCardInitialStatus();	//�ʱ� ī�尪�� �˷��� 
		
		printf("\n------------------------������ �����ϰڽ��ϴ�-------------------------\n");
		roundIndex++;				//�⺻���� �� ���带 �����ϹǷ� 
		
		printf("����� %d���� �Դϴ�.",roundIndex);	//���带 �˷��� 
		
		printf("���� �ڻ� ����� ������ �����ϴ�.");	//�ʱⰪ�� �� ���� �����Ҷ������� ���� �˷��ַ�����. 
		for(i=0;i<n_user;i++)
		{
			printf("�÷��̾�i�� ���� �ڻ��� %d �Դϴ�",i,now_money[i]);
		}
		
		printf("\n---------------------------------------------------------\n");
		 
		printf(">>>���� �����Դϴ�---------------------------------------------------\n");		
		while(cardSum[0]<21&&input=='Y')//ī���� ���� 21 �̸��̰ų� �� ����� Y�϶��� ����� 
			
			
			round_try_for_me++;//�ϴ� 1�� ���ϰ� ������ 
			printUserCardStatus(0,round_try_for_me);//�� ������ ī�� �� �˷��� 
			
			cardSum[0]=calcStepResult(0,round_try_for_me);		//������ ī�� ���� ���� �ǹ���. 
			if(cardSum[0]==21)					//ī���� ���� 21�� ��� ���� ��Ʈ�� ���� ��. 
				{
					printf("�����մϴ�! �����̳׿�:P ����� ��� �޾��� %d�� �Դϴ�",2*dollar[0]);
					now_money[0]+=2*dollar[0];
				}
			else if(cardSum[0]>21)		//���� 21���� Ŭ ��� ���� ��Ʈ�� ������ �ݾ��� ����.... 
				{
					printf("���̽��ϴ�:( ����� ī���� ���� %d �Դϴ�. ����� ���� �ݾ��� %d ���Դϴ�",cardSum[0],dollar[0]);
					now_money[0]-=dollar[0];	
				}
			else			//�Ѵ��� ��찡 �ƴ� ��� '��'���� GO�� ������ STOP �� �������� ���. 
				{
					input = getAction();
					if(input=='Y')			//���� Y�� �Է¹��� ��� ���ο� ī�带 ������. 
					{
						offerCardsplus(0,round_try_for_me);
					}
					cardNumber[0]=round_try_for_me+1;	//�� �� �� ��� �÷��̾ ���� ī�尡 �� 2���̹Ƿ� ������ ������ �ϴ� ���� �� ������. 
				}
		for(i=1;i<n_user;i++)					//'��'�� �� ���� �Ȱ��� ����Ǹ� �ٸ� ���� GO�� ���� STOP�� ������ �÷��̾ ������ 17�� �������� ������ �ٴ� �� �ۿ� ����. 
		{	printf(">>>�÷��̾�i�� �����Դϴ�---------------------------------------\n",i);
			while((cardSum[i]<21&&cardSum[i]<17)){
				
				round_try_for_player++;
				printUserCardStatus(i,round_try_for_player);
				cardSum[i]=calcStepResult(i,round_try_for_player);
				if(cardSum[i]==21)
				{
					printf("�����մϴ�! �����̳׿�:P �÷��̾� %i�� ��� �޾��� %d�� �Դϴ�",i,2*dollar[i]);
					now_money[i]+=2*dollar[i];
				}
				else if(cardSum[i]>21)
				{
					printf("���̽��ϴ�:( �÷��̾� %i�� ī����  ���� %d �Դϴ�. �÷��̾� %i�� ���� �ݾ��� %d ���Դϴ�",i,cardSum[i],i,dollar[i]);
					now_money[i]-=dollar[i];
				}
				else if(cardSum[i]<17)//���� 17 �̸��� ��� ���� �� ����. 
				{
					printf("�÷��̾�%i�� ī�带 ���� �� �̾ҽ��ϴ�.");
					offerCardsplus(i,round_try_for_player);
				}
				else if(cardSum[i]>=17)//���� 17 �̻��� ��� �׸� ���� 
				{
					printf("�÷��̾�%i�� ī�带 �׸� �̱⸦ �����߽��ϴ�.");
				}
				cardNumber[i]=round_try_for_player+1;//�� ��쿡�� ���� ���������� �ѹ� ������ ���� ī���� ���� �����̰� ������ ���� �� �̾�����
													//�ѹ� �� �����̹Ƿ� �׶� ������ 
			}
		}
		printf("������ ���� �Դϴ�!"); 				//���� ��� �÷��̾�� �Ȱ���. 
		while(cardSum[n_user]<17)
		{
			
			round_try_for_dealer++;
			printUserCardStatus(n_user,round_try_for_dealer);		//���⼭ ������ ���ܿԴ� ī�带 ������ 
			cardSum[n_user]=calcStepResult(n_user,round_try_for_dealer);
			if(cardSum[n_user]==21)
				break;
			else if(cardSum[n_user]>21)
				break;	
			else if(cardSum[n_user]<17)//������ ī�带 ���� �� ����. 
			{
				printf("������ ������ �� �̾ҽ��ϴ�.");
				offerCardsplus(n_user,round_try_for_dealer);
			}
			else if(cardSum[n_user]>17&&cardSum[n_user]<21)
			{
				printf("������ �׸� �̱⸦ �����߽��ϴ�.");
			}
			cardNumber[n_user]=round_try_for_dealer+1;
		}
		printf("������ ���� %d �Դϴ�",cardSum[n_user]);
		for (i=0;i<n_user;i++)
		{
			CheckResult(i);			//��� ���� ����. �÷��̾ �̰���� �� �̰������ Ȯ����. 
		}
		
		printf("��������� �ڻ� ����� ������ �����ϴ�.");
		for(i=0;i<n_user;i++)
		{
			printf("�÷��̾�%i�� ���� �ڻ��� %d �Դϴ�",i,now_money[i]);		//�ڻ� ����� �˷���. 
		}
		
		for(i=0;i<=n_user+1;i++)			//��������� ��� �÷��̾��� ī�尳���� ���� ����. 
		{
			until_cardnum+=cardNumber[i];
		}
		
		if(until_cardnum>=52)				//���� ī���� ������ 52���� �Ѿ��� ��� ī�� Ʈ������ ī�尡 ��� ������ ���� �ǹ��ϹǷ�  
		{									//������ ������ ��. 
			gameend = 1;
		}
		for(i=0;i<n_user;i++)
		{
			if(now_money[i]<=0)		//���� �÷��̾� �Ѹ��̶� ���� ���ٸ� ������ ������ ��.  
			{						// �� �� ��� ��� gameend ���� 1�� �޾Ƽ� do-while �� ������ gameend=0�� ���� �������� ���ϹǷ� �ݺ��� ����. 
				gameend = 1;
			}
		}
		
	}while(gameend == 0); //������ ������ ���� �ǹ���. 
	
	int winner_money;
	winner_money = checkWinner(n_user);			//���ڸ� Ȯ����. �� checkWinnter�Լ��� ������ ���� Ȯ���ϴ� �Լ��̹Ƿ� 
	for(i=0;i<n_user;i++)						//������ ���� ���� Ȯ���ϰ� �� ���� ���� ���ڸ� Ȯ����. 
	{
		if(winner_money==now_money[i])
		{
			printf("���ڴ� �÷��̾�%i�Դϴ�.",i);
			break;								//���ڸ� Ȯ�������� �� ���Ĵ� �� �ʿ䰡 �����Ƿ� ����... 
		}
	}	
		
	return 0;
}
