#include "Towhee2D.h"

#include <numeric>

Towhee2D::Towhee2D(int equation) {
    eq = equation;
    switch (eq)
    {
    case 1:
        // Heat Transfer
        nq = 1;
        break;
    case 2:
        // Linear Elasticity
        nq = 2;
        break;
    default:
        break;
    }
}


void
Towhee2D::getGauss1D(int ngauss, dblVec &xgauss, dblVec &wgauss) {
    // Returns the x locations and weights of the 
    // gauss quadrature points of the given ngauss.

    // Table Lookup
    xgauss.resize(18);
    wgauss.resize(18);

    switch (ngauss) {
    case 1:
        wgauss[0] = 2; xgauss[1] = 0;
        break;
    case 2:
        wgauss[0] = 1; xgauss[0] = -0.5773502691896257;
        wgauss[1] = 1; xgauss[1] = 0.5773502691896257;
        break;
    case 3:
        wgauss[0] = 0.8888888888888888; xgauss[0] = 0.0000000000000000;
        wgauss[1] = 0.5555555555555556; xgauss[1] = -0.7745966692414834;
        wgauss[2] = 0.5555555555555556; xgauss[2] = 0.7745966692414834;
        break;
    case 4:
        wgauss[0] = 0.6521451548625461; xgauss[0] = -0.3399810435848563;
        wgauss[1] = 0.6521451548625461; xgauss[1] = 0.3399810435848563;
        wgauss[2] = 0.3478548451374538; xgauss[2] = -0.8611363115940526;
        wgauss[3] = 0.3478548451374538; xgauss[3] = 0.8611363115940526;
        break;
    case 5:
        wgauss[0] = 0.5688888888888889; xgauss[0] = 0.0000000000000000;
        wgauss[1] = 0.4786286704993665; xgauss[1] = -0.5384693101056831;
        wgauss[2] = 0.4786286704993665; xgauss[2] = 0.5384693101056831;
        wgauss[3] = 0.2369268850561891; xgauss[3] = -0.9061798459386640;
        wgauss[4] = 0.2369268850561891; xgauss[4] = 0.9061798459386640;
        break;
    case 6:
        wgauss[0] = 0.3607615730481386; xgauss[0] = 0.6612093864662645;
        wgauss[1] = 0.3607615730481386; xgauss[1] = -0.6612093864662645;
        wgauss[2] = 0.4679139345726910; xgauss[2] = -0.2386191860831969;
        wgauss[3] = 0.4679139345726910; xgauss[3] = 0.2386191860831969;
        wgauss[4] = 0.1713244923791704; xgauss[4] = -0.9324695142031521;
        wgauss[5] = 0.1713244923791704; xgauss[5] = 0.9324695142031521;
        break;
    case 7:
        wgauss[0] = 0.4179591836734694; xgauss[0] = 0.0000000000000000;
        wgauss[1] = 0.3818300505051189; xgauss[1] = 0.4058451513773972;
        wgauss[2] = 0.3818300505051189; xgauss[2] = -0.4058451513773972;
        wgauss[3] = 0.2797053914892766; xgauss[3] = -0.7415311855993945;
        wgauss[4] = 0.2797053914892766; xgauss[4] = 0.7415311855993945;
        wgauss[5] = 0.1294849661688697; xgauss[5] = -0.9491079123427585;
        wgauss[6] = 0.1294849661688697; xgauss[6] = 0.9491079123427585;
        break;
    case 8:
        wgauss[0] = 0.3626837833783620; xgauss[0] = -0.1834346424956498;
        wgauss[1] = 0.3626837833783620; xgauss[1] = 0.1834346424956498;
        wgauss[2] = 0.3137066458778873; xgauss[2] = -0.5255324099163290;
        wgauss[3] = 0.3137066458778873; xgauss[3] = 0.5255324099163290;
        wgauss[4] = 0.2223810344533745; xgauss[4] = -0.7966664774136267;
        wgauss[5] = 0.2223810344533745; xgauss[5] = 0.7966664774136267;
        wgauss[6] = 0.1012285362903763; xgauss[6] = -0.9602898564975363;
        wgauss[7] = 0.1012285362903763; xgauss[7] = 0.9602898564975363;
        break;
    case 9:
        wgauss[0] = 0.3302393550012598; xgauss[0] = 0.0000000000000000;
        wgauss[1] = 0.1806481606948574; xgauss[1] = -0.8360311073266358;
        wgauss[2] = 0.1806481606948574; xgauss[2] = 0.8360311073266358;
        wgauss[3] = 0.0812743883615744; xgauss[3] = -0.9681602395076261;
        wgauss[4] = 0.0812743883615744; xgauss[4] = 0.9681602395076261;
        wgauss[5] = 0.3123470770400029; xgauss[5] = -0.3242534234038089;
        wgauss[6] = 0.3123470770400029; xgauss[6] = 0.3242534234038089;
        wgauss[7] = 0.2606106964029354; xgauss[7] = -0.6133714327005904;
        wgauss[8] = 0.2606106964029354; xgauss[8] = 0.6133714327005904;
        break;
    case 10:
        wgauss[0] = 0.2955242247147529; xgauss[0] = -0.1488743389816312;
        wgauss[1] = 0.2955242247147529; xgauss[1] = 0.1488743389816312;
        wgauss[2] = 0.2692667193099963; xgauss[2] = -0.4333953941292472;
        wgauss[3] = 0.2692667193099963; xgauss[3] = 0.4333953941292472;
        wgauss[4] = 0.2190863625159820; xgauss[4] = -0.6794095682990244;
        wgauss[5] = 0.2190863625159820; xgauss[5] = 0.6794095682990244;
        wgauss[6] = 0.1494513491505806; xgauss[6] = -0.8650633666889845;
        wgauss[7] = 0.1494513491505806; xgauss[7] = 0.8650633666889845;
        wgauss[8] = 0.0666713443086881; xgauss[8] = -0.9739065285171717;
        wgauss[9] = 0.0666713443086881; xgauss[9] = 0.9739065285171717;
        break;
    case 11:
        wgauss[0] = 0.2729250867779006;  xgauss[0] = 0.0000000000000000;
        wgauss[1] = 0.2628045445102467; xgauss[1] = -0.2695431559523450;
        wgauss[2] = 0.2628045445102467; xgauss[2] = 0.2695431559523450;
        wgauss[3] = 0.2331937645919905; xgauss[3] = -0.5190961292068118;
        wgauss[4] = 0.2331937645919905; xgauss[4] = 0.5190961292068118;
        wgauss[5] = 0.1862902109277343; xgauss[5] = -0.7301520055740494;
        wgauss[6] = 0.1862902109277343; xgauss[6] = 0.7301520055740494;
        wgauss[7] = 0.1255803694649046; xgauss[7] = -0.8870625997680953;
        wgauss[8] = 0.1255803694649046; xgauss[8] = 0.8870625997680953;
        wgauss[9] = 0.0556685671161737; xgauss[9] = -0.9782286581460570;
        wgauss[10] = 0.0556685671161737; xgauss[10] = 0.9782286581460570;
        break;
    case 12:
        wgauss[0] = 0.2491470458134028; xgauss[0] = -0.1252334085114689;
        wgauss[1] = 0.2491470458134028; xgauss[1] = 0.1252334085114689;
        wgauss[2] = 0.2334925365383548; xgauss[2] = -0.3678314989981802;
        wgauss[3] = 0.2334925365383548; xgauss[3] = 0.3678314989981802;
        wgauss[4] = 0.2031674267230659; xgauss[4] = -0.5873179542866175;
        wgauss[5] = 0.2031674267230659; xgauss[5] = 0.5873179542866175;
        wgauss[6] = 0.1600783285433462; xgauss[6] = -0.7699026741943047;
        wgauss[7] = 0.1600783285433462; xgauss[7] = 0.7699026741943047;
        wgauss[8] = 0.1069393259953184; xgauss[8] = -0.9041172563704749;
        wgauss[9] = 0.1069393259953184; xgauss[9] = 0.9041172563704749;
        wgauss[10] = 0.0471753363865118; xgauss[10] = -0.9815606342467192;
        wgauss[11] = 0.0471753363865118; xgauss[11] = 0.9815606342467192;
        break;
    case 13:
        wgauss[0] = 0.2325515532308739; xgauss[0] = 0.0000000000000000;
        wgauss[1] = 0.2262831802628972; xgauss[1] = -0.2304583159551348;
        wgauss[2] = 0.2262831802628972; xgauss[2] = 0.2304583159551348;
        wgauss[3] = 0.2078160475368885; xgauss[3] = -0.4484927510364469;
        wgauss[4] = 0.2078160475368885; xgauss[4] = 0.4484927510364469;
        wgauss[5] = 0.1781459807619457; xgauss[5] = -0.6423493394403402;
        wgauss[6] = 0.1781459807619457; xgauss[6] = 0.6423493394403402;
        wgauss[7] = 0.1388735102197872; xgauss[7] = -0.8015780907333099;
        wgauss[8] = 0.1388735102197872; xgauss[8] = 0.8015780907333099;
        wgauss[9] = 0.0921214998377285; xgauss[9] = -0.9175983992229779;
        wgauss[10] = 0.0921214998377285; xgauss[10] = 0.9175983992229779;
        wgauss[11] = 0.0404840047653159; xgauss[11] = -0.9841830547185881;
        wgauss[12] = 0.0404840047653159; xgauss[12] = 0.9841830547185881;
        break;
    case 14:
        wgauss[0] = 0.2152638534631578; xgauss[0] = -0.1080549487073437;
        wgauss[1] = 0.2152638534631578; xgauss[1] = 0.1080549487073437;
        wgauss[2] = 0.2051984637212956; xgauss[2] = -0.3191123689278897;
        wgauss[3] = 0.2051984637212956; xgauss[3] = 0.3191123689278897;
        wgauss[4] = 0.1855383974779378; xgauss[4] = -0.5152486363581541;
        wgauss[5] = 0.1855383974779378; xgauss[5] = 0.5152486363581541;
        wgauss[6] = 0.1572031671581935; xgauss[6] = -0.6872929048116855;
        wgauss[7] = 0.1572031671581935; xgauss[7] = 0.6872929048116855;
        wgauss[8] = 0.1215185706879032; xgauss[8] = -0.8272013150697650;
        wgauss[9] = 0.1215185706879032; xgauss[9] = 0.8272013150697650;
        wgauss[10] = 0.0801580871597602; xgauss[10] = -0.9284348836635735;
        wgauss[11] = 0.0801580871597602; xgauss[11] = 0.9284348836635735;
        wgauss[12] = 0.0351194603317519; xgauss[12] = -0.9862838086968123;
        wgauss[13] = 0.0351194603317519; xgauss[13] = 0.9862838086968123;
        break;
    case 15:
        wgauss[0] = 0.2025782419255613; xgauss[0] = 0.0000000000000000;
        wgauss[1] = 0.1984314853271116; xgauss[1] = -0.2011940939974345;
        wgauss[2] = 0.1984314853271116; xgauss[2] = 0.2011940939974345;
        wgauss[3] = 0.1861610000155622; xgauss[3] = -0.3941513470775634;
        wgauss[4] = 0.1861610000155622; xgauss[4] = 0.3941513470775634;
        wgauss[5] = 0.1662692058169939; xgauss[5] = -0.5709721726085388;
        wgauss[6] = 0.1662692058169939; xgauss[6] = 0.5709721726085388;
        wgauss[7] = 0.1395706779261543; xgauss[7] = -0.7244177313601701;
        wgauss[8] = 0.1395706779261543; xgauss[8] = 0.7244177313601701;
        wgauss[9] = 0.1071592204671719; xgauss[9] = -0.8482065834104272;
        wgauss[10] = 0.1071592204671719; xgauss[10] = 0.8482065834104272;
        wgauss[11] = 0.0703660474881081; xgauss[11] = -0.9372733924007060;
        wgauss[12] = 0.0703660474881081; xgauss[12] = 0.9372733924007060;
        wgauss[13] = 0.0307532419961173; xgauss[13] = -0.9879925180204854;
        wgauss[14] = 0.0307532419961173; xgauss[14] = 0.9879925180204854;
        break;
    case 16:
        wgauss[0] = 0.1894506104550685; xgauss[0] = -0.0950125098376374;
        wgauss[1] = 0.1894506104550685; xgauss[1] = 0.0950125098376374;
        wgauss[2] = 0.1826034150449236; xgauss[2] = -0.2816035507792589;
        wgauss[3] = 0.1826034150449236; xgauss[3] = 0.2816035507792589;
        wgauss[4] = 0.1691565193950025; xgauss[4] = -0.4580167776572274;
        wgauss[5] = 0.1691565193950025; xgauss[5] = 0.4580167776572274;
        wgauss[6] = 0.1495959888165767; xgauss[6] = -0.6178762444026438;
        wgauss[7] = 0.1495959888165767; xgauss[7] = 0.6178762444026438;
        wgauss[8] = 0.1246289712555339; xgauss[8] = -0.7554044083550030;
        wgauss[9] = 0.1246289712555339; xgauss[9] = 0.7554044083550030;
        wgauss[10] = 0.0951585116824928; xgauss[10] = -0.8656312023878318;
        wgauss[11] = 0.0951585116824928; xgauss[11] = 0.8656312023878318;
        wgauss[12] = 0.0622535239386479; xgauss[12] = -0.9445750230732326;
        wgauss[13] = 0.0622535239386479; xgauss[13] = 0.9445750230732326;
        wgauss[14] = 0.0271524594117541; xgauss[14] = -0.9894009349916499;
        wgauss[15] = 0.0271524594117541; xgauss[15] = 0.9894009349916499;
        break;
    case 17:
        wgauss[0] = 0.1794464703562065; xgauss[0] = 0.0000000000000000;
        wgauss[1] = 0.1765627053669926; xgauss[1] = -0.1784841814958479;
        wgauss[2] = 0.1765627053669926; xgauss[2] = 0.1784841814958479;
        wgauss[3] = 0.1680041021564500; xgauss[3] = -0.3512317634538763;
        wgauss[4] = 0.1680041021564500; xgauss[4] = 0.3512317634538763;
        wgauss[5] = 0.1540457610768103; xgauss[5] = -0.5126905370864769;
        wgauss[6] = 0.1540457610768103; xgauss[6] = 0.5126905370864769;
        wgauss[7] = 0.1351363684685255; xgauss[7] = -0.6576711592166907;
        wgauss[8] = 0.1351363684685255; xgauss[8] = 0.6576711592166907;
        wgauss[9] = 0.1118838471934040; xgauss[9] = -0.7815140038968014;
        wgauss[10] = 0.1118838471934040; xgauss[10] = 0.7815140038968014;
        wgauss[11] = 0.0850361483171792; xgauss[11] = -0.8802391537269859;
        wgauss[12] = 0.0850361483171792; xgauss[12] = 0.8802391537269859;
        wgauss[13] = 0.0554595293739872; xgauss[13] = -0.9506755217687678;
        wgauss[14] = 0.0554595293739872; xgauss[14] = 0.9506755217687678;
        wgauss[15] = 0.0241483028685479; xgauss[15] = -0.9905754753144174;
        wgauss[16] = 0.0241483028685479; xgauss[16] = 0.9905754753144174;
        break;
    case 18:
        wgauss[0] = 0.1691423829631436; xgauss[0] = -0.0847750130417353;
        wgauss[1] = 0.1691423829631436; xgauss[1] = 0.0847750130417353;
        wgauss[2] = 0.1642764837458327; xgauss[2] = -0.2518862256915055;
        wgauss[3] = 0.1642764837458327; xgauss[3] = 0.2518862256915055;
        wgauss[4] = 0.1546846751262652; xgauss[4] = -0.4117511614628426;
        wgauss[5] = 0.1546846751262652; xgauss[5] = 0.4117511614628426;
        wgauss[6] = 0.1406429146706507; xgauss[6] = -0.5597708310739475;
        wgauss[7] = 0.1406429146706507; xgauss[7] = 0.5597708310739475;
        wgauss[8] = 0.1225552067114785; xgauss[8] = -0.6916870430603532;
        wgauss[9] = 0.1225552067114785; xgauss[9] = 0.6916870430603532;
        wgauss[10] = 0.1009420441062872; xgauss[10] = -0.8037049589725231;
        wgauss[11] = 0.1009420441062872; xgauss[11] = 0.8037049589725231;
        wgauss[12] = 0.0764257302548891; xgauss[12] = -0.8926024664975557;
        wgauss[13] = 0.0764257302548891; xgauss[13] = 0.8926024664975557;
        wgauss[14] = 0.0497145488949698; xgauss[14] = -0.9558239495713977;
        wgauss[15] = 0.0497145488949698; xgauss[15] = 0.9558239495713977;
        wgauss[16] = 0.0216160135264833; xgauss[16] = -0.9915651684209309;
        wgauss[17] = 0.0216160135264833; xgauss[17] = 0.9915651684209309;
        break;
    }
}


