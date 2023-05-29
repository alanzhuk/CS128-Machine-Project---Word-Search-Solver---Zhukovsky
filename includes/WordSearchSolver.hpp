#ifndef WORDSEARCHSOLVER_HPP
#define WORDSEARCHSOLVER_HPP

#include <cstddef>
#include <string>
#include <vector>

#include "WordLocation.hpp"

enum class CheckDirection { kHorizontal, kVertical, kLeftDiag, kRightDiag };

bool operator==(WordLocation left, WordLocation right);

struct Coords {
  unsigned int row;
  unsigned int col;
};

class WordSearchSolver {
public:
  WordSearchSolver(const std::vector<std::vector<char>>& puzzle);
  WordLocation FindWord(const std::string& word);
  WordLocation FindWord(const std::string& word, CheckDirection direction);

private:
  bool LocationInBounds(size_t row, size_t col) const;
  bool VertChecker(const std::string& word, unsigned int row, unsigned int col) const;
  WordLocation CompVert(const std::string& word, Coords c) const;
  WordLocation CompLeftDiag(const std::string& word, Coords coords) const;
  WordLocation CompRightDiag(const std::string& word, Coords c) const;
  WordLocation Horizontal(const std::string& word) const;
  WordLocation Vertical(const std::string& word) const;
  WordLocation DiagStarter(const std::string& word, CheckDirection direction) const;
  bool LeftDiag(const std::string& word, unsigned int row, unsigned int col) const;
  bool RightDiag(const std::string& word, unsigned int row, unsigned int col) const;
  std::vector<std::vector<char>> puzzle_;
  size_t puzzle_height_;
  size_t puzzle_width_;
};

#endif