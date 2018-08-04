#pragma once

class EventHandlingObject {
public:
	EventHandlingObject() {} // registers the object in `Game` as an event receiver
	virtual ~EventHandlingObject() {} // unregisters the object
	virtual void Handle(const sf::Event &event) = 0; // called whenever there's an event
private:
	
};