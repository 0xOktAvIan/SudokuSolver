/**
 * @file Field.h
 * @author Nikolaj Zurbuchen
 * @brief field declaration
 * @version 0.1
 * @date 28-05-2022
 *
 * @copyright Copyright (c) 2022
 *
 */

#pragma once

#include <string>
#include <vector>

/**
 * @brief funcionality of a Sudoku field
 *
 */
class Field {
 public:
  /**
   * @brief construct a new empty Field object
   *
   */
  Field();

  /**
   * @brief construct a new Field object and extracts numbers from file_path
   *
   * @param file_path
   *
   * path to the file containing the Sudoku field
   */
  Field(std::string file_path);

  /**
   * @brief get a value of the Field at index
   *
   * @param index
   *
   * index in the Field
   *
   * @return int&
   */
  int& Get(unsigned int index);

  /**
   * @brief set a value of the Field at index
   *
   * @param index
   *
   * index in the Field
   *
   * @param value
   *
   * value to set the field
   */
  void Set(unsigned int index, int value);

  /**
   * @brief get size of the Field
   *
   * @return const unsigned int
   */
  const unsigned int Size() const;

  /**
   * @brief get the square the number at index is in
   *
   * @param index
   *
   * index in the Field
   *
   *  @return const std::vector<unsigned int>
   */
  const std::vector<int> Square(unsigned int index) const;

  /**
   * @brief get the horizontal line the number at index is in
   *
   * @param index
   *
   * index in the Field
   *
   * @return const std::vector<unsigned int>
   */
  const std::vector<int> HorizontalLine(unsigned int index) const;

  /**
   * @brief get the vertical line the number at index is in
   *
   * @param index
   *
   * index in the Field
   *
   * @return const std::vector<unsigned int>
   */
  const std::vector<int> VerticalLine(unsigned int index) const;

 private:
  /**
   * @brief storage of the numbers
   *
   */
  std::vector<int> numbers_;

  /**
   * @brief calculates the square in which the index lies
   *
   * @param index
   *
   * index in the Field
   *
   * @return const unsigned int
   */
  const unsigned int CalculateSquare(unsigned int index) const;
};