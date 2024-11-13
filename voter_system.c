#include <stdio.h>

// Structure to hold candidate information
typedef struct {
    char name[50]; // candidate name
    int votes; // number of votes
    char symbol; // candidate symbol
} Candidate;

// Global array to hold all candidates
Candidate candidates[10];

// Global variable to keep track of the number of candidates
int candidateCount = 0;

// Function to add a new candidate
void addCandidate(int candidateNumber) {
    printf("Enter the name of candidate %d: ", candidateNumber + 1);
    scanf("%s", candidates[candidateNumber].name);

    // Assign a symbol to the candidate
    candidates[candidateNumber].symbol = '!'; // for simplicity, just use '!'
    candidates[candidateNumber].votes = 0; // initialize votes to 0
}

// Function to display all candidates
void displayCandidates() {
    for (int i = 0; i < candidateCount; i++) {
        printf("%s (%c)\n", candidates[i].name, candidates[i].symbol);
    }
}

// Function to get votes
void getVote() {
    displayCandidates();
    printf("Enter your choice (1-%d): ", candidateCount);
    int choice;
    scanf("%d", &choice);

    // Increment the vote count for the chosen candidate
    candidates[choice - 1].votes++;
}

// Function to display the winner
void displayWinner() {
    int maxVotes = 0;
    int winnerIndex = -1;

    // Find the candidate with the most votes
    for (int i = 0; i < candidateCount; i++) {
        if (candidates[i].votes > maxVotes) {
            maxVotes = candidates[i].votes;
            winnerIndex = i;
        }
    }

    // Display the winner
    if (winnerIndex != -1) {
        printf("The winner is: %s with %d votes!\n", candidates[winnerIndex].name, maxVotes);
    } else {
        printf("No winner\n");
    }
}

// Main function
int main() {
    // Get the number of candidates
    printf("Enter the number of candidates: ");
    scanf("%d", &candidateCount);

    // Add candidates
    for (int i = 0; i < candidateCount; i++) {
        addCandidate(i);
    }

    // Get the number of voters
    int numVoters;
    printf("Enter the number of voters: ");
    scanf("%d", &numVoters);

    // Get votes
    for (int i = 0; i < numVoters; i++) {
        getVote();
    }

    // Display the winner
    displayWinner();

    return 0;
}