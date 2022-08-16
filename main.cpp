#include <iostream>
#include <cctype>
#include <cstdlib>
#include <cmath>

double find_answer (int first, int second, std::string op) {
  if (op == " + ") {
    return first + second;
  } else if (op == " - ") {
    return first - second;
  } else if (op == " * ") {
    return first * second;
  }
  double answer = (double) first / second;
  return round (answer * 10.0) / 10.0;
}

int main() {
  
  std::cout << "Welcome to the Math Quiz!\n";
  std::cout << "\nPlease enter the following information to continue:\n";

  std::string information1;
  std::cout << "\nWould you like ...\nA) three questions\nB) five questions\nC) seven questions\n";
  std::cin >> information1;

  int numberOfQuestions;
  if (information1 == "A" || information1 == "a") {
    numberOfQuestions = 3;
  } else if (information1 == "B" || information1 == "b") {
    numberOfQuestions = 5;
  } else if (information1 == "C" || information1 == "c") {
    numberOfQuestions = 7;
  } else {
    std::cout << "You entered something invalid, a choice has been made for you.\n";
    numberOfQuestions = 3;
  }

  std::string information2;
  std::cout << "\nWould you like ...\nA) addition questions\nB) subtraction questions\nC) multiplication questions\nD) division questions\n";
  std::cin >> information2;

  std::string typeOfQuestions;
  if (information2 == "A" || information2 == "a") {
    typeOfQuestions = " + ";
  } else if (information2 == "B" || information2 == "b") {
    typeOfQuestions = " - ";
  } else if (information2 == "C" || information2 == "c") {
    typeOfQuestions = " * ";
  } else if (information2 == "D" || information2 == "d") {
    typeOfQuestions = " / ";
  } else {
    std::cout << "You entered something invalid, a choice has been made for you.\n";
    typeOfQuestions = "+";
  }

  int range = 5;
  int correct = 0;
  for (int i = 0; i < numberOfQuestions; i++) {
    int first = (rand() % range) + 1;
    int second = (rand() % range) + 1;
    double userAnswer;
    std::cout << "\nQuestion # " << (i + 1) << ": " << first << typeOfQuestions << second << "?\n";
    std::cin >> userAnswer;
    double realAnswer = find_answer (first, second, typeOfQuestions);
    if (realAnswer == userAnswer) {
      std::cout << "Correct!\n";
      correct += 1;
    } else {
      std::cout << "Incorrect. The answer was " << realAnswer << ".\n";
    }  
    range += 5;
  }

  std::cout << "\nYou've reached the end! You got " << correct << "/" << numberOfQuestions << " correct!";
  
}
