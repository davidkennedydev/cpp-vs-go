#include <iostream>
using namespace std;

void f(string from) {
  for (int i = 0; i < 3; ++i)
    cout << from << ":" << i << endl;
}

int main(void) {
  
  f("direct");

#pragma omp parallel
#pragma omp sections
  {
#pragma omp section
    f("OpenMP parallel");

#pragma omp section
    []() {
      cout << "running" << endl;
    }();
  }
}
