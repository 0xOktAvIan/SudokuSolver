/**
 * @file Field.cc
 * @author Nikolaj Zurbuchen
 * @brief Field definition
 * @version 0.1
 * @date 28-05-2022
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "Field.h"

#include <fstream>

Field::Field() : numbers_(81) {
  for (int i = 0; i < 81; i++) {
    numbers_[i] = 0;
  }
}

Field::Field(std::string file_path) : numbers_(81) {
  std::ifstream istream(file_path);

  std::string line;
  while (getline(istream, line)) {
    unsigned int num = 0;
    for (int i = 0; i < line.length(); i++) {
      numbers_[i + num] = line[i] - 0x30;
    }

    num += 9;
  }
}

int& Field::Get(unsigned int index) { return numbers_[index]; }

void Field::Set(unsigned int index, int value) { numbers_[index] = value; }

const unsigned int Field::Size() const { return numbers_.size(); }

const std::vector<int> Field::Square(unsigned int index) const {
  switch (CalculateSquare(index)) {
    case 0:
      return std::vector<int>({numbers_[0], numbers_[1], numbers_[2],
                               numbers_[9], numbers_[10], numbers_[11],
                               numbers_[18], numbers_[19], numbers_[20]});
    case 1:
      return std::vector<int>({numbers_[3], numbers_[4], numbers_[5],
                               numbers_[12], numbers_[13], numbers_[14],
                               numbers_[21], numbers_[22], numbers_[23]});
    case 2:
      return std::vector<int>({numbers_[6], numbers_[7], numbers_[8],
                               numbers_[15], numbers_[16], numbers_[17],
                               numbers_[24], numbers_[25], numbers_[26]});
    case 3:
      return std::vector<int>({numbers_[27], numbers_[28], numbers_[29],
                               numbers_[36], numbers_[37], numbers_[38],
                               numbers_[45], numbers_[46], numbers_[47]});
    case 4:
      return std::vector<int>({numbers_[30], numbers_[31], numbers_[32],
                               numbers_[39], numbers_[40], numbers_[41],
                               numbers_[48], numbers_[49], numbers_[50]});
    case 5:
      return std::vector<int>({numbers_[33], numbers_[34], numbers_[35],
                               numbers_[42], numbers_[43], numbers_[44],
                               numbers_[51], numbers_[52], numbers_[53]});
    case 6:
      return std::vector<int>({numbers_[54], numbers_[55], numbers_[56],
                               numbers_[63], numbers_[64], numbers_[65],
                               numbers_[72], numbers_[73], numbers_[74]});
    case 7:
      return std::vector<int>({numbers_[57], numbers_[58], numbers_[59],
                               numbers_[66], numbers_[67], numbers_[68],
                               numbers_[75], numbers_[76], numbers_[77]});
    case 8:
      return std::vector<int>({numbers_[60], numbers_[61], numbers_[62],
                               numbers_[69], numbers_[70], numbers_[71],
                               numbers_[78], numbers_[79], numbers_[80]});
  }

  throw "Wrong value";
  return std::vector<int>();
}

const std::vector<int> Field::HorizontalLine(unsigned int index) const {
  if (index < 9) {
    return std::vector<int>(numbers_.begin(), numbers_.begin() + 9);
  } else if (index < 18) {
    return std::vector<int>(numbers_.begin() + 9, numbers_.begin() + 18);
  } else if (index < 27) {
    return std::vector<int>(numbers_.begin() + 18, numbers_.begin() + 27);
  } else if (index < 36) {
    return std::vector<int>(numbers_.begin() + 27, numbers_.begin() + 36);
  } else if (index < 45) {
    return std::vector<int>(numbers_.begin() + 36, numbers_.begin() + 45);
  } else if (index < 54) {
    return std::vector<int>(numbers_.begin() + 45, numbers_.begin() + 54);
  } else if (index < 63) {
    return std::vector<int>(numbers_.begin() + 54, numbers_.begin() + 63);
  } else if (index < 72) {
    return std::vector<int>(numbers_.begin() + 63, numbers_.begin() + 72);
  } else if (index < 81) {
    return std::vector<int>(numbers_.begin() + 72, numbers_.begin() + 81);
  }

  throw "Wrong value";
  return std::vector<int>();
}

const std::vector<int> Field::VerticalLine(unsigned int index) const {
  switch (index % 9) {
    case 0:
      return std::vector<int>({numbers_[0], numbers_[9], numbers_[18],
                               numbers_[27], numbers_[36], numbers_[45],
                               numbers_[54], numbers_[63], numbers_[72]});
    case 1:
      return std::vector<int>({numbers_[1], numbers_[10], numbers_[19],
                               numbers_[28], numbers_[37], numbers_[46],
                               numbers_[55], numbers_[64], numbers_[73]});
    case 2:
      return std::vector<int>({numbers_[2], numbers_[11], numbers_[20],
                               numbers_[29], numbers_[38], numbers_[47],
                               numbers_[56], numbers_[65], numbers_[74]});
    case 3:
      return std::vector<int>({numbers_[3], numbers_[12], numbers_[21],
                               numbers_[30], numbers_[39], numbers_[48],
                               numbers_[57], numbers_[66], numbers_[75]});
    case 4:
      return std::vector<int>({numbers_[4], numbers_[13], numbers_[22],
                               numbers_[31], numbers_[40], numbers_[49],
                               numbers_[58], numbers_[67], numbers_[76]});
    case 5:
      return std::vector<int>({numbers_[5], numbers_[14], numbers_[23],
                               numbers_[32], numbers_[41], numbers_[50],
                               numbers_[59], numbers_[68], numbers_[77]});
    case 6:
      return std::vector<int>({numbers_[6], numbers_[15], numbers_[24],
                               numbers_[33], numbers_[42], numbers_[51],
                               numbers_[60], numbers_[69], numbers_[78]});
    case 7:
      return std::vector<int>({numbers_[7], numbers_[16], numbers_[25],
                               numbers_[34], numbers_[43], numbers_[52],
                               numbers_[61], numbers_[70], numbers_[79]});
    case 8:
      return std::vector<int>({numbers_[8], numbers_[17], numbers_[26],
                               numbers_[35], numbers_[44], numbers_[53],
                               numbers_[62], numbers_[71], numbers_[80]});
  }

  throw "Wrong value";
  return std::vector<int>();
}

const unsigned int Field::CalculateSquare(unsigned int index) const {
  /*
  Square indices as follows:

   0 | 1 | 2
  -----------
   3 | 4 | 5
  -----------
   6 | 7 | 8

  */

  unsigned int possibility1, possibility2, possibility3;

  // rule out vertical possibilities
  if (index % 9 < 3) {
    possibility1 = 0;
    possibility2 = 3;
    possibility3 = 6;
  } else if (index % 9 < 6) {
    possibility1 = 1;
    possibility2 = 4;
    possibility3 = 7;
  } else if (index % 9 < 9) {
    possibility1 = 2;
    possibility2 = 5;
    possibility3 = 8;
  }

  // rule out horizontal possibilities
  if (index < 27) {
    return possibility1;
  } else if (index < 54) {
    return possibility2;
  } else if (index < 81) {
    return possibility3;
  }

  throw "Wrong value";
  return 0;
}