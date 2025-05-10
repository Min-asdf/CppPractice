//헤더
#include <iostream>
//랜덤함수 쓰기 위한 헤더
#include <ctime>

//함수 선언
//player RSP 선택 함수
char getPlayerChoice();
//computer RSP 선택 함수
char getComputerChoice();
//player, computer RSP 선택 보여주는 함수
void showChoice(char choice);
//승자 결정 함수
void chooseWinner(char player, char computer);

//메인 함수
int main() {
	//변수 선언
	char player;
	char computer;

	std::cout << "Rock-Scissors-Paper Game!\n\n";
	
	//playerChoice 입력
	player = getPlayerChoice();
	//입력받은 playerChoice 보여줌
	std::cout << "You choice: ";
	showChoice(player);

	//computerChoice 입력
	computer = getComputerChoice();
	std::cout << "Computer choice: ";
	//입력받은 computerChoice 보여줌
	showChoice(computer);

	//승자 결정 함수
	chooseWinner(player, computer);

	return 0;
}

//player RSP 선택 함수
char getPlayerChoice() {
	//변수 선언
	char player;

	//player가 r, s, p 중 1개 입력할 때까지 반복
	do {
	std::cout << "Choose one of the following\n";
	std::cout << "********************\n";
	std::cout << "'r' for rock\n";
	std::cout << "'s' for scissors\n";
	std::cout << "'p' for paper\n";
	std::cin >> player;
	}while(player != 'r' && player != 'p' && player != 's');

	//입력된 RSP return
	return player;
}

//computer RSP 선택 함수
char getComputerChoice() {
	//랜덤 함수
	srand(time(0));
	int num = rand() % 3 + 1;

	//computer RSP return
	switch (num) {
	case 1: return 'r';
	case 2: return 's';
	case 3: return 'p';
	}

	return 0;
}

//player, computer RSP 선택 보여주는 함수
void showChoice(char choice) {
	//player, computer 입력된 r, s, p 를 Rock, Scissors, Paper 로 바꿔서 보여줌
	switch (choice) {
	case 'r': std::cout << "Rock\n";
		break;
	case 's': std::cout << "Scissors\n";
		break;
	case 'p': std::cout << "Paper\n";
		break;
	}
}

//승자 결정 함수(player, computer RSP 입력 받음)
void chooseWinner(char player, char computer) {
	//player RSP와 computer RSP를 받아와서 무승부, 패배, 승리 결정
	switch (player) {
		//player가 Rock을 선택했을 때
		case 'r': if (computer == 'r') {
			std::cout << "It's a tie!\n";
		}
				else if (computer == 'p') {
			std::cout << "You lose!\n";
		}
				else {
			std::cout << "You win!\n";
		}
				break;
		//player가 Scissors를 선택했을 때
		case 's': if (computer == 'r') {
			std::cout << "You lose!\n";
		}
				else if (computer == 'p') {
			std::cout << "You win!\n";
		}
				else {
			std::cout << "It's a tie!\n";
		}
				break;
		//player가 Paper을 선택했을 때
		case 'p': if (computer == 'r') {
			std::cout << "You win!\n";
		}
				else if (computer == 'p') {
			std::cout << "It's a tie!\n";
		}
				else {
			std::cout << "You lose!\n";
		}
				break;
	}
}
