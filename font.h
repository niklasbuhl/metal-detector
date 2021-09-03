#ifndef FONT_H_
#define FONT_H_

#define FONT_H 7

typedef struct {

	char* c;

	int cWidth;
	int cHeight;

	int* cBitArray;

} Char;

int myFont[128];
int myFontWidth;

void font_init();

Char c_0;
Char c_1;
Char c_2;
Char c_3;
Char c_4;
Char c_5;
Char c_6;
Char c_7;
Char c_8;
Char c_9;

Char c_a;
Char c_b;
Char c_c;
Char c_d;
Char c_e;
Char c_f;
Char c_g;
Char c_h;
Char c_i;
Char c_j;
Char c_k;
Char c_l;
Char c_m;
Char c_n;
Char c_o;
Char c_p;
Char c_q;
Char c_r;
Char c_s;
Char c_t;
Char c_u;
Char c_v;
Char c_w;
Char c_x;
Char c_y;
Char c_z;

Char c_A;
Char c_B;
Char c_C;
Char c_D;
Char c_F;
Char c_G;
Char c_H;
Char c_I;
Char c_J;
Char c_K;
Char c_L;
Char c_M;
Char c_N;
Char c_O;
Char c_P;
Char c_Q;
Char c_R;
Char c_S;
Char c_T;
Char c_U;
Char c_V;
Char c_W;
Char c_X;
Char c_Y;
Char c_Z;

Char c_space;
Char c_period;
Char c_comma;
Char c_question;
Char c_exclamation;
Char c_slash;
Char c_plus;
Char c_star;
Char c_dash;
Char c_at;
Char c_colon;
Char c_amber;

#endif
