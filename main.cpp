#define _CRT_SECURE_NO_WARNINGS
# include <iostream> // cout, endl
# include <string>   // string
# include <cstdio>  
# include <vector>   // vector
# include <cstdlib>  // atoi, system
# include <iomanip>  // setw
# include <math.h>

using namespace std; // standard naming space

int PC_1[56] = {
  57, 49, 41, 33, 25, 17, 9,
   1, 58, 50, 42, 34, 26, 18,
  10,  2, 59, 51, 43, 35, 27,
  19, 11,  3, 60, 52, 44, 36,
  63, 55, 47, 39, 31, 23, 15,
   7, 62, 54, 46, 38, 30, 22,
  14,  6, 61, 53, 45, 37, 29,
  21, 13,  5, 28, 20, 12,  4 } ;

int Iteration[16] = {
  1, 1, 2, 2, 2, 2,
  2, 2, 1, 2, 2, 2,
  2, 2, 2, 1 } ;

int PC_2[48] = {
  14, 17, 11, 24,  1,  5,
   3, 28, 15,  6, 21, 10,
  23, 19, 12,  4, 26,  8,
  16,  7, 27, 20, 13,  2,
  41, 52, 31, 37, 47, 55,
  30, 40, 51, 45, 33, 48,
  44, 49, 39, 56, 34, 53,
  46, 42, 50, 36, 29, 32 } ;

int IP_table[64] = {
  58, 50, 42, 34, 26, 18, 10,  2,
  60, 52, 44, 36, 28, 20, 12,  4,
  62, 54, 46, 38, 30, 22, 14,  6,
  64, 56, 48, 40, 32, 24, 16,  8,
  57, 49, 41, 33, 25, 17,  9,  1,
  59, 51, 43, 35, 27, 19, 11,  3,
  61, 53, 45, 37, 29, 21, 13,  5,
  63, 55, 47, 39, 31, 23, 15,  7 } ;

int E_BIT_SELECTION_TABLE[48] = {
  32,  1,  2,  3,  4,  5,
   4,  5,  6,  7,  8,  9,
   8,  9, 10, 11, 12, 13,
  12, 13, 14, 15, 16, 17,
  16, 17, 18, 19, 20, 21,
  20, 21, 22, 23, 24, 25,
  24, 25, 26, 27, 28, 29,
  28, 29, 30, 31, 32,  1 } ;

int P_table[32] = {
  16,  7, 20, 21,
  29, 12, 28, 17,
   1, 15, 23, 26,
   5, 18, 31, 10,
   2,  8, 24, 14,
  32, 27,  3,  9,
  19, 13, 30,  6,
  22, 11,  4, 25 } ;

int IP_inverse_table[64] = {
  40,  8, 48, 16, 56, 24, 64, 32,
  39,  7, 47, 15, 55, 23, 63, 31,
  38,  6, 46, 14, 54, 22, 62, 30,
  37,  5, 45, 13, 53, 21, 61, 29,
  36,  4, 44, 12, 52, 20, 60, 28,
  35,  3, 43, 11, 51, 19, 59, 27,
  34,  2, 42, 10, 50, 18, 58, 26,
  33,  1, 41,  9, 49, 17, 57, 25,
} ;

