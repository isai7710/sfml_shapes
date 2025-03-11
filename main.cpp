#include "MyRoundedOutlinedRectangle.h"
#include <SFML/Graphics.hpp>

int main() {
  const unsigned int WINDOW_WIDTH = 500;
  const unsigned int WINDOW_HEIGHT = 500;

  const float RADIUS = 20.f;
  const float THICKNESS = 5.f;
  const uint32_t QUALITY = 128;

  const sf::Vector2f size{300.f, 100.f};
  const sf::Vector2f position{WINDOW_WIDTH / 2.f - size.x / 2.f,
                              WINDOW_HEIGHT / 2.f - size.y / 2.f};

  sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT),
                          "Visualizing Shape Generation");
  window.setFramerateLimit(60);

  MyRoundedOutlinedRectangle outline(position, size, RADIUS, THICKNESS,
                                     QUALITY);
  sf::Clock clock;
  float timePassed = 0.0f;
  float interval = 0.05f;

  // ----- GAME LOOP -----
  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window.close();
    }

    timePassed += clock.restart().asSeconds(); // Get frame time
    if (timePassed >= interval) {
      outline.incrementVisiblePoints(2);
      timePassed = 0.0f;
    }

    window.clear(sf::Color::White);
    window.draw(outline);
    window.display();
  }

  return 0;
}