void 
Towhee2D::getGauss2D(int ctype, int& n, dblVec& xgauss, dblVec& ygauss, dblVec& wgauss) {
    int p = 6;//2 * eOrder;

    switch (ctype) {
    case 0: // Triangle 
        if (p < 2) {
            n = 1;
            xgauss.resize(n);
            ygauss.resize(n);
            wgauss.resize(n);

            xgauss[0] = 1.0 / 3.0;
            
            ygauss[0] = 1.0 / 3.0;
            
            wgauss[0] = 1.0;
        }
        else if (p < 3) {
            n = 3;
            xgauss.resize(n);
            ygauss.resize(n);
            wgauss.resize(n);

            xgauss[0] = 1.0 / 6.0;
            xgauss[1] = 1.0 / 6.0;
            xgauss[2] = 4.0 / 6.0;

            ygauss[0] = 1.0 / 6.0;
            ygauss[1] = 4.0 / 6.0;
            ygauss[2] = 1.0 / 6.0;

            wgauss[0] = 1.0 / 3.0;
            wgauss[1] = 1.0 / 3.0;
            wgauss[2] = 1.0 / 3.0;
        }
        else if (p < 4) {
            n = 4;
            xgauss.resize(n);
            ygauss.resize(n);
            wgauss.resize(n);

            xgauss[0] = 1.0 / 3.0;
            xgauss[1] = 0.60;
            xgauss[2] = 0.20;
            xgauss[3] = 0.20;

            ygauss[0] = 1. / 3.;
            ygauss[1] = 0.20;
            ygauss[2] = 0.60;
            ygauss[3] = 0.20;

            wgauss[0] = -0.5625;
            wgauss[1] = 0.52083333333333333;
            wgauss[2] = 0.52083333333333333;
            wgauss[3] = 0.52083333333333333;
        }
        else if (p < 5) {
            n = 6;
            xgauss.resize(n);
            ygauss.resize(n);
            wgauss.resize(n);

            xgauss[0] = 0.445948490915965;
            xgauss[1] = 0.445948490915965;
            xgauss[2] = 0.108103018168070;
            xgauss[3] = 0.091576213509771;
            xgauss[4] = 0.091576213509771;
            xgauss[5] = 0.816847572980459;

            ygauss[0] = 0.445948490915965;
            ygauss[1] = 0.108103018168070;
            ygauss[2] = 0.445948490915965;
            ygauss[3] = 0.091576213509771;
            ygauss[4] = 0.816847572980459;
            ygauss[5] = 0.091576213509771;

            wgauss[0] = 0.223381589678011;
            wgauss[1] = 0.223381589678011;
            wgauss[2] = 0.223381589678011;
            wgauss[3] = 0.109951743655322;
            wgauss[4] = 0.109951743655322;
            wgauss[5] = 0.109951743655322;
        }
        else if (p < 6) {
            n = 7;
            xgauss.resize(n);
            ygauss.resize(n);
            wgauss.resize(n);
            
            xgauss[0] = 1. / 3.;
            xgauss[1] = 0.797426985353087;
            xgauss[2] = 0.101286507323456;
            xgauss[3] = 0.101286507323456;
            xgauss[4] = 0.059715871789770;
            xgauss[5] = 0.470142064105115;
            xgauss[6] = 0.470142064105115;

            ygauss[0] = 1. / 3.;
            ygauss[1] = 0.101286507323456;
            ygauss[2] = 0.797426985353087;
            ygauss[3] = 0.101286507323456;
            ygauss[4] = 0.470142064105115;
            ygauss[5] = 0.059715871789770;
            ygauss[6] = 0.470142064105115;

            wgauss[0] = 0.225;
            wgauss[1] = 0.125939180544827;
            wgauss[2] = 0.125939180544827;
            wgauss[3] = 0.125939180544827;
            wgauss[4] = 0.132394152788506;
            wgauss[5] = 0.132394152788506;
            wgauss[6] = 0.132394152788506;
        }
        else if (p < 7) {
            n = 12;
            xgauss.resize(n);
            ygauss.resize(n);
            wgauss.resize(n);

            xgauss[0] = 0.2492867451709100;
            xgauss[1] = 0.2492867451709100;
            xgauss[2] = 0.5014265096581790;
            xgauss[3] = 0.0630890144915020;
            xgauss[4] = 0.0630890144915020;
            xgauss[5] = 0.8738219710169960;
            xgauss[6] = 0.3103524510337840;
            xgauss[7] = 0.6365024991213990;
            xgauss[8] = 0.0531450498448170;
            xgauss[9] = 0.3103524510337840;
            xgauss[10] = 0.6365024991213990;
            xgauss[11] = 0.0531450498448170;

            ygauss[0] = 0.2492867451709100;
            ygauss[1] = 0.5014265096581790;
            ygauss[2] = 0.2492867451709100;
            ygauss[3] = 0.0630890144915020;
            ygauss[4] = 0.8738219710169960;
            ygauss[5] = 0.0630890144915020;
            ygauss[6] = 0.6365024991213990;
            ygauss[7] = 0.0531450498448170;
            ygauss[8] = 0.3103524510337840;
            ygauss[9] = 0.0531450498448170;
            ygauss[10] = 0.3103524510337840;
            ygauss[11] = 0.6365024991213990;

            wgauss[0] = 0.1167862757263788;
            wgauss[1] = 0.1167862757263788;
            wgauss[2] = 0.1167862757263788;
            wgauss[3] = 0.0508449063702069;
            wgauss[4] = 0.0508449063702069;
            wgauss[5] = 0.0508449063702069;
            wgauss[6] = 0.0828510756183738;
            wgauss[7] = 0.0828510756183738;
            wgauss[8] = 0.0828510756183738;
            wgauss[9] = 0.0828510756183738;
            wgauss[10] = 0.0828510756183738;
            wgauss[11] = 0.0828510756183738;
        }
        else {
            printf("Invalid number of Gauss points\n");
            exit(1);
        }
        break;
    case 1: // Quad
        if (p < 2) {
            n = 1;
            xgauss.resize(n);
            ygauss.resize(n);
            wgauss.resize(n);

            xgauss[0] = 0.5;

            ygauss[0] = 0.5;

            wgauss[0] = 1.0;
        }
        else if (p < 4) {
            n = 4;
            xgauss.resize(n);
            ygauss.resize(n);
            wgauss.resize(n);

            xgauss[0] = 0.788675134594813;
            xgauss[1] = 0.788675134594813;
            xgauss[2] = 0.211324865405187;
            xgauss[3] = 0.211324865405187;

            ygauss[0] = 0.788675134594813;
            ygauss[1] = 0.211324865405187;
            ygauss[2] = 0.788675134594813;
            ygauss[3] = 0.211324865405187;

            wgauss[0] = 0.250000000000000;
            wgauss[1] = 0.250000000000000;
            wgauss[2] = 0.250000000000000;
            wgauss[3] = 0.250000000000000;
        }
        else if (p < 6) {
            n = 8;
            xgauss.resize(n);
            ygauss.resize(n);
            wgauss.resize(n);

            xgauss[0] = 0.841565025531986;
            xgauss[1] = 0.158434974468014;
            xgauss[2] = 0.500000000000000;
            xgauss[3] = 0.500000000000000;
            xgauss[4] = 0.940958551844098;
            xgauss[5] = 0.940958551844098;
            xgauss[6] = 0.059041448155902;
            xgauss[7] = 0.059041448155902;

            ygauss[0] = 0.500000000000000;
            ygauss[1] = 0.500000000000000;
            ygauss[2] = 0.841565025531986;
            ygauss[3] = 0.158434974468014;
            ygauss[4] = 0.940958551844098;
            ygauss[5] = 0.059041448155902;
            ygauss[6] = 0.940958551844098;
            ygauss[7] = 0.059041448155902;

            wgauss[0] = 0.204081632653061;
            wgauss[1] = 0.204081632653061;
            wgauss[2] = 0.204081632653061;
            wgauss[3] = 0.204081632653061;
            wgauss[4] = 0.045918367346939;
            wgauss[5] = 0.045918367346939;
            wgauss[6] = 0.045918367346939;
            wgauss[7] = 0.045918367346939;
        }
        else if (p < 8) {
            n = 12;
            xgauss.resize(n);
            ygauss.resize(n);
            wgauss.resize(n);

            xgauss[0] = 0.962910049886275;
            xgauss[1] = 0.037089950113725;
            xgauss[2] = 0.500000000000000;
            xgauss[3] = 0.500000000000000;
            xgauss[4] = 0.902989891459300;
            xgauss[5] = 0.902989891459300;
            xgauss[6] = 0.097010108540701;
            xgauss[7] = 0.097010108540701;
            xgauss[8] = 0.690277216604158;
            xgauss[9] = 0.690277216604158;
            xgauss[10] = 0.309722783395842;
            xgauss[11] = 0.309722783395842;

            ygauss[0] = 0.500000000000000;
            ygauss[1] = 0.500000000000000;
            ygauss[2] = 0.962910049886275;
            ygauss[3] = 0.037089950113725;
            ygauss[4] = 0.902989891459300;
            ygauss[5] = 0.097010108540701;
            ygauss[6] = 0.902989891459300;
            ygauss[7] = 0.097010108540701;
            ygauss[8] = 0.690277216604158;
            ygauss[9] = 0.309722783395842;
            ygauss[10] = 0.690277216604158;
            ygauss[11] = 0.309722783395842;

            wgauss[0] = 0.060493827160494;
            wgauss[1] = 0.060493827160494;
            wgauss[2] = 0.060493827160494;
            wgauss[3] = 0.060493827160494;
            wgauss[4] = 0.059357943672658;
            wgauss[5] = 0.059357943672658;
            wgauss[6] = 0.059357943672658;
            wgauss[7] = 0.059357943672658;
            wgauss[8] = 0.130148229166849;
            wgauss[9] = 0.130148229166849;
            wgauss[10] = 0.130148229166849;
            wgauss[11] = 0.130148229166849;
        }
        else {
            printf("Invalid number of Gauss points\n");
            exit(1);
        }
        break;
    }

}