void Set_S_table( int **S_table[8] ) {
  // table1, row, column
  S_table[0][0][0]  = 14, S_table[0][1][0]  =  0, S_table[0][2][0]  =  4, S_table[0][3][0]  = 15;
  S_table[0][0][1]  =  4, S_table[0][1][1]  = 15, S_table[0][2][1]  =  1, S_table[0][3][1]  = 12;
  S_table[0][0][2]  = 13, S_table[0][1][2]  =  7, S_table[0][2][2]  = 14, S_table[0][3][2]  =  8;
  S_table[0][0][3]  =  1, S_table[0][1][3]  =  4, S_table[0][2][3]  =  8, S_table[0][3][3]  =  2;
  S_table[0][0][4]  =  2, S_table[0][1][4]  = 14, S_table[0][2][4]  = 13, S_table[0][3][4]  =  4;
  S_table[0][0][5]  = 15, S_table[0][1][5]  =  2, S_table[0][2][5]  =  6, S_table[0][3][5]  =  9;
  S_table[0][0][6]  = 11, S_table[0][1][6]  = 13, S_table[0][2][6]  =  2, S_table[0][3][6]  =  1;
  S_table[0][0][7]  =  8, S_table[0][1][7]  =  1, S_table[0][2][7]  = 11, S_table[0][3][7]  =  7;
  S_table[0][0][8]  =  3, S_table[0][1][8]  = 10, S_table[0][2][8]  = 15, S_table[0][3][8]  =  5;
  S_table[0][0][9]  = 10, S_table[0][1][9]  =  6, S_table[0][2][9]  = 12, S_table[0][3][9]  = 11;
  S_table[0][0][10] =  6, S_table[0][1][10] = 12, S_table[0][2][10] =  9, S_table[0][3][10] =  3;
  S_table[0][0][11] = 12, S_table[0][1][11] = 11, S_table[0][2][11] =  7, S_table[0][3][11] = 14;
  S_table[0][0][12] =  5, S_table[0][1][12] =  9, S_table[0][2][12] =  3, S_table[0][3][12] = 10;
  S_table[0][0][13] =  9, S_table[0][1][13] =  5, S_table[0][2][13] = 10, S_table[0][3][13] =  0;
  S_table[0][0][14] =  0, S_table[0][1][14] =  3, S_table[0][2][14] =  5, S_table[0][3][14] =  6;
  S_table[0][0][15] =  7, S_table[0][1][15] =  8, S_table[0][2][15] =  0, S_table[0][3][15] = 13;

  // table2, row, column
  S_table[1][0][0]  = 15, S_table[1][1][0]  =  3, S_table[1][2][0]  =  0, S_table[1][3][0]  = 13;
  S_table[1][0][1]  =  1, S_table[1][1][1]  = 13, S_table[1][2][1]  = 14, S_table[1][3][1]  =  8;
  S_table[1][0][2]  =  8, S_table[1][1][2]  =  4, S_table[1][2][2]  =  7, S_table[1][3][2]  = 10;
  S_table[1][0][3]  = 14, S_table[1][1][3]  =  7, S_table[1][2][3]  = 11, S_table[1][3][3]  =  1;
  S_table[1][0][4]  =  6, S_table[1][1][4]  = 15, S_table[1][2][4]  = 10, S_table[1][3][4]  =  3;
  S_table[1][0][5]  = 11, S_table[1][1][5]  =  2, S_table[1][2][5]  =  4, S_table[1][3][5]  = 15;
  S_table[1][0][6]  =  3, S_table[1][1][6]  =  8, S_table[1][2][6]  = 13, S_table[1][3][6]  =  4;
  S_table[1][0][7]  =  4, S_table[1][1][7]  = 14, S_table[1][2][7]  =  1, S_table[1][3][7]  =  2;
  S_table[1][0][8]  =  9, S_table[1][1][8]  = 12, S_table[1][2][8]  =  5, S_table[1][3][8]  = 11;
  S_table[1][0][9]  =  7, S_table[1][1][9]  =  0, S_table[1][2][9]  =  8, S_table[1][3][9]  =  6;
  S_table[1][0][10] =  2, S_table[1][1][10] =  1, S_table[1][2][10] = 12, S_table[1][3][10] =  7;
  S_table[1][0][11] = 13, S_table[1][1][11] = 10, S_table[1][2][11] =  6, S_table[1][3][11] = 12;
  S_table[1][0][12] = 12, S_table[1][1][12] =  6, S_table[1][2][12] =  9, S_table[1][3][12] =  0;
  S_table[1][0][13] =  0, S_table[1][1][13] =  9, S_table[1][2][13] =  3, S_table[1][3][13] =  5;
  S_table[1][0][14] =  5, S_table[1][1][14] = 11, S_table[1][2][14] =  2, S_table[1][3][14] = 14;
  S_table[1][0][15] = 10, S_table[1][1][15] =  5, S_table[1][2][15] = 15, S_table[1][3][15] =  9;

  // table3, row, column
  S_table[2][0][0]  = 10, S_table[2][1][0]  = 13, S_table[2][2][0]  = 13, S_table[2][3][0]  =  1;
  S_table[2][0][1]  =  0, S_table[2][1][1]  =  7, S_table[2][2][1]  =  6, S_table[2][3][1]  = 10;
  S_table[2][0][2]  =  9, S_table[2][1][2]  =  0, S_table[2][2][2]  =  4, S_table[2][3][2]  = 13;
  S_table[2][0][3]  = 14, S_table[2][1][3]  =  9, S_table[2][2][3]  =  9, S_table[2][3][3]  =  0;
  S_table[2][0][4]  =  6, S_table[2][1][4]  =  3, S_table[2][2][4]  =  8, S_table[2][3][4]  =  6;
  S_table[2][0][5]  =  3, S_table[2][1][5]  =  4, S_table[2][2][5]  = 15, S_table[2][3][5]  =  9;
  S_table[2][0][6]  = 15, S_table[2][1][6]  =  6, S_table[2][2][6]  =  3, S_table[2][3][6]  =  8;
  S_table[2][0][7]  =  5, S_table[2][1][7]  = 10, S_table[2][2][7]  =  0, S_table[2][3][7]  =  7;
  S_table[2][0][8]  =  1, S_table[2][1][8]  =  2, S_table[2][2][8]  = 11, S_table[2][3][8]  =  4;
  S_table[2][0][9]  = 13, S_table[2][1][9]  =  8, S_table[2][2][9]  =  1, S_table[2][3][9]  = 15;
  S_table[2][0][10] = 12, S_table[2][1][10] =  5, S_table[2][2][10] =  2, S_table[2][3][10] = 14;
  S_table[2][0][11] =  7, S_table[2][1][11] = 14, S_table[2][2][11] = 12, S_table[2][3][11] =  3;
  S_table[2][0][12] = 11, S_table[2][1][12] = 12, S_table[2][2][12] =  5, S_table[2][3][12] = 11;
  S_table[2][0][13] =  4, S_table[2][1][13] = 11, S_table[2][2][13] = 10, S_table[2][3][13] =  5;
  S_table[2][0][14] =  2, S_table[2][1][14] = 15, S_table[2][2][14] = 14, S_table[2][3][14] =  2;
  S_table[2][0][15] =  8, S_table[2][1][15] =  1, S_table[2][2][15] =  7, S_table[2][3][15] = 12;

  // table4, row, column
  S_table[3][0][0]  =  7, S_table[3][1][0]  = 13, S_table[3][2][0]  = 10, S_table[3][3][0]  =  3;
  S_table[3][0][1]  = 13, S_table[3][1][1]  =  8, S_table[3][2][1]  =  6, S_table[3][3][1]  = 15;
  S_table[3][0][2]  = 14, S_table[3][1][2]  = 11, S_table[3][2][2]  =  9, S_table[3][3][2]  =  0;
  S_table[3][0][3]  =  3, S_table[3][1][3]  =  5, S_table[3][2][3]  =  0, S_table[3][3][3]  =  6;
  S_table[3][0][4]  =  0, S_table[3][1][4]  =  6, S_table[3][2][4]  = 12, S_table[3][3][4]  = 10;
  S_table[3][0][5]  =  6, S_table[3][1][5]  = 15, S_table[3][2][5]  = 11, S_table[3][3][5]  =  1;
  S_table[3][0][6]  =  9, S_table[3][1][6]  =  0, S_table[3][2][6]  =  7, S_table[3][3][6]  = 13;
  S_table[3][0][7]  = 10, S_table[3][1][7]  =  3, S_table[3][2][7]  = 13, S_table[3][3][7]  =  8;
  S_table[3][0][8]  =  1, S_table[3][1][8]  =  4, S_table[3][2][8]  = 15, S_table[3][3][8]  =  9;
  S_table[3][0][9]  =  2, S_table[3][1][9]  =  7, S_table[3][2][9]  =  1, S_table[3][3][9]  =  4;
  S_table[3][0][10] =  8, S_table[3][1][10] =  2, S_table[3][2][10] =  3, S_table[3][3][10] =  5;
  S_table[3][0][11] =  5, S_table[3][1][11] = 12, S_table[3][2][11] = 14, S_table[3][3][11] = 11;
  S_table[3][0][12] = 11, S_table[3][1][12] =  1, S_table[3][2][12] =  5, S_table[3][3][12] = 12;
  S_table[3][0][13] = 12, S_table[3][1][13] = 10, S_table[3][2][13] =  2, S_table[3][3][13] =  7;
  S_table[3][0][14] =  4, S_table[3][1][14] = 14, S_table[3][2][14] =  8, S_table[3][3][14] =  2;
  S_table[3][0][15] = 15, S_table[3][1][15] =  9, S_table[3][2][15] =  4, S_table[3][3][15] = 14;

  // table5, row, column
  S_table[4][0][0]  =  2, S_table[4][1][0]  = 14, S_table[4][2][0]  =  4, S_table[4][3][0]  = 11;
  S_table[4][0][1]  = 12, S_table[4][1][1]  = 11, S_table[4][2][1]  =  2, S_table[4][3][1]  =  8;
  S_table[4][0][2]  =  4, S_table[4][1][2]  =  2, S_table[4][2][2]  =  1, S_table[4][3][2]  = 12;
  S_table[4][0][3]  =  1, S_table[4][1][3]  = 12, S_table[4][2][3]  = 11, S_table[4][3][3]  =  7;
  S_table[4][0][4]  =  7, S_table[4][1][4]  =  4, S_table[4][2][4]  = 10, S_table[4][3][4]  =  1;
  S_table[4][0][5]  = 10, S_table[4][1][5]  =  7, S_table[4][2][5]  = 13, S_table[4][3][5]  = 14;
  S_table[4][0][6]  = 11, S_table[4][1][6]  = 13, S_table[4][2][6]  =  7, S_table[4][3][6]  =  2;
  S_table[4][0][7]  =  6, S_table[4][1][7]  =  1, S_table[4][2][7]  =  8, S_table[4][3][7]  = 13;
  S_table[4][0][8]  =  8, S_table[4][1][8]  =  5, S_table[4][2][8]  = 15, S_table[4][3][8]  =  6;
  S_table[4][0][9]  =  5, S_table[4][1][9]  =  0, S_table[4][2][9]  =  9, S_table[4][3][9]  = 15;
  S_table[4][0][10] =  3, S_table[4][1][10] = 15, S_table[4][2][10] = 12, S_table[4][3][10] =  0;
  S_table[4][0][11] = 15, S_table[4][1][11] = 10, S_table[4][2][11] =  5, S_table[4][3][11] =  9;
  S_table[4][0][12] = 13, S_table[4][1][12] =  3, S_table[4][2][12] =  6, S_table[4][3][12] = 10;
  S_table[4][0][13] =  0, S_table[4][1][13] =  9, S_table[4][2][13] =  3, S_table[4][3][13] =  4;
  S_table[4][0][14] = 14, S_table[4][1][14] =  8, S_table[4][2][14] =  0, S_table[4][3][14] =  5;
  S_table[4][0][15] =  9, S_table[4][1][15] =  6, S_table[4][2][15] = 14, S_table[4][3][15] =  3;

  // table6, row, column
  S_table[5][0][0]  = 12, S_table[5][1][0]  = 10, S_table[5][2][0]  =  9, S_table[5][3][0]  =  4;
  S_table[5][0][1]  =  1, S_table[5][1][1]  = 15, S_table[5][2][1]  = 14, S_table[5][3][1]  =  3;
  S_table[5][0][2]  = 10, S_table[5][1][2]  =  4, S_table[5][2][2]  = 15, S_table[5][3][2]  =  2;
  S_table[5][0][3]  = 15, S_table[5][1][3]  =  2, S_table[5][2][3]  =  5, S_table[5][3][3]  = 12;
  S_table[5][0][4]  =  9, S_table[5][1][4]  =  7, S_table[5][2][4]  =  2, S_table[5][3][4]  =  9;
  S_table[5][0][5]  =  2, S_table[5][1][5]  = 12, S_table[5][2][5]  =  8, S_table[5][3][5]  =  5;
  S_table[5][0][6]  =  6, S_table[5][1][6]  =  9, S_table[5][2][6]  = 12, S_table[5][3][6]  = 15;
  S_table[5][0][7]  =  8, S_table[5][1][7]  =  5, S_table[5][2][7]  =  3, S_table[5][3][7]  = 10;
  S_table[5][0][8]  =  0, S_table[5][1][8]  =  6, S_table[5][2][8]  =  7, S_table[5][3][8]  = 11;
  S_table[5][0][9]  = 13, S_table[5][1][9]  =  1, S_table[5][2][9]  =  0, S_table[5][3][9]  = 14;
  S_table[5][0][10] =  3, S_table[5][1][10] = 13, S_table[5][2][10] =  4, S_table[5][3][10] =  1;
  S_table[5][0][11] =  4, S_table[5][1][11] = 14, S_table[5][2][11] = 10, S_table[5][3][11] =  7;
  S_table[5][0][12] = 14, S_table[5][1][12] =  0, S_table[5][2][12] =  1, S_table[5][3][12] =  6;
  S_table[5][0][13] =  7, S_table[5][1][13] = 11, S_table[5][2][13] = 13, S_table[5][3][13] =  0;
  S_table[5][0][14] =  5, S_table[5][1][14] =  3, S_table[5][2][14] = 11, S_table[5][3][14] =  8;
  S_table[5][0][15] = 11, S_table[5][1][15] =  8, S_table[5][2][15] =  6, S_table[5][3][15] = 13;

  // table7, row, column
  S_table[6][0][0]  =  4, S_table[6][1][0]  = 13, S_table[6][2][0]  =  1, S_table[6][3][0]  =  6;
  S_table[6][0][1]  = 11, S_table[6][1][1]  =  0, S_table[6][2][1]  =  4, S_table[6][3][1]  = 11;
  S_table[6][0][2]  =  2, S_table[6][1][2]  = 11, S_table[6][2][2]  = 11, S_table[6][3][2]  = 13;
  S_table[6][0][3]  = 14, S_table[6][1][3]  =  7, S_table[6][2][3]  = 13, S_table[6][3][3]  =  8;
  S_table[6][0][4]  = 15, S_table[6][1][4]  =  4, S_table[6][2][4]  = 12, S_table[6][3][4]  =  1;
  S_table[6][0][5]  =  0, S_table[6][1][5]  =  9, S_table[6][2][5]  =  3, S_table[6][3][5]  =  4;
  S_table[6][0][6]  =  8, S_table[6][1][6]  =  1, S_table[6][2][6]  =  7, S_table[6][3][6]  = 10;
  S_table[6][0][7]  = 13, S_table[6][1][7]  = 10, S_table[6][2][7]  = 14, S_table[6][3][7]  =  7;
  S_table[6][0][8]  =  3, S_table[6][1][8]  = 14, S_table[6][2][8]  = 10, S_table[6][3][8]  =  9;
  S_table[6][0][9]  = 12, S_table[6][1][9]  =  3, S_table[6][2][9]  = 15, S_table[6][3][9]  =  5;
  S_table[6][0][10] =  9, S_table[6][1][10] =  5, S_table[6][2][10] =  6, S_table[6][3][10] =  0;
  S_table[6][0][11] =  7, S_table[6][1][11] = 12, S_table[6][2][11] =  8, S_table[6][3][11] = 15;
  S_table[6][0][12] =  5, S_table[6][1][12] =  2, S_table[6][2][12] =  0, S_table[6][3][12] = 14;
  S_table[6][0][13] = 10, S_table[6][1][13] = 15, S_table[6][2][13] =  5, S_table[6][3][13] =  2;
  S_table[6][0][14] =  6, S_table[6][1][14] =  8, S_table[6][2][14] =  9, S_table[6][3][14] =  3;
  S_table[6][0][15] =  1, S_table[6][1][15] =  6, S_table[6][2][15] =  2, S_table[6][3][15] = 12;

  // table8, row, column
  S_table[7][0][0]  = 13, S_table[7][1][0]  =  1, S_table[7][2][0]  =  7, S_table[7][3][0]  =  2;
  S_table[7][0][1]  =  2, S_table[7][1][1]  = 15, S_table[7][2][1]  = 11, S_table[7][3][1]  =  1;
  S_table[7][0][2]  =  8, S_table[7][1][2]  = 13, S_table[7][2][2]  =  4, S_table[7][3][2]  = 14;
  S_table[7][0][3]  =  4, S_table[7][1][3]  =  8, S_table[7][2][3]  =  1, S_table[7][3][3]  =  7;
  S_table[7][0][4]  =  6, S_table[7][1][4]  = 10, S_table[7][2][4]  =  9, S_table[7][3][4]  =  4;
  S_table[7][0][5]  = 15, S_table[7][1][5]  =  3, S_table[7][2][5]  = 12, S_table[7][3][5]  = 10;
  S_table[7][0][6]  = 11, S_table[7][1][6]  =  7, S_table[7][2][6]  = 14, S_table[7][3][6]  =  8;
  S_table[7][0][7]  =  1, S_table[7][1][7]  =  4, S_table[7][2][7]  =  2, S_table[7][3][7]  = 13;
  S_table[7][0][8]  = 10, S_table[7][1][8]  = 12, S_table[7][2][8]  =  0, S_table[7][3][8]  = 15;
  S_table[7][0][9]  =  9, S_table[7][1][9]  =  5, S_table[7][2][9]  =  6, S_table[7][3][9]  = 12;
  S_table[7][0][10] =  3, S_table[7][1][10] =  6, S_table[7][2][10] = 10, S_table[7][3][10] =  9;
  S_table[7][0][11] = 14, S_table[7][1][11] = 11, S_table[7][2][11] = 13, S_table[7][3][11] =  0;
  S_table[7][0][12] =  5, S_table[7][1][12] =  0, S_table[7][2][12] = 15, S_table[7][3][12] =  3;
  S_table[7][0][13] =  0, S_table[7][1][13] = 14, S_table[7][2][13] =  3, S_table[7][3][13] =  5;
  S_table[7][0][14] = 12, S_table[7][1][14] =  9, S_table[7][2][14] =  5, S_table[7][3][14] =  6;
  S_table[7][0][15] =  7, S_table[7][1][15] =  2, S_table[7][2][15] =  8, S_table[7][3][15] = 11;
} // Set_S_table()

