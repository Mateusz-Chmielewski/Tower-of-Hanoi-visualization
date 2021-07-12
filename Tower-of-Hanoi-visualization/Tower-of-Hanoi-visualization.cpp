#include <iostream>
#include <SFML/Graphics.hpp>
#include <sstream>
#include <vector>

using namespace std;
using namespace sf;

//Algorithm that return in string step by step the solution to the Tower of Hanoi problem
string mchHanoiStringAlgorithm(int n, char a, char b, char c) {
    if (n != 0) {
        stringstream result;
        result << mchHanoiStringAlgorithm(n - 1, a, c, b);
        result << a << c << " ";
        result << mchHanoiStringAlgorithm(n - 1, b, a, c);
        return result.str();
    } else return "";
}

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


    //Initialize of the Tower of Hanoi algorithm
    int numberOfDisks = 6;
    string step = mchHanoiStringAlgorithm(numberOfDisks, 'A', 'B', 'C');
    cout << step;

    vector <RectangleShape> listOfDisksOnPale[3];

    //Creating disks
    for (int i = 1; i < numberOfDisks; i++) {
        unsigned DiskSizeX = 40 + 20 * i;
        unsigned DiskSizeY = 20;
        listOfDisksOnPale[0].push_back(RectangleShape(Vector2f(DiskSizeX, DiskSizeY)));
        listOfDisksOnPale[0].back().setFillColor(Color(0, 255, 255));
        listOfDisksOnPale[0].back().setOrigin((DiskSizeY + DiskSizeX) / 2 - paleSize.x / 2, 0);
    }


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

        displayedWindow.draw(listOfDisksOnPale[0].back());


        displayedWindow.display();
    }


    return 0;
}
