#include <iostream>
#include "test_class.h"

using namespace std;

void TestClass::printNumber() {
  std::cout << "Number: " << this->number << std::endl;
}