//---------------------------- �H�W��table----------------------------//

void String_To_Hex( string input, string & hex ) {
  hex = "" ;
  char temp_hex_input[3] ;
  for ( int i = 0 ; i < input.size() ; i++ ) {
    sprintf( temp_hex_input, "%x", input[i] ) ; // ��16�i���i�h
    hex = hex + temp_hex_input ;
  } // for 
} // String_To_Hex()

void Hex_To_Binary( string hex, string & binary ) {
  binary = "" ;
  for ( int h = 0 ; h < hex.size() ; h++ ) {
    if ( hex[h] == 'A' || hex[h] == 'a' ) {
      binary = binary + "1010" ;
    } // if 
    else if ( hex[h] == 'B' || hex[h] == 'b' ) {
      binary = binary + "1011" ;
    } // else if 
    else if ( hex[h] == 'C' || hex[h] == 'c' ) {
      binary = binary + "1100" ;
    } // else if 
    else if ( hex[h] == 'D' || hex[h] == 'd' ) {
      binary = binary + "1101" ;
    } // else if 
    else if ( hex[h] == 'E' || hex[h] == 'e' ) {
      binary = binary + "1110" ;
    } // else if 
    else if ( hex[h] == 'F' || hex[h] == 'f' ) {
      binary = binary + "1111" ;
    } // else if 
    else if ( hex[h] == '0' ) {
      binary = binary + "0000" ;
    } // else if 
    else if ( hex[h] == '1') {
      binary = binary + "0001" ;
    } // else if 
    else if ( hex[h] == '2' ) {
      binary = binary + "0010" ;
    } // else if 
    else if ( hex[h] == '3' ) {
      binary = binary + "0011" ;
    } // else if 
    else if ( hex[h] == '4' ) {
      binary = binary + "0100" ;
    } // else if 
    else if ( hex[h] == '5' ) {
      binary = binary + "0101" ;
    } // else if 
    else if ( hex[h] == '6' ) {
      binary = binary + "0110" ;
    } // else if 
    else if ( hex[h] == '7' ) {
      binary = binary + "0111" ;
    } // else if 
    else if ( hex[h] == '8' ) {
      binary = binary + "1000" ;
    } // else if 
    else if ( hex[h] == '9' ) {
      binary = binary + "1001" ;
    } // else if 
  } // for 
} // Hex_To_Binary()

