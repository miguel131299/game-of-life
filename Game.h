#include <cstddef>
#include <cstdint>
#include <functional>
#include <vector>

class GameOfLife {
public:
  GameOfLife();
  GameOfLife(GameOfLife &&) = default;
  GameOfLife(const GameOfLife &) = default;
  GameOfLife &operator=(GameOfLife &&) = default;
  GameOfLife &operator=(const GameOfLife &) = default;
  ~GameOfLife();

  void tick() {
    std::vector<std::vector<bool>> newBoard;

    for (std::size_t i = 0; i < board.size(); i++) {
      for (std::size_t j = 0; j < board[0].size(); j++) {
        std::uint8_t count = countLiveNeighbors(j, i);

        if (count < 2 || count > 3) {
          newBoard[i][j] = false;
        }

        else if (count == 3) {
          newBoard[i][j] = true;
        }

        else {
          newBoard[i][j] = board[i][j];
        }
      }
    }
  }

private:
  std::vector<std::vector<bool>> board;

  std::uint8_t countLiveNeighbors(std::size_t x, std::size_t y) {
    std::int8_t res = 0;

    for (size_t i = -1; i < 2; i++) {
      for (size_t j = -1; j < 2; j++) {
        if (i == 0 && j == 0) {
          continue;
        }

        if (getTile(x + i, y + j)) {
          res++;
        }
      }
    }

    return res;
  }

  bool getTile(std::size_t x, std::size_t y) {
    if (x >= 0 && x < board[0].size() && y >= 0 && y < board.size()) {
      return board[y][x];
    }

    return false;
  }
};

GameOfLife::GameOfLife() {}

GameOfLife::~GameOfLife() {}
