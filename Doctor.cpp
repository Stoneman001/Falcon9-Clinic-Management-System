#include "Doctor.h"
#include <iostream>
#include <vector>
#include <algorithm>

// Constructor
Doctor::Doctor() : root(nullptr), head(nullptr) {}

// Destructor
Doctor::~Doctor() {
    Patient* current = head;
    while (current != nullptr) {
        Patient* next = current->getNext();
        delete current;
        current = next;
    }
}
// Overloaded operator<< for the Patient class
std::ostream& operator<<(std::ostream& os, const Patient& patient) {
    os << "Patient ID: " << patient.getId() << ", Name: " << patient.getName()
       << ", Phone Number: " << patient.getPhoneNumber() << std::endl;
    return os;
}
// Insert a patient into the BST and linked list
void Doctor::insertPatient(int id, string name, string phoneNumber) {
    root = insert(root, id, name, phoneNumber);

    Patient* newPatient = new Patient(id, name, phoneNumber);
    if (head == nullptr) {
        head = newPatient;
    } else {
        Patient* temp = head;
        while (temp->getNext() != nullptr) {
            temp = temp->getNext();
        }
        temp->setNext(newPatient);
    }
}
// Update a patient in the BST and the linked list
void Doctor::updatePatient(int id, string name, string phoneNumber) {
    // Update the patient in the BST
    root = update(root, id, name, phoneNumber);

    // Update the patient in the linked list
    Patient* temp = head;
    while (temp != nullptr) {
        if (temp->getId() == id) {
            temp->setName(name);
            temp->setPhoneNumber(phoneNumber);
            break;
        }
        temp = temp->getNext();
    }
}
// Delete a patient from the BST and the linked list
void Doctor::deletePatient(int id) {
    // Delete the patient from the BST
    root = deleteNode(root, id);

    // Delete the patient from the linked list
    if (head == nullptr) {
        return;
    }

    if (head->getId() == id) {
        Patient* toDelete = head;
        head = head->getNext();
        delete toDelete;
        return;
    }

    Patient* temp = head;
    while (temp->getNext() != nullptr) {
        if (temp->getNext()->getId() == id) {
            Patient* toDelete = temp->getNext();
            temp->setNext(temp->getNext()->getNext());
            delete toDelete;
            break;
        }
        temp = temp->getNext();
    }
}
// Search for a patient in the BST
Patient* Doctor::search(Patient* node, int id) {
    if (node == nullptr || node->getId() == id) {
        return node;
    }

    if (id < node->getId()) {
        return search(node->getLeft(), id);
    } else {
        return search(node->getRight(), id);
    }
}
Patient* Doctor::searchPatient(int id) {
    Patient* current = root;
    while (current != nullptr && current->getId() != id) {
        if (id < current->getId()) {
            current = current->getLeft();
        } else {
            current = current->getRight();
        }
    }
    return current;
}

// Find the minimum node in the BST
Patient* Doctor::findMin(Patient* node) {
    return (node->getLeft() == nullptr) ? node : findMin(node->getLeft());
}
void Doctor::displaySortedPatients() {
    std::vector<Patient*> patients;
    inOrderTraversal(root, patients);

    // Use std::sort to sort the patients by ID
    std::sort(patients.begin(), patients.end(), [](const Patient* a, const Patient* b) {
        return a->getId() < b->getId();
    });

    // Display the sorted patients
    for (const auto& patient : patients) {
        std::cout << *patient << endl;
    }
}

