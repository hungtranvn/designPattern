#ifndef _MODEL_H_
#define _MODEL_H_

#include <vector>

enum class Status {
  out_of_bound_input,
  space_taken,
  valid_input,
  draw,
  winner
};

class Model {
  private:
    void check_if_won(int row, int col);
    bool update_grid(int row, int col);

}
#endif // _MODEL_H_
// https://github.com/joelmacias/MVCTicTacToe/blob/master/ModelTicTacToe.h
// https://github.com/deviadbo/Tic-Tac-Toe-MVC_Design
