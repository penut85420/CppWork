#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "struct.h"

menuData menu[5];
mobData player, *loadPly[5], monsters[4];
skillData skills[2];
short numDelay, numSaves = 5;
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

void systemInitial(menuData *menu);
void gotoxy(short, short);
short opMenu(menuData, int, int);
void clrArrow(short, short, int);
void putArrow(short, short);
void opArrow(short, short, int, int);
int getKey();
void newPlayer(mobData*);
void displayMsg(const char*);
void clrScrSqr(short, short, short, short);
void clrScreen(char);
void gamePlay();
void newGame();
void loadGame();
void setting();
void exitGame();
void sysBattle(mobData*, mobData);
void battleStatue(char*);
void gameBattle();
void gameBreak();
void gameSave();
void gameExit();
void countExp(mobData*);
int getExp(int);
void freshBattleStatue(mobData, mobData);
void countSkills(mobData*);

void (*opGame[])() = {newGame, loadGame, setting, exitGame};
void (*gameCmd[])() = {gameBattle, gameBreak, gameSave, gameExit};

int main() {
    int cmd;
    systemInitial(menu);

    while (cmd != 3) {
        cmd = opMenu(menu[0], 0, 0);
        opGame[cmd]();
    }

    return 0;
}

void systemInitial(menuData *menu) {
    CONSOLE_CURSOR_INFO cci;
    FILE *fp;

    system("title Simple RPG");
    cci.dwSize = 1;
    cci.bVisible = 0;
    SetConsoleCursorInfo(h, &cci);

    fp = fopen("data/setting.dat", "r");

    if (!fp) {
        fclose(fp);
        fp = fopen("data/setting.dat", "w");
        fprintf(fp, "50");
        numDelay = 50;
    } else {
        fscanf(fp, "%d", &numDelay);
    }

    fclose(fp);

    fp = fopen("data/menu.dat", "rb");
    fread(menu, sizeof(menuData), 4, fp);
    fclose(fp);

    fp = fopen("data/skills.dat", "rb");
    fread(skills, sizeof(skillData), 2, fp);
    fclose(fp);

    fp = fopen("data/monsters.dat", "rb");
    fread(monsters, sizeof(mobData), 4, fp);
    fclose(fp);
}
void gotoxy(short X, short Y) {
    COORD c = {X, Y};
    SetConsoleCursorPosition(h, c);
}
short opMenu(menuData menu, int X, int Y) {
    int key, numPoint = 0;

    for (int i = 0; i < menu.n; i++) {
        gotoxy(X, Y + i);
        printf("   %s", menu.strMenu[i]);
    }

    putArrow(X, Y);

    while (key = getKey())
        if (key == 1 || key == -1) {
            clrArrow(X, Y, menu.n);
            numPoint = (numPoint + key + menu.n) % menu.n;
            putArrow(X, Y + numPoint);
        }

    return numPoint;
}
void clrArrow(short X, short Y, int n) {
    for (int i = 0; i < n; i++) {
        gotoxy(X + 1, Y + i);
        printf(" ");
    }
}
void putArrow(short X, short Y) {
    gotoxy(X + 1, Y);
    printf(">");
}
int getKey() {
    int key = getch();

    if (key == 224) {
        key = getch();

        if (key == 72) return -1;
        else if (key == 80) return 1;
    } else if (key == 13 || key == 122) return 0;

    return 37;
}
short ynMenu(short X, short Y) {
    menuData menu;
    menu.n = 2;
    strcpy(menu.strMenu[0], "�O");
    strcpy(menu.strMenu[1], "�_");
    return opMenu(menu, X, Y);
}
void newPlayer(mobData *p) {
    int i, arr[] = {100, 100, 30, 30, 10, 10, 10, 1, 0, 100};

    do {
        printf("�п�J�A���W�r�G");
        gets(p->name);
    } while (p->name[0] == '\0');

    for (i = 0; i < 10; i++)
        p->abt[i] = arr[i];

    p->poisoning = 0;
    p->skill = 0;
}
void displayMsg(const char *msg) {
    char *p = (char*)msg;

    while (*p) p++;

    int len = p - msg;

    for (int i = 0; i < len; i++, Sleep(numDelay))
        putchar(msg[i]);
}
void clrScreen(char c) {
    if (!c) system("cls");
    else {
        gotoxy(0, 0);

        for (int i = 0; i < c; i++, printf("\n"))
            for (int j = 0; j < 100; j++)
                printf("�@");

        gotoxy(0, 0);
    }
}
void clrScrSqr(short X1, short Y1, short X2, short Y2) {
    for (int i = Y1; i < Y1 + Y2; i++) {
        gotoxy(X1, i);

        for (int j = 0; j < X2; j++)
            printf(" ");
    }
}
void makeSaveMenu() {
    FILE *fp;
    int i, cmd;
    char addr[11];

    for (i = 0; i < numSaves; i++) {
        sprintf(addr, "data/save%d.sav", i);
        fp = fopen(addr, "rb");

        if (!fp) sprintf(menu[4].strMenu[i], "�s�� %2d�G�L�s��", i + 1);
        else {
            loadPly[i] = (mobData*)malloc(sizeof(mobData));
            fread(loadPly[i], sizeof(mobData), 1, fp);
            sprintf(menu[4].strMenu[i], "�s�� %2d�G%s ���� %2d", i + 1, loadPly[i]->name, loadPly[i]->abt[7]);
        }

        fclose(fp);
    }

    menu[4].n = numSaves + 1;
    strcpy(menu[4].strMenu[numSaves], "���}");
}
void newGame() {
    int cmd;
    char msg[100];
    clrScreen(0);
    newPlayer(&player);
    sprintf(msg, "�A�n�A%s\n", player.name);
    displayMsg(msg);
    displayMsg("�o�ӥ@�ɨ���i�R�Ǫ����Iŧ\n");
    displayMsg("����ۤv�A���h�o�ǥi�R���Ǫ��a�I\n");
    displayMsg("\n�Ы����N���~��");
    getch();
    gamePlay();
}
void gamePlay() {
    int cmd;
    clrScreen(0);

    while (cmd != 3) {
        cmd = opMenu(menu[1], 0, 0);
        gameCmd[cmd]();

        if (player.abt[0] <= 0) break;
    }
}
void loadGame() {
    int i, cmd;
    makeSaveMenu();

    while (1) {
        clrScreen(0);
        cmd = opMenu(menu[4], 0, 0);

        if (cmd == numSaves) break;

        if (!loadPly[cmd]) {
            gotoxy(0, menu[4].n);
            printf("�Ӧ�m�L�s��");
        } else break;
    }

    if (cmd != numSaves) {
        player = *loadPly[cmd];
        gamePlay();
    }

    clrScreen(0);
}
void setting() {

}
void exitGame() {
    ;
}
void gameBattle() {
    menuData battle;
    clrScreen(0);
    printf("�п�ܭn�԰�����H�G");

    for (int i = 0; i < 4; i++)
        strcpy(battle.strMenu[i], monsters[i].name);

    battle.n = 4;
    sysBattle(&player, monsters[opMenu(battle, 0, 1)]);
}
void gameBreak() {
    printf("%d %d", player.skill, skills[0].mp);
    system("PAUSE");
}
void gameSave() {
    FILE *fp;
    int i, cmd;
    char addr[100];
    makeSaveMenu();

    while (1) {
        clrScreen(0);
        cmd = opMenu(menu[4], 0, 0);

        if (cmd == numSaves) break;

        if (loadPly[cmd]) {
            gotoxy(0, menu[4].n);
            printf("�Ӧs�ɤw�s�b�A�O�_�R���H");

            if (!ynMenu(2, menu[4].n + 1)) break;
        } else break;
    }

    if (cmd != numSaves) {
        sprintf(addr, "data/save%d.sav", cmd);
        fp = fopen(addr, "wb");

        if (fp) {
            fwrite(&player, sizeof(mobData), 1, fp);
            fclose(fp);
            clrScreen(0);
            printf("�s�ɦ��\\\n");
        }

        system("PAUSE");
    }

    clrScreen(0);
}
void gameExit() {
    ;
}
void sysBattle(mobData *p, mobData m) {
    char turn = p->abt[6] > m.abt[6] ? 1 : 0;
    int dmg, cmd, miss;
    char strTmp[100];
    clrScreen(0);
    printf("�D�J��F%s�I", m.name);
    Sleep(1000);
    clrScreen(0);
    freshBattleStatue(*p, m);

    while (p->abt[0] > 0 && m.abt[0] > 0) {
        if (turn) {
            cmd = 1;

            while (cmd > 0) {
                cmd = opMenu(menu[2], 8, 5);

                if (cmd == 0) {
                    clrScrSqr(8, 5, 8, 4);
                    dmg = p->abt[4] - m.abt[5];

                    if (dmg <= 0) dmg = 1;

                    if (rand() % m.abt[6] <= p->abt[6]) miss = 0;
                    else miss = 1;

                    if (!miss) {
                        m.abt[0] -= dmg;
                        freshBattleStatue(*p, m);
                        sprintf(strTmp, "%s�M���@�{�A��%s�y���F %d �I�ˮ`�I", p->name, m.name, dmg);
                        battleStatue(strTmp);
                        freshBattleStatue(*p, m);
                    } else {
                        sprintf(strTmp, "%s�@�ӧ�y�{�L�F%s�������I", m.name, p->name);
                        battleStatue(strTmp);
                    }
                } else if (cmd == 1) {
                    menuData skill;
                    skill.n = 0;

                    if (p->skill & 1) strcpy(skill.strMenu[skill.n++], skills[0].name);

                    if (p->skill & 2) strcpy(skill.strMenu[skill.n++], skills[1].name);

                    strcpy(skill.strMenu[skill.n++], "����");

                    while (1) {
                        cmd = opMenu(skill, 15, 6);

                        if (cmd != skill.n - 1) {
                            if (p->abt[2] >= skills[cmd].mp) {
                                clrScrSqr(8, 5, 20, 4);
                                p->abt[2] -= skills[cmd].mp;

                                if (skills[cmd].type) {
                                    dmg = skills[cmd].effect - m.abt[5];

                                    if (dmg <= 0) dmg = 1;

                                    if (rand() % m.abt[6] <= p->abt[6] * 1.1) miss = 0;
                                    else miss = 1;

                                    if (!miss) {
                                        m.abt[0] -= dmg;
                                        freshBattleStatue(*p, m);
                                        sprintf(strTmp, "%s�ϥX�F%s�A��%s�y���F %d �I�ˮ`�I", p->name, skills[cmd].name, m.name, dmg);
                                        battleStatue(strTmp);
                                    } else {
                                        sprintf(strTmp, "%s�@�ӧ�y�{�L�F%s��%s�I", m.name, p->name, skills[cmd].name);
                                        battleStatue(strTmp);
                                    }
                                } else {
                                    p->abt[0] += skills[cmd].effect;

                                    if (p->abt[0] > p->abt[1]) p->abt[0] = p->abt[1];

                                    freshBattleStatue(*p, m);
                                    sprintf(strTmp, "%s�ϥΤF�v¡�N�I", p->name);
                                    battleStatue(strTmp);
                                }

                                cmd = 0;
                                break;
                            }
                        } else {
                            clrScrSqr(15, 6, 12, skill.n);
                            cmd = 37;
                            break;
                        }
                    }
                }
            }

            p->abt[2] += 5;

            if (p->abt[2] > p->abt[3]) p->abt[2] = p->abt[3];
        } else {
            dmg = m.abt[4] - p->abt[5];

            if (dmg <= 0) dmg = 1;

            if (rand() % p->abt[6] <= m.abt[6]) miss = 0;
            else miss = 1;

            if (!miss) {
                p->abt[0] -= dmg;
                freshBattleStatue(*p, m);
                sprintf(strTmp, "%s��������%s�y���F %d �I�ˮ`�I", m.name, p->name, dmg);
                battleStatue(strTmp);

                if (m.poisoning && !(rand() % 5)) p->poisoning = 1;
            } else {
                sprintf(strTmp, "%s�@�ӧ�y�{�L�F%s�������I", p->name, m.name);
                battleStatue(strTmp);
            }
        }

        if (p->poisoning) {
            p->abt[0] -= 10;
            freshBattleStatue(*p, m);
            sprintf(strTmp, "%s���r���� %d �I�ˮ`", p->name, 10);
            battleStatue(strTmp);
        }

        freshBattleStatue(*p, m);
        clrScreen(1);
        turn = !turn;
    }

    if (m.abt[0] <= 0) {
        p->abt[8] += m.abt[8];
        p->abt[9] += m.abt[9];
        sprintf(strTmp, "%s�Q%s�����F�I", m.name, p->name);
        battleStatue(strTmp);
        sprintf(strTmp, "%s��o�F %d ʨ���I", p->name, m.abt[9]);
        battleStatue(strTmp);
        sprintf(strTmp, "%s��o�F %d �I�g��ȡI", p->name, m.abt[8]);
        battleStatue(strTmp);
        countExp(p);
        p->poisoning = 0;
    } else {
        sprintf(strTmp, "%s�G���b%s��U......", p->name, m.name);
        battleStatue(strTmp);
    }

    clrScreen(0);
}
void battleStatue(char *msg) {
    gotoxy(0, 0);
    printf("%s", msg);
    Sleep(1000);
    clrScreen(1);
}
void countExp(mobData *p) {
    int exp = getExp(p->abt[7]);
    char s[100];

    if (exp <= p->abt[8]) {
        p->abt[8] -= exp;
        p->abt[7]++;
        int arr[7] = {20, 20, 10, 5, 3, 2, 1};

        for (int i = 0; i < 7; i++)
            p->abt[i] += arr[i];

        p->abt[0] = p->abt[1];
        p->abt[2] = p->abt[3];
        sprintf(s, "%s���Ŵ��ɤF�I", p->name);
        battleStatue(s);
        sprintf(s, "%s�{�b�O���� %d", p->name, p->abt[7]);
        battleStatue(s);
        countSkills(p);
    }
}
int getExp(int lv) {
    return lv * lv * 10;
}
void countSkills(mobData *p) {
    for (int i = 0; i < 2; i++) {
        if (p->abt[7] >= skills[i].lv && !(p->skill & (int)pow(2, i))) {
            p->skill |= (int)pow(2, i);
            char s[100];
            sprintf(s, "%s�Ƿ|�F%s�I", p->name, skills[i].name);
            battleStatue(s);
        }
    }
}
void freshBattleStatue(mobData p, mobData m) {
    gotoxy(4, 2);
    printf("%s  HP: %3d/%3d", m.name, m.abt[0] < 0 ? 0 : m.abt[0], m.abt[1]);
    gotoxy(8, 4);
    printf("%s  HP: %3d/%3d  MP: %3d/%3d", p.name, p.abt[0] < 0 ? 0 : p.abt[0], p.abt[1], p.abt[2], p.abt[3]);
}
