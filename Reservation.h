#ifndef AIRLINE_RESERVATION_SYSTEM_RESERVATION_H
#define AIRLINE_RESERVATION_SYSTEM_RESERVATION_H
#include "Flight.h"
#include "User.h"
class Reservation {
private:
    Flight flight;
    User user;
public:
    Reservation(const Flight &flight, const User &user)
            : flight(flight), user(user) {}

    const Flight &getFlight() const {
        return flight;
    }

    const User &getUser() const {
        return user;
    }
};
#endif //AIRLINE_RESERVATION_SYSTEM_RESERVATION_H
