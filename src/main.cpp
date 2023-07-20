#include "includes/main.h"

int main(int argc, char *argv[]) {
  switch (argc) {
  case 1:
    // Print help when no arguments are given
    printHelp();
    break;
  case 5:
    // When 4 arguments are given, start the program
    argInput(argv);
    break;
  default:
    throw std::invalid_argument("Invalid input.");
    // Throw an exception when the number of arguments is invalid
  }
}