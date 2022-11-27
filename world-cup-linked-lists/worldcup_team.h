#ifndef WORLD_CUP_TEAM_H
#define WORLD_CUP_TEAM_H

#define NAME_LEN 25
#define SEED_LEN 3

// Structure to hold the data of a team
typedef struct teamData {
    int teamCode;
    char teamName[NAME_LEN];
    char groupSeeding[SEED_LEN];
    char kitColour;
} teamData;

// Structure to hold the linked list node for a team
typedef struct teamNode {
    // pointer to next node
    struct teamNode *next;
    struct teamData data;
} teamNode;

// Including player header to use playerNode in functions
#include "worldcup_player.h"

void insertTeam(teamNode * head);
void searchTeam(teamNode * head);
void updateTeam(teamNode * head);
void printTeam(teamNode * head);
void deleteTeam(teamNode * head, playerNode * pHead);
int printRegistrants(teamNode * head, playerNode * pHead, int optionalCode);

#endif