void 
Towhee2D::readMesh() {
    /*
        The reader will now be updated to read in GMSH 4 Files.
        This is the 2D-only version.
    */
#define READMESH
#ifdef READMESH
    // Hardcode file name for now.
    std::fstream file("quads_firstOrder_refined.msh");
    std::string line;
    while (std::getline(file, line)) {
        /*if (line == "$Comments") {
            while (line != "$EndComments") {
                // Ignore until comments end
                std::getline(file, line);
            }
        }
        else if (line == "$MeshFormat") {
            // Ignore
            std::getline(file, line);
            std::getline(file, line);
        }*/
        if (line == "$PhysicalNames") {
            // Right now all we need from PhysicalNames is the number of boundary groups
            std::getline(file, line);
            int nbGroups = 0;
            sscanf_s(line.c_str(), "%d", &nbGroups);
            bface.resize(nbGroups - 1);
            for (int i = 0; i < nbGroups; ++i) {
                std::getline(file, line);
            }
            // Eat "$EndPhysicalNames
            std::getline(file, line);
        }
        else if (line == "$Nodes") {
            std::getline(file, line);
            int nblocks;
            int nLocalNodes;
            int idx;
            double x, y;
            // Since nodes can be in any order and are all listed before points
            // we need to keep a map of each node coordinate to its index.
            intVec tmpMap;
            sscanf_s(line.c_str(), "%d %d %*d %*d", &nblocks, &nnodes);
            xy.resize(2);
            xy[0].resize(nnodes);
            xy[1].resize(nnodes);
            for (int i = 0; i < nblocks; ++i) {
                // Read nodes subheader
                std::getline(file, line);
                sscanf_s(line.c_str(), "%*d %*d %*d %d", &nLocalNodes);
                tmpMap.resize(nLocalNodes);
                for (int j = 0; j < nLocalNodes; ++j) {
                    // Read node indexs
                    std::getline(file, line);
                    sscanf_s(line.c_str(), "%d", &idx);
                    //our indices start at 0...
                    tmpMap[j] = idx - 1;
                }
                for (int j = 0; j < nLocalNodes; ++j) {
                    // Read node coordinates and assign to correct spot in xy.
                    std::getline(file, line);
                    sscanf_s(line.c_str(), "%lf %lf %*f", &x, &y);
                    xy[0][tmpMap[j]] = x;
                    xy[1][tmpMap[j]] = y;
                }
            }
            std::getline(file, line);
        }
        else if (line == "$Elements") {
            int nblocks, npe;
            // Keep track of how many faces have been added
            int faceCount = 0;
            int elemCount = 0;
            intVec nodes(9);
            std::getline(file, line);
            sscanf_s(line.c_str(), "%d %*d %*d %*d", &nblocks);
            for (int i = 0; i < nblocks; ++i) {
                std::getline(file, line);
                int dim, tag, type, nLocalElem;
                sscanf_s(line.c_str(), "%d %d %d %d", &dim, &tag, &type, &nLocalElem);
                if (dim == 1) {
                    // Boundary Element
                    faceCount = 0;
                    if (type == 1) {
                        // first order line
                        eOrder = 1;
                        npf = 2;
                        npe = 2;
                        bface[tag - 1].resize(nLocalElem);
                        for (int j = 0; j < nLocalElem; ++j) {
                            std::getline(file, line);
                            sscanf_s(line.c_str(), "%*d %d %d", &nodes[0], &nodes[1]);
                            bface[tag - 1][faceCount] = { nodes[0]-1, nodes[1]-1 };
                            faceCount++;
                        }
                    }
                    else if (type == 8) {
                        // second order line
                        eOrder = 2;
                        npf = 3;
                        npe = 3;
                        bface[tag - 1].resize(nLocalElem);
                        for (int j = 0; j < nLocalElem; ++j) {
                            std::getline(file, line);
                            sscanf_s(line.c_str(), "%*d %d %d %d", &nodes[0], &nodes[1], &nodes[2]);
                            bface[tag - 1][faceCount] = { nodes[0]-1, nodes[1]-1, nodes[2]-1 };
                            faceCount++;
                        }
                    }               
                }
                else if (dim == 2) {
                    // Read 2D elements into icon
                    // icon[elemCount] = {node[0], node[1], ...}
                    // ctype[elemCount] = 0 for tri, 1 for quad
                    if (type == 2) {
                        // first order tri
                        npe = 3;
                        icon.resize(elemCount + nLocalElem);
                        ctype.resize(nLocalElem);
                        for (int j = 0; j < nLocalElem; ++j) {
                            std::getline(file, line);
                            sscanf_s(line.c_str(), "%*d %d %d %d", &nodes[0], &nodes[1], &nodes[2]);
                            icon[elemCount] = { nodes[0]-1, nodes[1]-1, nodes[2]-1 };
                            ctype[elemCount] = 0;
                            ++elemCount;
                        }
                    }
                    else if (type == 3) {
                        // first order quad
                        npe = 4;
                        icon.resize(elemCount + nLocalElem);
                        ctype.resize(nLocalElem + nLocalElem);
                        for (int j = 0; j < nLocalElem; ++j) {
                            std::getline(file, line);
                            sscanf_s(line.c_str(), "%*d %d %d %d %d", &nodes[0], &nodes[1], &nodes[2],
                                &nodes[3]);
                            icon[elemCount] = { nodes[0]-1, nodes[1]-1, nodes[2]-1, nodes[3]-1 };
                            ctype[elemCount] = 1;
                            ++elemCount;
                        }
                    }
                    else if (type == 9) {
                        // second order tri
                        npe = 6;
                        for (int j = 0; j < nLocalElem; ++j) {
                            std::getline(file, line);
                            sscanf_s(line.c_str(), "%*d %d %d %d %d %d %d",
                                &nodes[0], &nodes[1], &nodes[2], &nodes[3], &nodes[4], &nodes[5]);
                            icon[elemCount] = { nodes[0]-1, nodes[1]-1, nodes[2]-1,
                                nodes[3]-1, nodes[4]-1, nodes[5]-1 };
                            ctype[elemCount] = 0;
                            ++elemCount;
                        }
                    }
                    else if (type == 10) {
                        // second order quad
                        npe = 9;
                        for (int j = 0; j < nLocalElem; ++j) {
                            std::getline(file, line);
                            sscanf_s(line.c_str(), "%*d %d %d %d %d %d %d %d %d %d",
                                &nodes[0], &nodes[1], &nodes[2], &nodes[3], &nodes[4], &nodes[5],
                                &nodes[6], &nodes[7], &nodes[8]);
                            icon[elemCount] = { nodes[0]-1, nodes[1]-1, nodes[2]-1, nodes[3]-1, 
                                nodes[4]-1, nodes[5]-1, nodes[6]-1, nodes[7]-1, nodes[8]-1 };
                            ctype[elemCount] = 1;
                            ++elemCount;
                        }
                    }
                }
            }
        }
    }

    // Apply Boundary Conditions
    // left right top bottom circle
    ncells = icon.size();
    nbGroups = 5;
    bcType = { {0,0,0},{1, 0},{1,1},{0,1,0},{1,2} };
    stress = { {1E7,0}, {0,0}, {0,0} };
    double E = 210E9;
    double nu = 0.3;
    double G = E / (2 * (1 + nu));
    a11 = E / (1 - (nu * nu));
    a12 = (nu * E) / (1 - (nu * nu));
    a21 = a12; // (isotropy)
    a22 = a11;
    a00 = G;
    h = 0.001;
#endif

//#define TESTMESH_HEAT
#ifdef TESTMESH_HEAT
    // The mesh is hard coded for now but in the future
    // this fxn can be fleshed out to read from file.
    // 2-D Example - Hard Coded Test Case
     // Number of Nodes in Mesh
    nnodes = 9;
    // Number of Elements/Cells in Mesh
    ncells = 4;
    // Nuber of boundary faces in mesh
    nbGroups = 4;
    // Element order
    eOrder = 1;
    // Node Locations
    xy = { {0, 0.01, 0.02, 0, 0.01, 0.02, 0, 0.01, 0.02},
        {0, 0, 0, 0.01, 0.01, 0.01, 0.02, 0.02, 0.02} };
    // Cell Connectivity
    icon = { {0,1,4,3},{1,2,5,4}, {3,4,7,6},{4,5,8,7} };
    // Cell Types (all cells are same order)
    // 0 - Tri
    // 1 - Quad
    ctype = { 1,1,1,1 };//,0 };
    // Boundary Faces (edges)
    bface = { {{0,1},{1,2}},{{0,3},{3,6}},{{6,7},{7,8}},{{2,5},{5,8}} };
    // If robin bc, second value is index in robin array... for now
    bcType = { {1,0}, {1,2E5}, {2,0}, {0,100} };
    robin = { {60.0,0.0} };
    npf = 2;
    //ia = { 0,4,10,14,20,29,35,39,45,49 };
    //ja = { 0,1,3,4,0,1,2,3,4,5,1,2,4,5,0,1,3,4,6,7,0,1,2,3,4,5,
    //    6,7,8,1,2,4,5,7,8,3,4,6,7,3,4,5,6,7,8,4,5,7,8 };
    //iau = { 0,5,11,16,24,32,37,43,48 };
    a11 = 30; // W/m^2*C
    a12 = 0;
    a21 = 0;
    a22 = 30; // W/m^2*C
    f = 1E7; // W/m^3
#endif

//#define TESTMESH_STRESS
#ifdef TESTMESH_STRESS
    nnodes = 4;
    ncells = 2;
    nbGroups = 2;
    eOrder = 1;
    npf = 2;
    xy = { {0,120,120,0}, {0,0,160,160} };
    icon = { {0,1,2}, {0,2,3} };
    ctype = { 0,0 };
    bface = { {{0,3}}, {{1,2}} };
    bcType = { {0,0,0}, {1,0} };
    stress = { {10, 0} };
    double E = 30E6;
    double nu = 0.25;
    double G = E / (2 * (1 + nu));
    a11 = E / (1 - (nu * nu));
    a12 = (nu * E) / (1 - (nu * nu));
    a21 = a12; // (isotropy)
    a22 = a11;
    a00 = G;
    h = 0.036;
#endif
}


