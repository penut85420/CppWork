#ifndef STRUCT_H_INCLUDED
#define STRUCT_H_INCLUDED

typedef struct menuData{
	char strMenu[6][40];
	short n;
}menuData;

typedef struct mobData{
	char name[15], poisoning; // player - statue, monster - attack with poison
    int abt[10]; // hp, mhp, mp, mmp, atk, def, spd, lv, exp, money, skill
    int skill;
}mobData;

typedef struct skillData{
	char name[16];
	int effect, type, mp, lv; //type0 self, type1 enemy
}skillData;

#endif // STRUCT_H_INCLUDED
