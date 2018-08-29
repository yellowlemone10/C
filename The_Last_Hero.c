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
void thmPoint(); // ü�� ���� ���� ������
void tmePoint(); // ����ġ,����ġ �ִ�â ����������
void tmsPoint(); // ������ġ, �ֵ�������ġ ����â
void tjob();
void tselect_numer();
int jobs(int Plevel, int Pmind, int Phpoint, int Pmpoint, int Pwork, int Phunter, int Preligion);

int level = 1;
char name[100];
int hPoint = 50;//ü�� 
int mPoint = 0;//���� 
int Epoint = 0;//����ġ
int smile = 0;//������ġ 
int money = 0;
char job[100] = "���谡";
int mind = 0;//���� 
int maxEpoint = 10;//����ġ â �̰� ������ ������ 
int maxSmile = 100;//������ġ â �̰� ������ ���� 
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
	printf("\n   ����  ��  ��  ����\n");
	printf("     ��    ����  �� �� \n");
	printf("     ��    ��  ��  ����\n\n");
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 14);
	printf("      ��            ��      ����  ������\n");
	printf("      ��          ��  ��   ��           ��   \n");
	printf("      ��         ��    ��   ����      ��   \n");
	printf("      ��         �����        ��     ��   \n");
	printf("      �����   ��    ��   ����      ��   \n\n");
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 2);
	printf("     ��    ��   ����   ����      ���\n");
	printf("     ��    ��   ��       ��   ��    ��  ��\n");
	printf("     �����   ����   ����    ��    ��\n");
	printf("     ��    ��   ��       ��   ��    ��  ��\n");
	printf("     ��    ��   ����   ��    ��    ���\n\n\n\n");
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 7);
	printf("                   1.���ӽ���\n\n\n");
	printf("                   2.�̾��ϱ�\n\n\n");
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
	printf("��");
	while(1){
		if(kbhit()){
			key = getch();
			if(key == 13){
				if(y == 20){
					system("cls");
					printf("\n\n\n\n\n       �̸��� �Է��� �ּ���:");
					scanf("%s", &name);
					system("cls");
					printf("\n\n\n                  �ȳ��ϼ��� %s��\n         Ȥ�� The Last Hero�� ó���̽ö��\n             Ʃ�丮���� �����ðھ��?\n\n", name);
					printf("\n\n\n\n\n                      1.����\n"); 
					printf("\n\n\n\n\n                      2.����");
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
	static int y = 18; //2��
	gotoxy(17, y); 
	printf("��");
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
	printf("��������������������������\n");
	printf("\n\n");
	printf("     �̸�: %s", name);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 2);
	printf("     ����: %d", level);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 3);
	printf("     ����ġ: %d/%d     \n\n\n", Epoint, maxEpoint);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 14);
	printf("          �� : %d", money);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 5);
	printf("     ������ġ : %d/%d\n\n\n", smile, maxSmile);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 8);
	printf("         ����:%d", mind);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 4);
	printf("     ü��: %d/%d", hPoint, maxhPoint);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 1);
	printf("     ����: %d/%d", mPoint, maxmPoint);
	printf("\n\n\n");
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 6);
	printf("                  ����: %s\n\n", job);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 7);
	printf("��������������������������\n\n\n");
	printf("                    1.��������\n\n");
	printf("                    2.��������\n\n");
	printf("                    3.��������\n\n");
	printf("                    4.�����ϱ�\n\n");
	hand2(); 
}

void load(){
	printf("�ε�â");
}