void Binary_To_Int( string binary, int & result ) {
  int bit = 0 ;
  result = 0 ;
  for ( int b = binary.size()-1 ; b >= 0 ; b-- ) {
    if ( binary[b] == '1' ) {
      result = result + pow(2, bit) ; // 2��0����+2��1����...
    } // if

    bit++ ;
  } // for 
} // Binary_To_Int()

void Int_To_Binary( int result, string &binary ) {
  binary = "" ;
  while ( result >= 1 ) { 
    if ( result % 2 == 1 ) {
      binary = "1" + binary;
    } // if 
    else if ( result % 2 == 0 ) {
      binary = "0" + binary;
    } // else if 

    result = result / 2 ;
  } // while 

  while (binary.size() < 4 ) { // ����4bits�n��0
    binary = "0" + binary ;
  } // while 

} // Int_To_Binary()

void Binary_To_Hex( string binary, string &hex ) {
  string temp ;
  hex = "" ;
  for ( int b = 0 ; b < binary.size() ; b = b + 4 ) {
    temp = binary.substr( b, 4 ) ;
    if ( temp == "0000" ) {
      hex = hex + "0" ;
    } // if 
    else if ( temp == "0001" ) {
      hex = hex + "1" ;
    } // else if 
    else if ( temp == "0010" ) {
      hex = hex + "2" ;
    } // else if 
    else if ( temp == "0011" ) {
      hex = hex + "3" ;
    } // else if 
    else if ( temp == "0100" ) {
      hex = hex + "4" ;
    } // else if 
    else if ( temp == "0101" ) {
      hex = hex + "5" ;
    } // else if 
    else if ( temp == "0110" ) {
      hex = hex + "6" ;
    } // else if 
    else if ( temp == "0111" ) {
      hex = hex + "7" ;
    } // else if 
    else if ( temp == "1000" ) {
      hex = hex + "8" ;
    } // else if 
    else if ( temp == "1001" ) {
      hex = hex + "9" ;
    } // else if 
    else if ( temp == "1010" ) {
      hex = hex + "A" ;
    } // else if 
    else if ( temp == "1011" ) {
      hex = hex + "B" ;
    } // else if 
    else if ( temp == "1100" ) {
      hex = hex + "C" ;
    } // else if 
    else if ( temp == "1101" ) {
      hex = hex + "D" ;
    } // else if 
    else if ( temp == "1110" ) {
      hex = hex + "E" ;
    } // else if 
    else if ( temp == "1111" ) {
      hex = hex + "F" ;
    } // else if 
  } // for 
} // Binary_To_Hex()

