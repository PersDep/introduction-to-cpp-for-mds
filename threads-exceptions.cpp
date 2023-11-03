#include <algorithm>
#include <iostream>
#include <cmath>
#include <functional>
#include <map>
#include <string>
#include <thread>
#include <typeinfo>
#include <vector>

using namespace std;

void my_custom_destructor_for_smart_pointer(std::map<string, int *> *ptr)
{
    delete ptr;
}

template <typename T>
class SmartPointer {
public:
  SmartPointer(T* ptr = nullptr, std::function<void(T*)> custom_delete = nullptr) : ptr(ptr), custom_delete(custom_delete) {}

  ~SmartPointer() {
    if (custom_delete != nullptr) {
      custom_delete(ptr);
    } else {
      delete ptr;
    }
  }

  // Dereference operators
  T* operator->() {
    return ptr;
  }

  T& operator*() {
    return *ptr;
  }

  // Move assignment operator
  SmartPointer& operator=(SmartPointer&& other) noexcept {
    std::swap(ptr, other.ptr);
    std::swap(custom_delete, other.custom_delete);
    return *this;
  }

  // Copy assignment operator
  SmartPointer& operator=(const SmartPointer& other) noexcept {
    if (this != &other) {
      delete ptr;
      ptr = new T(*other.ptr); // use non-throwing new operator
      custom_delete = other.custom_delete;
    }
    return *this;
  }

  void SetCustomDelete(std::function<void(T*)> custom_delete) {
    this->custom_delete = custom_delete;
  }

  // Release the pointer to the caller
  T* release() {
    T* ptr = this->ptr;
    this->ptr = nullptr;
    this->custom_delete = nullptr;
    return ptr;
  }

  // Check if the pointer is nullptr
  bool isNullptr() const {
    return ptr == nullptr;
  }

  // Get the raw pointer
  T* get() const {
    return ptr;
  }

private:
  T* ptr;
  std::function<void(T*)> custom_delete;
};

void threadFunction(int id) {
  cout << "Hello from a thread " << id << endl;
}

class DivideByZeroException : public exception {
public:
  const char* what() const throw() {
    return "Division by zero";
  }
};

int divide(int a, int b) {
  if (b == 0) {
    throw DivideByZeroException();
  }

  return a / b;
}

template <typename T>
struct TypeInfo {
  static const char* name() {
    return typeid(T).name();
  }
};


template <typename T>
class Array {
public:
  Array(int size) : size(size) {
    data = new T[size];
    // data = new T;
  }

  ~Array() {
    delete[] data;
  }

  T& operator[](int index) {
    return data[index];
  }

private:
  T* data;
  int size;
};

//unique_ptr

class SmartPointerSimple {
public:
    SmartPointerSimple(int* ptr) : ptr(ptr) {}

    ~SmartPointerSimple() {
    if (ptr != nullptr) {
        delete ptr;
    }
    }

    /**
     * Overloads the '->' operator to provide access to the underlying pointer.
     * @return A pointer to the underlying object.
     */
    int* operator->() {
        return ptr;
    }

    int& operator*() {
        return *ptr;
    }

    //__mul__
    //__div__

private:
    int* ptr;
};

class PersonClass {
private:
    string name;
    int age;
    double height;
    double weight;
    double geo_position_x, geo_position_y;

public:
    PersonClass() {
      name = "";
      age = 0;
      height = 0.0;
    }

    PersonClass(string name, int age, double height, double weight) {
      this->name = name;
      this->age = age;
      this->height = height;
      this->weight = weight;
    }

    void SetName(string name) {
        this->name = name;
    }

    void SetAge(int age) {
        this->age = age;
    }

    const string &GetName() { // vs string GetName()
        return name;
    }

    int GetAge() {
        return age;
    }

    double GetBodyMassIndex() {
        return weight / pow(height, 2);
    }

    void MovePerson(double x, double y) {
        geo_position_x = x;
        geo_position_y = y;
    }

    void PrintInfo() {
      cout << name << " is " << age << " years old and " << height << " meters tall." << endl;
    }
};

// inherited by class Student, class Teacher, class Worker, 

struct Person {
  string name;
  int age;
  double height;
};

//class Figure;
//inherited: class Circle, class triangle;

// OOP: incapsulation, polymorphism, inheritance

int main(void)
{
    //Smart pointers in STL:
    // unique_ptr
    // shared_ptr
    // weak_ptr -- more rarely used
    // auto_ptr -- more rarely used

    // cout << TypeInfo<int>::name() << endl; // Prints "int"
    // cout << TypeInfo<string>::name() << endl; // Prints "std::string"

    // Array<int> intArray(10);
    // intArray[0] = 1;

    // Array<string> stringArray(10);
    // stringArray[0] = "Hello";

    // auto add = [](int a, int b) {
    //     return a + b;
    // };
    
    // std::cout << add(1, 2) << std::endl;

    // std::vector<std::thread> threads;

    // for (int i = 0; i < 10; i++) {
    //     threads.emplace_back(std::thread([&](int id) {
    //         cout << "Hello from the thread " << id << "; threads amount:" << threads.size() << endl;
    //     }, i));
    // }

    // for (auto& thread : threads) {
    //     thread.join();
    // }

    int a = 10;
    int b = 0;

    // cout << a / b << endl;
    cout << divide(a, b) << endl;

    return 0;
}