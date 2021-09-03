#ifndef FONT_C
#define FONT_C

#include "font.h"

//
// Digits
//

int bA_0[7] = {
		0b00110,
		0b11001,
		0b11001,
		0b11101,
		0b11011,
		0b11001,
		0b00110
};

int bA_1[7] = {
		0b00110,
		0b01110,
		0b00110,
		0b00110,
		0b00110,
		0b00110,
		0b11111
};

int bA_2[7] = {
		0b01110,
		0b10011,
		0b00011,
		0b01110,
		0b11000,
		0b11000,
		0b11111

};

int bA_3[7] = {
		0b01110,
		0b10011,
		0b00011,
		0b01110,
		0b00011,
		0b10011,
		0b01110

};

int bA_4[7] = {
		0b00110,
		0b01110,
		0b10110,
		0b11111,
		0b00110,
		0b00110,
		0b00110

};

int bA_5[7] = {
		0b11111,
		0b11001,
		0b11000,
		0b01110,
		0b00011,
		0b10011,
		0b01110

};

int bA_6[7] = {
		0b01110,
		0b11001,
		0b11000,
		0b11110,
		0b11001,
		0b11001,
		0b01110

};

int bA_7[7] = {

		0b11111,
		0b00011,
		0b00011,
		0b00110,
		0b00110,
		0b01100,
		0b01100

};

int bA_8[7] = {
		0b01110,
		0b11001,
		0b11001,
		0b01110,
		0b11001,
		0b11001,
		0b01110

};

int bA_9[7] = {
		0b01110,
		0b10011,
		0b10011,
		0b01111,
		0b00011,
		0b10011,
		0b01110

};

//
// Lower Case Letters
//

int bA_a[7] = {
		0b00000,
		0b00000,
		0b01110,
		0b10011,
		0b10011,
		0b10011,
		0b11111
};

int bA_b[7] = {
		0b10000,
		0b10000,
		0b11110,
		0b10001,
		0b10001,
		0b10001,
		0b11110
};

int bA_c[7] = {
		0b00000,
		0b00000,
		0b01110,
		0b11001,
		0b11000,
		0b11001,
		0b01110
};

int bA_d[7] = {
		0b00001,
		0b00001,
		0b01111,
		0b11001,
		0b11001,
		0b11001,
		0b01111
};

int bA_e[7] = {
		0b00000,
		0b00000,
		0b01110,
		0b11001,
		0b11111,
		0b11000,
		0b01110

};
int bA_f[7] = {
		0b00111,
		0b01100,
		0b01100,
		0b11111,
		0b01100,
		0b01100,
		0b01100
};

int bA_g[7] = {
		0b00000,
		0b00000,
		0b01110,
		0b10011,
		0b01111,
		0b00011,
		0b11110

};

int bA_h[7] = {
		0b11000,
		0b11000,
		0b11110,
		0b11001,
		0b11001,
		0b11001,
		0b11001
};

int bA_i[7] = {
		0b00110,
		0b00110,
		0b00000,
		0b11111,
		0b00110,
		0b00110,
		0b11111
};

int bA_j[7] = {
		0b00110,
		0b00110,
		0b00000,
		0b01111,
		0b00110,
		0b00110,
		0b11100
};

int bA_k[7] = {
		0b11000,
		0b11000,
		0b11001,
		0b11010,
		0b11100,
		0b11010,
		0b11001
};

int bA_l[7] = {
		0b01100,
		0b01100,
		0b01100,
		0b01100,
		0b01100,
		0b01100,
		0b01110
};

int bA_m[7] = {
		0b00000,
		0b00000,
		0b11010,
		0b10101,
		0b10101,
		0b10101,
		0b10101

};

int bA_n[7] = {
		0b00000,
		0b00000,
		0b11110,
		0b10001,
		0b10001,
		0b10001,
		0b10001
};

int bA_o[7] = {
		0b00000,
		0b00000,
		0b01110,
		0b11001,
		0b11001,
		0b11001,
		0b01110
};

int bA_p[7] = {
		0b00000,
		0b00000,
		0b11110,
		0b11001,
		0b11110,
		0b11000,
		0b11000
};

int bA_q[7] = {
		0b00000,
		0b00000,
		0b01110,
		0b10010,
		0b01110,
		0b00010,
		0b00111
};

int bA_r[7] = {
		0b00000,
		0b00000,
		0b11011,
		0b11100,
		0b11000,
		0b11000,
		0b11000
};

int bA_s[7] = {
		0b00000,
		0b00000,
		0b01110,
		0b11000,
		0b01110,
		0b00001,
		0b11110

};

int bA_t[7] = {
		0b01100,
		0b01100,
		0b11111,
		0b01100,
		0b01100,
		0b01100,
		0b00111
};

