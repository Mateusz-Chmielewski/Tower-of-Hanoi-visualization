#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

int main()
{
    //Creating the window
    RenderWindow W;
    W.create(VideoMode(1280, 720, 32), "Tower of Hanoi");
    W.setActive(true);
    W.setKeyRepeatEnabled(false);
    W.setFramerateLimit(60);
    W.setPosition(Vector2i(550, 50));
    W.setVerticalSyncEnabled(true);


    //Creating a event and display the window
    Event event;

    while (W.isOpen()) {
        while (W.pollEvent(event))
            if (event.type == Event::Closed || Keyboard::isKeyPressed(Keyboard::Escape))
                W.close();

        W.clear(Color(255, 255, 255));

        W.display();
    }


    return 0;
}
