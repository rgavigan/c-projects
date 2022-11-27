#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "worldCupDB.h"
#include "worldcup_player.h"
#include "worldcup_team.h"

int promptPlayers(playerNode * pHead, teamNode * head) {
    // Prompt Player Commands
    printf("Commands: i = insert, s = search, u = update, p = print, d = delete, b = back to main menu\n");
    char command;
    while (command != 'q') {
        printf("Enter your command: ");
        scanf(" %c", &command);

        switch (command) {
            case 'i': insertPlayer(pHead, head); break;
            case 's': searchPlayer(pHead); break;
            case 'u': updatePlayer(pHead); break;
            case 'p': printPlayer(pHead, -1); break;
            case 'd': deletePlayer(pHead); break;
            // go back to main menu
            case 'b': return 1;
            default: printf("Please try again.\n");
        }
    }
    return 0;
}

int promptTeams(teamNode * head, playerNode * pHead) {
    // Prompt Team Commands    
    printf("Commands: i = insert, s = search, u = update, p = print, d = delete, r = print registrants, b = back to main menu\n");
    char command;
    while (command != 'q') {
        printf("Enter your command: ");
        scanf(" %c", &command);

        switch (command) {
            case 'i': insertTeam(head); break;
            case 's': searchTeam(head); break;
            case 'u': updateTeam(head); break;
            case 'p': printTeam(head); break;
            case 'd': deleteTeam(head, pHead); break;
            case 'r': printRegistrants(head, pHead, -1); break;
            // go back to main menu
            case 'b': return 1;
            default: printf("Please try again.\n");
        }
    }
    return 0;
}

void printHelp(void) {
    // Print out basics on how to use the program
    printf("Here is how you use the program:\n");
    printf("Step 1: Enter a main command: \n");
    printf("\t'h' -> will show you this help page\n");
    printf("\t'q' -> will exit the program, losing all data\n");
    printf("\t't' -> will allow you to perform operations on teams\n");
    printf("\t'p' -> will allow you to perform operations on players\n\n");
}

int main(void) {
    // Welcoming Prompt
    printf("******************\n");
    printf("* 2211 World Cup *\n");
    printf("******************\n\n");

    // Initialize team linked list as a node
    teamNode * head = (teamNode *) malloc(sizeof(teamNode));
    head->next = NULL;
    // Initialize player linked list as a node
    playerNode * pHead = (playerNode * ) malloc(sizeof(playerNode));
    pHead->next = NULL;

    // Prompt user to enter main command type
    printf("Commands: h = help, q = quit, t = teams, p = players\n");
    char command;
    while (command != 'q') {
        printf("Enter operation code: ");
        scanf(" %c", &command);
        int res, pRes;
    
        // Handle Command
        switch (command) {
            case 'h': printHelp(); break;
            // if/else statement to allow user to come back to this main menu if desired
            case 't': res = promptTeams(head, pHead); if (res == 0) {continue;} else {break;}
            case 'p': pRes = promptPlayers(pHead, head); if (pRes == 0) {continue;} else {break;}
            case 'q': break;
            default: printf("Please try again.\n");
        }
    }
    // Quit after 'q' typed as command
    printf("Thank you for using the 2211 World Cup Database!\n");
    return 0;
}