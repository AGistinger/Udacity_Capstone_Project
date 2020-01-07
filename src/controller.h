#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "snake.h"

class Controller {
 public:
  void HandleInput(bool &running, Fish &fish) const;

 private:
  void ChangeDirection(Fish &fish, Fish::Direction input,
                       Fish::Direction opposite) const;
};

#endif