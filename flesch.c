// flesch.c - Student Implementation File
// Implement the Flesch Reading Ease algorithm
//
// DO NOT modify the function signatures

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "flesch.h"

int countSentences(const char* text) {
    // TODO: Implement this function
    if (text[0] == '\0') {
        return 0;
    }
    int sentenceCount = 0;
    int i = 0;
    while (text[i] != '\0') {
        if (text[i] == '.' || text[i] == ':' || text[i] == ';' || text[i] == '?' || text[i] == '!') {
            sentenceCount++;
        }
    i++;
    }
    if (sentenceCount == 0) {
        return 1;
    }

    return sentenceCount;
}

int countWords(const char* text) {
    // TODO: Implement this function
    int inWord = 0;
    int wordCount = 0;
    int i = 0;
    while (text[i] != '\0') {
        if (text[i] != ' ' && text[i] != '\t' && text[i] != '\n' && text[i] != '.' && text[i] != ':' && text[i] != ';' && text[i] != '?' && text[i] != '!') {
            if (inWord == 0) {
                inWord = 1;
                wordCount++;
            }
        } else {
            inWord = 0;
        }
        i++;
    }
    return wordCount;
}

int countSyllables(const char* text) {
    // TODO: Implement this function
    int inSyllable = 0;
    int syllableCount = 0;
    int i = 0;
    char temp;
    while (text[i] != '\0') {
        temp = text[i];
        temp = tolower(temp);
        if (temp == 'a' || temp == 'e' || temp == 'i' || temp == 'o' || temp == 'u') {
            if (inSyllable == 0) {
                inSyllable = 1;
                syllableCount++;
            }
        } else {
            inSyllable = 0;
        }
        i++;
    }
    return syllableCount;
}

double calculateFleschScore(TextStats stats) {
    // TODO: Implement this function
    double score = 0.0;
    if (stats.words == 0) {
        return score;
    }

    score = 206.835 - (1.015 * ((double)stats.words / (double)stats.sentences)) - (84.6 * ((double)stats.syllables / (double)stats.words));

    return score;
}

TextStats analyzeText(const char* text) {
    TextStats stats;
    stats.sentences = countSentences(text);
    stats.words = countWords(text);
    stats.syllables = countSyllables(text);
    return stats;
}
