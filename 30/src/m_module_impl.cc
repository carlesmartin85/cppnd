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
	void render(std::vector<ptt::Shape*>* objects){
		std::cout << "I am inside Renderer.." << std::endl;
		for (ptt::Shape* object : *objects){
			object->render();
		}
	};
};

}