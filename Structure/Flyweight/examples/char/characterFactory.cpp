#include "characterFactory.h"
#include <iostream>

CharacterFactory::~CharacterFactory() {
  while(!characters_.empty()) {
    map<char, Character*>::iterator it = characters_.begin();
    delete it->second;
    characters_.erase(it);
  }
}

CharactorFactory::getCharacter(char key) {
  Character* character = NULL;
  if(characters_.find(key) != characters_.end()) {
    character = characters_[key];
  }
  else {
    switch(key) {
      case 'A':
        character = new CharacterA();
        break;
      case 'B':
        character = new CharacterB();
        break;
      case 'C':
        character = new CharacterC();
        break;
      case 'D':
        character = new CharacterD();
        break;
      case 'E':
        character = new ChracterE();
        break;
      default:
        std::cout << "Not Implemented" << std::endl;
        throw("Not Implemented");
    }
    characters_[key] = character;
  }
  return character;
}
