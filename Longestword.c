#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to represent an array of strings
typedef struct {
    char **words;  // Pointer to an array of strings
    int size;      // Number of strings in the array
} StringArray;

// Function to recursively find the longest word in the array
void findLongestWord(StringArray strArray, int index, char **longestWord) {
    if (index >= strArray.size) {
        return;
    }

    // Check if the current word is longer than the longest found so far
    if (*longestWord == NULL || strlen(strArray.words[index]) > strlen(*longestWord)) {
        *longestWord = strArray.words[index];
    }

    // Recursive call for the next index
    findLongestWord(strArray, index + 1, longestWord);
}

// Function to display the longest word
void displayLongestWord(char *longestWord) {
    if (longestWord != NULL) {
        printf("The longest word is: %s\n", longestWord);
    } else {
        printf("No words found.\n");
    }
}

// Function to release memory allocated for the array of strings
void freeStringArray(StringArray strArray) {
    for (int i = 0; i < strArray.size; i++) {
        free(strArray.words[i]); // Free each string
    }
    free(strArray.words); // Free the array of pointers
}

int main() {
    // Initialize the StringArray
    StringArray strArray;
    printf("Enter number of words:\n");
    scanf("%d",&strArray.size);  // input size
    strArray.words = (char **)malloc(strArray.size * sizeof(char *));
    
    // Allocate memory for each string and assign values
    for (int i = 0; i < strArray.size; i++) {
        strArray.words[i] = (char *)malloc(51 * sizeof(char)); // 50 chars + 1 for null terminator
    }
    // Input strings
    printf("Enter strings:\n");
    for(int i = 0; i < strArray.size; i++){
	    scanf("%s",strArray.words[i]);
    }

    // Find the longest word
    char *longestWord = NULL;
    findLongestWord(strArray, 0, &longestWord);

    // Display the longest word
    displayLongestWord(longestWord);

    // Free allocated memory
    freeStringArray(strArray);

    return 0;
}

