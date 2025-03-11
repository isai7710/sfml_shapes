#include "MyRoundedOutlinedRectangle.h"
#include <SFML/System/Vector2.hpp>
#include <algorithm>

MyRoundedOutlinedRectangle::MyRoundedOutlinedRectangle(const sf::Vector2f &p,
                                                       const sf::Vector2f &size,
                                                       float radius,
                                                       float thickness,
                                                       uint32_t quality)
    : vertices(sf::TriangleStrip, 2 * quality + 2), visiblePoints{2},
      quality{quality} {
  RoundedRectangleGenerator const outer_generator{size, radius, quality};
  sf::Vector2f inner_offset{thickness, thickness};
  sf::Vector2f inner_size = size - 2.0f * inner_offset;
  RoundedRectangleGenerator const inner_generator{inner_size,
                                                  radius - thickness, quality};

  for (uint32_t i = 0; i < quality; i++) {
    vertices[2 * i + 0].position =
        p + inner_offset + inner_generator.getPoint(i);
    vertices[2 * i + 0].color = color;
    vertices[2 * i + 1].position = p + outer_generator.getPoint(i);
    vertices[2 * i + 1].color = color;
  }

  vertices[2 * quality + 0].position =
      p + inner_offset + inner_generator.getPoint(0);
  vertices[2 * quality + 0].color = color;
  vertices[2 * quality + 1].position = p + outer_generator.getPoint(0);
  vertices[2 * quality + 1].color = color;
};

void MyRoundedOutlinedRectangle::draw(sf::RenderTarget &target,
                                      sf::RenderStates states) const {
  sf::VertexArray temp(sf::TriangleStrip, visiblePoints);
  for (int i = 0; i < visiblePoints; i++) {
    temp[i] = vertices[i];
  }
  target.draw(temp, states);
};

void MyRoundedOutlinedRectangle::incrementVisiblePoints(uint32_t increment) {
  visiblePoints = std::min(visiblePoints + increment, 2 * quality + 2);
}
