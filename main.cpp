#include <iostream>

class Date {
private:
    int day;
    int month;
    int year;

public:
    Date(int d, int m, int y) : day(d), month(m), year(y) {}
    int operator-(const Date& other) const {
        int days1 = year * 365 + month * 30 + day;
        int days2 = other.year * 365 + other.month * 30 + other.day;
        return days1 - days2;
    }
    Date operator+(int days) const {
        Date result = *this;
        result.day += days;
        while (result.day > 30) {
            result.day -= 30;
            result.month++;
            if (result.month > 12) {
                result.month = 1;
                result.year++;
            }
        }
        return result;
    }
    bool operator==(const Date& other) const {
        return (day == other.day && month == other.month && year == other.year);
    }
    bool operator!=(const Date& other) const {
        return !(*this == other);
    }
    void printDate() const {
        std::cout << day << "/" << month << "/" << year << std::endl;
    }
};

int main() {
    Date date1(14, 4, 2024);
    Date date2(1, 4, 2024);

    int difference = date1 - date2;
    std::cout << "Difference in days: " << difference << std::endl;

    Date date3 = date1 + 20;
    std::cout << "Date after adding 20 days: ";
    date3.printDate();

    if (date1 == date2) {
        std::cout << "Dates are equal." << std::endl;
    }
    else {
        std::cout << "Dates are not equal." << std::endl;
    }

    if (date1 != date2) {
        std::cout << "Dates are not equal." << std::endl;
    }
    else {
        std::cout << "Dates are equal." << std::endl;
    }

    return 0;
}
