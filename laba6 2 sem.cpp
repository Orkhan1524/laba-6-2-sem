#include <stdexcept>
#include <cmath>
#include <iostream>
using namespace std;
class PrimeNumber {
private:
    int value;

    // Проверка, является ли число простым
    bool isPrime(int num) const {
        if (num <= 1) return false;
        if (num <= 3) return true;
        if (num % 2 == 0 || num % 3 == 0) return false;
        for (int i = 5; i * i <= num; i += 6) {
            if (num % i == 0 || num % (i + 2) == 0) return false;
        }
        return true;
    }

public:
    // Конструктор
    PrimeNumber(int value) {
        if (!isPrime(value)) {
            throw InvalidPrimeNumberException(value);
        }
        this->value = value;
    }
};

class InvalidPrimeNumberException : public invalid_argument {
private:
    int invalidValue;

public:
    InvalidPrimeNumberException(int value) : invalid_argument("Invalid prime number"), invalidValue(value) {}

    // Метод для печати всех данных
    void printDetails() const {
        cout << "Invalid value: " << invalidValue << endl;
        cout << "Reason: " << what() << endl;
    }
};

int main() {
    try {
        // Создание объекта с простым числом
        PrimeNumber prime(7);
        cout << "Created prime number object with value: 7" << endl;

        // Создание объекта с непростым числом
        PrimeNumber invalidPrime(4);
        cout << "Created prime number object with value: 4" << endl;
    }
    catch (const InvalidPrimeNumberException& e) {
        // Обработка исключения
        e.printDetails();
    }

    return 0;
}
