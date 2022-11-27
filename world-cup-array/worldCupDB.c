#include <stdio.h>
#include <string.h>

// Getter function for team code
int getTeamCode() {
    int teamCode;
    while !(teamCode >= 0 && teamCode <= 21) {
        printf("        Enter team code: ")
        scanf("%d\n", &teamCode);
    }
    return teamCode;
}

// Getter function for team name
const char* getTeamName() {
    char teamName[25];
    printf("        Enter team name: ")
    scanf("%s\n", teamName);
    teamLen = strlen(teamName);
    if (teamLen > 24) {
        printf("You entered more than 24 characters. Your team name may be cut off.\n")
    }
    return teamName;
}

// Getter function for group seeding
const char* getGroupSeeding() {
    char groupSeeding[];
    int notValid = 1;
    while (notValid) {
        printf("        Enter group seeding: ")
        scanf("%s\n", groupSeeding);
        int grpLen = strlen(groupSeeding);
        if ((grpLen == 2) && ('A' <= groupSeeding[0] <= 'H') && ('1' <= groupSeeding[1] <= '4')) {
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
        printf("        Enter the kit colour: ")
        scanf("%c\n", &kitColour);
        isValid = strchr(valid, kitColour);
        if (isValid != NULL) {
            notValid = 0;
        }
        else {
            printf("Please enter a valid colour (R|O|Y|G|B|I|V)\n");
        }
    }
    return kitColour;
}


// Insert New Team
int insertTeam() {
    int teamCode = getTeamCode();
    char teamName[] = getTeamName();
    char groupSeeding[] = getGroupSeeding();
    char kitColour = getKitColour();

}

// Search For Team
int searchTeam() {
    int teamCode = getTeamCode();

}

// Update Team
int updateTeam() {
    int teamCode = getTeamCode();
}

// Print Entire List of Teams
int printTeamsList() {

}

int main(void) {
    // Welcoming Prompt
    printf("******************\n");
    printf("* 2211 World Cup *\n");
    printf("******************\n\n");

    // Initialize Data Structures


    // Prompt user to enter command type
    char command;
    while (command != 'q') {
        printf("Enter operation code: ");
        scanf("%c\n", &command);

        // Continue based on command input
        if (command == 'q') {
            return 0;
        }
        else if (command == 'i') {
            insertTeam();
        }
        else if (command == 's') {
            searchTeam();
        }
        else if (command == 'u') {
            updateTeam();
        }
        else if (command == 'p') {
            printTeamsList();
        }
    }

}
