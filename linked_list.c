#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int data; 
    struct node *next; // 自己参照というらしい
};

struct node *head = NULL;
struct node *current = NULL;

void insertbegin(int data) { // 一番最初用
    // 新しいノードを作る
    struct node *newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data = data; // データをいれる
    newNode->next = head; // nextにheadを入れる
    head = newNode;
}

void insertend(int data){
    // もし一番初めだったら処理を分ける必要がある
    if (head == NULL){ // headがNULLの状態で->nextをするとsegment falutになった
        insertbegin(data);
    } else {
        // 新しいノードを作る
        struct node *newNode = (struct node*) malloc(sizeof(struct node));
        newNode->data = data;
        struct node *linkedlist = head;

        // 一番最後に追加されたノードを探す
        while(linkedlist->next != NULL) {
              linkedlist = linkedlist->next;
        }
        // 一番最後のノードのnextを新しく作ったノードにする
        linkedlist->next = newNode;
    }
}

void main() {
    int i;
    int N = 100;

    // リストを作る
    for (i=0; i<N; i++) {
        insertend(i);
    }

    // リストを表示する
    struct node *p = head; // headから見ていく
    printf("\n[");
    while (p != NULL) {
        printf(" %d ", p->data);
        p = p->next; // 現在のノードのnextを次見るやつにする
    }
    printf("]\n");

}




