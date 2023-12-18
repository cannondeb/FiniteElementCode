#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <vector>


class Towhee2D
{
public:
    // Constructor -- Future add mesh name
    Towhee2D(int equation);
    // Destructor
    ~Towhee2D();

    /* Types*/
    typedef std::vector<int> intVec;
    typedef std::vector<std::vector<int>> int2d;
    typedef std::vector<std::vector<std::vector<int>>> int3d;
    typedef std::vector<double> dblVec;
    typedef std::vector<std::vector<double>> mat2d;
    typedef std::vector<std::vector<std::vector<double>>> mat3d;
    //typedef std::vector<std::vector<std::vector<std::vector<double>>>> mat4d;

    /* Member Variables*/
    #define PI 3.14159265358979
    // Set of Equations being solved. 1 - 2D Heat; 2 - 
    int eq;
    // Number of solution variables
    int nq;
    // Element order
    int eOrder;

    // Mesh information
    // Number of Nodes in Mesh
    int     nnodes;
    // Number of Elements/Cells in Mesh
    int     ncells;
    // Nuber of boundary groups in mesh
    int     nbGroups;
    // Boundary Faces bface[nbGroups][*][*] = group, bface[*][0][*] = face, bface[*][*][0] = nodes in face
    int3d   bface;
    // bcType[nbGroups][2]; bcType[*][0] = type, bcType[*][1] = value (ifrobin, index in robin array)
    // type = 0: Essential; type = 1: Natural; type = 2: Robin
    mat2d   bcType;
    // robin[*][0] = beta, robin[*][1] = Tinf
    mat2d robin;
    // boundary condition specifying stress components in x and y
    mat2d stress;
    // Nodes per face (line)
    int     npf;
    // Node Locations xy[0][:] = xlocs xy[1][:] = ylocs
    mat2d   xy;
    // Cell Connectivity
    int2d   icon;
    // Cell Types, 0 for tri, 1 for quad
    intVec  ctype;
    // Equation coefficients
    double  a11;
    double  a12;
    double  a21;
    double  a22;
    double  a00;
    double  f;
    double  h;

    // Solution Variables
    // Aq = rhs
    mat3d   A;
    intVec  ia;
    intVec  ja;
    intVec  iau;
    mat2d   rhs;
    mat2d   q;

    // Post Processing
    // stessess[cell][0] = Sx, [1] = Sy, [2] = Txy
    mat2d postStress;

    /* Functions*/
    void getGauss1D(int ngauss, dblVec &xgauss, dblVec &wgauss);
    void getGauss2D(int ctype, int &n, dblVec &xgauss, dblVec &ygauss, dblVec &wgauss);
    void getBasis1D(int npe, double r, dblVec& N, dblVec& Nr, dblVec& Nrr);
    void getBasis2D(int ctype, double r, double s, int &npe, dblVec& N, dblVec& Nr, dblVec& Ns);
    void readMesh();
    void getija();
    void buildMapper(int2d& mapper);
    void buildA();
    //void applyBCs();
    void gaussSeidel();
    void GLU(mat3d& D);
    double GBACKSUB(mat2d& B, mat3d& D, mat2d& dq, int n, bool iwriteres);
    void solve();
    void postProcess();
    void writeTec();

};

