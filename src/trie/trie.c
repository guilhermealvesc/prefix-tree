#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "trie.h"
#define MAX_CHARS 26

struct Trie {
  struct Trie *child[MAX_CHARS];
  bool upper;
};

Trie *criaTrie() {
  Trie *root = (Trie *) malloc(sizeof(Trie));
  if (root) {
    for (size_t i = 0; i < MAX_CHARS; i++)
      root->child[i] = NULL;
    root->upper = false;
  }
  return root;
}

void liberaTrie(Trie *tr) {
  if (!tr)
    return;
  for (size_t i = 0; i < MAX_CHARS; i++) {
    if(tr->child[i])
      liberaTrie(tr->child[i]);
  }
  free(tr);
}


int insereTrie(Trie* tr, char *str) {
  if(!tr || !str) return 0;
  char letter = *str;
  
  if(letter == '\0') return 1;

  if(!tr->child[letter]) 
    tr->child[letter] = (Trie *) malloc(sizeof(Trie));
  
  return insereTrie(tr->child[letter], str + 1);
}

int buscaTrie(Trie* tr, char *str) {
  if(!tr || !str) return 0;
  char letter = *str;

  if(letter == '\0') return 1;

  if(!tr->child[letter]) return 0;

  return buscaTrie(tr->child[letter], str + 1);
}

int removeTrie(Trie* tr, char *str) {

}

void imprimeTrie(Trie *tr) {
  
}


void autocompletarTrie(Trie* tr, char *prefixo) {

}