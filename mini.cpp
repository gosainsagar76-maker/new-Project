#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char usn[20], name[30], branch[20], phno[15];
    int sem;
    struct node *next;
};

struct node *head = NULL;

struct node* getnode() {
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter USN Name Branch Sem Phone: ");
    scanf("%s%s%s%d%s", temp->usn, temp->name, temp->branch, &temp->sem, temp->phno);
    temp->next = NULL;
    return temp;
}

void createFront(int n) {
    int i;
    struct node *temp;
    for(i = 0; i < n; i++) {
        temp = getnode();
        temp->next = head;
        head = temp;
    }
}

void display() {
    struct node *p = head;
    int count = 0;
    if(head == NULL) {
        printf("List empty\n");
        return;
    }
    while(p != NULL) {
        printf("%s %s %s %d %s\n", p->usn, p->name, p->branch, p->sem, p->phno);
        p = p->next;
        count++;
    }
    printf("Node count = %d\n", count);
}

void insertFront() {
    struct node *temp = getnode();
    temp->next = head;
    head = temp;
}

void deleteFront() {
    struct node *temp;
    if(head == NULL) {
        printf("List empty\n");
        return;
    }
    temp = head;
    head = head->next;
    free(temp);
}

void insertEnd() {
    struct node *temp = getnode(), *p = head;
    if(head == NULL) {
        head = temp;
        return;
    }
    while(p->next != NULL) p = p->next;
    p->next = temp;
}

void deleteEnd() {
    struct node *p = head, *q = NULL;
    if(head == NULL) {
        printf("List empty\n");
        return;
    }
    if(head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }
    while(p->next != NULL) {
        q = p;
        p = p->next;
    }
    q->next = NULL;
    free(p);
}

void insertPos() {
    int pos, i;
    struct node *temp = getnode(), *p = head;
    printf("Enter position: ");
    scanf("%d", &pos);
    if(pos == 1) {
        temp->next = head;
        head = temp;
        return;
    }
    for(i = 1; i < pos - 1 && p != NULL; i++) p = p->next;
    if(p == NULL) {
        printf("Invalid position\n");
        free(temp);
        return;
    }
    temp->next = p->next;
    p->next = temp;
}

void deletePos() {
    int pos, i;
    struct node *p = head, *q;
    printf("Enter position: ");
    scanf("%d", &pos);
    if(head == NULL) {
        printf("List empty\n");
        return;
    }
    if(pos == 1) {
        head = head->next;
        free(p);
        return;
    }
    for(i = 1; i < pos - 1 && p != NULL; i++) p = p->next;
    if(p == NULL || p->next == NULL) {
        printf("Invalid position\n");
        return;
    }
    q = p->next;
    p->next = q->next;
    free(q);
}

void reverse() {
    struct node *prev = NULL, *cur = head, *next;
    while(cur != NULL) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    head = prev;
}

int main() {
    int ch, n;
    do {
        printf("\n1.Create\n2.Display\n3.Insert End\n4.Delete End\n5.Insert Front\n6.Delete Front\n7.Insert Pos\n8.Delete Pos\n9.Reverse\n10.Exit\nEnter choice: ");
        scanf("%d", &ch);
        switch(ch) {
            case 1: printf("Enter n: "); scanf("%d", &n); createFront(n); break;
            case 2: display(); break;
            case 3: insertEnd(); break;
            case 4: deleteEnd(); break;
            case 5: insertFront(); break;
            case 6: deleteFront(); break;
            case 7: insertPos(); break;
            case 8: deletePos(); break;
            case 9: reverse(); break;
            case 10: break;
            default: printf("Invalid choice\n");
        }
    } while(ch != 10);
    return 0;
}