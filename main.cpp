#include <iostream>
#include <string>
#include "mytype.cpp"
#include "marks.cpp"
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

int main() {
  setlocale(LC_ALL, "Russian"); // Русская локализация консоли
  ifstream file("text.txt");
  if (!file.is_open()) {
    cout << "Failed to open file." << endl;
    return 1;
  }

  string line;
  getline(file, line);
  int numElements = stoi(line);

  vector<Reading> readings;
  for (int i = 0; i < numElements; i++) {
    getline(file, line);

    istringstream iss(line);
    string type;
    int weight;
    string direction;
    double coast;

    getline(iss, type, '|');
    getline(iss, line, '|');
    weight = stoi(line);
    getline(iss, direction, '|');
    getline(iss, line, '|');
    coast = stod(line);

    readings.push_back(Reading(type, weight, direction, coast));
  }

  file.close();

  // Вывод списка считанных элементов
  for (Reading& reading : readings) {
    cout << "Type: " << reading.type << endl;
    cout << "Weight: " << reading.weight << endl;
    cout << "Direction: " << reading.direction << endl;
    cout << "Coast: " << reading.coast << endl;
    cout << endl;
  }




  ifstream file2("marks.txt");
  if (!file2.is_open()) {
    cout << "Failed to open file." << endl;
    return 1;
  }

  string line2;
  getline(file2, line2);
  int numElements2 = stoi(line2);

  vector<Marks> marksList;
  for (int i = 0; i < numElements2; i++) {
    getline(file2, line2);

    istringstream iss(line2);
    string valueStr;
    string countStr;

    getline(iss, valueStr, '|');
    getline(iss, countStr, '|');

    int value = stoi(valueStr);
    int count = stoi(countStr);

    Marks marks(value, count);
    marksList.push_back(marks);
  }

  file2.close();

  // Print the list of Marks
  for (const Marks& marks : marksList) {
    cout << "Value: " << marks.value << endl;
    cout << "Count: " << marks.count << endl;
    cout << endl;
  }

  for (Reading& reading : readings) {
      if (reading.type == "простое" and reading.direction == "по России") {
          if (marksList[0].count == 0){
              continue;
          } else {
              reading.coast = reading.coast + marksList[0].value;
              marksList[0].count--;
          }

      } else if (reading.type == "простое" and reading.direction == "За границу") {
          if (marksList[1].count == 0){
              continue;
          } else {
              reading.coast = reading.coast + marksList[1].value;
              marksList[1].count--;
          }
      } else if (reading.type == "простое" and reading.direction == "Беларусь/Казахстан") {
          if (marksList[2].count == 0){
              continue;
          } else {
              reading.coast = reading.coast + marksList[2].value;
              marksList[2].count--;
          }
      } else if (reading.type == "заказное" and reading.direction == "по России") {
          if (marksList[2].count == 0){
              continue;
          } else {
              reading.coast = reading.coast + marksList[2].value;
              marksList[2].count--;
          }
      } else if (reading.type == "заказное" and reading.direction == "За границу") {
          if (marksList[3].count == 0){
              continue;
          } else {
              reading.coast = reading.coast + marksList[3].value;
              marksList[3].count--;
          }
        } else if (reading.type == "заказное" and reading.direction == "Беларусь/Казахстан") {
            if (marksList[4].count == 0){
                continue;
            } else {
                reading.coast = reading.coast + marksList[4].value;
                marksList[4].count--;
            }
        } else if (reading.type == "1 класс" and reading.direction == "по России") {
            if (marksList[4].count == 0){
                continue;
            } else {
                reading.coast = reading.coast + marksList[4].value;
                marksList[4].count--;
            }
      } else if (reading.type == "1 класс" and reading.direction == "За границу") {
          if (marksList[5].count == 0){
              continue;
          } else {
              reading.coast = reading.coast + marksList[5].value;
              marksList[5].count--;
          }
        } else if (reading.type == "1 класс" and reading.direction == "Беларусь/Казахстан") {
            if (marksList[6].count == 0){
                continue;
            } else {
                reading.coast = reading.coast + marksList[6].value;
                marksList[6].count--;
            }
        }
  }


  ofstream file3("result.txt", ios::trunc);
  if (!file3.is_open()) {
    cout << "Failed to open file." << endl;
    return 1;
  }
  file3 << numElements << endl;

  for (const Reading& reading : readings) {
    file3 << reading.type << "|" << reading.weight << "|" << reading.direction << "|" << reading.coast << "|" << endl;
  }

  file3.close();

  ofstream file4("final_marks.txt", ios::trunc);
  if (!file4.is_open()) {
    cout << "Failed to open file." << endl;
    return 1;
  }
  file4 << numElements2 << endl;

  for (const Marks& marks : marksList) {
    file4 << marks.value << "|" << marks.count << "|" << endl;
  }

  file4.close();

  for (const Marks& marks : marksList) {
    cout << "Value: " << marks.value << endl;
    cout << "Count: " << marks.count << endl;
    cout << endl;
  }

  return 0;
}