#include "AnimatedGameObject.h"

class Bug : public AnimatedGameObject {
public:
	// Inherited via AnimatedGameObject
	void setWidth(int width);
	void setJ(int jin);
	void setHeight(int height);
	void setDirection(int direction);
	void setStartRow(int sr);
	bool load(const std::string & filename) override;
	void draw(sf::RenderWindow & window) override;
	void update(float deltaT) override;
	void setPosition(float x, float y) override;
	void move(sf::Vector2f) override;
	sf::Vector2f getPosition() const override;
	float getHeight() const override;
	float getWidth() const override;
	void setScale(float scale) override;
private:
	int w = 0;
	int n = 0;
	int i = 0;
	int h = 0;
	int dir = 0;
	int startrow = 0;
	sf::Sprite m_sprite;
	sf::Texture m_texture;
	std::string m_filename;
	bool m_valid = false;
	int startx = 0;
	int starty = 0;
	int j = 0;
};


