#include "MyCircle.h"
#include <algorithm>

MyCircle::MyCircle(const sf::Vector2f &p, float radius, uint32_t quality)
    : vertices(sf::TriangleFan, quality), visiblePoints{3}, quality{quality} {
  CircleGenerator generator(radius, quality);

  for (uint32_t i = 0; i < quality; i++) {
    vertices[i].position = p + generator.getPoint(i);
    vertices[i].color = color;
  }
};

void MyCircle::draw(sf::RenderTarget &target, sf::RenderStates states) const {
  sf::VertexArray temp(sf::TriangleFan, visiblePoints);
  for (int i = 0; i < visiblePoints; i++) {
    temp[i] = vertices[i];
  }
  target.draw(temp, states);
};

void MyCircle::incrementVisiblePoints(uint32_t increment) {
  visiblePoints = std::min(visiblePoints + increment, quality);
}
