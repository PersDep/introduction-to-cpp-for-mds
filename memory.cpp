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

void threadFunction() {
  cout << "Hello from a thread" << endl;
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

    // std::unique_ptr<int> unique_integer_ptr(new int[100]);

    // unique_integer_ptr_copy = unique_integer_ptr; // copy will not work

    // // unique_integer_ptr[10] = 1000;
    // // unique_integer_ptr->
    // *unique_ptr
    // unique_integer_ptr.get()[10] = 1000;
    
    // cout << unique_integer_ptr.get()[10] << endl;

    // long long a0 = 10000000000; // up to 10 gigabytes on stack or even more until you have enough RAM
    // const int a1 = 1000000; // we can get 1 megabyte on stack, but 10 megabytes are already the crash
    // float d;
    // char *e = new char[a0]; // raw pointer
    // cout << "Allocated " << a0 << " bytes in heap successfully" << endl;
    // char b[a1];
    // cout << "Allocated " << a1 << " bytes on stack successfully" << endl;
    // int *c = new int[100]; // raw pointer
    // delete e; // you have to release raw pointers
    // the best option is not to use raw pointers
    // use smart pointers
    // delete c;

    // cout << "Hello" << endl;

    // std::cout << "\n";
    // std::cout << "________________________________________" << std::endl;

    // Person person1;
    // person1.name = "John Doe";
    // person1.age = 30;
    // person1.height = 1.80;

    // cout << person1.name << " is " << person1.age << " years old and " << person1.height << " meters tall." << endl;

    // std::cout << std::endl << std::endl;

    // PersonClass person2("John Doe", 30, 1.80, 80);
    // // PersonClass person2(string("John Doe"), 30, 1.80);
    // person2.PrintInfo();
    // cout << person2.GetBodyMassIndex() << endl;

    // try {
    //     int result = divide(10, 0);
    // } catch (DivideByZeroException& e) {
    //     cout << e.what() << endl;
    // }

    // cout << TypeInfo<int>::name() << endl; // Prints "int"
    // cout << TypeInfo<string>::name() << endl; // Prints "std::string"

    // Array<int> intArray(10);
    // intArray[0] = 1;

    // Array<string> stringArray(10);
    // stringArray[0] = "Hello";

    // SmartPointerSimple smartPointerSimple(new int(10));

    // cout << *smartPointerSimple << endl; // Prints 10

    // delete smartPointerSimple; // Memory is automatically freed

    // std::thread thread(threadFunction);

    // thread.join();

    // Create two SmartPointers that reference each other
    {
        SmartPointer<std::map<string, int *>> smartPointerA(new std::map<string, int *>());
        SmartPointer<std::map<string, int *>> smartPointerB(new std::map<string, int *>());

        // int *a = new int(10);
        // (*smartPointerA)["smartPointerB"] = a;
        // (*smartPointerB)["smartPointerA"] = a;

        (*smartPointerA)["smartPointerB"] = (int *)(&smartPointerB);
        (*smartPointerB)["smartPointerA"] = (int *)(&smartPointerA);

        smartPointerA.SetCustomDelete(my_custom_destructor_for_smart_pointer);
    }

    // Both SmartPointers will be automatically deleted when they go out of scope
    // Create a SmartPointer to a resource that will be shared by multiple threads
    // SmartPointer<std::vector<float>> resource(new std::vector<float>);

    // Create multiple threads that will access the resource
    // std::vector<std::thread> threads;
    // for (int i = 0; i < 10; i++) {
    // threads.push_back(std::thread([&resource]() {
    //     // Access the resource
    // }));
    // }

    // // Join all of the threads
    // for (auto& thread : threads) {
    //     thread.join();
    // }

    // The SmartPointer will automatically delete the resource when all of the threads have finished using it

    // map<string, int *> my_map;
    // map<vector, int *> my_map_with_vector_as_a_key;

    return 0;
}