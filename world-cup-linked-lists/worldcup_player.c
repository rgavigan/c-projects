#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "worldcup_player.h"
#include "worldcup_team.h"
#include "worldCupDB.h"

// Function that reads in a string
int readPlayerString(char str[], int n) {
    int ch, i = 0;
    int charCount = 0;

    while (isspace(ch = getchar()))
        ;

    while (ch != '\n' && ch != EOF) {
        if (i < n) {
            str[i++] = ch;
        }
        ch = getchar();
        charCount += 1;
    }
    str[i] = '\0';
    return charCount;
}

// Getter function for player code
int getPlayerCode() {
    int playerCode = -1;
    while (!(playerCode >= 0)) {
        printf("        Enter player code: ");
        scanf("%d", &playerCode);
    }
    return playerCode;
}

// Getter function for player name
char * getPlayerName(char playerName[]) {
    printf("        Enter player name: ");
    int playerLen = readPlayerString(playerName, PNAME_LEN - 1);

    // Inform user if name is cut off
    if (playerLen > PNAME_LEN - 1) {
        printf("You entered more than 49 characters. Your player name may be cut off.\n");
    }
    return playerName;
}

// Getter function for player age
int getPlayerAge() {
    int playerAge = -1;
    while (!(playerAge >= 17) && (playerAge <= 99)) {
        printf("        Enter player age: ");
        scanf("%d", &playerAge);

        // Inform user if player age is invalid
        if (playerAge < 17 || playerAge > 99) {
            printf("Please try again, valid player ages are from 17-99.\n");
        }
    }
    return playerAge;
}

// Getter function for player's club affiliation
char * getClubAffiliation(char clubAffiliation[]) {
    printf("        Enter club affiliation: ");
    int clubLen = readPlayerString(clubAffiliation, PNAME_LEN - 1);

    // Inform user if club affiliation is cut off
    if (clubLen > PNAME_LEN - 1) {
        printf("You entered more than 49 characters. Your club affiliation may be cut off.\n");
    }
    return clubAffiliation;
}

// Getter function for player age
int getPlayersTeam() {
    int playersTeam = -1;
    while (!(playersTeam >= 0)) {
        printf("        Enter player's team code: ");
        scanf("%d", &playersTeam);

        // Inform user if they insert a negative number
        if (playersTeam < 0) {
            printf("Please try again, valid team codes are positive integers.\n");
        }
    }
    return playersTeam;
}

// Function to insert a player into the linked list
void insertPlayer(playerNode * pHead, teamNode * head) {
    // Create new node
    playerNode * newNode = (playerNode *) malloc(sizeof(playerNode));

    // Memory Allocation Exceeded
    if (newNode == NULL) {
        printf("The database is full. Please free up some space before adding more data.\n");
        return;
    }

    // Get player code (must be unique)
    int playerCodeExists = 0;
    playerNode * cur = pHead->next;
    int code;
    while (1) {
        code = getPlayerCode();
        while (cur != NULL) {
            if (cur->data.playerCode == code) {
                playerCodeExists = 1;
            }
            cur = cur->next;
        }
        if (playerCodeExists == 1) {
            printf("Player code already exists. Please try again.\n");
        }
        else {
            break;
        }
        playerCodeExists = 0;
    }

    // Get name of player
    char name[PNAME_LEN];
    getPlayerName(name);

    // Get player age
    int age = getPlayerAge();

    // Get club affiliation
    char club[PNAME_LEN];
    getClubAffiliation(club);

    // Get team code for player, make sure that the team already exists
    int isValidTeam;
    int playersTeam;
    while (1) {
        teamNode * teamCur = head->next;
        isValidTeam = 0;
        playersTeam = getPlayersTeam();
        while (teamCur != NULL) {
            if (teamCur->data.teamCode == playersTeam) {
                isValidTeam = 1;
            }
            teamCur = teamCur->next;
        }

        // Informs user that an invalid team code was given
        if (isValidTeam == 0) {
            printf("This is not a valid team. Please try again.\n");
            printf("Here is the list of valid teams: \n");
            printTeam(head);
        }
        else {
            break;
        }
    }

    // Add data to newNode
    newNode->data.playerCode = code;
    strcpy(newNode->data.playerName, name);
    strcpy(newNode->data.playerClub, club);
    newNode->data.playerAge = age;
    newNode->data.team_code = playersTeam;

    // Node insertion after head
    newNode->next = pHead->next;
    pHead->next = newNode;
}

