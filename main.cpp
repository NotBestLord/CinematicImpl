#include <iostream>
#include <cstring>
#include <climits>
#include <stdexcept>

#include "Cinema.h"
#include "Customer.h"
#include "Reviewer.h"
#include "VIPTicket.h"
#include "VIPHall.h"
#include "Hall3D.h"
#include "Hall3DVIP.h"

static const int MAX_INPUT_LEN = 256;

static int readInt(const char* prompt) {
    int value;
    while (true) {
        std::cout << prompt;
        if (std::cin >> value) {
            std::cin.ignore(INT_MAX, '\n');
            return value;
        }
        std::cin.clear();
        std::cin.ignore(INT_MAX, '\n');
        std::cout << "Invalid number, please try again." << std::endl;
    }
}

static int readIntInRange(const char* prompt, int minVal, int maxVal) {
    while (true) {
        int v = readInt(prompt);
        if (v >= minVal && v <= maxVal) return v;
        std::cout << "Value must be between " << minVal
                  << " and " << maxVal << "." << std::endl;
    }
}

static double readPositiveDouble(const char* prompt) {
    double value;
    while (true) {
        std::cout << prompt;
        if (std::cin >> value && value >= 0) {
            std::cin.ignore(INT_MAX, '\n');
            return value;
        }
        std::cin.clear();
        std::cin.ignore(INT_MAX, '\n');
        std::cout << "Invalid value, please enter a non-negative number." << std::endl;
    }
}

static void readLine(const char* prompt, char* buffer, int bufferSize) {
    std::cout << prompt;
    std::cin.getline(buffer, bufferSize);
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(INT_MAX, '\n');
        buffer[0] = '\0';
    }
}

static Date readDate(const char* label) {
    std::cout << "Enter " << label << ":" << std::endl;
    int d = readIntInRange("  Day (1-31): ", 1, 31);
    int m = readIntInRange("  Month (1-12): ", 1, 12);
    int y = readIntInRange("  Year (1900-2100): ", 1900, 2100);
    return Date(d, m, y);
}

static bool readYesNo(const char* prompt) {
    char buffer[8];
    while (true) {
        readLine(prompt, buffer, 8);
        if (buffer[0] == 'y' || buffer[0] == 'Y') return true;
        if (buffer[0] == 'n' || buffer[0] == 'N') return false;
        std::cout << "Please answer with y or n." << std::endl;
    }
}

static void addHall(Cinema& cinema) {
    std::cout << "\n--- Add new hall ---" << std::endl;

    if (cinema.getNumMovies() == 0) {
        std::cout << "No movies in the system yet. Add a movie first." << std::endl;
        return;
    }

    cinema.printAllMovies();
    int movieIdx = readIntInRange("Choose movie index for this hall: ", 0, cinema.getNumMovies() - 1);
    Movie* movie = cinema.getMovieByIndex(movieIdx);

    int hallNumber = readInt("Enter hall number: ");

    std::cout << "Choose hall type:" << std::endl
              << "  1. Regular Hall" << std::endl
              << "  2. VIP Hall" << std::endl
              << "  3. 3D Hall" << std::endl
              << "  4. 3D VIP Hall" << std::endl;
    int type = readIntInRange("Type: ", 1, 4);

    Hall* hall = nullptr;
    switch (type) {
        case 1:
            hall = new Hall(hallNumber, *movie);
            break;
        case 2: {
            int waiters = readIntInRange("Waiters count: ", 0, 50);
            hall = new VIPHall(hallNumber, *movie, waiters);
            break;
        }
        case 3: {
            int glasses = readIntInRange("Glasses count: ", 0, 200);
            hall = new Hall3D(hallNumber, *movie, glasses);
            break;
        }
        case 4: {
            int waiters = readIntInRange("Waiters count: ", 0, 50);
            int glasses = readIntInRange("Glasses count: ", 0, 200);
            hall = new Hall3DVIP(hallNumber, *movie, waiters, glasses);
            break;
        }
    }

    try {
        cinema += hall;
        std::cout << "Hall added successfully." << std::endl;
    } catch (...) {
        delete hall;
        throw;
    }
}

static void addMovie(Cinema& cinema) {
    std::cout << "\n--- Add new movie ---" << std::endl;

    char title[MAX_INPUT_LEN];
    readLine("Enter movie title: ", title, MAX_INPUT_LEN);

    Date premiere = readDate("premiere date");
    int length = readIntInRange("Movie length (minutes): ", 1, 600);
    bool is3D = readYesNo("Is the movie available in 3D? (y/n): ");

    Movie* movie = new Movie(title, premiere, length, is3D);
    try {
        cinema += movie;
        std::cout << "Movie added successfully." << std::endl;
    } catch (...) {
        delete movie;
        throw;
    }
}

