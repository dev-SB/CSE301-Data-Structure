#include <stdio.h>
#include <malloc.h>

struct Node {
    int letter;
    struct Node *next;
    struct Node *prev;
};

void push(int data, struct Node **head, struct Node **end);

void display(struct Node **head, int wrongWordNo);

int checkPrev(struct Node **end);

int checkWord(struct Node **end);

int main() {
    int no;
    int wrongWord = 0;
    scanf("%d", &no);
    scanf("%d");
    struct Node *head = NULL;
    struct Node *end = NULL;
    int wordCount = 0;
    push(32, &head, &end);
    while (no > 0) {
        int c;
        int letterCount = 0;
        while ((c = getchar()) != '\n') {
            if (c < 97) {
                c += 32;
            }
            push(c, &head, &end);
            if (wordCount > 0 && letterCount == 0 && wrongWord == 0) {
                int val = checkPrev(&end);
                if (val == 0) {
                    wrongWord = wordCount+1;
                }
            }
            letterCount++;
        }
        if (wrongWord == 0) {
            int val = checkWord(&end);

            if (val == 0) {
                wrongWord = wordCount+1;
            }
        }
        push(32, &head, &end);
        no--;
        wordCount++;
    }
    display(&head, wrongWord);
    return 0;
}

void push(int data, struct Node **head, struct Node **end) {
    struct Node *n = (struct Node *) malloc(sizeof(struct Node));
    n->letter = data;
    n->next = NULL;
    if (*head == NULL) {
        n->prev = NULL;
        *head = n;
    } else {
        struct Node *ptr = *head;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = n;
        n->prev = ptr;
        *end = n;
    }

}

void display(struct Node **head, int wrongWordNo) {
    struct Node *ptr = *head;
    int wordNo=0;
    int allCorrect=1;
    while (ptr->next != NULL) {
        if (ptr->letter == 32) {
            wordNo++;
        } else if(wordNo==wrongWordNo) {
            allCorrect=0;
            printf("%c", ptr->letter);
        }
        ptr = ptr->next;
    }
    if(allCorrect==1){
        printf("no mistake");
    }
}

int checkPrev(struct Node **end) {

    if (abs((*end)->letter - (*end)->prev->prev->letter) % 24 == 1) {
        return 1;
    } else {
        return 0;
    }
}

int checkWord(struct Node **end) {
    struct Node *ptr = *end;
    while (ptr->prev->letter != 32) {
        ptr = ptr->prev;
    }
    if (ptr->letter == (*end)->letter) {
        return 1;
    } else {
        return 0;
    }
}
