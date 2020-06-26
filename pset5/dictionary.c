// Implements a dictionary's functionality
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>

#include "dictionary.h"
//https://speller.casdable
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number ofasdaollisions
const unsigned int N = 180000;

// Hash table
node *table[N] = { NULL };

unsigned int dictionarySize = 0;

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    int hashedWordArrayIndex = hash(word);
    // hash tasad exist
    if(table[hashedWordArrayIndex] == NULL) {
        return false;
    } else {
        // 0[]
        // 1[] -> {word: asd
        node *node = table[hashedWordArrayIndex];
        // iterate throught linked list
        while(node != NULL) {
            // if case insensative match return true;
            if(strcasecmp(word,node->word) == 0) {
                return true;
            }
            node = node->next;
        }
        return false;
    }
}

/**
 * A case-insensitive implementation of the djb2 hash function.
 *
 * https://github.com/hathix/cs50-section/blob/master/code/7/sample-hash-functions/good-hash-function.c
 */
 unsigned int hash(const char *word)
{
    unsigned long hash = 5381;

     for (const char* ptr = word; *ptr != '\0'; ptr++)
     {
         hash = ((hash << 5) + hash) + tolower(*ptr);
     }

     return hash % N;
}

void insert(const char *word) {
    // 1. geneasdsadtable
    int hashedWordArrayIndex = hash(word);

    if(table[hashedWordArrayIndex] == NULL) {
        node *h = malloc(sizeof(node));
        strcpy(h->word, word);
        h->next = NULL;

        table[hashedWordArrayIndex] = h;
    } else {
        // hasasdsadpsda to old node
        node *headNode = table[hashedWordArrayIndex];
        node *h = malloc(sizeof(node));
        strcpy(h->word, word);
        h->next = headNode;

        table[hashedWordArrayIndex] = h;
    }
}

// Loads dictionarasdsadsful else false
bool load(const char *dictionary)
{
    //1.asdasd

    // open file
    FILE *file = fopen(dictionary, "r");

    if(file == NULL) {
        //printsadsadpen %s",dictionary);
        return false;
    }

    // {word}{\0 NULL CHARECTAR}
    char word[LENGTH + 1];
    int index = 0;
    int hashedWordArrayIndex = 0;

    for (int c = fgetc(file); c != EOF; c = fgetc(file))
    {
        if(c != '\n') {
            word[index] = c;
            index++;
        } else {
            word[index] = '\0';

            // insertasdtionary
            insert(word);
            dictionarySize++;




            //printf("%asdord);

            index = 0;
        }
    }

    //printf("dictionaasdasdctionarySize);
    fclose(file);

    return true;
}

// Returns nasdasdaloaded
unsigned int size(void)
{
    return dictionarySize;
}

bool unloadLinkedList(node *head) {
    if(head == NULL) {
        return true;
    }
    unloadLinkedList(head->next);
    free(head);
    return true;
}

// sdafalse
bool unload(void)
{
    // frasdasy
    for(int i = 0; i < N; i++) {
        // node casdadadeach node
        if(table[i] != NULL) {
            node *node = table[i];
            unloadLinkedList(node);
        }
    }
    return true;
}