#ifndef MYCIRCLE_H
#define MYCIRCLE_H

#include <SFML/Graphics.hpp>
#include <cmath>

struct CircleGenerator {
  static float constexpr pi{3.1415927f}; // π as a compile-time constant
  float const radius = 0.0f;             // Circle's radius
  uint32_t const quality = 0; // Number of segments (more = smoother circle)
  float const da = 0.0f;      // Angle step (delta angle per segment)

  // Constructor initializes radius, quality, and angle increment
  CircleGenerator(float radius_, uint32_t quality_)
      : radius{radius_}, quality{quality_},
        da{(2.0f * pi) / static_cast<float>(quality)} // Compute angle step
  {}

  // Function to get the i-th point around the circle
  sf::Vector2f getPoint(uint32_t i) const {
    float const angle{da * static_cast<float>(i)}; // Compute angle
    return {radius * sf::Vector2f{std::cos(angle),
                                  std::sin(angle)}}; // Convert to (x, y)
  }
};

class MyCircle : public sf::Drawable {
public:
  MyCircle(const sf::Vector2f &p, float radius, uint32_t quality);

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
