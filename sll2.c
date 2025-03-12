#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

typedef struct node {
  char name[50];
  int nrp;
  struct node* next;  // Pakai struct node, bukan Node
} Node;

Node* head = NULL;
Node* newNode = NULL;

void getUserChoice();
void dummy();
void display();
void allocation();
void sisipAwal();

int main() {
  dummy();
  getUserChoice();

}
void allocation() {
  newNode = (Node*) malloc(sizeof(Node));
  if (newNode == NULL) {
    puts("Memori Penuh");
    exit(0);
  }
  printf("\nName\t: ");
  fgets(newNode->name, 50, stdin);
  newNode->name[strcspn(newNode->name, "\n")] = 0;
  fflush(stdin);

  printf("NRP\t: ");
  scanf("%d", &newNode->nrp);
  fflush(stdin);
  newNode->next = NULL;
}

void sisipAwal() {
  allocation();
  newNode->next = head;
  head = newNode;

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
      display();
      break;
    default:
      puts("INPUT INVALID!");
    }

    printf("\nWant to continue again [y/n] : ");
    scanf(" %c%*c", &answer);
  } while (answer == 'y' || answer == 'Y');
  puts("\nSELESAI");
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