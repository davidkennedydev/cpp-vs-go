#include <thread>
#include <list>

using std::thread;

namespace simple {

  class AutoThread {
    public:
      template <class Function, class... Args>
        AutoThread(Function func, Args&&... args) :
          t(func, args...) {}
      AutoThread (void (*function)()) :
        t(function) {}
      virtual ~AutoThread () {
        t.join();
      }

    private:
      thread t;
  };

  static std::list<AutoThread> threads;

  class Run {
  public:
    template <class Function, class... Args>
      Run(Function func, Args&&... args) {
        threads.emplace_back(func, args...);
      }
  };

} /* simple */ 

using run = simple::Run;

#define RUN(FUN) run{[](){ FUN }};
