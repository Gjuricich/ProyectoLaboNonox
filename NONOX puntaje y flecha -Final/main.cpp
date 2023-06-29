#include "ManagerNonox.h"

int main() {

  ManagerNonox manager;
  while (manager.getWindow().isOpen()) {
    sf::Event event;
    while (manager.getWindow().pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        manager.getWindow().close();
      }
    }

    manager.getWindow().clear();
    manager.update();
    manager.getWindow().display();
  }

    return 0;
}










