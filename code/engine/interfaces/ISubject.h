#pragma once

class IObserver;

class ISubject
{
public:
	virtual ~ISubject() {};

	virtual void addObserver(IObserver* observerP) = 0;
	virtual void removeObserver() = 0;
};