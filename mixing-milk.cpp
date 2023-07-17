#include <iostream>

using namespace std;

struct bucket_type {
  int capacity;
  int amount;
};

int main() {
  bucket_type buckets [3];
  for (int i = 0; i < 3; i++) {
    int capacity;
    int amount;
    scanf("%d %d", &capacity, &amount);
    buckets[i] = bucket_type{capacity, amount};
  }

  int current = 0;
  for (int x = 0; x < 100; x++) {
    int next = current + 1;
    if (current == 2) {
      next = 0;
    }

    int difference = buckets[next].capacity - buckets[next].amount;
    if (difference <= buckets[current].amount) {
      buckets[current].amount -= difference;
      buckets[next].amount = buckets[next].capacity;
    } else {
      buckets[next].amount += buckets[current].amount;
      buckets[current].amount = 0;
    }

    current = next;
  }

  printf(
    "%d\n%d\n%d\n",
    buckets[0].amount,
    buckets[1].amount,
    buckets[2].amount
  );

  return 0;
}
