// NOT DONE!!!!!!!!!
// array class for educational purposes
#include <algorithm>
#include <stdexcept>

template <typename T>
class beginner_list {
public:
  beginner_list(int n) {
    storage = new T[n];
    size = 0;
  }
  beginner_list(const beginner_list&);
  beginner_list& operator=(const beginner_list&);
  ~beginner_list() {
    delete storage;
    storage = nullptr;
  }
  T& operator[](int n) {
    if (n > size) throw std::out_of_range("Index out of range");
    return storage[n];
  }
private:
  T* storage = nullptr;
  int size = 0;
}; 

