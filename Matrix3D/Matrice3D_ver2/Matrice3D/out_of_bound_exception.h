#ifndef OUT_OF_BOUND_EXCEPTION_H
#define OUT_OF_BOUND_EXCEPTION_H

#include <stdexcept>
#include <string>

class out_of_bound_exception : public std::logic_error {
	int _z;
	int _y;
	int _x;
public:
	
	out_of_bound_exception(const std::string &message, int z, int y, int x);

	int get_z(void) const;
	int get_y(void) const;
	int get_x(void) const;
	
};


#endif