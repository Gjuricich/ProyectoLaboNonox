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
    manager.update(manager.getWindow());
    manager.getWindow().display();
  }

  return 0;
}



////   saveScoreArchive(190,"Romina");
////   saveScoreArchive(208,"Roman");
////   saveScoreArchive(10,"Tao");
////   saveScoreArchive(15,"COCO");
//
//   saveScoreArchive(190,"----");
//   saveScoreArchive(208,"Roman");
//
//
//    ArchiveScore _archivoScore;
//    Score score;
//
//    ///LIMPIO SCORE
////    score.setName("None");
////    score.setScore(0);
////
////  for(int i=0;i<10;i++){
////
////    _archivoScore.guardarArchivo(score);
////  }
//
//
//  for(int i=0;i<10;i++){
//
//    score=_archivoScore.leerArchivo(i);
//    cout<<score.getName()<<"    "<<score.getScore()<<endl;
//  }





//   ArchiveScore arch;
//   Score score;
//    score.setName("None");
//    score.setScore(0);
//
//  for(int i=0;i<10;i++){
//
//    arch.guardarArchivo(score);
//  }

//
//   ArchiveScore arch;
//   Score score;
////    score.setName("None");
////    score.setScore(0);
//
//  for(int i=0;i<10;i++){
//
//    score=arch.leerArchivo(i);
//    cout<<score.getName()<<"    "<<score.getScore()<<endl;
//  }
