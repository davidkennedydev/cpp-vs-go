#include <iostream>
#include <thread>
using namespace std;

void f(string from) {
  for (int i = 0; i < 3; ++i)
    cout << from << ":" << i << endl;
}

int main(void) {
  
  f("direct");

  thread t0{f, "thread"};

  thread t1 ([]() {
        cout << "running" << endl;
      });

  t0.join();
  t1.join();
}
