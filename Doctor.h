#ifndef DOCTOR_H
#define DOCTOR_H
#include "Patient.h"
#include "PatientHistory.h"
#include <string>
#include <vector> // Include the vector header

using namespace std;

class Doctor {
private:
    Patient* root;
    Patient* head;
    vector<PatientHistory> patientHistories; // container to store patient history
    void inOrderTraversal(Patient* node, std::vector<Patient*>& patients);
    void maxHeapify(Patient** arr, int n, int i);
    void heapSort(Patient** arr, int n);

public:
    Doctor();
   ~Doctor(); // Add destructor declaration

    // Member functions
    Patient* searchPatient(int id);
    void insertPatient(int id, string name, string phoneNumber);
    void updatePatient(int id, string name, string phoneNumber);
    void deletePatient(int id);
    void displaySortedPatients();
    void displayPatients();
    void sortPatientsUsingHeapSort();
    void insertPatientHistory(int patientId, const string& description, const string& dateVisited);
    void displayPatientHistory(int patientId);

private:
    Patient* insert(Patient* node, int id, string name, string phoneNumber);
    Patient* update(Patient* node, int id, string name, string phoneNumber);
    Patient* deleteNode(Patient* node, int id);
    Patient* search(Patient* node, int id);
    Patient* findMin(Patient* node);
};

#endif
