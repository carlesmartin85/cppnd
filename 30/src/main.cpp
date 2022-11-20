import <iostream>;
import <vector>;

import mainmodule;

int main(){

	ptt::Shape* shape{new ptt::Shape};
	ptt::Square* square{new ptt::Square};
	ptt::Circle* circle{new ptt::Circle};

	std::vector<ptt::Shape*>* ult_renderer{new std::vector<ptt::Shape*>};

	ult_renderer->emplace_back(shape);
	ult_renderer->emplace_back(square);
	ult_renderer->emplace_back(circle);

	ptt::Renderer* renderer{new ptt::Renderer};

	renderer->render(ult_renderer);

	delete shape;
	shape = nullptr;
	delete square;
	square = nullptr;
	delete circle;
	circle = nullptr;
	delete ult_renderer;
	ult_renderer = nullptr;
	delete renderer;
	renderer = nullptr;

}