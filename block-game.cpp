#include <array>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
A less generic permute would look something like this.

for i in range(n):
  for j in range(n):
    for k in range(n):
      options.append([i, j, k])

turned into recursive form, it becomes the following permute function.
*/

template <typename T>
void permute_inner(vector<array<T, 2>> &options, vector<vector<T>> &output,
                   vector<T> &current, int depth) {
  if (depth == options.size()) {
    output.push_back(vector<T>(current));
    return;
  }
  for (int i = 0; i < 2; i++) {
    current[depth] = options[depth][i];
    permute_inner(options, output, current, depth + 1);
  }
}

template <typename T> vector<vector<T>> permute(vector<array<T, 2>> options) {
  vector<vector<T>> output{};
  auto current = vector<T>(options.size());
  permute_inner<T>(options, output, current, 0);
  return output;
}

int main() {
  int n;
  scanf("%d", &n);

  vector<array<string, 2>> words(n);
  for (int i = 0; i < n; i++) {
    char *word_1 = new char[10];
    char *word_2 = new char[10];

    scanf("%s %s", word_1, word_2);
    words[i] = array<string, 2>{string{word_1}, string{word_2}};
  }

  vector<vector<string>> permutations = permute<string>(words);

  array<int, 26> blocks {};
  for (vector<string> collection : permutations) {
    array<int, 26> current_blocks {};
    for (string word : collection) {
      for (int c = 0; c < word.size(); c++) {
        current_blocks[word[c] - 97]++;
      }
    }
    for (int i = 0; i < 26; i++) {
      if (current_blocks[i] > blocks[i]) {
        blocks[i] = current_blocks[i];
      }
    }
  }

  for (int c = 0; c < 26; c++) {
    printf("%d\n", blocks[c]);
  }

  return 0;
}
