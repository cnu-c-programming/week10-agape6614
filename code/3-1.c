#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
    char name[1024];
    int score;
    struct Node* next;
};

struct Node* head = NULL;

void add(char name[], int score){
    
    struct Node* newNode = malloc(sizeof(struct Node));

    strcpy(newNode->name, name);
    newNode->score = score;
    newNode->next = NULL;

    if(head == NULL){
        head = newNode;
        return;
    }

    struct Node* cur = head;

    while(cur->next != NULL){
        cur = cur->next;
    }

    cur->next = newNode;
}

void delete(char name[]){

    struct Node* cur = head;
    struct Node* prev = NULL;

    while(cur != NULL){

        if(strcmp(cur->name, name) == 0){
            if(prev == NULL){
                head = cur->next;
            }
            else{
                prev->next = cur->next;
            }

            free(cur);
            return;
        }

        prev = cur;
        cur = cur->next;
    }
}

void print(){

    struct Node* cur = head;

    while(cur != NULL){
        printf("%s %d\n", cur->name, cur->score);
        cur = cur->next;
    }
}

int main(){
    char cmd[100];
    while(1){
        scanf("%s", cmd);

        if(strcmp(cmd, "add") == 0){

            char name[1024];
            int score;

            scanf("%s %d", name, &score);

            add(name, score);
        }

        else if(strcmp(cmd, "delete") == 0){

            char name[1024];

            scanf("%s", name);

            delete(name);
        }

        else if(strcmp(cmd, "print") == 0){
            print();
        }

        else if(strcmp(cmd, "quit") == 0){
            return 0;
        }
    }

    return 0;
}