static void addEmployee(Cinema& cinema) {
    std::cout << "\n--- Register new employee ---" << std::endl;

    char name[MAX_INPUT_LEN];
    readLine("Employee name: ", name, MAX_INPUT_LEN);
    int id = readInt("ID number: ");
    Date birth = readDate("birth date");
    double salary = readPositiveDouble("Base salary: ");

    Employee* emp = new Employee(name, id, birth, salary);
    try {
        cinema += emp;
        std::cout << "Employee registered successfully." << std::endl;
    } catch (...) {
        delete emp;
        throw;
    }
}

static void addGuest(Cinema& cinema) {
    std::cout << "\n--- Register new guest ---" << std::endl;

    std::cout << "Choose guest type:" << std::endl
              << "  1. Customer (club member)" << std::endl
              << "  2. Reviewer (movie critic)" << std::endl;
    int type = readIntInRange("Type: ", 1, 2);

    char name[MAX_INPUT_LEN];
    readLine("Guest name: ", name, MAX_INPUT_LEN);
    int id = readInt("ID number: ");

    Guest* guest = nullptr;
    if (type == 1) {
        int points = readIntInRange("Initial club points: ", 0, 100000);
        guest = new Customer(name, id, points);
    } else {
        char pub[MAX_INPUT_LEN];
        readLine("Publication name: ", pub, MAX_INPUT_LEN);
        guest = new Reviewer(name, id, pub);
    }

    try {
        cinema += guest;
        std::cout << "Guest registered successfully." << std::endl;
    } catch (...) {
        delete guest;
        throw;
    }
}

static void sellTicket(Cinema& cinema) {
    std::cout << "\n--- Sell ticket ---" << std::endl;

    if (cinema.getNumGuests() == 0) {
        std::cout << "No guests in the system. Register one first." << std::endl;
        return;
    }
    if (cinema.getNumMovies() == 0) {
        std::cout << "No movies in the system. Add one first." << std::endl;
        return;
    }

    cinema.printAllGuests();
    int guestIdx = readIntInRange("Choose guest index: ", 0, cinema.getNumGuests() - 1);
    Guest* guest = cinema.getGuestByIndex(guestIdx);

    cinema.printAllMovies();
    int movieIdx = readIntInRange("Choose movie index: ", 0, cinema.getNumMovies() - 1);
    const Movie* movie = cinema.getMovieByIndex(movieIdx);

    bool is3D = readYesNo("Is the ticket for 3D? (y/n): ");

    std::cout << "Ticket type:" << std::endl
              << "  1. Regular" << std::endl
              << "  2. VIP" << std::endl;
    int type = readIntInRange("Type: ", 1, 2);

    Ticket* ticket = nullptr;
    if (type == 1) {
        ticket = new Ticket(*movie, is3D);
    } else {
        bool meal = readYesNo("Include meal? (y/n): ");
        ticket = new VIPTicket(*movie, is3D, meal);
    }

    try {
        guest->addTicket(ticket);
        std::cout << "Ticket sold. Final price: "
                  << ticket->calcFinalPrice() << std::endl;
    } catch (...) {
        delete ticket;
        throw;
    }
}

static void printMovieDetails(const Cinema& cinema) {
    std::cout << "\n--- Print movie details ---" << std::endl;

    if (cinema.getNumMovies() == 0) {
        std::cout << "No movies available." << std::endl;
        return;
    }

    cinema.printAllMovies();
    int idx = readIntInRange("Choose movie index: ", 0, cinema.getNumMovies() - 1);

    const Movie* m = cinema.getMovieByIndex(idx);
    std::cout << *m << std::endl;
}

static void addEmployeeToShift(Cinema& cinema) {
    std::cout << "\n--- Add employee to shift ---" << std::endl;

    if (cinema.getNumEmployees() == 0) {
        std::cout << "No employees registered." << std::endl;
        return;
    }

    cinema.printAllEmployees();
    int idx = readIntInRange("Choose employee index: ", 0, cinema.getNumEmployees() - 1);
    const Employee* emp = cinema.getEmployeeByIndex(idx);

    int hours = readIntInRange("Shift length (hours): ", 1, 24);
    Date shiftDate = readDate("shift date");

    Shift* shift = new Shift(*emp, hours, shiftDate);
    try {
        cinema += shift;
        std::cout << "Shift created successfully." << std::endl;
    } catch (...) {
        delete shift;
        throw;
    }
}

static void promoteEmployee(Cinema& cinema) {
    std::cout << "\n--- Promote employee ---" << std::endl;

    if (cinema.getNumEmployees() == 0) {
        std::cout << "No employees to promote." << std::endl;
        return;
    }

    cinema.printAllEmployees();
    int idx = readIntInRange("Choose employee index: ", 0, cinema.getNumEmployees() - 1);
    Employee* emp = cinema.getEmployeeByIndex(idx);

    double oldSalary = emp->getSalary();
    ++(*emp);
    std::cout << "Salary updated: " << oldSalary
              << " -> " << emp->getSalary() << std::endl;
}

