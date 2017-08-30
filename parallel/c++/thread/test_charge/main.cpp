#include <iostream>
#include <vector>
#include <memory>
#include <thread>
using namespace std;

void f(string from) {
  for (int i = 0; i < 3; ++i)
    cout << from << ":" << i << endl;
}

int main(int, char *argv[]) {
  const size_t number_of_threads = atoi(argv[1]);
  vector<unique_ptr<thread>> threads(number_of_threads);

  for (size_t i = 0; i < number_of_threads; ++i)
    threads[i] = unique_ptr<thread>(new thread(f, "thread"));

  for (unique_ptr<thread> &t : threads)
    t->join();
}

