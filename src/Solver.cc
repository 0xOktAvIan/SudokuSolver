/**
 * @file Solver.cc
 * @author Nikolaj Zurbuchen
 * @brief solver definition
 * @version 0.1
 * @date 28-05-2022
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "Solver.h"

#include <vector>
#include <algorithm>
#include <iostream>

Solver::Solver(Field field) {
  Field solution;

  // Where the given numbers lie
  std::vector<bool> given_indices;
  for (int i = 0; i < field.Size(); i++) {
    if (field.Get(i) == 0) {
      given_indices.push_back(false);
    } else {
      given_indices.push_back(true);
      solution.Set(i, field.Get(i));
    }
  }

  int last_empty_index = 0;
  for (int i = 80; i != 0; i--) {
    if (given_indices[i] == false) {
      last_empty_index = i;
      break;
    }
  }

  int current_position = 0;

  int current_number = 1;
  std::vector<int> current_number_list;

  int tries = 1;
  std::vector<int> tries_list;

  bool incrementing = true;

  while (current_position < field.Size()) {
    // Check if the current position is already given
    if (given_indices[current_position]) {
      if (incrementing) {
        current_position++;
      } else {
        current_position--;
      }
      continue;
    }

    // Check if one cicle of tries (1-9) has been completed
    if (tries > 9) {
      solution.Set(current_position, 0);

      current_position--;
      current_number = current_number_list[current_number_list.size() - 1];
      current_number_list.pop_back();

      tries = tries_list[tries_list.size() - 1];
      tries_list.pop_back();

      incrementing = false;
      continue;
    }

    // Check if current_number is too big
    if (current_number > 9) {
      current_number = 1;
      continue;
    }

    // Trie next number
    solution.Set(current_position, current_number);

    // Check if valid
    if (ValidateField(solution, current_position)) {
      current_position++;

      if (current_number != 9) {
        current_number_list.push_back(++current_number);
      } else {
        current_number_list.push_back(1);
        current_number++;
      }

      tries_list.push_back(++tries);
      tries = 1;

      incrementing = true;

      if (solution.Get(last_empty_index) != 0) break;

      continue;
    }

    // If not valid, revert, increase number to trie and point in the cycle
    solution.Set(current_position, 0);
    current_number++;

    tries++;
  }

  // Output with "nice" formatting
  for (int i = 0; i < 81; i += 9) {
    auto tmp = solution.HorizontalLine(i);
    for (int j = 0; j < 9; j++) {
      std::cout << tmp[j];
      if (j % 3 == 2 && j != 8) std::cout << '|';
    }
    std::cout << '\n';
    if (i == 18 || i == 45) std::cout << "-----------\n";
  }
  std::cout << '\n';
}

bool Solver::ValidateField(Field field, unsigned int current_position) const {
  auto square = field.Square(current_position);
  auto horz_line = field.HorizontalLine(current_position);
  auto vert_line = field.VerticalLine(current_position);

  // Sort for duplicate check later
  std::sort(square.begin(), square.end());
  std::sort(vert_line.begin(), vert_line.end());
  std::sort(horz_line.begin(), horz_line.end());

  // Erase empty tiles
  for (int i = 0; i < 9; i++) {
    if (square[0] == 0) square.erase(square.begin());

    if (vert_line[0] == 0) vert_line.erase(vert_line.begin());

    if (horz_line[0] == 0) horz_line.erase(horz_line.begin());
  }

  // Find duplicates
  if ((std::adjacent_find(square.begin(), square.end()) != square.end()) ||
      (std::adjacent_find(vert_line.begin(), vert_line.end()) !=
       vert_line.end()) ||
      (std::adjacent_find(horz_line.begin(), horz_line.end()) !=
       horz_line.end())) {
    return false;
  }

  return true;
}