#ifndef H_USABLE
#define H_USABLE

//Class that defines the behavior of usable items
class Usable {
public:
	virtual void use(Character*) = 0;
};

#endif