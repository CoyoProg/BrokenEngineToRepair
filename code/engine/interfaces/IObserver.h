#pragma once

class  IObserver
{
public:
	virtual ~IObserver() {};
	virtual bool onNotify() = 0;
};