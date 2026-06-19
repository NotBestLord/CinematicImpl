#include "Cinema.h"

Cinema::Cinema()
{
	numEmployees = 0;
	numGuests = 0;
	numHalls = 0;
	numMovies = 0;
	numShifts = 0;
	employeesCapacity = INITIAL_CAPACITY;
	guestsCapacity = INITIAL_CAPACITY;
	hallsCapacity = INITIAL_CAPACITY;
	moviesCapacity = INITIAL_CAPACITY;
	shiftsCapacity = INITIAL_CAPACITY;
	employees = new Employee*[INITIAL_CAPACITY];
	guests = new Guest*[INITIAL_CAPACITY];
	halls = new Hall*[INITIAL_CAPACITY];
	movies = new const Movie*[INITIAL_CAPACITY];
	shifts = new const Shift*[INITIAL_CAPACITY];
}

Cinema::Cinema(const Cinema& other) :
	employees(nullptr),
	guests(nullptr),
	halls(nullptr),
	movies(nullptr),
	shifts(nullptr)
{
	*this = other;
}

Cinema::Cinema(Cinema&& other) :
	employees(nullptr),
	guests(nullptr),
	halls(nullptr),
	movies(nullptr),
	shifts(nullptr)
{
	this->employees = other.employees;
	this->employeesCapacity = other.employeesCapacity;
	this->numEmployees = other.numEmployees;
	other.employees = nullptr;

	this->guests = other.guests;
	this->guestsCapacity = other.guestsCapacity;
	this->numGuests = other.numGuests;
	other.guests = nullptr;

	this->halls = other.halls;
	this->hallsCapacity = other.hallsCapacity;
	this->numHalls = other.numHalls;
	other.halls = nullptr;

	this->movies = other.movies;
	this->moviesCapacity = other.moviesCapacity;
	this->numMovies = other.numMovies;
	other.movies = nullptr;

	this->shifts = other.shifts;
	this->shiftsCapacity = other.shiftsCapacity;
	this->numShifts = other.numShifts;
	other.shifts = nullptr;
}

const Cinema& Cinema::operator=(const Cinema& other)
{
	if (this != &other)
	{
		for (int i = 0; i < numEmployees; i++)
		{
			delete employees[i];
		}
		delete[] employees;
		for (int i = 0; i < numGuests; i++)
		{
			delete guests[i];
		}
		delete[] guests;
		for (int i = 0; i < numHalls; i++)
		{
			delete halls[i];
		}
		delete[] halls;
			for (int i = 0; i < numMovies; i++)
		{
			delete movies[i];
		}
		delete[] movies;
		for (int i = 0; i < numShifts; i++)
		{
			delete shifts[i];
		}
		delete[] shifts;

		numEmployees = other.numEmployees;
		numGuests = other.numGuests;
		numHalls = other.numHalls;
		numMovies = other.numMovies;
		numShifts = other.numShifts;
		employeesCapacity = other.employeesCapacity;
		guestsCapacity = other.guestsCapacity;
		hallsCapacity = other.hallsCapacity;
		moviesCapacity = other.moviesCapacity;
		shiftsCapacity = other.shiftsCapacity;
		employees = new Employee * [employeesCapacity];
		guests = new Guest * [guestsCapacity];
		halls = new Hall * [hallsCapacity];
		movies = new const Movie * [moviesCapacity];
		shifts = new const Shift * [shiftsCapacity];
		for (int i = 0; i < numEmployees; i++)
		{
			employees[i] = new Employee(*other.employees[i]);
		}
		for (int i = 0; i < numGuests; i++)
		{
			guests[i] = new Guest(*other.guests[i]);
		}
		for (int i = 0; i < numHalls; i++)
		{
			halls[i] = new Hall(*other.halls[i]);
		}
		for (int i = 0; i < numMovies; i++)
		{
			movies[i] = new Movie(*other.movies[i]);
		}
		for (int i = 0; i < numShifts; i++)
		{
			shifts[i] = new Shift(*other.shifts[i]);
		}
	}
	return *this;
}

Cinema::~Cinema()
{
	for (int i = 0; i < numEmployees; i++)
	{
		delete employees[i];
	}
	delete[] employees;
	for (int i = 0; i < numGuests; i++)
	{
		delete guests[i];
	}
	delete[] guests;
	for (int i = 0; i < numHalls; i++)
	{
		delete halls[i];
	}
	delete[] halls;
	for (int i = 0; i < numMovies; i++)
	{
		delete movies[i];
	}
	delete[] movies;
	for (int i = 0; i < numShifts; i++)
	{
		delete shifts[i];
	}
	delete[] shifts;
}

const Employee* Cinema::getEmployeeByIndex(int i) const
{
	if (i >= 0 && i <= employeesCapacity) return employees[i];
	cout << "Index should be between 0 and " << employeesCapacity << ". Operation cancelled." << endl;
	return nullptr;
}

Employee* Cinema::getEmployeeByIndex(int i)
{
	if (i >= 0 && i <= employeesCapacity) return employees[i];
	cout << "Index should be between 0 and " << employeesCapacity << ". Operation cancelled." << endl;
	return nullptr;
}

const Guest* Cinema::getGuestByIndex(int i) const
{
	if (i >= 0 && i <= guestsCapacity) return guests[i];
	cout << "Index should be between 0 and " << guestsCapacity << ". Operation cancelled." << endl;
	return nullptr;
}

