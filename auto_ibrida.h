#ifndef AUTO_IBRIDA_H
#define AUTO_IBRIDA_H
#include "motore_combustione.h"
#include "motore_elettrico.h"
class auto_ibrida: public motore_combustione, public motore_elettrico{
public:
    auto_ibrida();
};

#endif // AUTO_IBRIDA_H
