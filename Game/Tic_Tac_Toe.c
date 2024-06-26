#include <stdio.h>
#include <stdlib.h>
#include<string.h>
void verticlecheck(char *a, int n, int *t, char *player, int u, int *z);
void ask(int *z);
void horizontalcheck(char *a, int n, int *t, char *player, int y, int *z);
void draw_check();
void diagonalcheck(char *a, int n, int *t, char *player, int o, int *z);
void check(char *a, int n, int *t, char *player, int r, int *z);
void input1(char *a, int n, int *t, char *player1, int s, int *z);
void input2(char *a, int n, int *t, char *player2, int d, int *z);
void store(int input, char play, char *a, int n, int *t, char *player, int e,
           int *z);
void print(char *a, int n, int *t);
int main() {
  int replay = 1;
  int *z = &replay;
  char player1[10], player2[10];
  printf("Enter name of player 1 : ");
  fgets(player1, 10, stdin);
  printf("Enter name of player 2 : ");
  fgets(player2, 10, stdin);
  while (replay != 0) {
    int t = 0;
    printf("Enter a number between 1-9");
    char a[10];
    a[0] = '_';
    for (int i = 1; i < 10; i++) {
      a[i] = i;
    }
    for (int i = 1; i < 9; i = i + 3) {
      printf("\n%d | %d | %d\n", a[i], a[i + 1], a[i + 2]);
      if (i < 7) {
        printf("----------");
      }
    }
    for (int i = 1; i < 10; i++) {
      a[i] = ' ';
    }

    for (int i = 0; i < 10; i++) {
      input1(a, 10, &t, player1, 10, z);
      if (*z == 0)
        return 0;
      if (t == 1)
        break;
      input2(a, 10, &t, player2, 10, z);
      if (*z == 0)
        return 0;
      if (t == 1)
        break;
    }
  }
}
void store(int input, char play, char *a, int n, int *t, char *player, int e,
           int *z) {

  for (int i = 1; i < 10; i++) {
    if (input == i) {
      a[i] = play;
    }
  }
  check(a, n, t, player, 10, z);
  if (*z == 0)
    return;
  if (*t == 1)
    return;
  print(a, n, t);
  if (*t == 1)
    return;
}
void input1(char *a, int n, int *t, char *player1, int s, int *z) {
  int input;
  printf("%sEnter a place : ", player1);

  scanf("%d", &input);
  if (a[input] == '*' || a[input] == 'o' || input > 9 || input < 1) {
    input1(a, 10, t, player1, 10, z);
  } else {
    store(input, '*', a, n, t, player1, 10, z);
  }
}
void input2(char *a, int n, int *t, char *player2, int d, int *z) {
  int input;
  printf("%senter your place : ", player2);

  scanf("%d", &input);
  if (*t == 1)
    return;
  if (a[input] == '*' || a[input] == 'o' || input > 9 || input < 1) {
    input2(a, 10, t, player2, 10, z);
  } else {
    store(input, 'o', a, n, t, player2, 10, z);
  }
}
void print(char *a, int n, int *t) {
  for (int i = 1; i < 10; i = i + 3) {
    printf("\n%c | %c | %c\n", a[i], a[i + 1], a[i + 2]);
    if (i < 7) {
      printf("----------");
    }
  }
}
void check(char *a, int n, int *t, char *player, int r, int *z) {
  horizontalcheck(a, n, t, player, 10, z);
  if (*z == 0)
    return;
  verticlecheck(a, n, t, player, 10, z);
  if (*z == 0)
    return;
  diagonalcheck(a, n, t, player, 10, z);
  if (*z == 0)
    return;
  draw_check(a, n, t, player, 10, z);
  if (*z == 0)
    return;
}
void draw_check(char *a, int n, int *t, char *player, int y, int *z) {
  int test;
  for (int i = 1; i < 10; i++) {
    if (a[i] == '*' || a[i] == 'o') {
      if (i == 9) {
        printf("Game is draw\n");
        print(a, n, t);
        ask(z);
        if (*z == 0)
          return;
        *t = 1;
        return;
      }
    } else if (a[i] == ' ') {
      return;
    }
  }
}

void horizontalcheck(char *a, int n, int *t, char *player, int y, int *z) {
  for (int i = 1; i < 9; i = i + 3) {
    if (a[i] == a[i + 1] && a[i] == a[i + 2]) {
      if (a[i] == '*') {
        system("clear");
        printf("%swins the game", player);
        print(a, n, t);
        ask(z);
        if (*z == 0)
          return;
        *t = 1;
        return;
      } else if (a[i] == 'o') {
        system("clear");
        printf("%swins the game", player);
        print(a, n, t);
        ask(z);
        if (*z == 0)
          return;
        *t = 1;
        return;
      }
    }
  }
}
void verticlecheck(char *a, int n, int *t, char *player, int u, int *z) {
  for (int i = 1; i < 4; i++) {
    if (a[i] == a[i + 3] && a[i] == a[i + 6]) {
      if (a[i] == '*') {
        system("clear");
        printf("%swins the game", player);
        print(a, n, t);
        ask(z);
        if (*z == 0)
          return;
        *t = 1;
        return;
      } else if (a[i] == 'o') {
        system("clear");
        printf("%swins the game", player);
        print(a, n, t);
        ask(z);
        if (*z == 0)
          return;
        *t = 1;
        return;
      }
    }
  }
}
void diagonalcheck(char *a, int n, int *t, char *player, int o, int *z) {
  if (a[1] == a[5] && a[1] == a[9]) {
    if (a[1] == '*') {
      system("clear");
      printf("%swins the game", player);
      print(a, n, t);
      ask(z);
      if (*z == 0)
        return;
      *t = 1;
      return;
    } else if (a[1] == 'o') {
      system("clear");
      printf("%swins the game", player);
      print(a, n, t);
      ask(z);
      if (*z == 0)
        return;
      *t = 1;
      return;
    }
  }
  if (a[3] == a[5] && a[3] == a[7]) {
    if (a[3] == '*') {
      system("clear");
      printf("%swins the game", player);
      print(a, n, t);
      ask(z);
      if (*z == 0)
        return;
      *t = 1;
      return;
    } else if (a[3] == 'o') {
      system("clear");
      printf("%swins the game", player);
      print(a, n, t);
      ask(z);
      if (*z == 0)
        return;
      *t = 1;
      return;
    }
  }
}
void ask(int *z) {
  printf("\nDo you want to play the game again ?\n1:Yes\n0 : No\n");
  scanf("%d", z);
  if (*z != 0 && *z != 1) {
    ask(z);
  }
  if (*z == 0)
    return;
}