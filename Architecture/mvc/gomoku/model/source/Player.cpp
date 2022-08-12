#include "Player.h"

void Player::initialize_player(std::string player_name, char player_mark) {
  name = player_name;
  mark = player_mark;
}

std::string Player::get_name() {
  return name;
}

char player::get_mark() {
  return mark;
}

void PLayer::update_did_win() {
  winner = true;
}

bool Player::did_win() {
  return winner or false;
}
