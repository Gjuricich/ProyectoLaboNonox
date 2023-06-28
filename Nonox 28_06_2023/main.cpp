#include <SFML/Graphics.hpp>
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


//    ArchiveScore _archivoScore;
//    Score score;
//
//    ///LIMPIO SCORE
//    score.setName("None");
//    score.setScore(0);
//
//  for(int i=0;i<10;i++){
//
//    _archivoScore.guardarArchivo(score);
//  }








