#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define L_DISABLE_COPY(Class)      \
    Class(const Class &) = delete; \
    Class &operator=(const Class &) = delete;