static void compareTickets(const Cinema& cinema) {
    std::cout << "\n--- Compare ticket prices ---" << std::endl;

    int n = cinema.getNumGuests();
    if (n == 0) {
        std::cout << "No guests in the system." << std::endl;
        return;
    }

    cinema.printAllGuests();
    int g1Idx = readIntInRange("First guest index: ", 0, n - 1);
    const Guest* g1 = cinema.getGuestByIndex(g1Idx);
    if (g1->getNumTickets() == 0) {
        std::cout << "This guest has no tickets." << std::endl;
        return;
    }
    int t1Idx = readIntInRange("First ticket index: ", 0, g1->getNumTickets() - 1);
    const Ticket* t1 = g1->getTicket(t1Idx);

    int g2Idx = readIntInRange("Second guest index: ", 0, n - 1);
    const Guest* g2 = cinema.getGuestByIndex(g2Idx);
    if (g2->getNumTickets() == 0) {
        std::cout << "This guest has no tickets." << std::endl;
        return;
    }
    int t2Idx = readIntInRange("Second ticket index: ", 0, g2->getNumTickets() - 1);
    const Ticket* t2 = g2->getTicket(t2Idx);

    if (*t1 > *t2) {
        std::cout << "First ticket is more expensive ("
                  << t1->calcFinalPrice() << " vs "
                  << t2->calcFinalPrice() << ")" << std::endl;
    } else {
        std::cout << "Second ticket is more expensive or equal ("
                  << t2->calcFinalPrice() << " vs "
                  << t1->calcFinalPrice() << ")" << std::endl;
    }
}

static void checkHallEmpty(const Cinema& cinema) {
    std::cout << "\n--- Check hall availability ---" << std::endl;

    if (cinema.getNumHalls() == 0) {
        std::cout << "No halls in the system." << std::endl;
        return;
    }

    cinema.printAllHalls();
    int idx = readIntInRange("Choose hall index: ", 0, cinema.getNumHalls() - 1);

    const Hall* hall = cinema.getHallByIndex(idx);
    if (!(*hall)) {
        std::cout << "The hall is completely empty (all seats available)." << std::endl;
    } else {
        std::cout << "The hall has some seats taken." << std::endl;
    }
}

static void printAllGuestsOperation(const Cinema& cinema) {
    std::cout << "\n--- All guests (polymorphic print) ---" << std::endl;
    cinema.printAllGuests();
}

static void removeGuest(Cinema& cinema) {
    std::cout << "\n--- Remove guest ---" << std::endl;

    if (cinema.getNumGuests() == 0) {
        std::cout << "No guests to remove." << std::endl;
        return;
    }

    cinema.printAllGuests();
    int id = readInt("Enter ID of guest to remove: ");

    cinema -= id;
    std::cout << "Guest removed successfully." << std::endl;
}

static void printMenu() {
    std::cout << "\n========== Cinema Management System ==========" << std::endl
              << "  1.  Add new hall" << std::endl
              << "  2.  Add new movie" << std::endl
              << "  3.  Register new employee" << std::endl
              << "  4.  Register new guest" << std::endl
              << "  5.  Sell ticket" << std::endl
              << "  6.  Print movie details" << std::endl
              << "  7.  Add employee to shift" << std::endl
              << "  8.  Promote employee (raise salary)" << std::endl
              << "  9.  Compare ticket prices" << std::endl
              << " 10.  Check if hall is empty" << std::endl
              << " 11.  Print all guests (polymorphism)" << std::endl
              << " 12.  Remove guest from system" << std::endl
              << "  0.  Exit" << std::endl
              << "==============================================" << std::endl;
}

int main() {
    Cinema cinema;
    int choice;

    std::cout << "Welcome to the Cinema Management System!" << std::endl;

    do {
        printMenu();
        choice = readInt("Choose an option: ");

        try {
            switch (choice) {
                case 1:  addHall(cinema);                break;
                case 2:  addMovie(cinema);               break;
                case 3:  addEmployee(cinema);            break;
                case 4:  addGuest(cinema);               break;
                case 5:  sellTicket(cinema);             break;
                case 6:  printMovieDetails(cinema);      break;
                case 7:  addEmployeeToShift(cinema);     break;
                case 8:  promoteEmployee(cinema);        break;
                case 9:  compareTickets(cinema);         break;
                case 10: checkHallEmpty(cinema);         break;
                case 11: printAllGuestsOperation(cinema); break;
                case 12: removeGuest(cinema);            break;
                case 0:  std::cout << "Goodbye!" << std::endl; break;
                default:
                    std::cout << "Invalid choice. Please pick 0-12." << std::endl;
            }
        } catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        } catch (...) {
            std::cerr << "An unknown error occurred." << std::endl;
        }
    } while (choice != 0);

    return 0;
}
