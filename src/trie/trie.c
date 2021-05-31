#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "trie.h"
#define MAX_CHARS 26

#define hashChar(c) tolower(c) - 97
#define getChar(i) (char) (i + 97)
struct Trie {
  struct Trie *child[MAX_CHARS];
  unsigned short int end;
};

Trie startNode() {
  Trie node = (Trie) malloc(sizeof(struct Trie));
  if (node) {
    for (size_t i = 0; i < MAX_CHARS; i++)
      node->child[i] = NULL;
    node->end = 0;
  }
  return node;
}

Trie* criaTrie() {
  Trie* root = (Trie*) malloc(sizeof(Trie));
  if(root) {
    *root = startNode();
    if(!(*root)) 
      free(root);
  }
  return root;
}

void freeNodes(Trie tr) {
  if (!tr)
    return;
  for (size_t i = 0; i < MAX_CHARS; i++) {
    if (tr->child[i])
      freeNodes(tr->child[i]);
  }
  free(tr);
}

void liberaTrie(Trie *tr) {
  if(!tr) return;
  freeNodes(*tr);
  *tr = NULL;
}

int insereTrie(Trie *tr, char *str) {
  if (!tr || !str)
    return 0;
  Trie node = *tr;
  char letter = *str;
  if (letter == '\0') {
    node->end = 1;
    return 1;
  }
  //if alpha, insert
  if(isalpha(letter)) {
    int pos = hashChar(letter);
    if(!node->child[pos]) {
      Trie newNode = startNode();
      if(newNode)
        node->child[pos] = newNode;
      else return 0;
    }
    return insereTrie(&(node->child[pos]), str + 1);
  } else 
    return insereTrie(tr, str + 1); //if not alpha, ignore
}

int buscaTrie(Trie *tr, char *str) {
  if (!tr || !str)
    return 0;
  Trie node = *tr;
  char letter = *str;

  if (letter == '\0' && node->end) 
    return 1;
  

  if(isalpha(letter)) { 
    int pos = hashChar(letter);
    if (!node->child[pos])
      return 0;
    return buscaTrie(&(node->child[pos]), str + 1);
  } else 
    return buscaTrie(tr, str + 1);
}

int removeTrie(Trie *tr, char *str) {

}

void imprimeSubTrie(Trie tr, char *word, int tam) {

  if(!tr || !word || tam < 0) return;

  if(tr->end) {
    word[tam] = '\0';
    printf("%s\n", word);
  }

  for(size_t i = 0; i < MAX_CHARS; i++) {
    if(tr->child[i]) {
      word[tam] = getChar(i);
      imprimeSubTrie(tr->child[i], word, tam + 1);
    }
  }
}

void imprimeTrie(Trie *tr) {
  if (!tr) return;
  char word[100]; 
  imprimeSubTrie(*tr, word, 0);
}

Trie arvorePrefixo(Trie tr, char *prefixo) {
  if(!tr || !prefixo) return NULL;
  char letter = *prefixo;
  if (letter == '\0') 
    return tr;

  if(isalpha(letter)) {
    int pos = hashChar(letter);
    if(tr->child[pos]) {
      return arvorePrefixo(tr->child[pos], prefixo + 1);
    } else return NULL;
  } else return arvorePrefixo(tr, prefixo + 1);
}

void autocompletarTrie(Trie *tr, char *prefixo) {
  if(!tr || !prefixo) return;
  imprimeSubTrie(arvorePrefixo(*tr, prefixo), prefixo, strlen(prefixo));
}