Guest* Cinema::getGuestByIndex(int i)
{
	if (i >= 0 && i <= guestsCapacity) return guests[i];
	cout << "Index should be between 0 and " << guestsCapacity << ". Operation cancelled." << endl;
	return nullptr;
}

const Hall* Cinema::getHallByIndex(int i) const
{
	if (i >= 0 && i <= hallsCapacity) return halls[i];
	cout << "Index should be between 0 and " << hallsCapacity << ". Operation cancelled." << endl;
	return nullptr;
}

Hall* Cinema::getHallByIndex(int i)
{
	if (i >= 0 && i <= hallsCapacity) return halls[i];
	cout << "Index should be between 0 and " << hallsCapacity << ". Operation cancelled." << endl;
	return nullptr;
}

const Movie* Cinema::getMovieByIndex(int i) const
{
	if (i >= 0 && i <= moviesCapacity) return movies[i];
	cout << "Index should be between 0 and " << moviesCapacity << ". Operation cancelled." << endl;
	return nullptr;
}

const Shift* Cinema::getShiftByIndex(int i) const
{
	if (i >= 0 && i <= shiftsCapacity) return shifts[i];
	cout << "Index should be between 0 and " << shiftsCapacity << ". Operation cancelled." << endl;
	return nullptr;
}

Guest* Cinema::findGuestById(int id) const
{
	for (int i = 0; i < numGuests; i++)
	{
		if (guests[i]->getId() == id) return guests[i];
	}
	cout << "Guest with given ID doesn't exist." << endl;;
	return nullptr;
}

Employee* Cinema::findEmployeeById(int id) const
{
	for (int i = 0; i < numEmployees; i++)
	{
		if (employees[i]->getId() == id) return employees[i];
	}
	cout << "Employee with given ID doesn't exist." << endl;;
	return nullptr;
}

const Cinema& Cinema::operator+=(Employee* e)
{
	if (numEmployees == employeesCapacity) resizeEmployees();
	employees[numEmployees++] = e;
	return *this;
}

const Cinema& Cinema::operator+=(Guest* g)
{
	if (numGuests == guestsCapacity) resizeGuests();
	guests[numGuests++] = g;
	return *this;
}

const Cinema& Cinema::operator+=(Hall* h)
{
	if (numHalls == hallsCapacity) resizeHalls();
	halls[numHalls++] = h;
	return *this;
}

const Cinema& Cinema::operator+=(Movie* m)
{
	if (numMovies == moviesCapacity) resizeMovies();
	movies[numMovies++] = m;
	return *this;
}

const Cinema& Cinema::operator+=(Shift* s)
{
	if (numShifts == shiftsCapacity) resizeShifts();
	shifts[numShifts++] = s;
	return *this;
}

const Cinema& Cinema::operator-=(int guestId)
{
	bool found = false;
	for (int i = 0; i < numGuests; i++)
	{
		if (!found)
		{
			if (guests[i]->getId() == guestId)
			{
				delete guests[i];
				numGuests--;
			}
		}
		else
		{
			guests[i - 1] = guests[i];
			guests[i] = nullptr;
		}
	}
	if (!found) cout << "Guest with given ID doesn't exist. Operation cancelled." << endl;
	return *this;
}

void Cinema::printAllEmployees() const
{
	for (int i = 0; i < numEmployees; i++)
	{
		cout << i << ". " << employees[i] << endl;
	}
}

void Cinema::printAllGuests() const
{
	for (int i = 0; i < numGuests; i++)
	{
		cout << i << ". " << *guests[i] << endl;
	}
}

void Cinema::printAllHalls() const
{
	for (int i = 0; i < numHalls; i++)
	{
		cout << i << ". " << *halls[i] << endl;
	}
}

void Cinema::printAllMovies() const
{
	for (int i = 0; i < numMovies; i++)
	{
		cout << i << ". " << movies[i]->getTitle() << endl;
	}
}

void Cinema::printAllShifts() const
{
	for (int i = 0; i < numShifts; i++)
	{
		cout << i << ". " << *shifts[i] << endl;
	}
}

void Cinema::resizeEmployees()
{
	employeesCapacity *= 2;
	Employee** temp = new Employee*[employeesCapacity];
	for (int i = 0; i < numEmployees; i++)
	{
		temp[i] = employees[i];
	}
	delete[] employees;
	employees = temp;
}

void Cinema::resizeGuests()
{
	guestsCapacity *= 2;
	Guest** temp = new Guest*[guestsCapacity];
	for (int i = 0; i < numGuests; i++)
	{
		temp[i] = guests[i];
	}
	delete[] guests;
	guests = temp;
}

void Cinema::resizeHalls()
{
	hallsCapacity *= 2;
	Hall** temp = new Hall*[hallsCapacity];
	for (int i = 0; i < numHalls; i++)
	{
		temp[i] = halls[i];
	}
	delete[] halls;
	halls = temp;
}

void Cinema::resizeMovies()
{
	moviesCapacity *= 2;
	const Movie** temp = new const Movie*[moviesCapacity];
	for (int i = 0; i < numMovies; i++)
	{
		temp[i] = movies[i];
	}
	delete[] movies;
	movies = temp;
}

void Cinema::resizeShifts()
{
	shiftsCapacity *= 2;
	const Shift** temp = new const Shift*[shiftsCapacity];
	for (int i = 0; i < numShifts; i++)
	{
		temp[i] = shifts[i];
	}
	delete[] shifts;
	shifts = temp;
}
