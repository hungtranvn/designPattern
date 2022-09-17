#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <string>

class Player {
  public:
    Player() = default;
    ~Player() = default;
    void initialize_player(std::string player_name, char player_mark);
    std::string get_name();
    char get_mark();
    void update_did_win();
    bool did_win();
  private:
    std::string name;
    char mark;
    bool winner = false;
}
#endif // _PLAYER_H_