// Print out information about one player given pointer to node
void printSinglePlayer(playerNode * cur) {
    printf("%-13d %-52s %-17d %s\n", cur->data.playerCode, cur->data.playerName, cur->data.playerAge, cur->data.playerClub);
}

// Search for a player in the linked list and print
void searchPlayer(playerNode * pHead) {
    int isFound = 0;
    int code;
    while (1) {
        playerNode * cur = pHead->next;
        code = getPlayerCode();

        // Iterate through linked list and print if player is found
        while (cur != NULL) {
            if (cur->data.playerCode == code) {
                isFound = 1;
                printSinglePlayer(cur);
            }
            cur = cur->next;
        }

        // Inform user if player code was not found
        if (isFound == 0) {
            printf("Player code was not found. Please try again.\n");
        }
        else {
            break;
        }
    }
}

// Insert new player data in an update
void insertPlayerUpdate(playerNode * pHead, playerNode * curNode) {
    // Get player code
    int playerCodeExists;
    playerNode * cur;
    int code;
    while (1) {
        playerCodeExists = 0;
        code = getPlayerCode();
        cur = pHead->next;

        // Iterate linked list and check if code already exists for a different player
        while (cur != NULL) {
            if (cur->data.playerCode == code && (curNode->data.playerCode != code)) {
                playerCodeExists = 1;
            }
            cur = cur->next;
        }

        // Inform user if player code already exists
        if (playerCodeExists == 1) {
            printf("Player code already exists. Please try again.\n");
        }
        else {
            break;
        }
    }

    // Get name of player
    char name[PNAME_LEN];
    getPlayerName(name);

    // Get player age
    int age = getPlayerAge();

    // Get club affiliation (does not need to be unique)
    char club[PNAME_LEN];
    getClubAffiliation(club);

    // Update data in the current node
    curNode->data.playerCode = code;
    curNode->data.playerAge = age;
    strcpy(curNode->data.playerName, name);
    strcpy(curNode->data.playerClub, club);
}

// Function to update the data for a player
void updatePlayer(playerNode * pHead) {
    int isFound;
    int code;
    while (1) {
        isFound = 0;
        code = getPlayerCode();
        playerNode * cur = pHead->next;
        while (cur != NULL) {
            // Search linked list for player code and then update
            if (cur->data.playerCode == code) {
                isFound = 1;
                insertPlayerUpdate(pHead, cur);
            }
            cur = cur->next;
        }

        // Inform user if player code was not found in linked list
        if (isFound == 0) {
            printf("Player code was not found. Please try again.\n");
        }
        else {
            break;
        }
    }
}

// Print out the information for the entire database of players
int printPlayer(playerNode * pHead, int teamCode) {
    playerNode * cur = pHead->next;
    int counter = 0;
    // Print header
    printf("Player Code   Player Name                                          Player Age        Club Affiliation\n");
    while (cur != NULL) {
        // Regular print
        if (teamCode == -1) {
            printSinglePlayer(cur);
            cur = cur->next;
        }
        // Print players given a team code
        else {
            if (cur->data.team_code == teamCode) {
                printSinglePlayer(cur);
                counter += 1;
            }
            cur = cur->next;
        }
    }
    return counter;
}

// Function to remove a player from the linked list
void deletePlayer(playerNode * pHead) {
    // Get prev and cur nodes initialized
    int isFound;
    int code;
    while (1) {
        isFound = 0;
        playerNode * prev = pHead;
        playerNode * cur = pHead->next;
        code = getPlayerCode();

        // Iterate through linked list to find the player associated with code
        while (cur != NULL) {
            if (cur->data.playerCode == code) {
                // Delete node and free from memory
                isFound = 1;
                prev->next = cur->next;
                // Free the memory used up by cur
                free(cur);
                break;
            }
            // Increment prev/cur
            else {
                prev = cur;
                cur = cur->next;
            }
        }

        // Inform user if player code was not found
        if (isFound == 0) {
            printf("Player code was not found. Please try again.\n");
        }
        else {
            break;
        }
    }
}