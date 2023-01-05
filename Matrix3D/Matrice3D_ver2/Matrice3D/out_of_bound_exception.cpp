#include "out_of_bound_exception.h"
	
out_of_bound_exception::out_of_bound_exception(const std::string &message, int z, int y, int x) 
	: std::logic_error(message), _z(z), _y(y), _x(x) { }

int out_of_bound_exception::get_x(void) const {
	return _x;
}
int out_of_bound_exception::get_y(void) const {
	return _y;
}
int out_of_bound_exception::get_z(void) const {
	return _z;
}