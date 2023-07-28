#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum Cow { Bessie, Elsie, Mildred };

struct Entry {
  int day;
  Cow cow;
  int delta;
};

template <class T> void rightshift(vector<T> &vec, int offset) {
  for (int i = vec.size() - 1; i > offset; i--) {
    vec[i] = vec[i - 1];
  }
}

int maximumIndex(vector<int> integers) {
  int max = integers[0];
  int maxIndex = 0;
  bool hasTie = false;
  for (int i = 1; i < integers.size(); i++) {
    if (integers[i] == max) {
      hasTie = true;
    }
    if (integers[i] > max) {
      maxIndex = i;
      max = integers[i];
      hasTie = false;
    }
  }
  if (hasTie) {
    return -1;
  }
  return maxIndex;
}

int main() {
  int entryCount;
  scanf("%d", &entryCount);

  auto entries = vector<Entry>(entryCount);

  for (int i = 0; i < entryCount; i++) {
    int day;
    char *cow_cstr = new char[10];
    int delta;
    scanf("%d %s %d", &day, cow_cstr, &delta);

    auto cow_str = string{cow_cstr};
    Cow cow;
    if (cow_str == "Bessie") {
      cow = Bessie;
    } else if (cow_str == "Elsie") {
      cow = Elsie;
    } else if (cow_str == "Mildred") {
      cow = Mildred;
    }

    Entry current = Entry{day, cow, delta};

    bool broken = false;
    for (int x = 0; x < i; x++) {
      if (day > entries[x].day) {
        continue;
      }
      rightshift(entries, x);
      entries[x] = current;
      broken = true;
      break;
    }
    if (!broken) {
      entries[i] = current;
    }
  }

  int changes = 0;
  int currentMaxIdx = -1;
  auto stats = vector<int>{7, 7, 7};
  for (Entry entry : entries) {
    stats[entry.cow] = stats[entry.cow] + entry.delta;
    int newMaxIdx = maximumIndex(stats);
    if (newMaxIdx != currentMaxIdx) {
      changes++;
      currentMaxIdx = newMaxIdx;
    }
  }
  printf("%d\n", changes);

  return 0;
}