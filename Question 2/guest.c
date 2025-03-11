#define _CRT_SECURE_NO_WARNINGS
#include "guest.h"

//madisont - prog71985 - assign4, q2 - guest object implementation

//The program uses an array of 10 structures. Each structure should hold
//a room identification number, a marker that indicates whether the room
//is booked, and the first and last names of the booking guest

//Create Guest function
GUEST createGuest(char* first, char* last) {
	GUEST guest;
	strncpy(guest.firstName, first, MAXNAME);
	strncpy(guest.lastName, last, MAXNAME);
	return guest;
}

//Get Guest name(s) From Input function
char* getGuestNameInput(char message[], char name[MAXNAME]) {
	//Initialize name variable to be empty at the start of the function
	name[0] = '\0';
	//Initialize isValid variable as false
	bool isValid = false;

	do {
		//Print prompt message
		printf("\n%s", message);
		//Get name input from user and validate
		isValid = validateNameInput(name);

		//isValid will continue to be false if invalid
		if (!isValid)
		{
			printf("ERROR: Invalid input\n");
		}
	} while (!isValid);
	
	return name;
}

void saveGuestToDisk(GUEST g, FILE* fp) {
	fprintf(fp, "GUEST\n");
	fprintf(fp, "%s\n", g.firstName);
	fprintf(fp, "%s\n", g.lastName);
}

//Option c) Show alphabetical listing of guests who have booked a room
//Option a) Sort by first name
int CompareFirstName(const void* gOne, const void* gTwo) {
	return strncmp(((GUEST*)gOne)->firstName, ((GUEST*)gTwo)->firstName, MAXNAME); 
}

void sortGuestsByFirstName(GUEST guests[], int numGuests) {
	qsort(guests, numGuests, sizeof(GUEST), CompareFirstName);
}

void printGuestByFirstName(GUEST g[]) {
	//sort guests alphabetically by first name
	
	//print in alphabetical order
}

//Option c) Show alphabetical listing of guests who have booked a room
//Option b) Sort by last name
int CompareLastName(const void* gOne, const void* gTwo) {
    // Compare last names
	return strncmp(((GUEST*)gOne)->lastName, ((GUEST*)gTwo)->lastName, MAXNAME);
}

void sortGuestsByLastName(GUEST guests[], int numGuests) {
	qsort(guests, numGuests, sizeof(GUEST), CompareLastName);
}

void printGuestByLastName(GUEST g[]) {
	//sort guests alphabetically by last name
	//print in alphabetical order
}

void DeleteGuest(GUEST g) {
	//nothing yet
}