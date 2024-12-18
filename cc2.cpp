#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STATES 10
#define MAX_SYMBOLS 10


typedef struct {
    int transitions[MAX_STATES][MAX_SYMBOLS];
} TransitionTable;

int getSymbolIndex(char symbol, char *inputSymbols, int numSymbols) {
    for (int i = 0; i < numSymbols; i++) {
        if (inputSymbols[i] == symbol) {
            return i;
        }
    }
    return -1;
}

int isValidString(int startState, TransitionTable *table, char *inputString, int *acceptingStates, int numStates, int numSymbols) {
    int currentState = startState;
    for (int i = 0; i < strlen(inputString); i++) {
        char symbol = inputString[i];
        int symbolIndex = getSymbolIndex(symbol, "abcdefghijklmnopqrstuvwxyz", numSymbols);
        if (symbolIndex == -1) {
            return 0;
        }
        currentState = table->transitions[currentState][symbolIndex];
    }


    for (int i = 0; i < numStates; i++) {
        if (currentState == acceptingStates[i]) {
            return 1;
        }
    }
    return 0;
}

int main() {
    int numSymbols;
    printf("Number of input symbols: ");
    scanf("%d", &numSymbols);

    char inputSymbols[MAX_SYMBOLS];
    printf("Input symbols: ");
    for (int i = 0; i < numSymbols; i++) {
        scanf(" %c", &inputSymbols[i]);
    }

    int numStates;
    printf("Enter number of states: ");
    scanf("%d", &numStates);

    int startState;
    printf("Initial state: ");
    scanf("%d", &startState);

    int numAcceptingStates;
    printf("Number of accepting states: ");
    scanf("%d", &numAcceptingStates);

    int acceptingStates[MAX_STATES];
    printf("Accepting states: ");
    for (int i = 0; i < numAcceptingStates; i++) {
        scanf("%d", &acceptingStates[i]);
    }


    TransitionTable table;
    for (int i = 0; i < numStates; i++) {
        for (int j = 0; j < numSymbols; j++) {
            table.transitions[i][j] = -1;
        }
    }

    printf("Transition table:\n");
    for (int i = 0; i < numStates; i++) {
        for (int j = 0; j < numSymbols; j++) {
            char symbol = inputSymbols[j];
            int nextState;
            printf("%d to %c -> ", i, symbol);
            scanf("%d", &nextState);
            table.transitions[i][j] = nextState;
        }
    }

    char inputString[MAX_STATES];
    printf("Input string: ");
    scanf("%s", inputString);

    if (isValidString(startState, &table, inputString, acceptingStates, numStates, numSymbols)) {
        printf("Valid String\n");
    } else {
        printf("Invalid String\n");
    }

    return 0;
}
