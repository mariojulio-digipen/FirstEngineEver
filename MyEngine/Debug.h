#ifndef Debug_H
#define Debug_H

#include "GL\glew.h"
#include <GL\GLU.h>

#define CHECKERROR {int err = glGetError(); if (err) { fprintf(stderr, "OpenGL error in GLObject.cpp at line %d: %s\n", __LINE__, gluErrorString(err)); getchar(); exit(-1);} }

#endif