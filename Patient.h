#ifndef PATIENT_H
#define PATIENT_H
#include <string>
using namespace std;

class Patient {
private:
    int id;
    string name;
    string phoneNumber;
    Patient* left;
    Patient* right;
    Patient* next;

public:
    Patient(int id, string name, string phoneNumber);

    // Getters and setters
    int getId() const;
    void setId(int id);
    string getName() const;
    void setName(string name);
    string getPhoneNumber() const;
    void setPhoneNumber(string phoneNumber);
    Patient* getLeft() const;
    void setLeft(Patient* left);
    Patient* getRight() const;
    void setRight(Patient* right);
    Patient* getNext() const;
    void setNext(Patient* next);
};
#endif