void
Towhee2D::getBasis1D(int npe, double r, dblVec& N, dblVec& Nr, dblVec& Nrr) {
    /*  npe - Nodes Per Element, order is P(N-1)
        r - Computational space -1 < r < 1
        N - Basis Functions
        Nr - dN/dr
        Nrr - d^2N/dr^2
    */

    switch (npe) {
    case 2: // Linear P1
        N[0] = 0.5 * (1 - r);
        N[1] = 0.5 * (1 + r);
        Nr[0] = -0.5;
        Nr[1] = 0.5;
        Nrr[0] = 0;
        Nrr[1] = 0;
        break;
    case 3: // Quadratic P2
        N[0] = -0.5 * r * (1 - r);
        N[1] = (1 + r) * (1 - r);
        N[2] = 0.5 * r * (1 + r);
        Nr[0] = -0.5 + r;
        Nr[1] = -2 * r;
        Nr[2] = 0.5 + r;
        break;
        // TODO: Nrr[0] Nrr[1] Nrr[2]  
        // TODO: Case 0
    }
}


void
Towhee2D::getBasis2D(int ctype, double r, double s, int &npe, dblVec & N, dblVec & Nr, dblVec & Ns) {
    /*
        ctype:
            0 - Triangle
            1 - Quad
        p: order
            P1 - Linear
            P2 - Quadrilateral, etc.
    */
    int p = eOrder;
    switch (ctype) {
    case 0: // Triangle
        switch (p) {
        case 1:
            npe = 3;
            N[0] = 1 - r - s;
            N[1] = r;
            N[2] = s;

            Nr[0] = -1;
            Nr[1] = 1;
            Nr[2] = 0;

            Ns[0] = -1;
            Ns[1] = 0;
            Ns[2] = 1;
            break;
        case 2:
            npe = 6;
            N[0] = 1 - (3 * (r + s)) + (2 * ((r * r) + (s * s))) + (4 * r * s);
            N[1] = 2 * r * (r - 0.5);
            N[2] = 2 * s * (s - 0.5);
            N[3] = 4 * r * (1 - r - s);
            N[4] = 4 * r * s;
            N[5] = 4 * s * (1 - r - s);

            Nr[0] = -3 + 4 * (r + s);
            Nr[1] = 4 * r - 1;
            Nr[2] = 0;
            Nr[3] = (-4 * r) + (4 * (1 - r - s));
            Nr[4] = 4 * s;
            Nr[5] = -4 * s;

            Ns[0] = -3 + 4 * (r + s);
            Ns[1] = 0;
            Ns[2] = 4 * s - 1;
            Ns[3] = -4 * r;
            Ns[4] = 4 * r;
            Ns[5] = (-4 * s) + (4 * (1 - r - s));
            break;
        }
        break;
    case 1: // Quad
        switch (p) {
        case 1:
            npe = 4;
            N[0] = (1 - r) * (1 - s);
            N[1] = r * (1 - s);
            N[2] = r * s;
            N[3] = s * (1 - r);

            Nr[0] = s - 1;
            Nr[1] = 1 - s;
            Nr[2] = s;
            Nr[3] = -s;

            Ns[0] = r - 1;
            Ns[1] = -r;
            Ns[2] = r;
            Ns[3] = 1 - r;
            break;
        case 2:
            npe = 9;
            N[0] = 4 * (0.5 - r) * (1 - r) * (0.5 - s) * (1 - s);
            N[1] = 4 * (r - 0.5) * r * (0.5 - s) * (1 - s);
            N[2] = 4 * (r - 0.5) * r * (s - 0.5) * s;
            N[3] = 4 * (0.5 - r) * (1 - r) * (s - 0.5) * s;
            N[4] = 8 * (1 - r) * r * (0.5 - s) * (1 - s);
            N[5] = 8 * (r - 0.5) * r * (1 - s) * s;
            N[6] = 8 * (1 - r) * r * (s - 0.5) * s;
            N[7] = 8 * (0.5 - r) * (1 - r) * (1 - s) * s;
            N[8] = 16 * (1 - r) * r * (1 - s) * s;

            Nr[0] = -4 * (1 - r) * (0.5 - s) * (1 - s) - 4 * (0.5 - r) * (0.5 - s) * (1 - s);
            Nr[1] = 4 * r * (0.5 - s) * (1 - s) + 4 * (r - 0.5) * (0.5 - s) * (1 - s);
            Nr[2] = 4 * r * (s - 0.5) * s + 4 * (r - 0.5) * (s - 0.5) * s;
            Nr[3] = -4 * (1 - r) * (s - 0.5) * s - 4 * (0.5 - r) * (s - 0.5) * s;
            Nr[4] = 8 * (1 - r) * (0.5 - s) * (1 - s) - 8 * r * (0.5 - s) * (1 - s);
            Nr[5] = 8 * r * (1 - s) * s + 8 * (r - 0.5) * (1 - s) * s;
            Nr[6] = 8 * (1 - r) * (s - 0.5) * s - 8 * r * (s - 0.5) * s;
            Nr[7] = -8 * (1 - r) * (1 - s) * s - 8 * (0.5 - r) * (1 - s) * s;
            Nr[8] = 16 * (1 - r) * (1 - s) * s - 16 * r * (1 - s) * s;

            Ns[0] = -4 * (0.5 - r) * (1 - r) * (1 - s) - 4 * (0.5 - r) * (1 - r) * (0.5 - s);
            Ns[1] = -4 * (r - 0.5) * r * (1 - s) * s - 4 * (r - 0.5) * r * (0.5 - s);
            Ns[2] = 4 * (r - 0.5) * r * s + 4 * (r - 0.5) * r * (s - 0.5);
            Ns[3] = 4 * (0.5 - r) * (1 - r) * s + 4 * (0.5 - r) * (1 - r) * (s - 0.5);
            Ns[4] = -8 * (1 - r) * r * (1 - s) - 8 * (1 - r) * r * (0.5 - s);
            Ns[5] = 8 * (r - 0.5) * r * (1 - s) - 8 * (4 - 0.5) * r * s;
            Ns[6] = 8 * (1 - r) * r * s + 8 * (1 - r) * r * (s - 0.5);
            Ns[7] = 8 * (0.5 - r) * (1 - r) * (1 - s) - 8 * (0.5 - r) * (1 - r) * s;
            Ns[8] = 16 * (1 - r) * r * (1 - s) - 16 * (1 - r) * r * s;
            break;
        }
    }
}


