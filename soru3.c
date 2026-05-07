#include <stdio.h>
#include <stdlib.h>

#define ALFABE 26

typedef struct TrieNode {
    struct TrieNode *cocuk[ALFABE];
    int kelimeSonu;
} TrieNode;

TrieNode* yeniNode() {
    TrieNode* node = (TrieNode*)malloc(sizeof(TrieNode));
    node->kelimeSonu = 0;

    for (int i = 0; i < ALFABE; i++)
        node->cocuk[i] = NULL;

    return node;
}

void ekle(TrieNode* root, char* kelime) {
    TrieNode* temp = root;

    for (int i = 0; kelime[i]; i++) {
        int index = kelime[i] - 'a';

        if (!temp->cocuk[index])
            temp->cocuk[index] = yeniNode();

        temp = temp->cocuk[index];
    }

    temp->kelimeSonu = 1;
}

int ara(TrieNode* root, char* kelime) {
    TrieNode* temp = root;

    for (int i = 0; kelime[i]; i++) {
        int index = kelime[i] - 'a';

        if (!temp->cocuk[index])
            return 0;

        temp = temp->cocuk[index];
    }

    return temp->kelimeSonu;
}

int main() {
    TrieNode* root = yeniNode();

    ekle(root, "elma");
    ekle(root, "ev");

    printf("elma: %d\n", ara(root, "elma"));
    printf("kitap: %d\n", ara(root, "kitap"));

    return 0;
}
