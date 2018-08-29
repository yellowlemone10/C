#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
#include<string.h>

#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define ENTER 13
void start();
void keyTF();
void game();
void load();
void help();
void hand();
void hand2();
void thmPoint(); // 체력 마력 설명 페이지
void tmePoint(); // 경험치,경험치 최대창 설명페이지
void tmsPoint(); // 공포수치, 최데공포수치 설명창
void tjob();
void tselect_numer();
int jobs(int Plevel, int Pmind, int Phpoint, int Pmpoint, int Pwork, int Phunter, int Preligion);

int level = 1;
char name[100];
int hPoint = 50;//체력 
int mPoint = 0;//마력 
int Epoint = 0;//경험치
int smile = 0;//공포수치 
int money = 0;
char job[100] = "모험가";
int mind = 0;//성향 
int maxEpoint = 10;//경험치 창 이거 넘으면 레벨업 
int maxSmile = 100;//공포수치 창 이거 넘으면 죽음 
int maxhPoint = 50;
int maxmPoint = 0;
void gotoxy(int x, int y){
	COORD pos = {x - 1, y - 1};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int main(){
	keyTF();
	system("mode con cols=50 lines=30");
	start(); 
}

void start(){
	int i;
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 3);
	printf("\n   ■■■  ■  ■  ■■■\n");
	printf("     ■    ■■■  ■ ■ \n");
	printf("     ■    ■  ■  ■■■\n\n");
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 14);
	printf("      ■            ■      ■■■  ■■■■■\n");
	printf("      ■          ■  ■   ■           ■   \n");
	printf("      ■         ■    ■   ■■■      ■   \n");
	printf("      ■         ■■■■        ■     ■   \n");
	printf("      ■■■■   ■    ■   ■■■      ■   \n\n");
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 2);
	printf("     ■    ■   ■■■   ■■■      ■■\n");
	printf("     ■    ■   ■       ■   ■    ■  ■\n");
	printf("     ■■■■   ■■■   ■■■    ■    ■\n");
	printf("     ■    ■   ■       ■   ■    ■  ■\n");
	printf("     ■    ■   ■■■   ■    ■    ■■\n\n\n\n");
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 7);
	printf("                   1.게임시작\n\n\n");
	printf("                   2.이어하기\n\n\n");
	hand();
	
}

void keyTF(){
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
    cursorInfo.dwSize = 1;
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

void hand(){
	int key;
	static int y = 20;
	gotoxy(17, y); 
	printf("☞");
	while(1){
		if(kbhit()){
			key = getch();
			if(key == 13){
				if(y == 20){
					system("cls");
					printf("\n\n\n\n\n       이름을 입력해 주세요:");
					scanf("%s", &name);
					system("cls");
					printf("\n\n\n                  안녕하세요 %s님\n         혹시 The Last Hero가 처음이시라면\n             튜토리얼을 들으시겠어요?\n\n", name);
					printf("\n\n\n\n\n                      1.수락\n"); 
					printf("\n\n\n\n\n                      2.거절");
				while (1){
       				char ch = _getch();
        			if (ch == '1'){
           				help();
            			break;
        			}
        			if (ch == '2'){
        				game();
						break;
					}
        				
   				}				
				}
				else if(y == 23){
					system("cls");
					load();
				}
			}
			if(key == 224 || key == 0)
			{
				key = getch();
				switch(key){
					case DOWN:
						if(y <= 20){
							system("cls");
							y += 3;
							start();
						}	
						break;
					case UP:
						if(y >= 23 ){
							system("cls");
							y -= 3;
							start();
						}
						break;
					default:
						break;
				}
			}
		}
	}
}

void hand2(){
	int key;
	static int y = 18; //2씩
	gotoxy(17, y); 
	printf("☞");
	while(1){
		if(kbhit()){
			key = getch();
			if(key == 13){
				if(y == 18){
					system("cls");				
				}
				else if(y == 20){
					system("cls");
				}
				else if(y == 22){
					system("cls");
				}
				else if(y == 24){
					system("cls");
				}
			}
			if(key == 224 || key == 0)
			{
				key = getch();
				switch(key){
					case DOWN:
						if(y <= 22){
							system("cls");
							y += 2;
							game();
						}	
						break;
					case UP:
						if(y >= 20){
							system("cls");
							y -= 2;
							game();
						}
						break;
					default:
						break;
				}
			}
		}
	}
}

void game(){
	int key; 
	system("cls"); 
	printf("■■■■■■■■■■■■■■■■■■■■■■■■■\n");
	printf("\n\n");
	printf("     이름: %s", name);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 2);
	printf("     레벨: %d", level);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 3);
	printf("     경험치: %d/%d     \n\n\n", Epoint, maxEpoint);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 14);
	printf("          돈 : %d", money);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 5);
	printf("     공포수치 : %d/%d\n\n\n", smile, maxSmile);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 8);
	printf("         성향:%d", mind);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 4);
	printf("     체력: %d/%d", hPoint, maxhPoint);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 1);
	printf("     마력: %d/%d", mPoint, maxmPoint);
	printf("\n\n\n");
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 6);
	printf("                  직업: %s\n\n", job);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 7);
	printf("■■■■■■■■■■■■■■■■■■■■■■■■■\n\n\n");
	printf("                    1.던전가기\n\n");
	printf("                    2.상점가기\n\n");
	printf("                    3.신전가기\n\n");
	printf("                    4.전직하기\n\n");
	hand2(); 
}

