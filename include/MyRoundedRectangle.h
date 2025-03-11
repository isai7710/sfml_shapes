#ifndef MYROUNDEDRECTANGLE_H
#define MYROUNDEDRECTANGLE_H

#include "MyCircle.h"
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include <cmath>

struct RoundedRectangleGenerator {
  sf::Vector2f const size;
  sf::Vector2f const
      centers[4]; // center vectors of each of the 4 archs of the rectangle
  uint32_t const arc_quality;
  CircleGenerator const generator;

  // Constructor initializes radius, quality, and angle increment
  RoundedRectangleGenerator(sf::Vector2f size_, float radius, uint32_t quality)
      : size{size_},
        centers{
            {size.x - radius,
             size.y - radius},         // bottom right arch center point
            {radius, size.y - radius}, // bottom left arch center point
            {radius, radius},          // top left arch center point
            {size.x - radius, radius}  // top right arch center point
        },
        // arc_quality determines how many points each arch will have, must be
        // divided evenly by 4 so each arc has equal number of points
        arc_quality{quality / 4}, generator{radius, quality - 4} {}

  // Function to get the i-th point of the perimeter of the rounded rectangle
  sf::Vector2f getPoint(uint32_t i) const {
    uint32_t const corner_idx{i / arc_quality};
    return centers[corner_idx] + generator.getPoint(i - corner_idx);
  }
};

class MyRoundedRectangle : public sf::Drawable {
public:
  MyRoundedRectangle(const sf::Vector2f &p, const sf::Vector2f &size,
                     float radius, uint32_t quality);

  void incrementVisiblePoints(uint32_t increment);

  // Setters for customization
  /*void setPosition(const sf::Vector2f &position);*/
  /*void setFillColor(const sf::Color &color);*/

private:
  virtual void draw(sf::RenderTarget &target,
                    sf::RenderStates states) const override;
  uint32_t quality;
  uint32_t visiblePoints;
  sf::VertexArray vertices;
  sf::Color color{sf::Color::Blue};
};

#endif
