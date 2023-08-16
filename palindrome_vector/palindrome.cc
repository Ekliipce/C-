#include "palindrome.hh"

#include <iostream>
#include <vector>

int main() {
  std::vector<char> v1{'a', 'b', 'b', 'a'};
  std::vector<std::string> v2{"<3", "YAKA", "<3"};
  std::vector<int> v3{1, 2, 1, 2, 2, 1};
  std::vector<float> v4{};
  std::vector<bool> v5{true};

  (palindrome(v1));
  (palindrome(v2));
  (palindrome(v3));
  (palindrome(v4));
  (palindrome(v5));

  std::cout << "v1 is " << (palindrome(v1) ? "" : "not ") << "a palindrome\n";
  std::cout << "v2 is " << (palindrome(v2) ? "" : "not ") << "a palindrome\n";
  std::cout << "v3 is " << (palindrome(v3) ? "" : "not ") << "a palindrome\n";
  std::cout << "v4 is " << (palindrome(v4) ? "" : "not ") << "a palindrome\n";
  std::cout << "v5 is " << (palindrome(v5) ? "" : "not ") << "a palindrome\n";
}