int bA_u[7] = {
		0b00000,
		0b00000,
		0b11001,
		0b11001,
		0b11001,
		0b11001,
		0b01110
};

int bA_v[7] = {
		0b00000,
		0b00000,
		0b11001,
		0b11001,
		0b01010,
		0b01010,
		0b00100
};

int bA_w[7] = {
		0b00000,
		0b00000,
		0b10101,
		0b10101,
		0b10101,
		0b10101,
		0b01010
};

int bA_x[7] = {
		0b00000,
		0b00000,
		0b11001,
		0b01110,
		0b00100,
		0b01110,
		0b11001
};

int bA_y[7] = {
		0b00000,
		0b00000,
		0b11001,
		0b11001,
		0b01111,
		0b00010,
		0b11100
};

int bA_z[7] = {
		0b00000,
		0b00000,
		0b11111,
		0b00010,
		0b00100,
		0b11000,
		0b11111
};

//
// Upper Case Letters
//

int bA_A[7] = {
		0b01110,
		0b11001,
		0b11001,
		0b11111,
		0b11001,
		0b11001,
		0b11001
};
int bA_B[7] = {
		0b11100,
		0b11010,
		0b11010,
		0b11110,
		0b11001,
		0b11001,
		0b11110
};

int bA_C[7] = {
		0b01110,
		0b11001,
		0b11000,
		0b11000,
		0b11000,
		0b11001,
		0b01110
};

int bA_D[7] = {
		0b11110,
		0b11001,
		0b11001,
		0b11001,
		0b11001,
		0b11001,
		0b11110
};

int bA_E[7] = {
		0b11111,
		0b11000,
		0b11000,
		0b11100,
		0b11000,
		0b11000,
		0b11111
};

int bA_F[7] = {
		0b11111,
		0b11000,
		0b11000,
		0b11110,
		0b11000,
		0b11000,
		0b11000
};

int bA_G[7] = {
		0b01110,
		0b11000,
		0b11000,
		0b11011,
		0b11001,
		0b11001,
		0b01110
};

int bA_H[7] = {
		0b11001,
		0b11001,
		0b11001,
		0b11111,
		0b11001,
		0b11001,
		0b11001
};

int bA_I[7] = {
		0b11111,
		0b01100,
		0b01100,
		0b01100,
		0b01100,
		0b01100,
		0b11111
};

int bA_J[7] = {
		0b11111,
		0b00011,
		0b00011,
		0b00011,
		0b00011,
		0b10011,
		0b01110
};
int bA_K[7] = {
		0b11001,
		0b11001,
		0b11010,
		0b11100,
		0b11010,
		0b11001,
		0b11001
};
int bA_L[7] = {
		0b01100,
		0b01100,
		0b01100,
		0b01100,
		0b01100,
		0b01101,
		0b11111
};
int bA_M[7] = {
		0b11011,
		0b11111,
		0b10101,
		0b10101,
		0b10001,
		0b10001,
		0b10001
};

int bA_N[7] = {
		0b11001,
		0b10101,
		0b10101,
		0b10101,
		0b10101,
		0b10101,
		0b10011
};

int bA_O[7] = {
		0b01110,
		0b11001,
		0b11001,
		0b11001,
		0b11001,
		0b11001,
		0b01110
};
int bA_P[7] = {
		0b11110,
		0b11001,
		0b11001,
		0b11110,
		0b11000,
		0b11000,
		0b11000
};

int bA_Q[7] = {
		0b01100,
		0b10010,
		0b10010,
		0b10010,
		0b10010,
		0b10010,
		0b01111
};

int bA_R[7] = {
		0b11110,
		0b11001,
		0b11001,
		0b11110,
		0b11001,
		0b11001,
		0b11001
};

int bA_S[7] = {
		0b01110,
		0b11001,
		0b11000,
		0b01110,
		0b00001,
		0b00001,
		0b11110
};
int bA_T[7] = {
		0b11111,
		0b01100,
		0b01100,
		0b01100,
		0b01100,
		0b01100,
		0b01100
};

int bA_U[7] = {
		0b11001,
		0b11001,
		0b11001,
		0b11001,
		0b11001,
		0b11001,
		0b01110
};

int bA_V[7] = {
		0b11001,
		0b11001,
		0b11001,
		0b11001,
		0b01010,
		0b01010,
		0b01110
};

int bA_W[7] = {
		0b10101,
		0b10101,
		0b10101,
		0b10101,
		0b10101,
		0001010,
		0b01010
};

int bA_X[7] = {
		0b11001,
		0b11001,
		0b01010,
		0b00100,
		0b01010,
		0b11001,
		0b11001
};

int bA_Y[7] = {
		0b11001,
		0b11001,
		0b11001,
		0b01110,
		0b01100,
		0b01100,
		0b01100
};

