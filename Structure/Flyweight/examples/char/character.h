#ifndef _CHARACTER_H_
#define _CHARACTER_H_
class Character {
protected:
  char symbol_;
  int width_;
  int height_;
  int ascent_;
  int descent_;
  int pointSize_;
public:
  virtual void Display(int pointSize) = 0;
};
#endif // _CHARACTER_H_