void
Towhee2D::getija() {
    ia.resize(nnodes + 1);
    iau.resize(nnodes);

    int2d matid(nnodes, std::vector<int>(nnodes));

    int npe = 0;
    int icj = 0;
    int ick = 0;
    int nnz = 0;

    // Figure out where non-zeros will be
    for (int i = 0; i < ncells; ++i) {
        npe = icon[i].size();
        for (int j = 0; j < npe; ++j) {
            icj = icon[i][j];
            for (int k = 0; k < npe; ++k) {
                ick = icon[i][k];
                matid[icj][ick] = 1;
            }
        }
    }
    
    // sum up non-zeros
    for (int i = 0; i < nnodes; ++i) {
        for (int j = 0; j < nnodes; ++j) {
            if (matid[i][j] == 1) {
                nnz++;
            }
        }
    }

    // Fill ia
    ia[0] = 0;
    for (int i = 0; i < nnodes; ++i) {
        ia[i + 1] = ia[i] + std::accumulate(matid[i].begin(), matid[i].end(), 0);
    }

    // Fill ja
    int izz = 0;
    ja.resize(nnz);
    for (int i = 0; i < nnodes; ++i) {
        for (int j = 0; j < nnodes; ++j) {
            if (matid[i][j] == 1) {            
                ja[izz] = j;
                izz++;
            }
        }
    }

    // fill iau
    for (int i = 0; i < nnodes; ++i) {
        for (int j = ia[i]; j < ia[i+1]; ++j) {
            if (ja[j] == i) {
                iau[i] = j;
            }
        }
    }
}


