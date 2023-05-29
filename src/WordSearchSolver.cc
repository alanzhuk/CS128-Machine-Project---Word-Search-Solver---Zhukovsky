#include "WordSearchSolver.hpp"
bool WordSearchSolver::LocationInBounds(size_t row, size_t col) const {
  return ((row < puzzle_height_) && (col < puzzle_width_));
}
bool operator==(WordLocation left, WordLocation right) {
    if (left.char_positions.size() != right.char_positions.size()) {
        return false;
    }
    for (unsigned int i = 0; i < left.char_positions.size(); i++) {
        CharPositions &l = left.char_positions[i];
        CharPositions &r = right.char_positions[i];
        if (l.character != r.character || l.row != r.row || l.col != r.col) {
            return false;
        }
    }
    return true;
}
WordSearchSolver::WordSearchSolver(const std::vector<std::vector<char>>& puzzle){ 
  puzzle_ = puzzle;
  puzzle_height_ = puzzle.size();
  puzzle_width_ = puzzle.at(1).size();
}
WordLocation WordSearchSolver::Horizontal(const std::string& word) const{
  for(size_t row = 0; row < puzzle_height_; row++) {
    unsigned int streak = 0;
    std::vector<CharPositions> chars;
    for (size_t col = 0; col < puzzle_width_; col++) {
      if (streak == word.size()) {
        WordLocation ret = {word, chars};
        return ret;
      }
      if (puzzle_[row][col] == word.at(streak)) {
        CharPositions hold = {puzzle_[row][col], row, col};
        chars.push_back(hold);
        streak++;
      } else {
        streak = 0;
        chars.clear();
      }
    }
    if (streak == word.size()) {
        WordLocation ret = {word, chars};
        return ret;
    }
  }
  return WordLocation{};
}
WordLocation WordSearchSolver::DiagStarter(const std::string& word, CheckDirection direction) const{
  for (unsigned int row = 0; row < puzzle_height_; row++) {
    for (unsigned int col = 0; col < puzzle_width_; col++) {
      switch(direction) {
        case CheckDirection::kLeftDiag:
          if (word.at(0) == puzzle_[row][col] && LeftDiag(word, row, col)) {
            Coords c = {row, col};
            return CompLeftDiag(word, c);
          }
          break;
        case CheckDirection::kRightDiag:
          if (word.at(0) == puzzle_[row][col] && RightDiag(word, row, col)) {
            Coords c = {row, col};
            return CompRightDiag(word, c);
          }
          break;
        default:
          break;
      }
    }
  }
  return WordLocation{};
}
bool WordSearchSolver::VertChecker(const std::string& word, unsigned int row, unsigned int col) const{
  unsigned int count = 0;
  while (LocationInBounds(row, col)) {
    if (count == word.size()) {
      return true;
    }
    if (word.at(count) == puzzle_[row][col]) {
      count++;
    } else {
      return false;
    }
    row++;
  }
  return count == word.size();
}
WordLocation WordSearchSolver::CompVert(const std::string& word, Coords c) const{
  unsigned int row = c.row;
  unsigned int col = c.col;
  std::vector<CharPositions> hold;
  for (unsigned int i = 0; i < word.size(); i++) {
    CharPositions temp = {puzzle_[row][col],row, col};
    hold.push_back(temp);
    row++;
  }
  WordLocation ret = {word, hold};
  return ret;
}
WordLocation WordSearchSolver::Vertical(const std::string& word) const{
  for(unsigned int col = 0; col < puzzle_width_; col++) {
    for (unsigned int row = 0; row < puzzle_height_; row++) {
      if (word.at(0) == puzzle_[row][col] && VertChecker(word, row, col)) {
          Coords c = {row, col};
        return CompVert(word, c);
      }
    }
  }
  return WordLocation{};
}
bool WordSearchSolver::LeftDiag(const std::string& word, unsigned int row, unsigned int col) const{
  unsigned int count = 0;
  while (LocationInBounds(row, col)) {
    if (count == word.size()) {
      return true;
    }
    if (word.at(count) == puzzle_[row][col]) {
      count++;
    } else {
      return false;
    }
    row++;
    col--;
  }
  return count == word.size();
}
WordLocation WordSearchSolver::CompLeftDiag(const std::string& word, Coords c) const{
  unsigned int row = c.row;
  unsigned int col = c.col;
  std::vector<CharPositions> hold;
  for (unsigned int i = 0; i < word.size(); i++) {
    CharPositions temp = {puzzle_[row][col],row, col};
    hold.push_back(temp);
    row++;
    col--;
  }
  WordLocation ret = {word, hold};
  return ret;
}

bool WordSearchSolver::RightDiag(const std::string& word, unsigned int row, unsigned int col) const{
  unsigned int count = 0;
  while (LocationInBounds(row, col)) {
    if (count == word.size()) {
      return true;
    }
    if (word.at(count) == puzzle_[row][col]) {
      count++;
    } else {
      return false;
    }
    row++;
    col++;
  }
  return count == word.size();
}
WordLocation WordSearchSolver::CompRightDiag(const std::string& word, Coords c) const{
  unsigned int row = c.row;
  unsigned int col = c.col;
  std::vector<CharPositions> hold;
  for (unsigned int i = 0; i < word.size(); i++) {
    CharPositions temp = {puzzle_[row][col],row, col};
    hold.push_back(temp);
    row++;
    col++;
  }
  WordLocation ret = {word, hold};
  return ret;
}
WordLocation WordSearchSolver::FindWord(const std::string& word, CheckDirection direction) {
  switch(direction) {
    case CheckDirection::kHorizontal:
      return Horizontal(word);
      break;
    case CheckDirection::kVertical:
      return Vertical(word);
      break;
    case CheckDirection::kRightDiag:
    case CheckDirection::kLeftDiag:
      return DiagStarter(word, direction);
      break;
    default:
      break;
  }
  return WordLocation{};
}
WordLocation WordSearchSolver::FindWord(const std::string& word) {
  WordLocation empty = {};
  if (FindWord(word, CheckDirection::kHorizontal) != empty) {
    return FindWord(word, CheckDirection::kHorizontal);
  } 
  if (FindWord(word, CheckDirection::kVertical) != empty) {
    return FindWord(word, CheckDirection::kVertical);
  } 
  if (FindWord(word, CheckDirection::kLeftDiag) != empty) {
    return FindWord(word, CheckDirection::kLeftDiag);
  } 
  if (FindWord(word, CheckDirection::kRightDiag) != empty) {
    return FindWord(word, CheckDirection::kRightDiag);
  }
  return WordLocation{};
}
