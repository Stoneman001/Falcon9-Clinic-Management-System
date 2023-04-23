#include "PatientHistory.h"

PatientHistory::PatientHistory(int patientId, const string& description, const string& dateVisited)
    : patientId(patientId), description(description), dateVisited(dateVisited) {}

int PatientHistory::getPatientId() const {
    return patientId;
}

void PatientHistory::setPatientId(const Patient& patient) {
    patientId = patient.getId(); // use the patient object's ID to set the patientId variable
}

string PatientHistory::getDescription() const {
    return description;
}

void PatientHistory::setDescription(const string& description) {
    this->description = description;
}

string PatientHistory::getDateVisited() const {
    return dateVisited;
}

void PatientHistory::setDateVisited(const string& dateVisited) {
    this->dateVisited = dateVisited;
}
