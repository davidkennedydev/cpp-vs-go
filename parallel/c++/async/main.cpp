#include <iostream>
#include <future>
using namespace std;

void f(string from) {
  for (int i = 0; i < 3; ++i)
    cout << from << ":" << i << endl;
}

int main(void) {
  
  f("direct");

  auto x = async(f, "future async");

  auto y = async([]() {
        cout << "running" << endl;
      });
}