int bA_Z[7] = {
		0b11111,
		0b00010,
		0b00110,
		0b01100,
		0b11000,
		0b11000,
		0b11111
};

// Symbols

int bA_space[7] = {
		0b00000,
		0b00000,
		0b00000,
		0b00000,
		0b00000,
		0b00000,
		0b00000
};
int bA_period[7] = {
		0b00000,
		0b00000,
		0b00000,
		0b00000,
		0b00000,
		0b11000,
		0b11000
};
int bA_comma[7] = {
		0b00000,
		0b00000,
		0b00000,
		0b00000,
		0b11000,
		0b11000,
		0b01000
};
int bA_question[7] = {
		0b01110,
		0b11001,
		0b00001,
		0b01110,
		0b01100,
		0b00000,
		0b01100
};

int bA_exclamation[7] = {
		0b11000,
		0b11000,
		0b11000,
		0b11000,
		0b00000,
		0b11000,
		0b11000
};

int bA_slash[7] = {
		0b00001,
		0b00010,
		0b00010,
		0b00100,
		0b01000,
		0b01000,
		0b10000
};
int bA_plus[7] = {
		0b00000,
		0b00000,
		0b00100,
		0b01110,
		0b00100,
		0b00000,
		0b00000
};

int bA_star[7] = {
		0b00100,
		0b00100,
		0b11111,
		0b01110,
		0b01010,
		0b10001,
		0b00000
};

int bA_dash[7] = {
		0b00000,
		0b00000,
		0b00000,
		0b01110,
		0b00000,
		0b00000,
		0b00000
};

int bA_at[7] = {
		0b01110,
		0b10001,
		0b10011,
		0b10101,
		0b10111,
		0b10000,
		0b01111
};

int bA_amber[7] = {
		0b01100,
		0b11010,
		0b01100,
		0b11010,
		0b11011,
		0b11010,
		0b01101
};

int bA_colon[7] = {
		0b00000,
		0b00000,
		0b11000,
		0b11000,
		0b00000,
		0b11000,
		0b11000
};

// Digits

Char c_0 = {"0",5,7,bA_0};
Char c_1 = {"1",5,7,bA_1};
Char c_2 = {"2",5,7,bA_2};
Char c_3 = {"3",5,7,bA_3};
Char c_4 = {"4",5,7,bA_4};
Char c_5 = {"5",5,7,bA_5};
Char c_6 = {"6",5,7,bA_6};
Char c_7 = {"7",5,7,bA_7};
Char c_8 = {"8",5,7,bA_8};
Char c_9 = {"9",5,7,bA_9};

// Lower Case Letters

Char c_a = {"a",5,7,bA_a};
Char c_b = {"b",5,7,bA_b};
Char c_c = {"c",5,7,bA_c};
Char c_d = {"d",5,7,bA_d};
Char c_e = {"e",5,7,bA_e};
Char c_f = {"f",5,7,bA_f};
Char c_g = {"g",5,7,bA_g};
Char c_h = {"h",5,7,bA_h};
Char c_i = {"i",5,7,bA_i};
Char c_j = {"j",5,7,bA_j};
Char c_k = {"k",5,7,bA_k};
Char c_l = {"l",5,7,bA_l};
Char c_m = {"m",5,7,bA_m};
Char c_n = {"n",5,7,bA_n};
Char c_o = {"o",5,7,bA_o};
Char c_p = {"p",5,7,bA_p};
Char c_q = {"q",5,7,bA_q};
Char c_r = {"r",5,7,bA_r};
Char c_s = {"s",5,7,bA_s};
Char c_t = {"t",5,7,bA_t};
Char c_u = {"u",5,7,bA_u};
Char c_v = {"v",5,7,bA_v};
Char c_w = {"w",5,7,bA_w};
Char c_x = {"x",5,7,bA_x};
Char c_y = {"y",5,7,bA_y};
Char c_z = {"z",5,7,bA_z};

// Upper Case Letters

Char c_A = {"A",5,7,bA_A};
Char c_B = {"B",5,7,bA_B};
Char c_C = {"C",5,7,bA_C};
Char c_D = {"D",5,7,bA_D};
Char c_E = {"E",5,7,bA_E};
Char c_F = {"F",5,7,bA_F};
Char c_G = {"G",5,7,bA_G};
Char c_H = {"H",5,7,bA_H};
Char c_I = {"I",5,7,bA_I};
Char c_J = {"J",5,7,bA_J};
Char c_K = {"K",5,7,bA_K};
Char c_L = {"L",5,7,bA_L};
Char c_M = {"M",5,7,bA_M};
Char c_N = {"N",5,7,bA_N};
Char c_O = {"O",5,7,bA_O};
Char c_P = {"P",5,7,bA_P};
Char c_Q = {"Q",5,7,bA_Q};
Char c_R = {"R",5,7,bA_R};
Char c_S = {"S",5,7,bA_S};
Char c_T = {"T",5,7,bA_T};
Char c_U = {"U",5,7,bA_U};
Char c_V = {"V",5,7,bA_V};
Char c_W = {"W",5,7,bA_W};
Char c_X = {"X",5,7,bA_X};
Char c_Y = {"Y",5,7,bA_Y};
Char c_Z = {"Z",5,7,bA_Z};

