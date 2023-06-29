#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h> 

typedef struct {
    int length;
    char* array;
} Word;

Word reverseSentence(const char arr[]) {
    int count = 0;
    int wordCount = 0;
    int totalLength = 0;

    // Count the number of words in the sentence
    for (int i = 0; arr[i] != '\0'; i++) {
        if (arr[i] == ' ') {
            wordCount++;
        }
        totalLength++;
    }

    // Add 1 to wordCount to account for the last word
    wordCount++;

    // Allocate memory for the array of words
    Word* words = (Word*)malloc(wordCount * sizeof(Word));

    int wordIndex = 0;
    count = 0;

    // Split the sentence into words and store them in the words array
    for (int i = 0; i <= totalLength; i++) {
        if (arr[i] == ' ' || arr[i] == '\0') {
            words[wordIndex].length = count;
            words[wordIndex].array = (char*)malloc((count + 1) * sizeof(char)); // Allocate memory for the word array

            // Copy the characters of the word
            for (int j = 0; j < count; j++) {
                words[wordIndex].array[j] = arr[i - count + j];
            }
            words[wordIndex].array[count] = '\0';

            // Reset count for the next word
            count = 0;
            wordIndex++;
        }
        else {
            count++;
        }
    }

    // Reverse the order of words in the words array
    for (int i = 0, j = wordCount - 1; i < j; i++, j--) {
        Word temp = words[i];
        words[i] = words[j];
        words[j] = temp;
    }

    // Concatenate the reversed words into a new sentence
    char* reversedSentence = (char*)malloc((totalLength + 1) * sizeof(char));
    reversedSentence[0] = '\0'; // Initialize the reversed sentence as an empty string

    for (int i = 0; i < wordCount; i++) {
        strcat(reversedSentence, words[i].array);
        if (i < wordCount - 1) {
            strcat(reversedSentence, " ");
        }
    }

    // Free the dynamically allocated memory for the words and words array
    for (int i = 0; i < wordCount; i++) {
        free(words[i].array);
    }
    free(words);

    // Create the Word struct to return the reversed sentence
    Word reversedWord;
    reversedWord.length = totalLength;
    reversedWord.array = reversedSentence;

    return reversedWord;
}

int main() {
    char sentence[] = "Russias president indicates that associates of the Wagner groups leader in government and the military will face punishment.";
    Word reversedWord = reverseSentence(sentence);

    // Print the reversed sentence
    printf("Reversed Sentence: %s\n", reversedWord.array);

    // Free the dynamically allocated memory for the reversed sentence
    free(reversedWord.array);

    return 0;
}
