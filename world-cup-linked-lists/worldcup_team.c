#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "worldcup_team.h"
#include "worldcup_player.h"
#include "worldCupDB.h"

// Function to read strings
int readString(char str[], int n) {
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

// Convert kit colour to string representation
char * kitStringRep(char kit, char kitString[10]) {
    switch (kit) {
        case 'R': strcpy(kitString, "Red"); break;
        case 'O': strcpy(kitString, "Orange"); break;
        case 'Y': strcpy(kitString, "Yellow"); break;
        case 'G': strcpy(kitString, "Green"); break;
        case 'B': strcpy(kitString, "Blue"); break;
        case 'I': strcpy(kitString, "Indigo"); break;
        case 'V': strcpy(kitString, "Violet"); break;
        default: printf("Invalid Colour\n");
    }
    return kitString;
}

// Getter function for team code
int getTeamCode() {
    int teamCode = -1;
    while (!(teamCode >= 0)) {
        printf("        Enter team code: ");
        scanf("%d", &teamCode);
    }
    return teamCode;
}

// Getter function for team name
char * getTeamName(char teamName[]) {
    printf("        Enter team name: ");
    int teamLen = readString(teamName, NAME_LEN - 1);

    // Inform user if the name entered will be cut off
    if (teamLen > NAME_LEN - 1) {
        printf("You entered more than 24 characters. Your team name may be cut off.\n");
    }
    return teamName;
}

// Getter function for group seeding
char * getGroupSeeding(char groupSeeding[]) {
    int notValid = 1;
    while (notValid) {
        printf("        Enter group seeding: ");
        int grpLen = readString(groupSeeding, SEED_LEN - 1);

        // Check if the group seeding is valid
        if ((grpLen == SEED_LEN - 1) && (groupSeeding[0] >= 'A' && groupSeeding[0] <= 'H') && (groupSeeding[1] >= '1' && groupSeeding[1] <= '4')) {
            notValid = 0;
        }
        else {
            printf("Please enter a valid group seeding (A-H)(1-4)\n");
        }
    }
    return groupSeeding;
}

// Getter function for kit colour
char getKitColour() {
    char valid[] = "ROYGBIV";
    char kitColour;
    int notValid = 1;
    while (notValid) {
        printf("        Enter the kit colour: ");
        scanf(" %c", &kitColour);
        char *isValid = strchr(valid, kitColour);
        if (isValid != NULL) {
            notValid = 0;
        }
        else {
            printf("Please enter a valid colour (R|O|Y|G|B|I|V)\n");
        }
    }
    return kitColour;
}

// Inserting team into linked list
void insertTeam(teamNode * head) {  
    // Create new node
    teamNode * newNode = (teamNode *) malloc(sizeof(teamNode));

    // Memory Allocation Exceeded
    if (newNode == NULL) {
        printf("The database is full. Please free up some space before adding more data.\n");
        return;
    }

    // Get team code
    int teamCodeExists = 0;
    teamNode * cur = head->next;
    int code;
    while (1) {
        code = getTeamCode();

        // Iterate linked list to check if team code already exists
        while (cur != NULL) {
            if (cur->data.teamCode == code) {
                teamCodeExists = 1;
            }
            cur = cur->next;
        }
        if (teamCodeExists == 1) {
            printf("Team code already exists. Please try again.\n");
        }
        else {
            break;
        }
        teamCodeExists = 0;
    }

    // Get name of team
    cur = head->next;
    char name[NAME_LEN];
    getTeamName(name);
    while (1) {
        int teamNameExists = 0;

        // Iterate linked list to check if team name already exists
        while (cur != NULL) {
            if (strcmp(cur->data.teamName, name) == 0) {
                printf("Team name already exists. Please try again.\n");
                teamNameExists = 1;
                break;
            }
            cur = cur->next;
        }
        if (teamNameExists == 0) {
            break;
        }
        teamNameExists= 0;
        getTeamName(name);
    }

    // Get group seeding of team
    cur = head->next;
    char seed[SEED_LEN];
    getGroupSeeding(seed);
    while (1) {
        int groupSeedExists = 0;
        while (cur != NULL) {
            // Iterate linked list to check if group seeding already exists
            if (strcmp(cur->data.groupSeeding, seed) == 0) {
                printf("Group seeding already exists. Please try again.\n");
                groupSeedExists = 1;
                break;
            }
            cur = cur->next;
        }
        if (groupSeedExists == 0) {
            break;
        }
        groupSeedExists = 0;
        getGroupSeeding(seed);
    }

    // Get kit colour
    char kit = getKitColour();

    // Add data to newNode
    newNode->data.teamCode = code;
    strcpy(newNode->data.teamName, name);
    strcpy(newNode->data.groupSeeding, seed);
    newNode->data.kitColour = kit;

    // Node insertion after head
    newNode->next = head->next;
    head->next = newNode;
}

// Function to insert new data in an update
void insertUpdate(teamNode * head, teamNode * curNode) {
    // Get team code
    int teamCodeExists;
    teamNode * cur;
    int code;
    while (1) {
        teamCodeExists = 0;
        code = getTeamCode();
        cur = head->next;

        // Iterate through linked list and check if the team code already exists
        while (cur != NULL) {
            if (cur->data.teamCode == code && (curNode->data.teamCode != code)) {
                teamCodeExists = 1;
            }
            cur = cur->next;
        }
        if (teamCodeExists == 1) {
            printf("Team code already exists. Please try again.\n");
        }
        else {
            break;
        }
    }

    // Get name of team
    cur = head->next;
    char name[NAME_LEN];
    getTeamName(name);
    while (1) {
        int teamNameExists = 0;

        // Iterate through linked list and check if the team name already exists
        while (cur != NULL) {
            if ((strcmp(cur->data.teamName, name) == 0) && (strcmp(curNode->data.teamName, name)) != 0) {
                printf("Team name already exists. Please try again.\n");
                teamNameExists = 1;
                break;
            }
            cur = cur->next;
        }
        if (teamNameExists == 0) {
            break;
        }
        teamNameExists = 0;
        getTeamName(name);
    }

    // Get group seeding of team
    cur = head->next;
    char seed[SEED_LEN];
    getGroupSeeding(seed);
    while (1) {
        int groupSeedExists = 0;

        // Iterate through linked list and check if the group seeding already exists
        while (cur != NULL) {
            if ((strcmp(cur->data.groupSeeding, seed) == 0) && (strcmp(curNode->data.groupSeeding, seed)) != 0) {
                printf("Group seeding already exists. Please try again.\n");
                groupSeedExists = 1;
                break;
            }
            cur = cur->next;
        }
        if (groupSeedExists == 0) {
            break;
        }
        groupSeedExists = 0;
        getGroupSeeding(seed);
    }

    // Get kit colour
    char kit = getKitColour();

    // Update the node with this new data
    curNode->data.teamCode = code;
    curNode->data.kitColour = kit;
    strcpy(curNode->data.teamName, name);
    strcpy(curNode->data.groupSeeding, seed);
}

// Print out information about one team given pointer to node
void printSingleTeam(teamNode * cur) {
    char kitColString[10];
    kitStringRep(cur->data.kitColour, kitColString);
    printf("%-11d %-25s %-27s %s\n", cur->data.teamCode, cur->data.teamName, cur->data.groupSeeding, kitColString);
}

// Function to search for a team given a code and print out the information
void searchTeam(teamNode * head) {
    int isFound = 0;
    int code;
    while (1) {
        teamNode * cur = head->next;
        code = getTeamCode();
        while (cur != NULL) {
            if (cur->data.teamCode == code) {
                isFound = 1;
                printSingleTeam(cur);
            }
            cur = cur->next;
        }
        if (isFound == 0) {
            printf("Team code was not found. Please try again.\n");
        }
        else {
            break;
        }
    }
}

// Function to update a team
void updateTeam(teamNode * head) {
    int isFound;
    int code;
    while (1) {
        isFound = 0;
        code = getTeamCode();
        teamNode * cur = head->next;

        // Iterate through linked list and find a team with the code given
        while (cur != NULL) {
            if (cur->data.teamCode == code) {
                isFound = 1;
                insertUpdate(head, cur);
            }
            cur = cur->next;
        }
        if (isFound == 0) {
            printf("Team code was not found. Please try again.\n");
        }
        else {
            break;
        }
    }
}

// Function to print out every team in the linked list
void printTeam(teamNode * head) {
    teamNode * cur = head->next;
    // Print header
    printf("Team Code   Team Name                 Group Seeding               Primary Kit Colour\n");
    while (cur != NULL) {
        printSingleTeam(cur);
        cur = cur->next;
    }
}

// Function to remove a team from the linked list
void deleteTeam(teamNode * head, playerNode * pHead) {
    // Get prev and cur nodes initialized
    int isFound;
    int code;
    while (1) {
        isFound = 0;
        teamNode * prev = head;
        teamNode * cur = head->next;
        code = getTeamCode();

        // Iterate through linked list and find a team with the associated code
        while (cur != NULL) {
            if (cur->data.teamCode == code) {
                printf("Checking for team members: \n");
                int numMembers = printRegistrants(head, pHead, code);
                printf("\n");

                // If the team has members and cannot be deleted
                if (numMembers > 0) {
                    // don't delete team
                    printf("There are still members in this team. Please delete these members or re-assign them before deleting the team.\n");
                    return;
                }

                // If the team has no members on it
                else {
                    printf("No members found on this team. Deleting team.\n");
                    // delete team
                    isFound = 1;
                    prev->next = cur->next;
                    free(cur);
                    break;
                }
            }
            // increment prev/cur
            else {
                prev = cur;
                cur = cur->next;
            }
        }
        if (isFound == 0) {
            printf("Team code was not found. Please try again.\n");
        }
        else {
            break;
        }
    }
}

// Function to print out all the players on a specified team
int printRegistrants(teamNode * head, playerNode * pHead, int optionalCode) {
    // Regular print case if team not found (helps in deletion method)
    if (optionalCode != -1) {
        int numRegistrants = 0;
        numRegistrants += printPlayer(pHead, optionalCode);
        return numRegistrants;
    }

    // Prompt for team code
    int isFound = 0;
    int code;
    while (1) {
        teamNode * cur = head->next;
        code = getTeamCode();

        // Iterate through linked list and print registered players for a team if found
        while (cur != NULL) {
            if (cur->data.teamCode == code) {
                isFound = 1;
                // print all the registered players with team_code equal to code
                printPlayer(pHead, code);
            }
            cur = cur->next;
        }
        if (isFound == 0) {
            printf("Team code was not found. Please try again.\n");
        }
        else {
            break;
        }
    }
    return -1;
}