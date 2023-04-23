#include "Doctor.h"
#include <iostream>

int main() {
	// Create a Doctor object
	Doctor doctor;

	// Insert patients
	doctor.insertPatient(1, "John Dempsey", "346-456-7890");
	doctor.insertPatient(2, "Chima Godwin", "987-654-3210");
	doctor.insertPatient(3, "Bob Johnson", "565-555-1290");
	doctor.insertPatient(6, "John Kemp", "155-950-5758");
	doctor.insertPatient(7, "Adebayo Adedeji", "103-456-7890");
	doctor.insertPatient(4, "Williams Uche", "239-456-7890");
	doctor.insertPatient(10, "Pete Markenson", "369-456-7795");
	doctor.insertPatient(11, "Yun Chun", "450-655-2210");
	doctor.insertPatient(9, "Jema Karett", "755-459-0515");
	doctor.insertPatient(12, "Rodriquez Buella", "151-562-9659");
	doctor.insertPatient(5, "Jane Smith", "937-604-3210");
	doctor.insertPatient(8, "Emma Smith", "270-654-3200");
	doctor.insertPatient(20, "Bille Wright", "540-890-6550");
	doctor.insertPatient(15, "Willy Sprow", "155-459-2515");
	doctor.insertPatient(25, "Juse Konga", "795-750-0900");
	doctor.insertPatient(21, "Jane Emerrete", "370-809-3210");
	doctor.insertPatient(19, "Smith Dockerman", "702-554-4200");

	// Display patients
	std::cout << "Added Patient Records: " << std::endl;
	doctor.displayPatients();

	// Update a patient
	doctor.updatePatient(12, "Rodriquez Buella", "151-562-9650");
	doctor.updatePatient(9, "Jemma k. Karette", "755-459-0515");
	doctor.updatePatient(20, "Billena Wright", "540-890-6550");
	doctor.updatePatient(25, "Juse Konga", "359-950-5636");

	// Display patients records After Update
	std::cout << "" << std::endl;
	std::cout << "Patient Records After Updating: " << std::endl;
	doctor.displayPatients();

	// Display sorted patients
	// std::cout << "Sorted Patients: " << std::endl;
	// doctor.displaySortedPatients();

	// Delete a patient
	doctor.deletePatient(6);
	doctor.deletePatient(19);

	// Display patients
	std::cout << "" << std::endl;
	std::cout << "Patient Records After Deleting: " << std::endl;
	doctor.displayPatients();

	// Sort patients using Heap Sort
	std::cout << "" << std::endl;
	std::cout << "Sorted Patient Records (Heap Sort): " << std::endl;
	doctor.sortPatientsUsingHeapSort();

	// Insert a patient history
	doctor.insertPatientHistory(1, "Routine check-up", "2022-04-09");
	doctor.insertPatientHistory(8, "Teeth Whiteening", "2023-01-30");
	doctor.insertPatientHistory(9, "Tooth Removal", "2022-04-09");
	doctor.insertPatientHistory(12, "Brace Removal", "2023-02-25");
	doctor.insertPatientHistory(4, "Routine check-up", "2022-04-09");
	doctor.insertPatientHistory(8, "Check-up", "2023-02-30");
	doctor.insertPatientHistory(1, "Routine check-up", "2022-04-09");
	doctor.insertPatientHistory(8, "Teeth Whiteening", "2023-01-30");

	// Display patient history
	std::cout << "" << std::endl;
	std::cout << "Patient Histories: " << std::endl;
	doctor.displayPatientHistory(1);
	doctor.displayPatientHistory(8);
	doctor.displayPatientHistory(9);
	doctor.displayPatientHistory(4);
	doctor.displayPatientHistory(12);

	return 0;
}
