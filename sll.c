#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

#define MAX 50
typedef int itemType;
typedef struct node Node;

struct node {
  char name[MAX];
  int nrp;
  Node* next;
};

Node* head, * newNode;

void allocation();
void freeNode(Node*);
void sisipAwal();
void sisipAkhir();
void hapusAwal();
void hapusAkhir();
void display();
void getUserChoice();
void dummy();


int main() {
  // dummy();
  getUserChoice();
}

void getUserChoice() {
  char answer, choice;
  puts("SELAMAT DATANG DI PROGRAM APLIKASI");
  puts("======LINKED LIST SEDERHANA======");

  do {
    puts("\nPilihan:");
    puts(" 1. Sisip Awal");
    puts(" 2. Sisip Akhir");
    puts(" 3. Hapus Awal");
    puts(" 4. Hapus Akhir");
    puts(" 5. Menampilkan");
    printf("Masukkan pilihan anda: ");
    scanf(" %c%*c", &choice);

    switch (choice) {
    case '1':
      // sisipAwal();
      break;
    case '2':
      // sisipAkhir();
      break;
    case '3':
      // hapusAwal();
      break;
    case '4':
      // hapusAkhir();
      break;
    case '5':
      // display();
      break;
    default:
      puts("INPUT INVALID!");
    }

    printf("\nWant to continue again [y/n] : ");
    scanf(" %c%*c", &answer);
  } while (answer == 'y' || answer == 'Y');
  puts("\nSELESAI");
}

// minjem memory di ram, dan input dari user
// dipake di 'sisip awal' n 'sisip akhir'
void allocation() {
  newNode = (Node*) malloc(sizeof(Node));

  if (newNode == NULL) {
    puts("\nALLOCATION FAILED! Memory not available to add a new node.");
    exit(0);
  }

  printf("\nName\t: ");
  fgets(newNode->name, MAX, stdin);
  newNode->name[strcspn(newNode->name, "\n")] = 0;
  fflush(stdin);

  printf("NRP\t: ");
  scanf("%d", &newNode->nrp);
  fflush(stdin);

  newNode->next = NULL;
}

void freeNode(Node* p) {
  free(p);
  p = NULL;
}

void sisipAwal() {
  allocation();
  newNode->next = head;
  head = newNode;
}

void sisipAkhir() {
  allocation();
  Node* tail = head;

  if (head == NULL) {
    head = newNode;
    return;
  }
  while (tail->next != NULL) {
    tail = tail->next; // kalo tidak null, masuk ke statement ini
  }
  tail->next = newNode;
}

void display() {
  if (head == NULL) {
    puts("Linked List Empty");
    return;
  }

  Node* read = head;

  puts("\nNo Name\t\tNRP");
  for (int i = 1; read != NULL; i++) {
    printf("%-3d%-12s%3d\n", i, read->name, read->nrp);
    read = read->next;
  }
}

void hapusAwal() {
  if (head == NULL) {
    puts("Linked List Empty, nothing to delete");
    return;
  }
  Node* temp = head;
  head = head->next;
  freeNode(temp);
}

void hapusAkhir() {
  if (head == NULL) {
    puts("Linked List Empty, nothing to delete");
    return;
  }

  Node* remove = head, * before;
  while (remove->next != NULL) {
    before = remove;
    remove = remove->next;
  }
  before->next = NULL;
  freeNode(remove);
}

void dummy() {
  Node* one = (Node*) malloc(sizeof(Node));
  strcpy(one->name, "John");
  one->nrp = 11;

  Node* two = (Node*) malloc(sizeof(Node));
  strcpy(two->name, "Zoe");
  two->nrp = 22;

  head = one;
  one->next = two;
  two->next = NULL;
}


// gcc sll.c -o sll && sll