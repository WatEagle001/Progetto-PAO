#include "Model/outofboundsexception.h"

OutOfBoundsException::OutOfBoundsException(): std::range_error("Exception: index is out of bounds") {}
