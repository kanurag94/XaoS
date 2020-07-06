﻿#include <cmath>
#include <cstring>
#include "config.h"
#include "number_t.h"
#include <cstdio>
#include <cstdlib>
#include "filter.h"
#include "julia.h"
#include "filter.h"

/*most of code was moved to docalc.c */

#ifdef STATISTICS
int iters2, guessed2, unguessed2, total2;
#endif
void init_julia(struct image *img, number_t rangep, number_t range,
                number_t xdelta, number_t ystep)
{
    int i, j, x, y;
    number_t im;
    unsigned char *addr, **addr1 = img->currlines;
    for (i = 0; i < img->height; i++) {
        im = IMIN + (i + 0.5) * ystep;
        x = (int)(sqrt((double)(rangep - im * im)) * xdelta + 0.5);
        if (!i || i == img->height - 1)
            x = 0;
        addr = addr1[i];
        y = img->width / 2 - x;
        if (y < 1)
            y = 1;
        for (j = 0; j < y; j++) {
            addr[j] = 1;
        }
        y = img->width;
        j = img->width / 2 + x;
        if (j >= img->width)
            j = img->width - 1;
        for (j = img->width / 2 + x; j < y; j++) {
            addr[j] = 1;
        }
    }
    for (i = 0; i < img->height; i++) {
        addr = addr1[i];
        memset((char *)addr, NOT_CALCULATED, img->width);
    }
}

static int requirement(struct filter *f, struct requirements *r)
{
    r->nimages = 1;
    r->flags = 0;
    r->supportedmask = SMALLITER;
    return (f->next->action->requirement(f->next, r));
}

static int initialize(struct filter *f, struct initdata *i)
{
    inhermisc(f, i);
    f->image = i->image;
    return (1);
}

static struct filter *getinstance(const struct filteraction *a)
{
    struct filter *f = createfilter(a);
    f->name = "Julia generator";
    return (f);
}

static void destroyinstance(struct filter *f) { free(f); }

static int doit(struct filter *f, int /*flags*/, int /*time*/)
{
    /*if(f->image->nimages==2) f->image->flip(f->image); */
    if (f->fractalc->currentformula->calculate_julia != NULL) {
        f->fractalc->currentformula->calculate_julia(f->image, f->fractalc->pre,
                                                     f->fractalc->pim);
        return (CHANGED);
    }
#ifdef STATISTICS
    printf("Total guessed %i, unguessed %i, iterations %i\n", guessed2,
           unguessed2, iters2);
#endif

    return 0;
}

const struct filteraction julia_filter = {
    "Julia generator",
    "julia",
    0,
    getinstance,
    destroyinstance,
    doit,
    requirement,
    initialize,
    convertupgeneric,
    convertdowngeneric,
    NULL,
};