void help(){
	int key;
	system("cls");
	printf("\n\n\n\n\n\n      The Last Hero�� Ʃ�丮���� �����մϴ�\n\n");
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 14);
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n                                          ENTER��");
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
	printf("��������������������������\n");
	printf("\n\n");
	printf("     �̸�: %s", name);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 2);
	printf("     ����: %d", level);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 3);
	printf("     ����ġ: %d/%d     \n\n\n", Epoint, maxEpoint);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 14);
	printf("          �� : %d", money);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 5);
	printf("     ������ġ : %d/%d\n\n\n", smile, maxSmile);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 8);
	printf("         ����:%d", mind);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 4);
	printf("     ü��: %d/%d", hPoint, maxhPoint);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 1);
	printf("     ����: %d/%d", mPoint, maxmPoint);
	printf("\n\n\n");
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 6);
	printf("                  ����: %s\n\n", job);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 7);
	printf("��������������������������\n\n\n");
	printf("                 ���� ���̽ô� â��\n\n        ������ ���� �ǽ� ���� ���� â �Դϴ�\n\n");
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 14);
	printf("\n\n\n\n\n\n\n\n                                          ENTER��");
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
	printf("��������������������������\n");
	printf("\n\n");
	printf("     �̸�: %s", name);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 7);
	printf("  �� ");
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 2);
	printf("����: %d", level);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 7);
	printf("  �� ");
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 3);
	printf("����ġ: %d/%d     \n\n\n", Epoint, maxEpoint);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 14);
	printf("          �� : %d", money);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 5);
	printf("     ������ġ : %d/%d\n\n\n", smile, maxSmile);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 8);
	printf("         ����:%d", mind);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 4);
	printf("     ü��: %d/%d", hPoint, maxhPoint);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 1);
	printf("     ����: %d/%d", mPoint, maxmPoint);
	printf("\n\n\n");
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 6);
	printf("                  ����: %s\n\n", job);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 7);
	printf("��������������������������\n\n\n");
	printf("             �� �հ����� ����Ű�� ����\n\n      ������ ����ġ �׸���  ����䱸ġ �Դϴ�\n\n ����䱸ġ���� ����ġ�� �װ� �Ǹ� �������� �մϴ�\n\n");
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 14);
	printf("\n\n\n\n\n\n                                          ENTER��");
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
	printf("��������������������������\n");
	printf("\n\n");
	printf("     �̸�: %s", name);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 2);
	printf("     ����: %d", level);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 3);
	printf("     ����ġ: %d/%d     \n\n\n", Epoint, maxEpoint);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 14);
	printf("          �� : %d", money);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 5);
	printf("     ������ġ : %d/%d\n\n\n", smile, maxSmile);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 8);
	printf("         ����:%d", mind);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 4);
	printf("     ü��: %d/%d", hPoint, maxhPoint);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 1);
	printf("     ����: %d/%d", mPoint, maxmPoint);
	printf("\n\n\n");
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 6);
	printf("                  ����: %s\n\n", job);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 7);
	printf("��������������������������\n\n\n");
	printf("                     ������\n\n               ���� ������ġ �Դϴ�\n\n");
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 14);
	printf("\n\n\n\n\n\n\n\n                                          ENTER��");
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
	printf("��������������������������\n");
	printf("\n\n");
	printf("     �̸�: %s", name);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 2);
	printf("     ����: %d", level);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 3);
	printf("     ����ġ: %d/%d     \n\n\n", Epoint, maxEpoint);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 7);
	printf("       �� ");
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 14);
	printf("�� : %d", money);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 5);
	printf("     ������ġ : %d/%d\n\n\n", smile, maxSmile);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 8);
	printf("         ����:%d", mind);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 4);
	printf("     ü��: %d/%d", hPoint, maxhPoint);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 1);
	printf("     ����: %d/%d", mPoint, maxmPoint);
	printf("\n\n\n");
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 6);
	printf("                  ����: %s\n\n", job);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 7);
	printf("��������������������������\n\n\n"); 
	printf("              ���� ������ �����Ҷ���\n\n                 ������ ����Ҷ�\n\n             �������� ��ǰ�� �����Ҷ�\n\n            �׸��� �����Ҷ� ����մϴ�\n\n");
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 14);
	printf("\n\n\n\n                                          ENTER��");
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
	printf("��������������������������\n");
	printf("\n\n");
	printf("     �̸�: %s", name);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 2);
	printf("     ����: %d", level);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 3);
	printf("     ����ġ: %d/%d     \n\n\n", Epoint, maxEpoint);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 14);
	printf("          �� : %d", money);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 7);
	printf("  �� ");
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 5);
	printf("������ġ : %d/%d\n\n\n", smile, maxSmile);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 8);
	printf("         ����:%d", mind);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 4);
	printf("     ü��: %d/%d", hPoint, maxhPoint);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 1);
	printf("     ����: %d/%d", mPoint, maxmPoint);
	printf("\n\n\n");
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 6);
	printf("                  ����: %s\n\n", job);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 7);
	printf("��������������������������\n\n\n");
	printf("                    ������ġ��\n\n        ���� �ִ�ġ�� 100���� ���� �װ� �ǰ�\n\n       �ִ�ġ�� �÷��̾��� ĳ���Ͱ� �������ų�\n\n         Ư���� �������� �����ϸ� �þ�ϴ�");
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 14);
	printf("\n\n\n\n\n\n                                          ENTER��");
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
	printf("��������������������������\n");
	printf("\n\n");
	printf("     �̸�: %s", name);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 2);
	printf("     ����: %d", level);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 3);
	printf("     ����ġ: %d/%d     \n\n\n", Epoint, maxEpoint);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 14);
	printf("          �� : %d", money);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 5);
	printf("     ������ġ : %d/%d\n\n\n", smile, maxSmile);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 8);
	printf("         ����:%d", mind);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 4);
	printf("     ü��: %d/%d", hPoint, maxhPoint);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 1);
	printf("     ����: %d/%d", mPoint, maxmPoint);
	printf("\n\n\n");
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 6);
	printf("                  ����: %s\n\n", job);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 7);
	printf("��������������������������\n\n\n");
	printf("                     ��������\n\n            ����, ü�� �׸��� �����Դϴ�\n\n");
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 14);
	printf("\n\n\n\n\n\n\n\n                                          ENTER��");
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
	printf("��������������������������\n");
	printf("\n\n");
	printf("     �̸�: %s", name);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 2);
	printf("     ����: %d", level);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 3);
	printf("     ����ġ: %d/%d     \n\n\n", Epoint, maxEpoint);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 14);
	printf("          �� : %d", money);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 5);
	printf("     ������ġ : %d/%d\n\n\n", smile, maxSmile);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 7);
	printf("      �� ");
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 8);
	printf("����:%d", mind);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 4);
	printf("     ü��: %d/%d", hPoint, maxhPoint);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 1);
	printf("     ����: %d/%d", mPoint, maxmPoint);
	printf("\n\n\n");
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 6);
	printf("                  ����: %s\n\n", job);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 7);
	printf("��������������������������\n\n\n");
	printf("        ������ ���״�� ĳ������ �����Դϴ�\n\n          ĳ������ �ൿ���� ���� �����ǰ�\n\n    +�� �� -�� �� �̸� ���⿡���� �� �� �ִ�\n\n      Ư���� �����̳� ��ų, �������� �ֽ��ϴ�");
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 14);
	printf("\n\n\n\n\n\n                                          ENTER��");
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
	printf("��������������������������\n");
	printf("\n\n");
	printf("     �̸�: %s", name);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 2);
	printf("     ����: %d", level);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 3);
	printf("     ����ġ: %d/%d     \n\n\n", Epoint, maxEpoint);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 14);
	printf("          �� : %d", money);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 5);
	printf("     ������ġ : %d/%d\n\n\n", smile, maxSmile);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 8);
	printf("         ����:%d", mind);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 7);
	printf("  �� ");
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 4);
	printf("ü��: %d/%d", hPoint, maxhPoint);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 7);
	printf("  �� ");
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 1);
	printf("����: %d/%d", mPoint, maxmPoint);
	printf("\n\n\n");
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 6);
	printf("                  ����: %s\n\n", job);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 7);
	printf("��������������������������\n\n\n");
	printf("     ü�°� ������ ���� �������� ������ �Դϴ�\n\n         ü���� ���ٸ� �ɸ��ʹ� ����ϰ�\n\n            ������ ���ٸ� ��Ƽ�� ��ų��\n\n            ������ ��� �� �� �����ϴ�\n\n");
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 14);
	printf("\n\n\n\n                                          ENTER��");
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
	printf("��������������������������\n");
	printf("\n\n");
	printf("     �̸�: %s", name);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 2);
	printf("     ����: %d", level);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 3);
	printf("     ����ġ: %d/%d     \n\n\n", Epoint, maxEpoint);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 14);
	printf("          �� : %d", money);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 5);
	printf("     ������ġ : %d/%d\n\n\n", smile, maxSmile);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 8);
	printf("         ����:%d", mind);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 4);
	printf("     ü��: %d/%d", hPoint, maxhPoint);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 1);
	printf("     ����: %d/%d", mPoint, maxmPoint);
	printf("\n\n\n");
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 6);
	printf("                  ����: %s\n\n", job);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 7);
	printf("��������������������������\n\n\n");
	printf("                    ����������\n\n                    �����Դϴ�\n\n");
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 14);
	printf("\n\n\n\n\n\n\n\n                                          ENTER��");
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
	printf("��������������������������\n");
	printf("\n\n");
	printf("     �̸�: %s", name);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 2);
	printf("     ����: %d", level);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 3);
	printf("     ����ġ: %d/%d     \n\n\n", Epoint, maxEpoint);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 14);
	printf("          �� : %d", money);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 5);
	printf("     ������ġ : %d/%d\n\n\n", smile, maxSmile);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 8);
	printf("         ����:%d", mind);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 4);
	printf("     ü��: %d/%d", hPoint, maxhPoint);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 1);
	printf("     ����: %d/%d", mPoint, maxmPoint);
	printf("\n\n\n");
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 7);
	printf("               �� ");
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 6);
	printf("����: %s\n\n", job);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 7);
	printf("��������������������������\n\n\n");
	printf("        ������ ����� �� �ൿ ������ ����\n\n          �� �� �ִ� ������ �޶����ϴ�\n\n�������⸦ ���־��� ���������� ���� Ȯ���� Ŀ����\n\n �ƴϸ� ���� �͹��Ͼ��� ������ ���� ���� �ֽ��ϴ�");
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 14);
	printf("\n\n\n\n                                          ENTER��");
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
	printf("\n\n\n\n\n\n         �׷� �̻� Ʃ�丮���� ��ġ�ڽ��ϴ�\n\n                   ������ ���ϴ�");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n                                          ENTER��");
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
