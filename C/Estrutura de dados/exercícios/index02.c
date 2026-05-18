#include <stdio.h>
typedef struct{
    int largura;
    int altura;
}Retangulo;

Retangulo criaRetangulo(int l, int a){
    Retangulo r1;
    r1.largura = l;
    r1.altura = a;
    
    return r1;
}

int areaRetangulo(Retangulo r){
    int area = r.largura * r.altura;
    
    return area;
}
int main() {
    Retangulo novoRetangulo = criaRetangulo(5,3);
    int area = areaRetangulo(novoRetangulo);
    
    printf("largura: %d\n", novoRetangulo.largura);
    printf("altura: %d\n", novoRetangulo.altura);
    printf("area: %d", area);
    return 0;
}