void
Towhee2D::buildMapper(int2d & mapper) {
    int2d map(nnodes, intVec(nnodes, -1));
    int icol;
    for (int i = 0; i < nnodes; ++i) {
        for (int k = ia[i]; k < ia[i + 1]; ++k) {
            icol = ja[k];
            map[i][icol] = k;
        }
    }
    mapper = map;
}


void
Towhee2D::buildA() {
    int type;
    int ngauss;
    int npe;
    double r;
    double s;
    double w;

    // current x location
    double x;
    // current y location
    double y;
    // Gauss Points
    dblVec  xgauss;
    dblVec  ygauss;
    // Gauss Weights
    dblVec  wgauss;
    // dx/dr
    double xr;
    // dx/ds;
    double xs;
    // dy/dr
    double yr;
    // dy/ds
    double ys;
    // Basis functions N(r)
    dblVec N(9);
    // dN/dr
    dblVec Nr(9);
    // d^2N/dr^2
    dblVec Nrr(9);
    // dN/ds
    dblVec Ns(9);
    // dN/dx
    dblVec Nx(9);
    // dN/dy
    dblVec Ny(9);
    // det(J)
    double jac;
    // Inverse derivatives.
    double rx, ry, sx, sy;
    double area;

    int Aidx;
    int2d map;
    buildMapper(map);

    // Re-size A
  
    size_t nnz = ja.size();
    A.resize(nq, mat2d(nq, dblVec(nnz)));
    rhs.resize(nq, dblVec(nnodes));
    q.resize(nq, dblVec(nnodes));

    
    for (int i = 0; i < ncells; ++i) {
        type = ctype[i];
        npe = icon[i].size();
        area = (0 == type) ? 0.5 : 1.0;
        getGauss2D(type, ngauss, xgauss, ygauss, wgauss);
        for (int j = 0; j < ngauss; ++j) {
            r = xgauss[j];
            s = ygauss[j];
            w = wgauss[j];
            x = 0;
            y = 0;
            xr = 0;
            xs = 0;
            yr = 0;
            ys = 0;
            getBasis2D(type, r, s, npe, N, Nr, Ns);
            for (int k = 0; k < npe; ++k) {
                x += N[k] * xy[0][icon[i][k]];
                y += N[k] * xy[1][icon[i][k]];
                xr += Nr[k] * xy[0][icon[i][k]];
                xs += Ns[k] * xy[0][icon[i][k]];
                yr += Nr[k] * xy[1][icon[i][k]];
                ys += Ns[k] * xy[1][icon[i][k]];
            }
            jac = (xr * ys) - (xs * yr);
            rx = ys / jac;
            ry = -xs / jac;
            sx = -yr / jac;
            sy = xr / jac;
            for (int k = 0; k < npe; ++k) {
                Nx[k] = (Nr[k] * rx) + (Ns[k] * sx);
                Ny[k] = (Nr[k] * ry) + (Ns[k] * sy);
            }
            // If doing the heat equation (nq = 1)
            if (eq == 1) {
                // Build Rows
                for (int n = 0; n < npe; ++n) {
                    rhs[0][icon[i][n]] += area * w * jac * f * N[n];
                    // Now Columns
                    for (int m = 0; m < npe; ++m) {
                        Aidx = map[icon[i][n]][icon[i][m]];
                        A[0][0][Aidx] += area * w * jac *
                            (a11 * Nx[n] * Nx[m] + a12 * Nx[n] * Ny[m] +
                                a21 * Ny[n] * Nx[m] + a22 * Ny[n] * Ny[m] +
                                a00 * N[n] * N[m]);
                    }
                }
            }
            // Plane Stress Equation (nq = 2)
            else if (eq == 2) {
                int irowg = 0;
                int icolg = 0;
                double f1u, g1u, f1v, g1v, f2u, g2u, f2v, g2v;
                // Rows
                for (int n = 0; n < npe; ++n) {
                    irowg = icon[i][n];
                    for (int m = 0; m < npe; ++m) {
                        icolg = icon[i][m];
                        f1u = a11 * Nx[m];
                        g1u = a00 * Ny[m];
                        f1v = a12 * Ny[m];
                        g1v = a00 * Nx[m];
                        f2u = a00 * Ny[m];
                        g2u = a21 * Nx[m];
                        f2v = a00 * Nx[m];
                        g2v = a22 * Ny[m];

                        Aidx = map[icon[i][n]][icon[i][m]];

                        A[0][0][Aidx] += h * w * area * jac * (Nx[n] * f1u + Ny[n] * g1u);
                        A[0][1][Aidx] += h * w * area * jac * (Nx[n] * f1v + Ny[n] * g1v);
                        A[1][0][Aidx] += h * w * area * jac * (Nx[n] * f2u + Ny[n] * g2u);
                        A[1][1][Aidx] += h * w * area * jac * (Nx[n] * f2v + Ny[n] * g2v);
                    }
                }
            }
        }
    }
    
    // Apply Boundary Conditions
    int ngauss1D = (2 * eOrder) + 1;
    int nbfaces = 0;
    int faceIdx = 0;
    double xnorm = 0;
    double ynorm = 0;
    double rlength = 0;
    double beta = 0;
    double Tinf = 0;
    for (int grp = 0; grp < nbGroups; ++grp) {
        nbfaces = bface[grp].size();
        for (int i = 0; i < nbfaces; ++i) {
            getGauss1D(ngauss1D, xgauss, wgauss);
            for (int j = 0; j < ngauss1D; ++j) {
                r = xgauss[j];
                w = wgauss[j];
                getBasis1D(npf, r, N, Nr, Nrr);
                x = 0;
                y = 0;
                xr = 0;
                yr = 0;
                for (int k = 0; k < npf; ++k) {
                    faceIdx = bface[grp][i][k];
                    x += xy[0][faceIdx] * N[k];
                    y += xy[1][faceIdx] * N[k];
                    xr += xy[0][faceIdx] * Nr[k];
                    yr += xy[1][faceIdx] * Nr[k];
                }
                jac = sqrt((xr * xr) + (yr * yr));
                xnorm = -yr / jac;
                ynorm = xr / jac;
                rlength = sqrt((xnorm * xnorm) + (ynorm * ynorm));
                xnorm = -xnorm / rlength;
                ynorm = -ynorm / rlength;
                
                // 2D Heat
                if (eq == 1) {
                    if (bcType[grp][0] == 1) {
                        // Natural BC
                        for (int n = 0; n < npf; ++n) {
                            rhs[0][bface[grp][i][n]] += w * jac * bcType[grp][1] * N[n];
                        }
                    }
                    else if (bcType[grp][0] == 2) {
                        // Robin BC
                        for (int n = 0; n < npf; ++n) {
                            beta = robin[bcType[grp][1]][0];
                            Tinf = robin[bcType[grp][1]][1];
                            rhs[0][bface[grp][i][n]] += w * jac * beta * Tinf * N[n];
                            for (int m = 0; m < npf; ++m) {
                                Aidx = map[bface[grp][i][n]][bface[grp][i][m]];
                                A[0][0][Aidx] += w * jac * beta * N[n] * N[m];
                            }
                        }
                    }
                }
                // Plane Stress
                else if (eq == 2) {
                    if (bcType[grp][0] == 1) {
                        // Natural Bc, specify x,y components of stress.
                        for (int n = 0; n < npf; ++n) {
                            rhs[0][bface[grp][i][n]] += h * w * jac * stress[bcType[grp][1]][0] * N[n];
                            rhs[1][bface[grp][i][n]] += h * w * jac * stress[bcType[grp][1]][1] * N[n];
                        }
                    }
                }
                
            }
        }
    }
    // Another loop to find BC = 0 to enforce essential BCs.

    int idx = 0;
    int idiag = 0;
    for (int grp = 0; grp < nbGroups; ++grp) {
        nbfaces = bface[grp].size();
        if (bcType[grp][0] == 0) {
            for (int i = 0; i < nbfaces; ++i) {
                for (int n = 0; n < npf; ++n) {
                    idx = bface[grp][i][n];
                    for (int k = ia[idx]; k < ia[idx + 1]; ++k) {
                        if (eq == 1) {
                            // 2D Heat
                            A[0][0][k] = 0;
                        }
                        else if (eq == 2) {
                            // Plane Stress
                            if (bcType[grp][1] == 0) {
                                // u = essential
                                A[0][0][k] = 0;
                                A[0][1][k] = 0;
                            }
                            else if (bcType[grp][1] == 1) {
                                // v = essential
                                A[1][0][k] = 0;
                                A[1][1][k] = 0;
                            }
                            else if (bcType[grp][1] == 2) {
                                // u = v = essential
                                // currently u must = v for easiness...
                                A[0][0][k] = 0;
                                A[0][1][k] = 0;
                                A[1][0][k] = 0;
                                A[1][1][k] = 0;
                            }
                        }
                    }
                    idiag = iau[idx];
                    if (eq == 1) {
                        // 2D Heat
                        A[0][0][idiag] = 1;
                        rhs[0][idx] = bcType[grp][1];
                    }
                    if (eq == 2) {
                        // Plane Stress
                        if (bcType[grp][1] == 0) {
                            // u = essential
                            A[0][0][idiag] = 1;
                            rhs[0][idx] = bcType[grp][2];

                        }
                        else if (bcType[grp][1] == 1) {
                            // v = essential
                            A[1][1][idiag] = 1;
                            rhs[1][idx] = bcType[grp][2];
                           
                        }
                        else if (bcType[grp][1] == 2) {
                            // u = v = essential
                            // currently u must = v for easiness...
                            A[0][0][idiag] = 1;
                            A[1][1][idiag] = 1;
                            rhs[0][idx] = bcType[grp][2];
                            rhs[1][idx] = bcType[grp][2];
                        }

                    }
                }
            }
        }
    }
    

    // Print Results for Debugging
    auto it = A[0][0].begin();
    for (it; it < A[0][0].end(); ++it) {
        double prnt = *it;
     //   printf(" % 1.4E", prnt);
     //   printf("\n");
    }
   // printf("\n");
   // printf("\n");

    auto it1 = rhs[0].begin();
    auto it2 = rhs[1].begin();
    for (it1; it1 < rhs[0].end(); ++it1) {
        double prnt = *it1;
        double prnt2 = *it2;
      //  printf(" % 1.4E\n", prnt);
       // printf(" % 1.4E\n", prnt2);
        ++it2;
    }
}


