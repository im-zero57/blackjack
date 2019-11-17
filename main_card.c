#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//받은 숫자가 의미하는 카드의 진짜 숫자를 정의---------
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

//할당된 숫자가 의미하는 카드의 모양과 숫자를 알려줌 

void printCard(int card) {
	
	int ch_card;
	if(card==1)
	{
		printf("♠ACE"); 
	}
	else if(card>1&&card<11)
	{
		printf("♠%d",card-1);
	}
	else if(card==11)
	{
		printf("♠king");	
	}
	else if(card==12)
	{
		printf("♠Queen");
	} 
	else if(card==13)
	{
		printf("♠Jack");
	}
	else if(card==14)
	{
		printf("◇ACE");
	}
	else if(card>14&&card<24)
	{
		printf("◇%d",card-13);
	}
	else if(card==24)
	{
		printf("◇King");
	}
	else if(card==25)
	{
		printf("◇Queen");
	}
	else if(card==26)
	{
		printf("◇Jack");
	}
	else if(card==27)
	{
		printf("♡ACE");
	}
	else if(card>27&&card<37)
	{
		printf("♡%d",card-28);
	}
	else if(card==37)
	{
		printf("♡King");
	}
	else if(card==38)
	{
		printf("♡Queen");
	}
	else if(card==39)
	{
		printf("♡Jack");
	}
	else if(card==40)
	{
		printf("♣ACE");
	}
	else if(card>40&&card<50)
	{
		printf("♣%d",card-39);
	}
	else if(card==50)
	{
		printf("♣King");
	}
	else if(card==51)
	{
		printf("♣Queen");
	}
	else if(card==52)
	{
		printf("♣Jack");												 
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
		cardhold[i][0] = pullCard(i);				//플레이어 모두에게 제공되는 두가지 카드 중 첫번째 카드. 
		cardhold[i][1] = pullCard(i+5);				//플레이어 모두에게 제공되는 두가지 카드 중 두번째 카드. 
	}
	cardhold[N_MAX_USER][0] = pullCard(N_MAX_USER-1);	//딜러에게 제공하는 두가지 카드 중 첫번째 카드. 
	cardhold[N_MAX_USER][1] = pullCard(N_MAX_USER);		//딜러에게 제공하는 두가지 카드 중 두번째 카드. 
	
	return;
}

//플레이어가 'go'를 선택할 경우 제공되는 추가의 카드 
void offerCardsplus(int player,int turn){
	int i;
	for (i=3;i<turn+2;i++)							 
		cardhold[player][i] = pullCard(i+10);		//플레이어에게 제공되는 셋,넷,,, 그 이상의 카드. 이 모든 카드는 pullCard 함수로 받는다. 
}

//카드를 나눠줌 
int pullCard(int number){
	int i, check_number, return_number, card;
	
	do{												//플레이어에게 제공되는 카드를 의미함. 
		Number[number]=rand()%N_CARD;				//CARDTRAY에 임의로 값을 할당하고 pullcard함수에서는 그 CARDTRAY의 배열이름을 임의로 할당해서 가져옴. 
		for(i=0;i<number;i++)						//이 경우 중복을 피하고자 임시로 Number배열에 임의로 할당된 숫자를 저장하고 만약 임의로 할당된 
		{											 
			if(Number[number]=Number[i])
			{
				check_number=1;						//숫자가 같을 경우 다시 할당받도록 함.  
			}
			else
			{
				check_number=2;
			}
		}
	}while(check_number==1);

	card = CARDTRAY[Number[number]];				//최종적으로 숫자가 다를 경우에만 CARDTRAY에 들어갈 수 있음. 
	return card;
}

void printCardInitialStatus(void){					//초기의 카드를 알려주는 함수. 
	int i;											//'나'의 카드를 알려줌. 
	printf("본인의 카드 : ");
	printCard(cardhold[0][0]);
	printCard(cardhold[0][1]);
	printf("------------------------------------------");
	for (i=1;i<with_player;i++)						//함께 할 플레이어 카드를 알려줌. 
	{
		printf("i 플레이어의 카드: ");
		printCard(cardhold[i][0]);
		printCard(cardhold[i][1]);
		printf("---------------------------------------");
	}
	printf("딜러의 카드 : ");						//딜러의 카드를 알려줌. 
	printf("알 수 없음");							//딜러의 카드는 한가지만 알려줄 수 있음. 
	printCard(cardhold[N_MAX_USER][0]);
}

void printUserCardStatus(int user, int cardcnt){
	int i;											//각 단계에서 새로 뽑은 카드를 추가해서 알려줌. 
	
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