void load(){
	printf("로드창");
}

void help(){
	int key;
	system("cls");
	printf("\n\n\n\n\n\n      The Last Hero의 튜토리얼을 시작합니다\n\n");
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 14);
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n                                          ENTER☞");
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 7);
	while(1){
		if(kbhit()){
			key = getch();
			if(key == 13){
				break;
			}
		}
	}
	tmePoint();
}

void tmePoint(){
	int key; 
	system("cls"); 
	printf("■■■■■■■■■■■■■■■■■■■■■■■■■\n");
	printf("\n\n");
	printf("     이름: %s", name);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 2);
	printf("     레벨: %d", level);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 3);
	printf("     경험치: %d/%d     \n\n\n", Epoint, maxEpoint);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 14);
	printf("          돈 : %d", money);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 5);
	printf("     공포수치 : %d/%d\n\n\n", smile, maxSmile);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 8);
	printf("         성향:%d", mind);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 4);
	printf("     체력: %d/%d", hPoint, maxhPoint);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 1);
	printf("     마력: %d/%d", mPoint, maxmPoint);
	printf("\n\n\n");
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 6);
	printf("                  직업: %s\n\n", job);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 7);
	printf("■■■■■■■■■■■■■■■■■■■■■■■■■\n\n\n");
	printf("                 지금 보이시는 창은\n\n        앞으로 보게 되실 메인 게임 창 입니다\n\n");
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 14);
	printf("\n\n\n\n\n\n\n\n                                          ENTER☞");
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 7);
	while(1){
		if(kbhit()){
			key = getch();
			if(key == 13){
				break;
			}
		}
	}	
	system("cls"); 
	printf("■■■■■■■■■■■■■■■■■■■■■■■■■\n");
	printf("\n\n");
	printf("     이름: %s", name);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 7);
	printf("  ☞ ");
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 2);
	printf("레벨: %d", level);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 7);
	printf("  ☞ ");
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 3);
	printf("경험치: %d/%d     \n\n\n", Epoint, maxEpoint);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 14);
	printf("          돈 : %d", money);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 5);
	printf("     공포수치 : %d/%d\n\n\n", smile, maxSmile);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 8);
	printf("         성향:%d", mind);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 4);
	printf("     체력: %d/%d", hPoint, maxhPoint);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 1);
	printf("     마력: %d/%d", mPoint, maxmPoint);
	printf("\n\n\n");
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 6);
	printf("                  직업: %s\n\n", job);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 7);
	printf("■■■■■■■■■■■■■■■■■■■■■■■■■\n\n\n");
	printf("             위 손가락이 가리키는 것은\n\n      레벨과 경험치 그리고  경험요구치 입니다\n\n 경험요구치까지 경험치를 쌓게 되면 레벨업을 합니다\n\n");
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 14);
	printf("\n\n\n\n\n\n                                          ENTER☞");
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 7);
	while(1){
		if(kbhit()){
			key = getch();
			if(key == 13){
				break;
			}
		}
	}
	tmsPoint();
}