void LookUp_PC_1_Table( string inputkey, string & inputkey_K_plus ) {
  inputkey_K_plus = "" ;
  for ( int i = 0 ; i < 56 ; i++ ) {
    inputkey_K_plus = inputkey_K_plus + inputkey[PC_1[i]-1] ; 
    // �]��table�̪��Ƴ��q1�}�l�A����m�q0�}�l�A�ҥH�n-1
  } // for 
} // LookUp_PC_1_Table()

void Move( string C[17], string D[17] ) { // �첾�AK+���e��U�@�b�N�OC��D

  for ( int cd = 1; cd < 17 ; cd++ ) {
    // �]��table�̪��Ƴ��q1�}�l�A����m�q0�}�l�A�ҥH�n-1
    if ( Iteration[cd-1] == 1 ) {
      C[cd] = C[cd-1].substr( 1, 27 ) + C[cd-1][0] ; // ���2���̫�1����U�ӡA�ɳ̥��䪺�줸��̫᭱
      D[cd] = D[cd-1].substr( 1, 27 ) + D[cd-1][0] ;
    } // if 
    else if ( Iteration[cd-1] == 2 ) {
      C[cd] = C[cd-1].substr( 2, 26 ) + C[cd-1][0] + C[cd-1][1] ; // ���3���̫�@����U�ӡA�ɳ̥��䪺2�Ӧ줸��̫᭱
      D[cd] = D[cd-1].substr( 2, 26 ) + D[cd-1][0] + D[cd-1][1] ;
    } // else if 
  } // for 

} // Move()

