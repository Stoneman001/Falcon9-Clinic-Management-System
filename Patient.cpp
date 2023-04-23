#include "Patient.h"

// Constructor
Patient::Patient(int id, string name, string phoneNumber)
    : id(id), name(name), phoneNumber(phoneNumber), left(nullptr), right(nullptr), next(nullptr) {}

// Getters and setters
int Patient::getId() const {
    return id;
}

void Patient::setId(int id) {
    this->id = id;
}

string Patient::getName() const {
    return name;
}

void Patient::setName(string name) {
    this->name = name;
}

string Patient::getPhoneNumber() const {
    return phoneNumber;
}

void Patient::setPhoneNumber(string phoneNumber) {
    this->phoneNumber = phoneNumber;
}

Patient* Patient::getLeft() const {
    return left;
}

void Patient::setLeft(Patient* left) {
    this->left = left;
}

Patient* Patient::getRight() const {
    return right;
}

void Patient::setRight(Patient* right) {
    this->right = right;
}

Patient* Patient::getNext() const {
    return next;
}

void Patient::setNext(Patient* next) {
    this->next = next;
}