void tmsPoint(){
	int key; 
	system("cls"); 
	printf("■■■■■■■■■■■■■■■■■■■■■■■■■\n");
	printf("\n\n");
	printf("     이름: %s", name);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 2);
	printf("     레벨: %d", level);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 3);
	printf("     경험치: %d/%d     \n\n\n", Epoint, maxEpoint);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 14);
	printf("          돈 : %d", money);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 5);
	printf("     공포수치 : %d/%d\n\n\n", smile, maxSmile);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 8);
	printf("         성향:%d", mind);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 4);
	printf("     체력: %d/%d", hPoint, maxhPoint);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 1);
	printf("     마력: %d/%d", mPoint, maxmPoint);
	printf("\n\n\n");
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 6);
	printf("                  직업: %s\n\n", job);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 7);
	printf("■■■■■■■■■■■■■■■■■■■■■■■■■\n\n\n");
	printf("                     다음은\n\n               돈과 공포수치 입니다\n\n");
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 14);
	printf("\n\n\n\n\n\n\n\n                                          ENTER☞");
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 7);
	while(1){
		if(kbhit()){
			key = getch();
			if(key == 13){
				break;
			}
		}
	}	
	system("cls"); 
	printf("■■■■■■■■■■■■■■■■■■■■■■■■■\n");
	printf("\n\n");
	printf("     이름: %s", name);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 2);
	printf("     레벨: %d", level);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 3);
	printf("     경험치: %d/%d     \n\n\n", Epoint, maxEpoint);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 7);
	printf("       ☞ ");
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 14);
	printf("돈 : %d", money);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 5);
	printf("     공포수치 : %d/%d\n\n\n", smile, maxSmile);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 8);
	printf("         성향:%d", mind);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 4);
	printf("     체력: %d/%d", hPoint, maxhPoint);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 1);
	printf("     마력: %d/%d", mPoint, maxmPoint);
	printf("\n\n\n");
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 6);
	printf("                  직업: %s\n\n", job);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 7);
	printf("■■■■■■■■■■■■■■■■■■■■■■■■■\n\n\n"); 
	printf("              돈은 던전에 입장할때나\n\n                 신전에 기부할때\n\n             상점에서 물품을 구매할때\n\n            그리고 전직할때 사용합니다\n\n");
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 14);
	printf("\n\n\n\n                                          ENTER☞");
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 7);
	while(1){
		if(kbhit()){
			key = getch();
			if(key == 13){
				break;
			}
		}
	}	
	system("cls");
	printf("■■■■■■■■■■■■■■■■■■■■■■■■■\n");
	printf("\n\n");
	printf("     이름: %s", name);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 2);
	printf("     레벨: %d", level);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 3);
	printf("     경험치: %d/%d     \n\n\n", Epoint, maxEpoint);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 14);
	printf("          돈 : %d", money);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 7);
	printf("  ☞ ");
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 5);
	printf("공포수치 : %d/%d\n\n\n", smile, maxSmile);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 8);
	printf("         성향:%d", mind);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 4);
	printf("     체력: %d/%d", hPoint, maxhPoint);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 1);
	printf("     마력: %d/%d", mPoint, maxmPoint);
	printf("\n\n\n");
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 6);
	printf("                  직업: %s\n\n", job);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 7);
	printf("■■■■■■■■■■■■■■■■■■■■■■■■■\n\n\n");
	printf("                    공포수치는\n\n        옆의 최대치인 100까지 차면 죽게 되고\n\n       최대치는 플레이어의 캐릭터가 강해지거나\n\n         특정한 아이템을 착용하면 늘어납니다");
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 14);
	printf("\n\n\n\n\n\n                                          ENTER☞");
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 7);
	while(1){
		if(kbhit()){
			key = getch();
			if(key == 13){
				break;
			}
		}
	}	
	thmPoint();
}

void thmPoint(){
	int key; 
	system("cls"); 
	printf("■■■■■■■■■■■■■■■■■■■■■■■■■\n");
	printf("\n\n");
	printf("     이름: %s", name);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 2);
	printf("     레벨: %d", level);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 3);
	printf("     경험치: %d/%d     \n\n\n", Epoint, maxEpoint);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 14);
	printf("          돈 : %d", money);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 5);
	printf("     공포수치 : %d/%d\n\n\n", smile, maxSmile);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 8);
	printf("         성향:%d", mind);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 4);
	printf("     체력: %d/%d", hPoint, maxhPoint);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 1);
	printf("     마력: %d/%d", mPoint, maxmPoint);
	printf("\n\n\n");
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 6);
	printf("                  직업: %s\n\n", job);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 7);
	printf("■■■■■■■■■■■■■■■■■■■■■■■■■\n\n\n");
	printf("                     다음으로\n\n            성향, 체력 그리고 마력입니다\n\n");
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 14);
	printf("\n\n\n\n\n\n\n\n                                          ENTER☞");
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 7);
	while(1){
		if(kbhit()){
			key = getch();
			if(key == 13){
				break;
			}
		}
	}	
	system("cls"); 
	printf("■■■■■■■■■■■■■■■■■■■■■■■■■\n");
	printf("\n\n");
	printf("     이름: %s", name);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 2);
	printf("     레벨: %d", level);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 3);
	printf("     경험치: %d/%d     \n\n\n", Epoint, maxEpoint);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 14);
	printf("          돈 : %d", money);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 5);
	printf("     공포수치 : %d/%d\n\n\n", smile, maxSmile);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 7);
	printf("      ☞ ");
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 8);
	printf("성향:%d", mind);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 4);
	printf("     체력: %d/%d", hPoint, maxhPoint);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 1);
	printf("     마력: %d/%d", mPoint, maxmPoint);
	printf("\n\n\n");
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 6);
	printf("                  직업: %s\n\n", job);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 7);
	printf("■■■■■■■■■■■■■■■■■■■■■■■■■\n\n\n");
	printf("        성향은 말그대로 캐릭터의 성향입니다\n\n          캐릭터의 행동으로 인해 결정되고\n\n    +는 선 -는 악 이며 성향에따라 고를 수 있는\n\n      특수한 직업이나 스킬, 아이템이 있습니다");
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 14);
	printf("\n\n\n\n\n\n                                          ENTER☞");
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 7);
	while(1){
		if(kbhit()){
			key = getch();
			if(key == 13){
				break;
			}
		}
	}	
	system("cls"); 
	printf("■■■■■■■■■■■■■■■■■■■■■■■■■\n");
	printf("\n\n");
	printf("     이름: %s", name);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 2);
	printf("     레벨: %d", level);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 3);
	printf("     경험치: %d/%d     \n\n\n", Epoint, maxEpoint);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 14);
	printf("          돈 : %d", money);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 5);
	printf("     공포수치 : %d/%d\n\n\n", smile, maxSmile);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 8);
	printf("         성향:%d", mind);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 7);
	printf("  ☞ ");
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 4);
	printf("체력: %d/%d", hPoint, maxhPoint);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 7);
	printf("  ☞ ");
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 1);
	printf("마력: %d/%d", mPoint, maxmPoint);
	printf("\n\n\n");
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 6);
	printf("                  직업: %s\n\n", job);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 7);
	printf("■■■■■■■■■■■■■■■■■■■■■■■■■\n\n\n");
	printf("     체력과 마력은 가장 기초적인 에너지 입니다\n\n         체력이 없다면 케릭터는 사망하고\n\n            마력이 없다면 액티브 스킬과\n\n            마법을 사용 할 수 없습니다\n\n");
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 14);
	printf("\n\n\n\n                                          ENTER☞");
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 7);
	while(1){
		if(kbhit()){
			key = getch();
			if(key == 13){
				break;
			}
		}
	}	
	tjob();
}

