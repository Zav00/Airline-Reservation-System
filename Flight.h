#ifndef AIRLINE_RESERVATION_SYSTEM_FLIGHT_H
#define AIRLINE_RESERVATION_SYSTEM_FLIGHT_H
#include <string>
class Flight {

private:
    std::string flightNumber;
    std::string flightOrigin;
    std::string flightDestination;
    std::string departureDate;
    int availableSeats;
public:

    Flight(const std::string &flightNumber, const std::string &flightOrigin, const std::string &flightDestination,
           const std::string &departureDate, int availableSeats)
            : flightNumber(flightNumber),
              flightOrigin(flightOrigin),
              flightDestination(flightDestination),
              departureDate(departureDate),
              availableSeats(availableSeats) {}

    const std::string &getFlightNumber() const {
        return flightNumber;
    }

    const std::string &getFlightOrigin() const {
        return flightOrigin;
    }

    const std::string &getFlightDestination() const {
        return flightDestination;
    }

    const std::string &getDepartureDate() const {
        return departureDate;
    }

    int getAvailableSeats() const {
        return availableSeats;
    }

    void bookSeat() {
        availableSeats--;
    }

};

#endif //AIRLINE_RESERVATION_SYSTEM_FLIGHT_H
