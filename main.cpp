#include <iostream>
#include "Cinema.h"
#include "Customer.h"
#include "Reviewer.h"
#include "VIPTicket.h"
#include "HallBuilder.h"

static constexpr int MAX_INPUT_LEN = 256;

using namespace std;

static int readInt(string prompt) {
    int value;
    while (true) {
        cout << prompt;
        if (cin >> value) {
            cin.ignore(INT_MAX, '\n');
            return value;
        }
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << "Invalid number, please try again." << endl;
    }
}

static int readIntInRange(string prompt, int minVal, int maxVal) {
    while (true) {
        int v = readInt(prompt);
        if (v >= minVal && v <= maxVal) return v;
        cout << "Value must be between " << minVal
                  << " and " << maxVal << "." << endl;
    }
}

static double readPositiveDouble(string prompt) {
    double value;
    while (true) {
        cout << prompt;
        if (cin >> value && value >= 0) {
            cin.ignore(INT_MAX, '\n');
            return value;
        }
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << "Invalid value, please enter a non-negative number." << endl;
    }
}

static void readLine(string prompt, string& buffer, int bufferSize) {
	cout << prompt;
	vector<char> bufferArr(bufferSize);
	cin.getline(bufferArr.data(), bufferSize);
	buffer = string(bufferArr.data());
	if (cin.fail()) {
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		buffer.clear();
	}
}

static Date readDate(string label) {
    cout << "Enter " << label << ":" << endl;
    int d = readIntInRange("  Day (1-31): ", 1, 31);
    int m = readIntInRange("  Month (1-12): ", 1, 12);
    int y = readIntInRange("  Year (1900-2100): ", 1900, 2100);
    return Date(d, m, y);
}

static bool readYesNo(string prompt) {
    string buffer;
    while (true) {
        readLine(prompt, buffer, 8);
        if (buffer[0] == 'y' || buffer[0] == 'Y') return true;
        if (buffer[0] == 'n' || buffer[0] == 'N') return false;
        cout << "Please answer with y or n." << endl;
    }
}

static void addHall(Cinema& cinema) {
    cout << "\n--- Add new hall ---" << endl;

    if (cinema.getNumMovies() == 0) {
        cout << "No movies in the system yet. Add a movie first." << endl;
        return;
    }

    cinema.printAllMovies();
    int movieIdx = readIntInRange("Choose movie index for this hall: ", 0, cinema.getNumMovies() - 1);
    const Movie* movie = cinema.getMovieByIndex(movieIdx);

    int hallNumber = readInt("Enter hall number: ");

    cout << "Choose hall type:" << endl
              << "  1. Regular IHall" << endl
              << "  2. VIP IHall" << endl
              << "  3. 3D IHall" << endl
              << "  4. 3D VIP IHall" << endl;
    int type = readIntInRange("Type: ", 1, 4);

    unique_ptr<HallBuilder> builder;
    switch (type) {
        case 1: builder = make_unique<HallBuilder>(*movie);       break;
        case 2: builder = make_unique<VIPHallBuilder>(*movie);    break;
        case 3: builder = make_unique<Hall3DBuilder>(*movie);     break;
        case 4: builder = make_unique<Hall3DVIPBuilder>(*movie);  break;
    }

    builder->setHallNumber(hallNumber);

    if (type == 2 || type == 4)
    {
        int waiters = readIntInRange("Waiters count: ", 0, 50);
        dynamic_cast<VIPHallBuilder*>(builder.get())->setWaitersCount(waiters);
    }
    if (type == 3 || type == 4)
    {
        int glasses = readIntInRange("Glasses count: ", 0, 200);
        dynamic_cast<Hall3DBuilder*>(builder.get())->setGlassesCount(glasses);
    }

    unique_ptr<IHall> hall = builder->build();

    cinema += std::move(hall);
    cout << "IHall added successfully." << endl;
}

static void addMovie(Cinema& cinema) {
    cout << "\n--- Add new movie ---" << endl;

    string title;
    readLine("Enter movie title: ", title, MAX_INPUT_LEN);

    Date premiere = readDate("premiere date");
    int length = readIntInRange("Movie length (minutes): ", 1, 600);
    bool is3D = readYesNo("Is the movie available in 3D? (y/n): ");

    auto movie = make_unique<Movie>(title, premiere, length, is3D);
    cinema += std::move(movie);
    cout << "Movie added successfully." << endl;
}

