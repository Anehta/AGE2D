#include "age_accumulator.h"
#include "age_system.h"
AGE_Accumulator::AGE_Accumulator(double init_value, double end_value, double speed, bool is_cycled)
{
	this->init_value=init_value;
	this->end_value=end_value;
	this->value=this->init_value;
	this->speed=speed;
	this->is_cycled=is_cycled;
}

void AGE_Accumulator::step(double factor)
{
	value+=factor*speed;
	if(value>=end_value)
	{
		if(is_cycled)
		{
			value=init_value;
		}
		else
		{
			value=end_value;
		}
	}
}

double AGE_Accumulator::currentValue()
{
	return value;
}

void AGE_Accumulator::setInitValue(double init_value)
{
	this->init_value=init_value;
}

void AGE_Accumulator::setEndValue(double end_value)
{
	this->end_value=end_value;
}

void AGE_Accumulator::setSpeed(double speed)
{
	this->speed=speed;
}

void AGE_Accumulator::setIsCycled(bool new_bool)
{
	this->is_cycled=new_bool;
}

double AGE_Accumulator::getInitValue()
{
	return this->init_value;
}

double AGE_Accumulator::getEndValue()
{
	return this->end_value;
}

double AGE_Accumulator::getSpeed()
{
	return this->speed;
}

bool AGE_Accumulator::isCycled()
{
	return this->is_cycled;
}
