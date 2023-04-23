#ifndef PATIENTHISTORY_H
#define PATIENTHISTORY_H

#include <string>
#include "Patient.h" // include Patient header file

class PatientHistory {
private:
    int patientId;
    string description;
    string dateVisited;

public:
    PatientHistory(int patientId, const string& description, const string& dateVisited);

    // Getters and setters
    int getPatientId() const;
    void setPatientId(const Patient& patient); // changed parameter type to const reference to Patient object
    string getDescription() const;
    void setDescription(const string& description);
    string getDateVisited() const;
    void setDateVisited(const string& dateVisited);
};

#endif
