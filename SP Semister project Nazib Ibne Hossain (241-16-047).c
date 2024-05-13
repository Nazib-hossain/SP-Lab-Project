#include <stdio.h>
#include <stdbool.h>          //For loop and switch uses in functions
#include <conio.h>           // For _getch() function
#define NUM_ROOMS 50

// Structure to represent a customer

struct Customer {
    int roomNumber;
    int numGuests;
    int stayDuration;        // in days
    int Occupied;
};

// Initialize array of customers

struct Customer customers[NUM_ROOMS] = {0};

// Function to check if a room is occupied

int RoomOccupied(int roomNumber) {
    return customers[roomNumber - 1].Occupied;
}

// Function to mark a room as occupied and update customer details

void checkIn(int roomNumber, int numGuests, int stayDuration) {
    struct Customer *customer = &customers[roomNumber - 1];
    customer->roomNumber = roomNumber;
    customer->numGuests = numGuests;
    customer->stayDuration = stayDuration;
    customer->Occupied = true;
}

// Function to mark a room as unoccupied

void checkOut(int roomNumber) {
    customers[roomNumber - 1].Occupied = false;
}

// Function to display room status

void displayRoomStatus() {
    printf("\n");
    printf("\n");
    printf("\tRoom Status (Occupied = Occupied, Unoccupied = U):\n");
    printf("\t-------------------------------------------------\n");
    printf("\n");
    for (int i = 0; i < NUM_ROOMS; i++)
    {
        printf("\n");
        printf("\t      Room %d: %c\n", i + 1, RoomOccupied(i + 1) ? 'O' : 'U');

    }
}

// Function to clear the terminal screen

void clearScreen() {
    system("cls");         // Execute the "cls" command to clear the console
}

int main() {
    int choice;

    do {
         clearScreen();                     // Clear the screen //
        printf("\n");
        printf("\n");
        printf("\ \t \t \t \t \t (Hotel Customer Management System)\n ");
        printf("-----------------------------------------------------------------------------------------------------------------------\n");
        printf(" \n");
        printf(" \n");

        printf("\t \t \t \t \t \t  1. Check-In\n");
        printf("\t \t \t \t \t \t  2. Check-Out\n");
        printf("\t \t \t \t \t \t  3. View Room Status\n");
        printf("\t \t \t \t \t \t  4. Exit\n");
        printf("\n \t \t \t \t \t \t  Enter your choice: ");
        scanf("%d", &choice);
        printf(" \n");
        printf(" \n");
        printf("-----------------------------------------------------------------------------------------------------------------------\n");

        switch (choice) {
            case 1: {
                int roomNumber, numGuests, stayDuration;
                printf("\n");
                printf("\n");
                printf("\t Enter room number: ");
                scanf("%d", &roomNumber);
                printf("\t Enter number of guests: ");
                scanf("%d", &numGuests);
                printf("\t Enter stay duration (in days): ");
                scanf("%d", &stayDuration);

                if (!RoomOccupied(roomNumber)) {
                    checkIn(roomNumber, numGuests, stayDuration);
                    printf("\t Customer checked in successfully!\n");           //If the selected room is empty//
                } else {
                    printf("\t Sorry, this room is already occupied.\n");     //If the selected room is empty//
                }
                break;
            }
            case 2: {
                printf("\n");
                printf("\n");
                int roomNumber;
                printf("\t Enter room number to check out: ");
                scanf("%d", &roomNumber);

                if (RoomOccupied(roomNumber)) {
                    checkOut(roomNumber);
                    printf("\t Customer checked out successfully!\n");    //If the selected room is not occupied//
                } else {
                    printf("\t Sorry, this room is not occupied.\n");     //If the selected room is empty//
                }
                break;
            }
            case 3:
                displayRoomStatus();
                break;
            case 4:
                printf("\nExiting the program. Thank you!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
        _getch();         // Wait for user input (any key press)

    } while (choice != 4);

   return 0;
}
