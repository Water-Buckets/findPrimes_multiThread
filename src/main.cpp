#include "main.h"

int main(int argc, char *argv[]) {
  switch (argc) {
  case 1:
    printHelp();
    break;
  case 5:
    argInput(argv);
    break;
  default:
    throw std::invalid_argument("Invalid input.");
  }
}
