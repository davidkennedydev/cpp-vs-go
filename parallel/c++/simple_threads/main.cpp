#include <iostream>
#include "simple_threads.h"
using namespace std;

void f(string from) {
  for (int i = 0; i < 3; ++i)
    cout << from << ":" << i << endl;
}

int main(void) {
  
  f("direct");

  run{f, "thread"};

  RUN (
      cout << "running" << endl;
  )

  return 0;
}
