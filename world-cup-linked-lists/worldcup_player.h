#ifndef WORLD_CUP_PLAYER_H
#define WORLD_CUP_PLAYER_H

#define PNAME_LEN 50

// Structure to hold the data of a player
typedef struct playerData {
    int playerCode;
    char playerName[PNAME_LEN];
    int playerAge;
    char playerClub[PNAME_LEN];
    int team_code;
} playerData;

// Structure to hold a linked list node for a player
typedef struct playerNode{
    // pointer to next node
    struct playerNode *next;
    struct playerData data;
} playerNode;

// Including the team header to use teamCode in functions
#include "worldcup_team.h"

void insertPlayer(playerNode * pHead, teamNode * head);
void searchPlayer(playerNode * pHead);
void updatePlayer(playerNode * pHead);
int printPlayer(playerNode * pHead, int teamCode);
void deletePlayer(playerNode * pHead);

#endif