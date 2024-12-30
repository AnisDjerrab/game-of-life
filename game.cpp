#include <iostream>
#include <SFML/graphics.hpp>
#include <vector>
#include <random>

using namespace std;

/*pour executer
g++ game.cpp -o game.exe -I /c/SFML/include -L /c/SFML/lib -lsfml-graphics -lsfml-window -lsfml-system && ./game.exe
*/

vector<int> avenir(vector<vector<int>> coordonnees, vector<int> coordonnees_locales)
{
    int voisins(0);
    vector<int> situation;

    for (int i(0); i < coordonnees.size(); i++)
    {
    
        if (coordonnees_locales[0] == (coordonnees[i][0] - 20) && coordonnees_locales[1] == coordonnees[i][1])
        {
            if (coordonnees[i][2] == 1)
            {
                voisins += 1;
            }
        }


        else if (coordonnees_locales[0] == (coordonnees[i][0] + 20) && coordonnees_locales[1] == coordonnees[i][1])
        {
            if (coordonnees[i][2] == 1)
            {
                voisins += 1;
            }
        }

        else if (coordonnees_locales[0] == coordonnees[i][0] && coordonnees_locales[1] == (coordonnees[i][1] - 20))
        {
            if (coordonnees[i][2] == 1)
            {
                voisins += 1;
            }
        }

        else if (coordonnees_locales[0] == coordonnees[i][0] && coordonnees_locales[1] == (coordonnees[i][1] + 20))
        {
            if (coordonnees[i][2] == 1)
            {
                voisins += 1;
            }
        }

        else if (coordonnees_locales[0] == (coordonnees[i][0] + 20) && coordonnees_locales[1] == (coordonnees[i][1] + 20))
        {
            if (coordonnees[i][2] == 1)
            {
                voisins += 1;
            }
        }

        else if (coordonnees_locales[0] == (coordonnees[i][0] + 20) && coordonnees_locales[1] == (coordonnees[i][1] - 20))
        {
            if (coordonnees[i][2] == 1)
            {
                voisins += 1;
            }
        }

        else if (coordonnees_locales[0] == (coordonnees[i][0] - 20) && coordonnees_locales[1] == (coordonnees[i][1] - 20))
        {
            if (coordonnees[i][2] == 1)
            {
                voisins += 1;
            }
        }

        else if (coordonnees_locales[0] == (coordonnees[i][0] - 20) && coordonnees_locales[1] == (coordonnees[i][1] + 20))
        {
            if (coordonnees[i][2] == 1)
            {
                voisins += 1;
            }
        }
        if (voisins > 3)
        {
            break;
        }
    }
    if (voisins == 2 or voisins == 3)
    {
        if (voisins == 3)
        {
            return situation = {
                1,
                1
            };
        }
        else
        {
            return situation = {
                1, 
                0
            };
        }
    }
    else 
    {
        return situation = {
            0, 
            0
        };
    }
    
}


int arrondis20(int nombre)
{
    int intermediaire = nombre % 100;
    if (intermediaire > 20 and intermediaire < 40)
    {
        intermediaire -= 20;
    }
    else if (intermediaire > 40 and intermediaire < 60)
    {
        intermediaire -= 40;
    }
    else if (intermediaire > 60 and intermediaire < 80)
    {
        intermediaire -= 60;
    }
    else if (intermediaire > 80 and intermediaire < 100)
    {
        intermediaire -= 80;
    }
    if (intermediaire > 0 and intermediaire < 20)
    {
        intermediaire = -intermediaire;
        nombre += intermediaire;
    }
    return nombre;
}


