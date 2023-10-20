#include <algorithm>
#include <iostream>
#include <cmath>
#include <string>
#include <thread>
#include <typeinfo>

using namespace std;


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

class SmartPointer {
public:
    SmartPointer(int* ptr) : ptr(ptr) {}

    ~SmartPointer() {
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
        
    }

    void SetAge(int age) {
        
    }

    string GetName() {
    }

    int GetAge() {
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
    std::cout << "\n";
    std::cout << "________________________________________" << std::endl;

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

    SmartPointer smartPointer(new int(10));

    cout << *smartPointer << endl; // Prints 10

    // delete smartPointer; // Memory is automatically freed

    // std::thread thread(threadFunction);

    // thread.join();

    return 0;
}