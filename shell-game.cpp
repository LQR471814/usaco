#include<iostream>

using namespace std;

struct attempt_type {
  int first;
  int second;
  int guess;
};

int main() {
  int size;
  scanf("%d", &size);

  attempt_type attempts [size];
  for (int i = 0; i < size; i++) {
    int first;
    int second;
    int guess;
    scanf("%d %d %d", &first, &second, &guess);
    attempts[i] = attempt_type{first, second, guess};
  }

  int maximum = 0;
  for (int i = 0; i < size; i++) {
    int pebble_location = i;
    int guessed = 0;

    for (int a = 0; a < size; a++) {
      attempt_type attempt = attempts[a];
      if (attempt.first == pebble_location) {
        pebble_location = attempt.second;
      } else if (attempt.second == pebble_location) {
        pebble_location = attempt.first;
      }
      if (pebble_location == attempt.guess) {
        guessed++;
      }
    }

    if (guessed > maximum) {
      maximum = guessed;
    }
  }

  printf("%d\n", maximum);
  return 0;
}
