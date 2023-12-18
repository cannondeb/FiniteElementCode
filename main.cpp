#include "towhee2D.h"

int main() {
    // Governing Equation:
    // 1 -> 2D Heat Conduction
    // 2 -> 2D Linear Elasticity
    //int equation = 1;
    //Towhee2D heat2D(equation);
   // heat2D.solve();

    int equation = 2;
    Towhee2D linElast(equation);
    linElast.solve();

    return 0;
}