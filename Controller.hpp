#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include <Message.hpp>

typedef struct ControllerType
{
    float x;
    float y;
} controller_t;

//  create message
typedef sb::Message<controller_t> Controller;

#endif