void LookUp_PC_2_Table( string C[17], string D[17], string K[16] ) { // CD���O�dPC_2��table�ܦ�K
  string CD[17] ;
  for ( int cd = 1; cd < 17 ; cd++ ) { // C��D�����_��
    CD[cd] = C[cd] + D[cd] ;
  } // for 

  for ( int k = 0 ; k < 16 ; k++ ) { // �]��K��16��
    for ( int t = 0 ; t < 48 ; t++ ) { // PC_2 table��48�ӭn��
      K[k] = K[k] + CD[k+1][PC_2[t]-1] ;
    } // for 
  } // for 
 
} // LookUp_PC_2_Table()

void Create_16_subkeys( string inputkey, string K[16] ) {
  string hex_inputkey, binary_inputkey, inputkey_K_plus ;
  char temp_hex_inputkey[10] ;
  string C[17], D[17] ;
  for ( int k = 0 ; k < 16 ; k++ ) { // �@�}�l��K�M��
    K[k] = "" ;
  } // for 

  String_To_Hex( inputkey, hex_inputkey ) ; // �i�Ӫ�string�Q��sprintf��16�i��
  Hex_To_Binary( hex_inputkey, binary_inputkey ) ; // 16�i����binary

  LookUp_PC_1_Table( binary_inputkey, inputkey_K_plus ) ; // �dPC_1 table�ܦ�K+

  C[0] = inputkey_K_plus.substr( 0, 28 ) ; // K+���@�b�e�b��
  D[0] = inputkey_K_plus.substr( 28, 28 ) ; // K+���@�b�e�b��
  Move( C, D ) ; // ��interation table�Ӧ첾�|�o��C1~C16�BD1~D16
  LookUp_PC_2_Table( C, D, K ) ; // �A���O�dPC_2 table�ӱo��16��subkeys K
} // Create_16_subkeys()

