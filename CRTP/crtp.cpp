#include "crtp.h"

template <typename D>
void exec1(D& derived) {
  std::cout << "*************EXEC1*************\n";
  derived.interface();
  std::cout << "*******************************\n";
}

template <typename D>
void exec2(Base<D> derived) {
  std::cout << "*************EXEC2*************\n";
  derived.interface();
  std::cout << "*******************************\n";
}

/**
 * https://www.modernescpp.com/index.php/c-is-still-lazy
 * https://necatiergin2019.medium.com/sanal-fonksiyonlara-bir-alternatif-olarak-crtp-6b516612866
 */
int main() {
  Der1 der1{};
  Der2 der2{};
  Der3 der3{};
  exec1(der1);
  exec1(der2);
  exec1(der3);
  exec2(der1);
  exec2(der2);
  exec2(der3);
  return EXIT_SUCCESS;
}