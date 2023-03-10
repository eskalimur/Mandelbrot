// Mandelbrot.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
#include <omp.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
    int px = 1024;
    int py = 1024;
    int maxIterations = 10000;
    int num_thread = 4;

    omp_set_num_threads(num_thread);

    #pragma omp parallel
    calcPix(px, py, maxIterations);

    return 0;
}


int calcPix(int px, int py, int maxIterations) {
    int minx = 0;
    int miny = 0;
    int maxx = 0;
    int maxy = 0;
    int cx, cy = normalizeToViewRectangle(px, py, minx, miny, maxx, maxy);
    int zx = cx;
    int zy = cy;


    for (int n = 0; n < maxIterations; n++) {
        float x = (zx * zx - zy * zy) + cx;
        float y = (zy * zx + zx * zy) + cy;
        if ((x * x + y * y) > 4) {
            // diverge, produce nice color | paint pixel px, py in a color depending on n
            paint(px, py, n);
                return;
        }
        zx = x;
        zy = y;
    }
    paint pixel px, py black // in the set
}

void paint(int px, int py, int n) {
    //color
}



int normalizeToViewRectangle(int px, int py, int minx, int miny, int maxx, int maxy) {
    return 0;
}