void LookUp_IP_Table( string M, string & IP) {
  IP = "" ;
  for ( int ip = 0 ; ip < 64 ; ip++ ) {
    IP = IP + M[IP_table[ip]-1] ;
  } // for 
 
} // LookUp_IP_Table()

void XOR( string X, string Y, string & Z ) {
  Z = "" ;
  for ( int xy = 0 ; xy < X.size() ; xy++ ) {
    if ( X[xy] == Y[xy] ) { // �p�G���bits�۵�
      Z = Z + "0" ; // XOR�X�ӴN�O0
    } // if 
    else { // �p�G���bits���۵�
      Z = Z + "1" ; // XOR�X�ӴN�O1
    } // else 
  } // for 
} // XOR() 

void LookUp_S_Table( int **S_table, string B, string & SB ) {
  SB = "" ;
  string head_and_tail, center ;
  int row = 0, column = 0 ;
  head_and_tail = head_and_tail + B[0] + B[B.size() - 1] ; // ���Y��
  Binary_To_Int( head_and_tail, row ) ; // ��binary��int
  center = B.substr( 1, 4 ) ; // �������|��bits
  Binary_To_Int( center, column ) ; // �নint

  Int_To_Binary( S_table[row][column], SB ) ; // �Y���Orow�A�����Ocolumn�A�d����binary
} // LookUp_S_Table()

void LookUp_P_Table( string wholeSB, string &P ) {
  P = "" ;
  for ( int p = 0 ; p < 32 ; p++ ) {
    P = P + wholeSB[P_table[p] - 1] ;
  } // for
} // LookUp_P_Table()

void LookUp_IP_inverse_Table( string RL_16, string &IPI ) {
  IPI = "" ;
  for ( int ipi = 0 ; ipi < 64 ; ipi++ ) {
    IPI = IPI + RL_16[IP_inverse_table[ipi] - 1] ;
  } // for
} // LookUp_IP_inverse_Table()

void f_function( string R, string K, int **S_table[8], string & P ) {
  P = "" ;
  string E, X, B[8], SB[8], wholeSB ;
  for ( int e = 0 ; e < 48 ; e++ ) {
    E = E + R[E_BIT_SELECTION_TABLE[e] - 1] ; // R0�h�dE_BIT_SELECTION_TABLE��E(R0)�A48bits
  } // for 

  XOR( K, E, X ) ; // subkeys K�h��E(R0)��XOR�OX�A48bits

  B[0] = X.substr(  0, 6 ) ; // X��8�q��B1�A��1�q
  B[1] = X.substr(  6, 6 ) ; // X��8�q��B2�A��2�q
  B[2] = X.substr( 12, 6 ) ; // X��8�q��B3�A��3�q
  B[3] = X.substr( 18, 6 ) ; // X��8�q��B4�A��4�q
  B[4] = X.substr( 24, 6 ) ; // X��8�q��B5�A��5�q
  B[5] = X.substr( 30, 6 ) ; // X��8�q��B6�A��6�q
  B[6] = X.substr( 36, 6 ) ; // X��8�q��B7�A��7�q
  B[7] = X.substr( 42, 6 ) ; // X��8�q��B8�A��8�q
  for ( int call = 0; call < 8 ; call++ ) {
    LookUp_S_Table( S_table[call], B[call], SB[call] ) ; // B�d����SB1~SB8
    wholeSB = wholeSB + SB[call] ; // ��SB��_����wholeSB
  } // for 

  LookUp_P_Table( wholeSB, P ) ; // P��32bits
} // f_function()

void Put_R_and_L( string R[17], string L[17], int **S_table[8], string K[16]) {
  string P ;
  //  �ӳo�Ӥ����g�� 
  //  Ln = Rn-1
  //  Rn = Ln - 1 + f( Rn - 1, Kn )

  for ( int n = 1 ; n < 17 ; n++ ) {
    L[n] = R[n-1] ;
    f_function( R[n-1], K[n-1], S_table, P ) ; // �]��K�u��16�өҥHl-1
    XOR( L[n-1], P,R[n] ) ;
  } // for  

} // Put_R_and_L()

void Encode_64_bits( string M, int **S_table[8], string K1[16], string &C ) { // �[�K
  // M�Obinary������A64bits
  C = "" ;
  string hex_plaintext, IP, P, IPI;
  string L[17], R[17], RL_16 ;
  while ( M.size() < 64 ) { // �p�G����64bits�|�b�᭱��0
    M = M + "0" ;
  } // while 

  LookUp_IP_Table( M, IP ) ; // ������dIP_table�o��IP�AIP�O64bits
  L[0] = IP.substr( 0, 32 ) ; // IP���@�b�e�b����L[0]
  R[0] = IP.substr( 32, 32 ) ; // IP���@�b�e�b����R[0]

  Put_R_and_L( R, L, S_table, K1 ) ; // ������
  RL_16 = RL_16 + R[16] + L[16] ; // R16��L16���_��
  LookUp_IP_inverse_Table( RL_16, IPI ) ; 

  Binary_To_Hex( IPI, C ) ;
} // Encode_64_bits()

