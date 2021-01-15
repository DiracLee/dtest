#ifndef DTEST_COLOR_H_
#define DTEST_COLOR_H_

#define COLOR(msg, code) "\033[0;" #code "m" msg "\033[0m"

#define BLACK(msg) COLOR(msg, 30)
#define RED(msg) COLOR(msg, 31)
#define GREEN(msg) COLOR(msg, 32)
#define YELLOW(msg) COLOR(msg, 33)
#define BLUE(msg) COLOR(msg, 34)
#define PINK(msg) COLOR(msg, 35)
#define CYAN(msg) COLOR(msg, 36)

#endif  // DTEST_COLOR_H_