int main()
{
    sf::RenderWindow screen(sf::VideoMode(1100, 800), "game of life");
    sf::Clock clock;

    sf::Texture texture1;
    texture1.loadFromFile("C:/users/Anis Djerrab/Downloads/photo_fleche.jpg");
    sf::Sprite sprite1;
    sprite1.setTexture(texture1);
    sprite1.setPosition(25.f, 90.f);
    sprite1.setScale(0.1f, 0.1f);

    sf::Texture texture2;
    texture2.loadFromFile("C:/users/Anis Djerrab/Downloads/photo_demarrer.jpg");
    sf::Sprite sprite2;
    sprite2.setTexture(texture2);
    sprite2.setPosition(25.f, 25.f);
    sprite2.setScale(0.125f, 0.125f);

    sf::Texture texture3;
    texture3.loadFromFile("C:/users/Anis Djerrab/Downloads/Reset.jpg");
    sf::Sprite sprite3;
    sprite3.setTexture(texture3);
    sprite3.setPosition(25.f, 155.f);
    sprite3.setScale(0.32f, 0.32f);

    sf::Texture texture4;
    texture4.loadFromFile("C:/users/Anis Djerrab/Downloads/photo_random.jpg");
    sf::Sprite sprite4;
    sprite4.setTexture(texture4);
    sprite4.setPosition(25.f, 220.f);
    sprite4.setScale(0.26f, 0.26f);

    vector<vector<int>> coordonnees;
    bool confirmation = false;
    int attente(0);
    int attente2(0);
    bool confirmation_temporaire;
    bool confirmation_definitive(false);
    vector<vector<int>> liste_a_modifier;


    for (size_t i(0); i < 1100; i += 20)
    {
        for (size_t y(0); y < 800; y += 20)
        {
            vector<int> coordonnees_locales;
            coordonnees_locales.push_back(i);
            coordonnees_locales.push_back(y);
            coordonnees_locales.push_back(0);
            coordonnees_locales.push_back(0);
            coordonnees.push_back(coordonnees_locales);
        }
    }
    cout << coordonnees.size() << endl;

    sf::FloatRect bounds1 = sprite1.getGlobalBounds();
    sf::FloatRect bounds2 = sprite2.getGlobalBounds();
    sf::FloatRect bounds3 = sprite3.getGlobalBounds();
    sf::FloatRect bounds4 = sprite4.getGlobalBounds();

    while (screen.isOpen())
    {
        sf::Event event;
        sf::Time deltaTime = clock.restart();
        while (screen.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                screen.close();
            }
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2f mousePos = sf::Vector2f(event.mouseButton.x, event.mouseButton.y);
                    vector<int> coordonnees_locales;
                    coordonnees_locales.push_back(event.mouseButton.x);
                    coordonnees_locales.push_back(event.mouseButton.y);
                    coordonnees_locales[0] = arrondis20(coordonnees_locales[0]);
                    coordonnees_locales[1] = arrondis20(coordonnees_locales[1]);
                    for (size_t i(0); i < coordonnees.size(); i++)
                    {
                        if (coordonnees[i][0] == coordonnees_locales[0] and coordonnees[i][1] == coordonnees_locales[1])
                        {
                            if (coordonnees[i][3] > 10)
                            {
                                coordonnees[i][3] = 0;
                                if (coordonnees[i][2] == 0)
                                {
                                    coordonnees[i][2] = 1;
                                }
                                else
                                {
                                    coordonnees[i][2] = 0;
                                }
                            }
                        }
                        if (bounds1.contains(mousePos))
                        {
                            if (attente > 10)
                            {
                                attente = 0;
                                confirmation_temporaire = true;
                            }
                        }
                        else if (bounds2.contains(mousePos))
                        {
                            if (attente2 > 10)
                            {
                                attente2 = 0;
                                if (confirmation_definitive)
                                {
                                    confirmation_definitive = false;
                                }
                                else
                                {
                                    confirmation_definitive = true;
                                }
                            }
                        }
                        else if (bounds3.contains(mousePos))
                        {
                            for (size_t i(0); i < coordonnees.size(); i++)
                            {
                                coordonnees[i][2] = 0;
                            }
                        }
                        else if (bounds4.contains(mousePos))
                        {
                            random_device rd;
                            mt19937 gen(rd());
                            uniform_int_distribution<> dis(0, 3);
                            for (size_t i(0); i < coordonnees.size(); i++)
                            {
                                coordonnees[i][2] = 0;
                                int random_number = dis(gen);
                                if (random_number == 1)
                                {
                                    coordonnees[i][2] = 1;
                                }
                            }
                        }
                    }
                }
            }
        }

        screen.clear(sf::Color::White);
        if (confirmation_temporaire == true or confirmation_definitive == true)
        {
            for (int i(0); i < coordonnees.size(); i++)
            {
                
                vector<int> avenirCarre = avenir(coordonnees, coordonnees[i]);
                if (avenirCarre[0] == 1 && coordonnees[i][2] == 1)
                {
                    vector<int> liste;
                    liste.push_back(i);
                    liste.push_back(0);
                    liste_a_modifier.push_back(liste);
                }
                else if (avenirCarre[0] == 1 && avenirCarre[1] == 1 && coordonnees[i][2] == 0)
                {
                    vector<int> liste;
                    liste.push_back(i);
                    liste.push_back(0);
                    liste_a_modifier.push_back(liste);
                }
                else
                {
                    vector<int> liste;
                    liste.push_back(i);
                    liste.push_back(1);
                    liste_a_modifier.push_back(liste);
                }

            }
            for (size_t i(0); i < coordonnees.size(); i++)
            {
                for (size_t y(0); y < liste_a_modifier.size(); y++)
                {
                    if (liste_a_modifier[y][0] == i)
                    {
                        if (liste_a_modifier[y][1] == 0)
                        {
                            coordonnees[i][2] = 1;
                        }
                        else
                        {
                            coordonnees[i][2] = 0;
                        }
                    }
                }
            }
        }
        
        
        for (size_t i(0); i < coordonnees.size(); i++)
        {
            if (coordonnees[i][2] == 1)
            {
                sf::RectangleShape rectangle(sf::Vector2f(20.f, 20.f));
                rectangle.setPosition(static_cast<float>(coordonnees[i][0]), static_cast<float>(coordonnees[i][1]));
                rectangle.setFillColor(sf::Color::Black);
                screen.draw(rectangle);
            }
            coordonnees[i][3] += 1;
        }

        
        for (size_t i(0); i < 800; i += 20)
        {
            sf::Vertex line[] = {
                    
                sf::Vertex(sf::Vector2f(0, i), sf::Color::Black),  
                sf::Vertex(sf::Vector2f(1100, i), sf::Color::Black)  
            };
            screen.draw(line, 2, sf::Lines);
        }
        for (size_t i(0); i < 1100; i += 20)
        {
            sf::Vertex line[] = {
                    
                sf::Vertex(sf::Vector2f(i, 0), sf::Color::Black),  
                sf::Vertex(sf::Vector2f(i, 800), sf::Color::Black)  
            };
            screen.draw(line, 2, sf::Lines);
        }

        if (deltaTime.asSeconds() < 1.f /60.f)
        {
            sf::sleep(sf::seconds(1.f / 60.f - deltaTime.asSeconds()));
        }
        confirmation_temporaire = false;
        attente += 1;
        attente2 += 1;

        liste_a_modifier.clear();

        screen.draw(sprite1);
        screen.draw(sprite2);
        screen.draw(sprite3);
        screen.draw(sprite4);

        screen.display();
    }

    return 0;
}