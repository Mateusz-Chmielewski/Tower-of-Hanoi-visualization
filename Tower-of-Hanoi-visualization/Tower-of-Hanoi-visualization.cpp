#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

int main()
{
    //Creating the window
    RenderWindow displayedWindow;
    displayedWindow.create(VideoMode(1280, 720, 32), "Tower of Hanoi");
    displayedWindow.setActive(true);
    displayedWindow.setKeyRepeatEnabled(false);
    displayedWindow.setFramerateLimit(60);
    displayedWindow.setPosition(Vector2i(550, 50));
    displayedWindow.setVerticalSyncEnabled(true);

    //Creating shapes of pales
    Vector2f paleSize(40, 600);
    auto palePositionX = displayedWindow.getSize().x / 4;
    auto palePositionY = displayedWindow.getSize().y - paleSize.y;

    RectangleShape paleA(paleSize);
    paleA.setFillColor(Color(255, 0, 0));
    paleA.setOrigin(0, 0);
    paleA.setPosition(palePositionX, palePositionY);

    RectangleShape paleB(paleSize);
    paleB.setFillColor(Color(0, 255, 0));
    paleB.setOrigin(0, 0);
    paleB.setPosition(palePositionX * 2, palePositionY);

    RectangleShape paleC(paleSize);
    paleC.setFillColor(Color(0, 0, 255));
    paleC.setOrigin(0, 0);
    paleC.setPosition(palePositionX * 3, palePositionY);

    //Creating a event and displaying the window
    Event event;

    while (displayedWindow.isOpen()) {
        while (displayedWindow.pollEvent(event))
            if (event.type == Event::Closed || Keyboard::isKeyPressed(Keyboard::Escape))
                displayedWindow.close();

        displayedWindow.clear(Color(255, 255, 255));

        //Dislaing pales
        displayedWindow.draw(paleA);
        displayedWindow.draw(paleB);
        displayedWindow.draw(paleC);


        displayedWindow.display();
    }


    return 0;
}
