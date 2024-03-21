#pragma once
#define PREMIADOS_UTILS

float calcular_media_ponderada(float nota1, int p1, float nota2, int p2) {
    return (nota1 * p1) + (nota2 * p2) / (p1 + p2);
}