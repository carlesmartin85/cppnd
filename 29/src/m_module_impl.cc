export module mainmodule:partition;

import <iostream>;
import <vector>;

export namespace ptt{

class Shape{
public:
	virtual void render(){
		std::cout << "I am a Shape..." << std::endl;
	};
};

class Square : public Shape{
public:
	void render() override{
		std::cout << "I am a Square..." << std::endl;
	}
};

class Circle : public Shape{
public:
	void render() override{
		std::cout << "I am a Circle..." << std::endl;
	}
};

class Renderer{
public:
	void render(const std::vector<Shape *> objects){
		for (auto *object : objects){
			object->render();
		}
	}
};

}