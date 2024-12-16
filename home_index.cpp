#include <iostream>
#include <vector>
#include <string>


using namespace std;

class Person {
private:
  string name;
  int age;

public:
  // Конструктор
  Person(string n, int a) : name(n), age(a) {}

  // Геттери
  string getName() const { return name; }
  int getAge() const { return age; }

  // Метод для виведення інформації про людину
  void printPersonInfo() const {
    cout << "Ім'я: " << name << ", вік: " << age << endl;
  }
};

class Apartment {
private:
  int apartmentNumber;
  vector<Person*> residents;

public:
  // Конструктор
  Apartment(int num) : apartmentNumber(num) {}

  // Додавання мешканця до квартири
  void addResident(Person* p) {
    residents.push_back(p);
  }

  // Видалення мешканця з квартири
  void removeResident(Person* p) {
      for (size_t i = 0; i < residents.size(); ++i) {
          if (residents[i] == p) {
              delete residents[i];
              residents[i] = nullptr;
              residents.erase(residents.begin() + i);
              return;
          }
      }
  }

   // Виведення інформації про номер квартири
  void printResidents() const {
    cout << "Квартира " << apartmentNumber << ":" << endl;
    for (const Person* p : residents) {
      if (p != nullptr) {
          p->printPersonInfo();
      }
    }
  }
  // Деструктор
  ~Apartment() {
    for (Person* resident : residents) {
      delete resident;
    }
  }
};


class House {
private:
  vector<Apartment*> apartments;

public:
  // Конструктор
  House() {}

  // Додавання квартири до будинку
  void addApartment(Apartment* a) {
    apartments.push_back(a);
  }

  // Виведення інформації про всіх мешканців будинку, метод this ->
  void printAllResidents() const {
    for (const Apartment* a : apartments) {
      if (a != nullptr) {
        a->printResidents();
      }
    }
  }

   // Деструктор
   ~House() {
    for (Apartment* apartment : apartments) {
      delete apartment;
    }
  }
};

int main() {
  House myHouse;
  system("chcp 65001");

  // Створення квартир та додавання мешканців(єкземплярів)
  Apartment* apt1 = new Apartment(342);
  Person* person1 = new Person("Сергій", 24);
  apt1->addResident(person1);
  myHouse.addApartment(apt1);


  Apartment* apt2 = new Apartment(235);
  Person* person2 = new Person("Марк", 35);
  apt2->addResident(person2);
  myHouse.addApartment(apt2);

  // Виведення інформації про мешканців
  myHouse.printAllResidents();

}
