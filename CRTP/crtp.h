#ifndef CPPDESIGNPATTERNS_CRTP_CRTP_H
#define CPPDESIGNPATTERNS_CRTP_CRTP_H

#include <iostream>

template <typename Der>
struct Base {
  Base() {std::cout << "Base::Base()\n";}
  void interface() {
    static_cast<Der*>(this)->impl();
  }

  void impl () const {
    std::cout << "Base::impl() const\n";
  }
};

struct Der1 : public Base<Der1> {
  Der1() {std::cout << "Der1::Der1()\n";}
  /**
   * Taban sınıf fonksiyonun imzasıyla
   * türemiş sınıfın fonksiyonunun imzasının
   * aynı olması gerekmiyor
   */
  uint8_t impl () {
    std::cout << "Der1::impl()\n";
    return UINT8_MAX;
  }
};

struct Der2 : public Base<Der2> {
  Der2() {std::cout << "Der2::Der2()\n";}
};

class Der3 : public Base<Der3> {
public:
  Der3() {std::cout << "Der3::Der3()\n";}
  /**
   * Taban sınıf fonksiyonun imzasıyla
   * türemiş sınıfın fonksiyonunun imzasının
   * aynı olması gerekmiyor
   */
  void impl () {
    std::cout << "Der3::impl()\n";
    this->private_func();
  }

private:
  void private_func() const {
    std::cout << "Der3::private_func()\n";
  }
  /*
  void impl () {
    std::cout << "Der3::impl()\n";
  }
  */
};

#endif // CPPDESIGNPATTERNS_CRTP_H
