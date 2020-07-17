#ifndef BTRACE_H
#define BTRACE_H

template<typename T>
int boundarytrace(int x1, int y1, int x2, int y2, T *xpos,
                  T *ypos);

template<typename T>
int boundarytraceall(T *xpos, T *ypos);

#endif