void LookUp_RL16_In_IP_inverse_Table( string IPI, string &RL_16 ) {
  RL_16 = "" ;
  char temp_RL16[65] = {0};

  for ( int ipi = 0 ; ipi < 64 ; ipi++ ) {
    temp_RL16[IP_inverse_table[ipi] - 1] = IPI[ipi] ;
  } // for 
  temp_RL16[64] = '\0' ;

  RL_16.assign( temp_RL16 ) ;
} // LookUp_RL16_In_IP_inverse_Table()

void LookUp_M_In_IP_Table( string IP, string & M ) {
  M = "" ;
  char temp_M[65] = { 0 };

  for ( int m = 0 ; m < 64 ; m++ ) {
    temp_M[IP_table[m] - 1] = IP[m] ;
  } // for 
  temp_M[64] = '\0' ;

  M.assign( temp_M ) ;
} // LookUp_M_In_IP_Table()

void Decode_64_bits( string C, string K2[16], int **S_table[8], string &M) { // �ѱK
  M = "" ;
  string IPI, RL_16, P, IP ;
  string R[17], L[17] ;
  Hex_To_Binary( C, IPI ) ;
  LookUp_RL16_In_IP_inverse_Table( IPI, RL_16 ) ; // IPI�ӱ��^R16L16
  R[16] = RL_16.substr( 0, 32 ) ; // RL16���@�b�e�b��
  L[16] = RL_16.substr( 32, 32 ) ; // RL16���@�b�e�b��

  for ( int f = 16 ; f > 0 ; f-- ) { // �o��R0 L0
    R[f-1] = L[f] ; //R15��iL16
    f_function( R[f-1], K2[f-1], S_table, P ) ; // K16�O��15�Ӧ�m
    XOR( R[f], P, L[f - 1] ) ; // �D�XL15
  } // for 
  
  IP = IP + L[0] + R[0] ; // ���^��
  
  LookUp_M_In_IP_Table( IP, M ) ; // M���ѱK������
} // Decode_64_bits() 

int main() {
  int **S_table[8] ;
  int keynum = 0, encrypt_or_decrypt = 0, tobecontinue = 1;
  string inputkey1, inputkey2, inputkey3 ;
  string plaintext, C, M, hex_M, hex_plaintext;
  string K1[16], K2[16], K3[16] ;
  for ( int i = 0; i < 8 ; i++ ) {
    S_table[i] = new int*[4] ;
    for ( int j = 0 ; j < 4; j++ ) {
      S_table[i][j] = new int[16] ;
    } // for 
  } // for 

  Set_S_table( S_table ) ;

  while ( tobecontinue == 1 ) {
    cout << "�п�J�n�X��key: " ;
    cin >> keynum ;
    if ( keynum == 2 ) {
      cout << "�п�Jkey1:" ;
      cin >> inputkey1 ;
      cout << "�п�Jkey2:" ;
      cin >> inputkey2 ; 
    } // if 
    else if ( keynum == 3 ) {
      cout << "�п�Jkey1:" ;
      cin >> inputkey1 ;
      cout << "�п�Jkey2:" ;
      cin >> inputkey2 ;
      cout << "�п�Jkey3:" ;
      cin >> inputkey3 ;
    } // else if 

    cout << "�п�J�n�[�K�ٸѱK(1 �[�K (2 �ѱK: " ;
    cin >> encrypt_or_decrypt ;
    if ( encrypt_or_decrypt == 1 ) { // ���[�K
      cout << "�п�J����: " ;
      cin >> plaintext ;

      Create_16_subkeys( inputkey1, K1 ); // in: string   out: 16��K(binary)
      String_To_Hex( plaintext, hex_plaintext ) ; // ����i���ন16�i��
      Hex_To_Binary( hex_plaintext, M ) ; // 16�i����binary�A�o��binary����(M�A64bits)
      Encode_64_bits( M, S_table, K1, C ) ; // in:binary   out:hex 
      Create_16_subkeys( inputkey2, K2 ) ;
      Decode_64_bits( C, K2, S_table, M ) ; // in:hex   out:binary 
      if ( keynum == 2 ) {
        Create_16_subkeys( inputkey1, K3 ) ;
        Encode_64_bits( M, S_table, K3, C ) ; // in:binary   out:hex
      } // if 
      else {
        Create_16_subkeys( inputkey3, K3 ) ;
        Encode_64_bits( M, S_table, K3, C ) ;
      } // else 

      cout << endl << "���G:" << C;
    } // if 
    else { // �ѱK
      cout << "�п�J�K��: " ;
      cin >> plaintext ;

      Create_16_subkeys( inputkey1, K1 ) ;
      Decode_64_bits( plaintext, K1, S_table, M ) ;
      Create_16_subkeys( inputkey2, K2 ) ;
      Encode_64_bits( M, S_table, K2, C ) ;
      if ( keynum == 2 ) {
        Create_16_subkeys( inputkey1, K3 ) ;
        Decode_64_bits( C, K3, S_table, M ) ;
      } // if 
      else {
        Create_16_subkeys( inputkey3, K3 ) ;
        Decode_64_bits( C, K3, S_table, M ) ;
      } // else 

      Binary_To_Hex( M, hex_M ) ;
      cout << endl << "���G:" << hex_M;
    } // else 

    cout << endl << "�O�_�n�~��? (1 �~�� (2 ����: " ;
    cin >> tobecontinue ;
  } // while 

  system( "pause" ) ;
} // main()