#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <stdio.h> 
#include <time.h> 

int main(){

    const int scrwidth = 500;  //g++ -c main.cpp ; g++ main.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
    const int scrheight = 500;

    const float res = 5;

    bool life[(int)(scrwidth/res)][(int)(scrheight/res)];
    bool life1[(int)(scrwidth/res)][(int)(scrheight/res)];

    int neig = 0; //Neighbours

    srand(time(NULL));

    for(int y = 0; y < (int)(scrheight/res); y++){
      for(int x = 0; x < (int)(scrwidth/res); x++){

        if(rand() % 3 == 0){
          life[x][y] = true;
        }else{
          life[x][y] = false;
        }
      }
    }

    sf::RenderWindow window(sf::VideoMode(scrwidth, scrheight), "Kaut Kas");
    sf::CircleShape cell(res/2);
    cell.setFillColor(sf::Color::Green);

    while (window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)){

            for(int y = 0; y < (int)(scrheight/res); y++){
                for(int x = 0; x < (int)(scrwidth/res); x++){

                    if(rand() % 3 == 0){
                        life[x][y] = true;
                    }else{
                        life[x][y] = false;
                    }
                }
            }
        }

        for(int y = 0; y < (int)(scrheight/res); y++){
            for(int x = 0; x < (int)(scrwidth/res); x++){
                neig = 0;

                if(true == life[x-1][y-1]){neig++;}
                if(true == life[x-1][y]){neig++;}
                if(true == life[x-1][y+1]){neig++;}

                if(true == life[x][y-1]){neig++;}
                if(true == life[x][y+1]){neig++;}

                if(true == life[x+1][y-1]){neig++;}
                if(true == life[x+1][y]){neig++;}
                if(true == life[x+1][y+1]){neig++;}

                if((neig == 2 || neig == 3) && (life[x][y] == true)){life1[x][y] = true;}else
                  if(neig == 3){life1[x][y] = true;}else{life1[x][y] = false;}

            }
        }

        std::copy(&life1[0][0], &life1[0][0]+(int)(scrheight/res)*(int)(scrwidth/res), &life[0][0]);

        window.clear();
        for(int y = 0; y < (int)(scrheight/res); y++){
          for(int x = 0; x < (int)(scrwidth/res); x++){
            if(life[x][y] == true){
              cell.setPosition(x*res,y*res);
              window.draw(cell);
            }
          }
        }
        window.display();
    }

    return 0;
}
