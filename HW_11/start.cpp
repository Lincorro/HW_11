#include <iostream>
#include <limits>
#include "caesar.h"
#include "email.h"

void start() {
    bool work = true;
    int choose = 0;

    std::cout << "Welcome to Homework 11\n";

    while (work) {
        std::cout << "\nChoose number exercise:\n"
            << "1 - Caesar Cipher\n"
            << "2 - Checking the correctness of the email address\n"
            << "3 - IP address validation\n"
            << "0 - Exit\n"
            << "Your choice: ";

        // �������� �����
        if (!(std::cin >> choose)) {
            std::cout << "Error: Please enter a NUMBER (0-3)\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        // ������� ������ ����� ����� �����
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choose) {
        case 1:
            std::cout << "\n=== Caesar Cipher ===\n";
            caesar();
            break;

        case 2:
            std::cout << "\n=== Email Validation ===\n";
            emailCheck();
            break;

        case 3:
            std::cout << "\n=== IP Validation ===\n";
            // ����� ������ ���� ������� ��� IP
            std::cout << "Function not implemented yet\n";
            break;

        case 0:
            work = false;
            std::cout << "Exiting program...\n";
            break;

        default:
            std::cout << "Error: Invalid choice. Please select 0-3\n";
            break;
        }

        // ������� ���������� ����� ����� ���������� �������
        if (choose >= 1 && choose <= 3 && work) {
            std::cout << "\nPress Enter to return to menu...";
            // ������� ������� ����� �� ��������� ���������� ��������
            std::cin.clear();
            // ����� ���� ������ ������� Enter
            while (std::cin.get() != '\n') {
                // ���� �� ����� ����� Enter
            }
        }
    }
}