void
Towhee2D::GLU(mat3d & D) {
    /*  Compute LU decomposition of the Diagonal Blocks
        We can store L and U in D.
    */
    double sum = 0;

    for (int ii = 0; ii < nnodes; ++ii) {
        for (int j = 1; j < nq; ++j) {
            D[0][j][ii] = D[0][j][ii] / D[0][0][ii];
        }
        for (int seg = 1; seg < nq; ++seg) {
            for (int row = seg; row < nq; ++row) {
                sum = 0;
                for (int j = 0; j <= (seg - 1); ++j) {
                    sum += D[row][j][ii] * D[j][seg][ii];
                }
                D[row][seg][ii] -= sum;
            }
            for (int col = (seg + 1); col < nq; ++col) {
                sum = 0;
                for (int j = 0; j <= (seg - 1); ++j) {
                    sum += D[seg][j][ii] * D[j][col][ii];
                }
                D[seg][col][ii] -= sum / D[seg][seg][ii];
            }
        }
    }
}


double
Towhee2D::GBACKSUB(mat2d & B, mat3d & D, mat2d & dq, int n, \
    bool iwriteres) {
    /*
        Does the Gauss-Seidel Heavy Lifting.
        D is Diagonal Blocks, O is off diagonal Blocks
        D{x(n+1)} = {dq - Ox(n)}
        Since we decomposed D into L and U we can solve
        [L][U]{x} = {dq - Ox}
        [L]{z} = {b - Ox} can be solved by forward substitution
        U{x} = {z} can be solved by backward substitution
        due to the properties of L and U.
    */

    double sum = 0;
    double rms = 0;
    int istart, iend, idiag, m, icol;
    dblVec resmonitor(nq);

    // Set rhs to res
    for (int i = 0; i < nnodes; ++i) {
        for (int j = 0; j < nq; ++j) {
            B[j][i] = rhs[j][i];
        }
    }

    // Loop over nodes and add offdiagonal pieces.
    // Compute {B - Ox}
    rms = 0;
    for (int i = 0; i < nnodes; ++i) {
        istart = ia[i];
        iend = ia[i + 1] - 1;
        idiag = iau[i];
        m = i;
        // Residuals for each row
        for (int j = 0; j < nq; ++j) {
            resmonitor[j] = 0;
        }
        // Loop over columns
        for (int ii = istart; ii <= iend; ++ii) {
            icol = ja[ii];
            if (ii != idiag) {
                for (int j = 0; j < nq; ++j) {
                    for (int k = 0; k < nq; ++k) {
                        B[j][i] -= A[j][k][ii] * dq[k][icol];
                    }
                }
            }
        }
        for (int j = 0; j < nq; ++j) {
            resmonitor[j] += B[j][i];
        }

        // Finish Computing Residual
        for (int j = 0; j < nq; ++j) {
            for (int k = 0; k < nq; ++k) {
                resmonitor[j] -= A[j][k][idiag] * dq[k][i];
            }
        }
        for (int j = 0; j < nq; ++j) {
            rms += resmonitor[j] * resmonitor[j];
        }

        // Now solve for new dq at the node
        // Forward
        B[0][m] = B[0][m] / D[0][0][i];
        for (int j = 1; j < nq; ++j) {
            sum = B[j][m];
            for (int k = 0; k <= (j - 1); ++k) {
                sum -= D[j][k][i] * B[k][m];
            }
            B[j][m] = sum / D[j][j][i];
        }

        //Backward
        for (int j = (nq - 2); j >= 0; --j) {
            sum = B[j][m];
            for (int k = (nq - 1); k >= j + 1; --k) {
                B[j][m] -= D[j][k][i] * B[k][m];
            }
        }

        for (int j = 0; j < nq; ++j) {
            dq[j][i] = B[j][i];
        }
    }

    if (iwriteres) {
        rms = sqrt(rms / (nq * nnodes));
        printf("\n N: %d rms: % 1.4E \n", n, rms);
    }
    return rms;
}


