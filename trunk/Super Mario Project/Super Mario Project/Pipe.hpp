////////////////////////////////////////////////////////////////////////
// Pipe.hpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef HPP_PIPE
#define HPP_PIPE

#include "Door.hpp"
#include "Monster.hpp"

#define MONSTER_EXIT_TIME 4000

namespace Collisions
{
	class Pipe : public Door
    {

	public:
		enum Direction
		{
			TO_TOP,
			TO_LEFT,
			TO_RIGHT,
			TO_BOTTOM
		};
    
		/* Constructors */
		Pipe(const string& textureName) : Door(textureName), _direction(TO_LEFT), _monster(nullptr), _monsterExitDuration(Clock()), _lenght(5) { }
		Pipe(const string& textureName, Coord<float> position, int indexDoorDestination, const string& levelDestination, State state, int lenght, Direction direction, Monster* monster) 
			: Door(textureName, position, indexDoorDestination, levelDestination, state), _lenght(lenght), _direction(direction), _monster(monster) { }

		/* getters and setters */
		Direction getDirection();
		Monster* getMonster();
		int getLenght();
		float getMonsterExitDuration();
		void setDirection(Direction Direction);
		void setMonster(Monster* Monster);

		/* Methods */
		void update(RenderWindow& app);
		void render(RenderWindow& app);

		/* Destructor */
        virtual ~Pipe();
		
    private:
		Direction _direction;
		Monster* _monster;
		int _lenght;
		Clock _monsterExitDuration;
    };
} // namespace

#endif // HPP_PIPE