// Symbols

Char c_space = {" ",5,7,bA_space};
Char c_period = {".",5,7,bA_period};
Char c_comma = {",",5,7,bA_comma};
Char c_question = {"?",5,7,bA_question};
Char c_exclamation = {"!",5,7,bA_exclamation};
Char c_slash = {"/",5,7,bA_slash};
Char c_plus = {"+",5,7,bA_plus};
Char c_star = {"*",5,7,bA_star};
Char c_dash = {"-",5,7,bA_dash};
Char c_at = {"@",5,7,bA_at};
Char c_amber = {"&",5,7,bA_amber};
Char c_colon = {":",5,7,bA_colon};

void font_init() {

	// Font width in 0b10000 = 16

	myFontWidth = 16;

	int i;

	// Reset font

	for(i = 0; i < 128; i++) {
		myFont[i] = 0;
	}

	// Digits

	myFont[48] = (int) &c_0;
	myFont[49] = (int) &c_1;
	myFont[50] = (int) &c_2;
	myFont[51] = (int) &c_3;
	myFont[52] = (int) &c_4;
	myFont[53] = (int) &c_5;
	myFont[54] = (int) &c_6;
	myFont[55] = (int) &c_7;
	myFont[56] = (int) &c_8;
	myFont[57] = (int) &c_9;

	// Lower Case Letters

	myFont[97] = (int) &c_a;
	myFont[98] = (int) &c_b;
	myFont[99] = (int) &c_c;
	myFont[100] = (int) &c_d;
	myFont[101] = (int) &c_e;
	myFont[102] = (int) &c_f;
	myFont[103] = (int) &c_g;
	myFont[104] = (int) &c_h;
	myFont[105] = (int) &c_i;
	myFont[106] = (int) &c_j;
	myFont[107] = (int) &c_k;
	myFont[108] = (int) &c_l;
	myFont[109] = (int) &c_m;
	myFont[110] = (int) &c_n;
	myFont[111] = (int) &c_o;
	myFont[112] = (int) &c_p;
	myFont[113] = (int) &c_q;
	myFont[114] = (int) &c_r;
	myFont[115] = (int) &c_s;
	myFont[116] = (int) &c_t;
	myFont[117] = (int) &c_u;
	myFont[118] = (int) &c_v;
	myFont[119] = (int) &c_w;
	myFont[120] = (int) &c_x;
	myFont[121] = (int) &c_y;
	myFont[122] = (int) &c_z;

	// Upper Case Letters

	myFont[65] = (int) &c_A;
	myFont[66] = (int) &c_B;
	myFont[67] = (int) &c_C;
	myFont[68] = (int) &c_D;
	myFont[69] = (int) &c_E;
	myFont[70] = (int) &c_F;
	myFont[71] = (int) &c_G;
	myFont[72] = (int) &c_H;
	myFont[73] = (int) &c_I;
	myFont[74] = (int) &c_J;
	myFont[75] = (int) &c_K;
	myFont[76] = (int) &c_L;
	myFont[77] = (int) &c_M;
	myFont[78] = (int) &c_N;
	myFont[79] = (int) &c_O;
	myFont[80] = (int) &c_P;
	myFont[81] = (int) &c_Q;
	myFont[82] = (int) &c_R;
	myFont[83] = (int) &c_S;
	myFont[84] = (int) &c_T;
	myFont[85] = (int) &c_U;
	myFont[86] = (int) &c_V;
	myFont[87] = (int) &c_W;
	myFont[88] = (int) &c_X;
	myFont[89] = (int) &c_Y;
	myFont[90] = (int) &c_Z;

	// Symbols

	myFont[32] = (int) &c_space;
	myFont[46] = (int) &c_period;
	myFont[44] = (int) &c_comma;
	myFont[63] = (int) &c_question;
	myFont[33] = (int) &c_exclamation;
	myFont[47] = (int) &c_slash;
	myFont[43] = (int) &c_plus;
	myFont[42] = (int) &c_star;
	myFont[45] = (int) &c_dash;
	myFont[64] = (int) &c_at;
	myFont[38] = (int) &c_amber;
	myFont[58] = (int) &c_colon;

}

#endif