static void addEmployee(Cinema& cinema) {
    cout << "\n--- Register new employee ---" << endl;

    string name;
    readLine("Employee name: ", name, MAX_INPUT_LEN);
    int id = readInt("ID number: ");
    Date birth = readDate("birth date");
    double salary = readPositiveDouble("Base salary: ");

    auto emp = make_unique<Employee>(name, id, birth, salary);
    cinema += std::move(emp);
    cout << "Employee registered successfully." << endl;
}

static void addGuest(Cinema& cinema) {
    cout << "\n--- Register new guest ---" << endl;

    cout << "Choose guest type:" << endl
              << "  1. Customer (club member)" << endl
              << "  2. Reviewer (movie critic)" << endl;
    int type = readIntInRange("Type: ", 1, 2);

    string name;
    readLine("Guest name: ", name, MAX_INPUT_LEN);
    int id = readInt("ID number: ");
    Date date = readDate("birth date");

    unique_ptr<Guest> guest;
    if (type == 1) {
        int points = readIntInRange("Initial club points: ", 0, 100000);
        guest = make_unique<Customer>(name, id, date, points);
    } else {
        string pub;
        readLine("Publication name: ", pub, MAX_INPUT_LEN);
        guest = make_unique<Reviewer>(name, id, date, pub);
    }

    cinema += std::move(guest);
    cout << "Guest registered successfully." << endl;
}

static void sellTicket(Cinema& cinema) {
    cout << "\n--- Sell ticket ---" << endl;

    if (cinema.getNumGuests() == 0) {
        cout << "No guests in the system. Register one first." << endl;
        return;
    }
    if (cinema.getNumMovies() == 0) {
        cout << "No movies in the system. Add one first." << endl;
        return;
    }

    cinema.printAllGuests();
    int guestIdx = readIntInRange("Choose guest index: ", 0, cinema.getNumGuests() - 1);
    Guest* guest = cinema.getGuestByIndex(guestIdx);

    cinema.printAllMovies();
    int movieIdx = readIntInRange("Choose movie index: ", 0, cinema.getNumMovies() - 1);
    const Movie* movie = cinema.getMovieByIndex(movieIdx);

    bool is3D = readYesNo("Is the ticket for 3D? (y/n): ");

    cout << "Ticket type:" << endl
              << "  1. Regular" << endl
              << "  2. VIP" << endl;
    int type = readIntInRange("Type: ", 1, 2);

    unique_ptr<Ticket> ticket;
    if (type == 1) {
        ticket = make_unique<Ticket>(*movie, is3D);
    } else {
        bool meal = readYesNo("Include meal? (y/n): ");
        ticket = make_unique<VIPTicket>(*movie, is3D, meal);
    }

    double finalPrice = ticket->calcFinalPrice();
    guest->addTicket(std::move(ticket));
    cout << "Ticket sold. Final price: " << finalPrice << endl;
}

static void printMovieDetails(const Cinema& cinema) {
    cout << "\n--- Print movie details ---" << endl;

    if (cinema.getNumMovies() == 0) {
        cout << "No movies available." << endl;
        return;
    }

    cinema.printAllMovies();
    int idx = readIntInRange("Choose movie index: ", 0, cinema.getNumMovies() - 1);

    const Movie* m = cinema.getMovieByIndex(idx);
    cout << *m << endl;
}

static void addEmployeeToShift(Cinema& cinema) {
    cout << "\n--- Add employee to shift ---" << endl;

    if (cinema.getNumEmployees() == 0) {
        cout << "No employees registered." << endl;
        return;
    }

    cinema.printAllEmployees();
    int idx = readIntInRange("Choose employee index: ", 0, cinema.getNumEmployees() - 1);
    const Employee* emp = cinema.getEmployeeByIndex(idx);

    int hours = readIntInRange("Shift length (hours): ", 1, 24);
    Date shiftDate = readDate("shift date");

    auto shift = make_unique<Shift>(*emp, hours, shiftDate);
    cinema += std::move(shift);
    cout << "Shift created successfully." << endl;
}

static void promoteEmployee(Cinema& cinema) {
    cout << "\n--- Promote employee ---" << endl;

    if (cinema.getNumEmployees() == 0) {
        cout << "No employees to promote." << endl;
        return;
    }

    cinema.printAllEmployees();
    int idx = readIntInRange("Choose employee index: ", 0, cinema.getNumEmployees() - 1);
    Employee* emp = cinema.getEmployeeByIndex(idx);

    double oldSalary = emp->getSalary();
    ++(*emp);
    cout << "Salary updated: " << oldSalary
              << " -> " << emp->getSalary() << endl;
}