void
Towhee2D::gaussSeidel() {
    /* Manages solving the linear system and monitors the residual.
    */
    int idiag;
    bool iwriteres = true;
    // Initialize dq (solution) to 0
    mat2d dq(nq, dblVec(nnodes, 0));
    // Scratch Matrix
    mat2d B(nq, dblVec(nnodes, 0));
    // Contians the Diagonal Blocks of A
    mat3d D(nq, mat2d(nq, dblVec(nnodes)));

    for (int i = 0; i < nnodes; ++i) {
        idiag = iau[i];
        for (int j = 0; j < nq; ++j) {
            for (int k = 0; k < nq; ++k) {
                D[j][k][i] = A[j][k][idiag];
            }
        }
    }

    // Invert Diagonal Matrices by LU factorization.
    GLU(D);

    int n = 1;
    double residual = 1;
    while (residual > 1E-10 && n <= 3000) {
        residual = GBACKSUB(B, D, dq, n, iwriteres);
        ++n;
    }
    // Write solution
    for (int i = 0; i < nnodes; ++i) {
        for (int j = 0; j < nq; ++j) {
            //printf("\n % 1.4E \n", dq[j][i]);
        }
    }
    q = dq;
}


void 
Towhee2D::postProcess() {
    // Compute normal and shear stresses Sx, Sy, Txy.

    // Allocate size
    postStress = std::vector<std::vector<double>>(ncells, std::vector<double>(3));

    int type;
    int ngauss;
    int npe;
    double r;
    double s;
    double w;

    // current x location
    double x;
    // current y location
    double y;
    // Gauss Points
    dblVec  xgauss;
    dblVec  ygauss;
    // Gauss Weights
    dblVec  wgauss;
    // dx/dr
    double xr;
    // dx/ds;
    double xs;
    // dy/dr
    double yr;
    // dy/ds
    double ys;
    // Basis functions N(r)
    dblVec N(9);
    // dN/dr
    dblVec Nr(9);
    // d^2N/dr^2
    dblVec Nrr(9);
    // dN/ds
    dblVec Ns(9);
    // dN/dx
    dblVec Nx(9);
    // dN/dy
    dblVec Ny(9);
    // det(J)
    double jac;
    // Inverse derivatives.
    double rx, ry, sx, sy;
    double ux, uy, vx, vy = 0;

    ngauss = 1; // linear derivatives
    for (int i = 0; i < ncells; ++i) {
        type = ctype[i];
        npe = icon[i].size();
        getGauss2D(type, ngauss, xgauss, ygauss, wgauss);
        for (int j = 0; j < ngauss; ++j) {
            r = xgauss[j];
            s = ygauss[j];
            w = wgauss[j];
            x = 0;
            y = 0;
            xr = 0;
            xs = 0;
            yr = 0;
            ys = 0;
            getBasis2D(type, r, s, npe, N, Nr, Ns);
            for (int k = 0; k < npe; ++k) {
                x += N[k] * xy[0][icon[i][k]];
                y += N[k] * xy[1][icon[i][k]];
                xr += Nr[k] * xy[0][icon[i][k]];
                xs += Ns[k] * xy[0][icon[i][k]];
                yr += Nr[k] * xy[1][icon[i][k]];
                ys += Ns[k] * xy[1][icon[i][k]];
            }
            jac = (xr * ys) - (xs * yr);
            rx = ys / jac;
            ry = -xs / jac;
            sx = -yr / jac;
            sy = xr / jac;
            for (int k = 0; k < npe; ++k) {
                Nx[k] = (Nr[k] * rx) + (Ns[k] * sx);
                Ny[k] = (Nr[k] * ry) + (Ns[k] * sy);
            }
            ux = 0;
            uy = 0;
            vx = 0;
            vy = 0;
            for (int k = 0; k < npe; ++k) {
                ux += Nx[k] * q[0][icon[i][k]];
                uy += Ny[k] * q[0][icon[i][k]];
                vx += Nx[k] * q[1][icon[i][k]];
                vy += Ny[k] * q[1][icon[i][k]];
            }
            // Sx
            postStress[i][0] = (a11 * ux) + (a12 * vy);
            // Sy
            postStress[i][1] = (a21 * ux) + (a22 * vy);
            // Txy
            postStress[i][2] = a00 * 2 * (uy + vx);
        }
    }
}


void
Towhee2D::writeTec() {
    std::fstream fs;
    fs.open("quads_refined.dat", std::fstream::in | std::fstream::out | std::fstream::trunc);
    fs << "TITLE = \"FEM OUTPUT\"\n";
    fs << "VARIABLES = \"X\", \"Y\", \"U\", \"V\" \"Sx\" \"Sy\" \"Txy\"\n";
    fs << "ZONE N=" << nnodes << ", E=" << ncells << ", DATAPACKING=BLOCK, ZONETYPE=FEQUADRILATERAL\n";
    fs << "VARLOCATION=([5-7]=CELLCENTERED)\n";
    
    // Now write values at nodes
    for (int i = 0; i < nnodes; ++i) {
        fs << xy[0][i] << " ";
    }
    fs << "\n";
    for (int i = 0; i < nnodes; ++i) {
        fs << xy[1][i] << " ";
    }
    fs << "\n";
    for (int i = 0; i < nnodes; ++i) {
        fs << q[0][i] << " ";
    }
    fs << "\n";
    for (int i = 0; i < nnodes; ++i) {
        fs << q[1][i] << " ";
    }
    fs << "\n";
    // Now Write Stresses at Cells.
    for (int i = 0; i < ncells; ++i) {
        fs << postStress[i][0] << " ";
    }
    fs << "\n";
    for (int i = 0; i < ncells; ++i) {
        fs << postStress[i][1] << " ";
    }
    fs << "\n";
    for (int i = 0; i < ncells; ++i) {
        fs << postStress[i][2] << " ";
    }
    fs << "\n";
   
    // Now write connectivity
    for (int i = 0; i < ncells; ++i) {
        for (int j = 0; j < icon[i].size(); ++j) {
            fs << icon[i][j] + 1 << " ";
            if ((ctype[i] == 0) && (j == icon[i].size() - 1)) {
                fs << icon[i][j] + 1 << " ";
            }
        }
        fs << "\n";
    }
    fs.close();
}


void
Towhee2D::solve() {
    // Organizes all other calls to fxns.
    readMesh();
    getija();
    buildA();
    gaussSeidel();
    postProcess();
    writeTec();
}

Towhee2D::~Towhee2D()
{
}