void tjob(){
	int key; 
	system("cls"); 
	printf("■■■■■■■■■■■■■■■■■■■■■■■■■\n");
	printf("\n\n");
	printf("     이름: %s", name);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 2);
	printf("     레벨: %d", level);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 3);
	printf("     경험치: %d/%d     \n\n\n", Epoint, maxEpoint);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 14);
	printf("          돈 : %d", money);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 5);
	printf("     공포수치 : %d/%d\n\n\n", smile, maxSmile);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 8);
	printf("         성향:%d", mind);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 4);
	printf("     체력: %d/%d", hPoint, maxhPoint);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 1);
	printf("     마력: %d/%d", mPoint, maxmPoint);
	printf("\n\n\n");
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 6);
	printf("                  직업: %s\n\n", job);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 7);
	printf("■■■■■■■■■■■■■■■■■■■■■■■■■\n\n\n");
	printf("                    마지막으로\n\n                    직업입니다\n\n");
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 14);
	printf("\n\n\n\n\n\n\n\n                                          ENTER☞");
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 7);
	while(1){
		if(kbhit()){
			key = getch();
			if(key == 13){
				break;
			}
		}
	}	
	system("cls"); 
	printf("■■■■■■■■■■■■■■■■■■■■■■■■■\n");
	printf("\n\n");
	printf("     이름: %s", name);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 2);
	printf("     레벨: %d", level);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 3);
	printf("     경험치: %d/%d     \n\n\n", Epoint, maxEpoint);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 14);
	printf("          돈 : %d", money);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 5);
	printf("     공포수치 : %d/%d\n\n\n", smile, maxSmile);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 8);
	printf("         성향:%d", mind);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 4);
	printf("     체력: %d/%d", hPoint, maxhPoint);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 1);
	printf("     마력: %d/%d", mPoint, maxmPoint);
	printf("\n\n\n");
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 7);
	printf("               ☞ ");
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 6);
	printf("직업: %s\n\n", job);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 7);
	printf("■■■■■■■■■■■■■■■■■■■■■■■■■\n\n\n");
	printf("        직업은 당신이 한 행동 업적에 따라서\n\n          고를 수 있는 직업이 달라집니다\n\n근접무기를 자주쓰면 근접직업이 나올 확률이 커지고\n\n 아니면 정말 터무니없는 직업이 나올 수도 있습니다");
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 14);
	printf("\n\n\n\n                                          ENTER☞");
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 7);
	while(1){
		if(kbhit()){
			key = getch();
			if(key == 13){
				break;
			}
		}
	}	
	system("cls");
	printf("\n\n\n\n\n\n         그럼 이상 튜토리얼을 마치겠습니다\n\n                   건투를 빕니다");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n                                          ENTER☞");
	while(1){
		if(kbhit()){
			key = getch();
			if(key == 13){
				break;
			}
		}
	}	
	game();
	
}
