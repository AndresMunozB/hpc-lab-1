#include "functions.h"

void sort_in_register(__m128 *r1, __m128 *r2, __m128 *r3, __m128 *r4)
{
    //REGISTROS TEMPORALES
    __m128 p11, p12, p13, p14, p22, p23;

    //PRIMERO PASO
    p11 = _mm_min_ps(*r1, *r3);
    p12 = _mm_min_ps(*r2, *r4);
    p13 = _mm_max_ps(*r1, *r3);
    p14 = _mm_max_ps(*r2, *r4);

    //SEGUNDO PASO
    *r1 = _mm_min_ps(p11, p12); //FINAL
    p22 = _mm_max_ps(p11, p12);
    p23 = _mm_min_ps(p13, p14);
    *r4 = _mm_max_ps(p13, p14); //FINAL

    //TERCER PASO
    *r2 = _mm_min_ps(p22, p23); //FINAL
    *r3 = _mm_max_ps(p22, p23); //FINAL

    //TRASPONER LA MATRIZ
    _MM_TRANSPOSE4_PS(*r1, *r2, *r3, *r4);
}

void bmn_network(__m128 *r1, __m128 *r2)
{
    __m128 t1, t2;

    // PRIMER PASO
    *r1 = _mm_shuffle_ps(*r1, *r1, _MM_SHUFFLE(3, 1, 2, 0)); // INVERTIR AL MEDIO
    *r2 = _mm_shuffle_ps(*r2, *r2, _MM_SHUFFLE(0, 2, 1, 3)); // INVERTIR LOS EXTREMOS

    t1 = _mm_max_ps(*r1, *r2);
    t2 = _mm_min_ps(*r1, *r2);

    // SEGUNDO PASO
    *r1 = _mm_shuffle_ps(t1, t2, _MM_SHUFFLE(2, 0, 2, 0));
    *r2 = _mm_shuffle_ps(t1, t2, _MM_SHUFFLE(3, 1, 3, 1));
    *r1 = _mm_shuffle_ps(*r1, *r1, _MM_SHUFFLE(3, 1, 2, 0)); // INVERTIR AL MEDIO
    *r2 = _mm_shuffle_ps(*r2, *r2, _MM_SHUFFLE(3, 1, 2, 0)); // INVERTIR AL MEDIO

    t1 = _mm_max_ps(*r1, *r2);
    t2 = _mm_min_ps(*r1, *r2);

    // TERCER PASO
    *r1 = _mm_shuffle_ps(t1, t2, _MM_SHUFFLE(1, 0, 1, 0));
    *r2 = _mm_shuffle_ps(t1, t2, _MM_SHUFFLE(3, 2, 3, 2));
    *r1 = _mm_shuffle_ps(*r1, *r1, _MM_SHUFFLE(3, 1, 2, 0)); // INVERTIR AL MEDIO
    *r2 = _mm_shuffle_ps(*r2, *r2, _MM_SHUFFLE(3, 1, 2, 0)); // INVERTIR AL MEDIO

    t1 = _mm_max_ps(*r1, *r2);
    t2 = _mm_min_ps(*r1, *r2);

    // FINAL
    *r1 = _mm_shuffle_ps(t1, t2, _MM_SHUFFLE(1, 0, 1, 0));
    *r2 = _mm_shuffle_ps(t1, t2, _MM_SHUFFLE(3, 2, 3, 2));
    *r1 = _mm_shuffle_ps(*r1, *r1, _MM_SHUFFLE(3, 1, 2, 0)); // INVERTIR AL MEDIO
    *r2 = _mm_shuffle_ps(*r2, *r2, _MM_SHUFFLE(3, 1, 2, 0)); // INVERTIR AL MEDIO
}