static void compareTickets(const Cinema& cinema) {
    cout << "\n--- Compare ticket prices ---" << endl;

    int n = cinema.getNumGuests();
    if (n == 0) {
        cout << "No guests in the system." << endl;
        return;
    }

    cinema.printAllGuests();
    int g1Idx = readIntInRange("First guest index: ", 0, n - 1);
    const Guest* g1 = cinema.getGuestByIndex(g1Idx);
    if (g1->getNumTickets() == 0) {
        cout << "This guest has no tickets." << endl;
        return;
    }
    for(int i=0;i<g1->getNumTickets();i++)
    {
        cout << i << ". " << g1->getTicket(i)->getMovie().getTitle() << endl;
    }
    int t1Idx = readIntInRange("First ticket index: ", 0, g1->getNumTickets() - 1);
    const Ticket* t1 = g1->getTicket(t1Idx);

    int g2Idx = readIntInRange("Second guest index: ", 0, n - 1);
    const Guest* g2 = cinema.getGuestByIndex(g2Idx);
    if (g2->getNumTickets() == 0) {
        cout << "This guest has no tickets." << endl;
        return;
    }
    for(int i=0;i<g2->getNumTickets();i++)
    {
        cout << i << ". " << g2->getTicket(i)->getMovie().getTitle() << endl;
    }
    int t2Idx = readIntInRange("Second ticket index: ", 0, g2->getNumTickets() - 1);
    const Ticket* t2 = g2->getTicket(t2Idx);

    if (*t1 > *t2) {
        cout << "First ticket is more expensive ("
                  << t1->calcFinalPrice() << " vs "
                  << t2->calcFinalPrice() << ")" << endl;
    } else {
        cout << "Second ticket is more expensive or equal ("
                  << t2->calcFinalPrice() << " vs "
                  << t1->calcFinalPrice() << ")" << endl;
    }
}

static void checkHallEmpty(const Cinema& cinema) {
    cout << "\n--- Check hall availability ---" << endl;

    if (cinema.getNumHalls() == 0) {
        cout << "No halls in the system." << endl;
        return;
    }

    cinema.printAllHalls();
    int idx = readIntInRange("Choose hall index: ", 0, cinema.getNumHalls() - 1);

    const IHall* hall = cinema.getHallByIndex(idx);
    if (!(*hall)) {
        cout << "The hall is completely empty (all seats available)." << endl;
    } else {
        cout << "The hall has some seats taken." << endl;
    }
}

static void printAllGuestsOperation(const Cinema& cinema) {
    cout << "\n--- All guests (polymorphic print) ---" << endl;
    cinema.printAllGuests();
}

static void removeGuest(Cinema& cinema) {
    cout << "\n--- Remove guest ---" << endl;

    if (cinema.getNumGuests() == 0) {
        cout << "No guests to remove." << endl;
        return;
    }

    cinema.printAllGuests();
    int id = readInt("Enter ID of guest to remove: ");

    cinema -= id;
    cout << "Guest removed successfully." << endl;
}

static void printMenu() {
    cout << "\n========== Cinema Management System ==========" << endl
              << "  0.  Exit" << endl
              << "  1.  Add new hall" << endl
              << "  2.  Add new movie" << endl
              << "  3.  Register new employee" << endl
              << "  4.  Register new guest" << endl
              << "  5.  Sell ticket" << endl
              << "  6.  Print movie details" << endl
              << "  7.  Add employee to shift" << endl
              << "  8.  Promote employee (raise salary)" << endl
              << "  9.  Compare ticket prices" << endl
              << " 10.  Check if hall is empty" << endl
              << " 11.  Print all guests (polymorphism)" << endl
              << " 12.  Remove guest from system" << endl
              << "==============================================" << endl;
}

int main() {
    Cinema& cinema = Cinema::getInstance();
    int choice;

    cout << "Welcome to the Cinema Management System!" << endl;

    do {
        printMenu();
        choice = readInt("Choose an option: ");

        try {
            switch (choice) {
                case 0:  cout << "Goodbye!" << endl; break;
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
                default:
                    cout << "Invalid choice. Please pick 0-12." << endl;
            }
        } catch (const exception& e) {
            cerr << "Error: " << e.what() << endl;
        } catch (...) {
            cerr << "An unknown error occurred." << endl;
        }
    } while (choice != 0);

    return 0;
}