// Display patients in the linked list
void Doctor::displayPatients() {
    Patient* temp = head;
    while (temp != nullptr) { std::cout << "ID: " << temp->getId() << " Name: " << temp->getName() << " Phone: " << temp->getPhoneNumber() << std::endl;
        temp = temp->getNext();
    }
}
// Insert a patient into the BST
Patient* Doctor::insert(Patient* node, int id, string name, string phoneNumber) {
    if (node == nullptr) {
        return new Patient(id, name, phoneNumber);
    }

    if (id < node->getId()) {
        node->setLeft(insert(node->getLeft(), id, name, phoneNumber));
    } else {
        node->setRight(insert(node->getRight(), id, name, phoneNumber));
    }

    return node;
}
// Update a patient in the BST
Patient* Doctor::update(Patient* node, int id, string name, string phoneNumber) {
    if (node == nullptr) {
        return nullptr;
    }

    if (node->getId() == id) {
        node->setName(name);
        node->setPhoneNumber(phoneNumber);
        return node;
    }

    if (id < node->getId()) {
        node->setLeft(update(node->getLeft(), id, name, phoneNumber));
    } else {
        node->setRight(update(node->getRight(), id, name, phoneNumber));
    }

    return node;
}

// Delete a patient from the BST
Patient* Doctor::deleteNode(Patient* node, int id) {
    if (node == nullptr) {
        return nullptr;
    }

    if (id < node->getId()) {
        node->setLeft(deleteNode(node->getLeft(), id));
    } else if (id > node->getId()) {
        node->setRight(deleteNode(node->getRight(), id));
    } else {
        if (node->getLeft() == nullptr) {
            Patient* temp = node->getRight();
            delete node;
            return temp;
        } else if (node->getRight() == nullptr) {
            Patient* temp = node->getLeft();
            delete node;
            return temp;
        } else {
            Patient* temp = findMin(node->getRight());
            node->setId(temp->getId());
            node->setName(temp->getName());
            node->setPhoneNumber(temp->getPhoneNumber());
            node->setRight(deleteNode(node->getRight(), temp->getId()));
        }
    }

    return node;
}
// Helper function to heapify a subtree rooted with node i
void Doctor::maxHeapify(Patient** arr, int n, int i) {
    int largest = i; // Initialize largest as root
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // If left child is larger than root
    if (left < n && arr[left]->getId() > arr[largest]->getId()) {
        largest = left;
    }

    // If right child is larger than largest so far
    if (right < n && arr[right]->getId() > arr[largest]->getId()) {
        largest = right;
    }

    // If largest is not root
    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

// Function to implement heap sort
void Doctor::heapSort(Patient** arr, int n) {
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--) {
        maxHeapify(arr, n, i);
    }

    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        std::swap(arr[0], arr[i]);

        // Call max heapify on the reduced heap
        maxHeapify(arr, i, 0);
    }
}
void Doctor::inOrderTraversal(Patient* node, vector<Patient*>& nodeArray) {
    if (node == nullptr) {
        return;
    }

    inOrderTraversal(node->getLeft(), nodeArray);
    nodeArray.push_back(node);
    inOrderTraversal(node->getRight(), nodeArray);
}
void Doctor::sortPatientsUsingHeapSort() {
    // Convert the BST to an array (vector)
    vector<Patient*> patientsArray;
    inOrderTraversal(root, patientsArray);

    // Sort the array using Heap Sort
    heapSort(patientsArray.data(), patientsArray.size());

    // Output the sorted array
    for (const auto& patient : patientsArray) {
        cout << "ID: " << patient->getId() << " Name: " << patient->getName() << " Phone: " << patient->getPhoneNumber() << endl;
    }
}
// function to insert patient history
void Doctor::insertPatientHistory(int patientId, const string& description, const string& dateVisited) {
    // Search for the patient with the given ID
    Patient* patient = searchPatient(patientId);

    // If patient is found, create a new patient history and add it to the patientHistories vector
    if (patient != nullptr) {
        PatientHistory patientHistory(patientId, description, dateVisited);
        patientHistories.push_back(patientHistory);
    }
}
void Doctor::displayPatientHistory(int patientId) {
    bool found = false;
    for (const auto& patientHistory : patientHistories) {
        if (patientHistory.getPatientId() == patientId) {
            std::cout << "Patient ID: " << patientHistory.getPatientId()
                      << " Description: " << patientHistory.getDescription()
                      << " Date Visited: " << patientHistory.getDateVisited()
                      << std::endl;
            found = true;
        }
    }
    if (!found) {
        std::cout << "Patient history not found for ID " << patientId << std::endl;
    }
}
