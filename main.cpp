#include <iostream>
#include<vector>
#include<fstream>
#include "Reservation.h"




void registerFlight(std::vector<Flight> &flights, const std::string &flightNumber, const std::string &flightOrigin,
                    const std::string &flightDestination, const std::string &departureDate, int availableSeats) {
    Flight flight(flightNumber, flightOrigin, flightDestination, departureDate, availableSeats);
    flights.push_back(flight);
    std::cout << "Flight is registered successfully.\n";
}

void registerUser(std::vector<User> &users, const std::string name, const std::string &contactInfo) {
    User user(name, contactInfo);
    users.push_back(user);
    std::cout << "User is registered successfully.\n";
}

std::vector<Flight> searchFlights(const std::vector<Flight> &flights, const std::string &origin,
                                  const std::string &destination, const std::string &departureDate) {
    std::vector<Flight> availableFlight;
    for (const Flight &flight: flights) {
        if (flight.getFlightOrigin() == origin && flight.getFlightDestination() == destination
            && flight.getDepartureDate() >= departureDate && flight.getAvailableSeats() > 0) {
            availableFlight.push_back(flight);
        }
    }
    return availableFlight;
}

void bookFlight(std::vector<Flight> &flights, std::vector<User> &users, std::vector<Reservation> &reservations,
                const std::string &flightNumber, const std::string &userName, const std::string &contactInfo) {
    Flight * selectedFlightPtr = nullptr;
    for (Flight &flight: flights) {
        if (flight.getFlightNumber() == flightNumber && flight.getAvailableSeats() > 0) {
            selectedFlightPtr = &flight;
            break;
        }
    }
    if (selectedFlightPtr == nullptr) {
        std::cout << "Invalid flight selection or flight is fully booked.\n";
        return;
    }
    User newUser(userName, contactInfo);
    users.push_back(newUser);
    Reservation newReservation(*selectedFlightPtr, newUser);
    reservations.push_back(newReservation);
    selectedFlightPtr->bookSeat();
    std::cout << "Flight booked successfully.\n";
}

void generateTicket(const Reservation &reservation) {
    std::cout << " Ticket:\n";
    std::cout << "Flight Number: " << reservation.getFlight().getFlightNumber() << std::endl;
    std::cout << "Origin: " << reservation.getFlight().getFlightOrigin() << std::endl;
    std::cout << "Destination: " << reservation.getFlight().getFlightDestination() << std::endl;
    std::cout << "Departure Date and Time: " << reservation.getFlight().getDepartureDate() << std::endl;
    std::cout << "Passenger Name: " << reservation.getUser().getName() << std::endl;
    std::cout << "Contact: " << reservation.getUser().getContactInfo() << std::endl;
    std::cout << "------------------------\n";
}

void saveTicketToFile(const Reservation &reservation) {
    std::ofstream filename("ticket.txt");
    if (filename.is_open()) {
        filename << "Ticket:\n";
        filename << "Flight Number: " << reservation.getFlight().getFlightNumber() << std::endl;
        filename << "Origin: " << reservation.getFlight().getFlightOrigin() << std::endl;
        filename << "Destination: " << reservation.getFlight().getFlightDestination() << std::endl;
        filename << "Departure Date and Time: " << reservation.getFlight().getDepartureDate() << std::endl;
        filename << "Passenger Name: " << reservation.getUser().getName() << std::endl;
        filename << "Contact: " << reservation.getUser().getContactInfo() << std::endl;
        filename << "------------------------\n";
        filename.close();
        std::cout << "Ticket saved to file.\n";
    } else {
        std::cout << "unable to save ticket to the file.\n";
    }
}

int main() {
    std::vector<Flight> flights;
    std::vector<User> users;
    std::vector<Reservation> reservations;
    registerFlight(flights, "F001", "New York", "Los Angeles", "2023-07-15 09:00", 50);
    registerFlight(flights, "F002", "Los Angeles", "Chicago", "2023-07-16 13:30", 30);
    registerFlight(flights, "F003", "Chicago", "New York", "2023-07-17 11:15", 20);
    registerUser(users, "Arman", "arman@gmail.com");
    registerUser(users, "Gago", "gago@egmail.com");
    std::vector<Flight> availableFlights = searchFlights(flights, "New York", "Los Angeles", "2023-07-15 00:00");
    if (!availableFlights.empty()) {
        std::cout << "Available flights:\n";
        for (const Flight &flight: availableFlights) {
            std::cout << "Flight Number: " << flight.getFlightNumber() << ", Origin: " << flight.getFlightOrigin()
                      << ", Destination: " << flight.getFlightDestination() << ", Departure Date and Time: "
                      << flight.getDepartureDate() << ", Available Seats: " << flight.getAvailableSeats()
                      << std::endl;
        }
    } else {
        std::cout << "No available flights found.\n";
    }
    bookFlight(flights, users, reservations, "F001", "Arman", "arman@egmail.com");
    bookFlight(flights, users, reservations, "F002", "Gago", "gago@egmail.com");
    generateTicket(reservations[0]);
    generateTicket(reservations[1]);
    saveTicketToFile(reservations[0]);
    saveTicketToFile(reservations[1]);
    return 0;
}