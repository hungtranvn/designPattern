#ifndef _CHARACTER_FACTORY_H_
#define _CHARACTER_FACTORY_H_
#include <map>
class CharacterFactory {
private:
  map<char, Character*> characters_;
public:
  virtual ~CharacterFactory();
  Character* getCharacter(char key);
}
#endif // _CHARACTER_FACTORY_H_
