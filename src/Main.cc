/**
 * @file Main.cc
 * @author Nikolaj Zurbuchen
 * @brief Main Program File
 * @version 0.1
 * @date 28-05-2022
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "Field.h"
#include "Solver.h"

int main() {
  Field field("FILEPATH");
  Solver solver(field);
}