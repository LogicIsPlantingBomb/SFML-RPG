#include<iostream>
#include<SFML/Graphics.hpp>
#include<vector>
#include<math.h>
#include"Player.h"
#include"Enemy.h"
#include"framerate.h"
using namespace sf;
using namespace std;
int main(){
        ContextSettings settings;
        settings.antialiasingLevel=8;
        RenderWindow window(VideoMode(1920,1080),"RPG",Style::Default,settings);	
	window.setFramerateLimit(300);
	Framerate framerate;
	framerate.Initialize();
	framerate.Load();
	Player player;
	player.Initialize();
	player.Load();
	Enemy enemy;
	enemy.Initialize();
	enemy.Load();
	Clock clock;
       	while(window.isOpen()){
		Time deltaTimeTimer=clock.restart();
		double deltaTime=deltaTimeTimer.asMicroseconds()/1000.0;
		framerate.Update(deltaTime);
                Event event;
		while(window.pollEvent(event)){
                        if(event.type==Event::Closed){
                                window.close();
                        }
                }
		Vector2f getMousePosition= Vector2f(Mouse::getPosition(window));
		enemy.Update(&player,deltaTime);
		player.Update(&enemy,deltaTime,getMousePosition);
		window.clear(Color::Green);
		framerate.Draw(&window);
                enemy.Draw(&window);	
		player.Draw(&window);
                window.display();
        }
	return 0;
}
