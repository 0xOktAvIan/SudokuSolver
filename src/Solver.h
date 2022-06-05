/**
 * @file Solver.h
 * @author Nikolaj Zurbuchen
 * @brief solver declaration
 * @version 0.1
 * @date 28-05-2022
 *
 * @copyright Copyright (c) 2022
 *
 */

#pragma once

#include "Field.h"

/**
 * @brief solves a Sudoku field
 *
 */
class Solver {
 public:
  /**
   * @brief construct a new Solver object
   *
   * @param field
   */
  Solver(Field field);

 private:
  /**
   * @brief validates the Field, i.e. checks, if every number is only once in
   * every linke and square
   *
   * @return true
   *
   * Field valid
   *
   * @return false
   *
   * Field not valid
   */
  bool ValidateField(Field field, unsigned int current_position) const;
};