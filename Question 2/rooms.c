#define _CRT_SECURE_NO_WARNINGS
#include "rooms.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

//madisont - prog71985 - assign4, q2 - implementation

//The program uses an array of 10 structures. Each structure should hold
//a room identification number, a marker that indicates whether the room
//is booked, and the first and last names of the booking guest

//Create Room function
ROOM createRoom(int number, char status, GUEST guest) {
	ROOM room;
	room.roomNumber = number;
	room.bookStatus = status;
	room.roomGuest = guest;
	return room;
}

ROOM writeRooms(ROOM rooms[MAXROOMS], FILE* fp) {
	
	//Initialize empty rooms for start of file
	for (int i = 0; i < MAXROOMS; i++)
	{
		rooms[i] = createRoom(i + 1, UNBOOKED, createGuest("", ""));
		//Write rooms to file
		fprintf(fp, "ROOM\n");
		fprintf(fp, "Room Number: %d\n", rooms[i].roomNumber);
		fprintf(fp, "Book Status: %c\n", rooms[i].bookStatus);
		fprintf(fp, "Guest: %s %s\n", rooms[i].roomGuest.firstName, rooms[i].roomGuest.lastName);
		fprintf(fp, "\n");
	}

	return rooms[MAXROOMS];
}

//Option a) Show number of empty (unbooked) rooms
void numOfEmptyRooms(ROOM r[]) {
	int emptyRooms = 0;
	for (int i = 0; i <= MAXROOMS; i++)
	{
		//If room is unbooked add to emptyRooms
		if (r[i].bookStatus == UNBOOKED) emptyRooms++;
	}
	printf("\nThere are %d empty rooms.\n\n\n", emptyRooms);
}

//Option b) Show list of the empty (unbooked) rooms
void listEmptyRooms(ROOM r[]) {
	//Check for empty rooms
	for (int i = 0; i <= MAXROOMS; i++)
	{
		//If room is unbooked add to emptyRooms
		if (r[i].bookStatus == UNBOOKED)
		{
			//List empty rooms room numbers
			printf("\nRoom %d is unbooked.", r[i].roomNumber);
		}
	}
}

//Option d) Book a room to a guest
//Books next available room
ROOM bookRoomToGuest(ROOM r[], int numRooms, GUEST guest) {

	for (int i = 0; i < numRooms; i++) 
	{
		if (r[i].bookStatus == UNBOOKED) 
		{
			//Change book status and add guest
			r[i].bookStatus = BOOKED;
			r[i].roomGuest = guest;
			//Return the booked room
			return r[i]; 
		}
	}
	//If no available room is found, return a default room
	ROOM defaultRoom = { 0 };
	return defaultRoom;
}

void saveBookingToDisk(ROOM r, FILE* fp) {
	fprintf(fp, )
}

//Option e) Delete an existing room booking
void deleteBooking(ROOM r) {
	//Change book status to available
	//Remove guest from room
	//Delete guest
}