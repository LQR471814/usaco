#include<string>
#include<iostream>

using namespace std;

int main() {
  // input
  string input {};
  getline(cin >> ws, input); // ws ignores all leading whitespace
  cout << input << "\n";

  // output
  string name { "Hello" };
  name += " world\n";
  cout << name;

  return 0;
}