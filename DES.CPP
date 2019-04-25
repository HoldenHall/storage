//Holden Hall
//4-25-19
//Simple DES:
//This program takes in a key and a sentence and encrypts
//the message using bitsets, circle shifts, and permuatations.
//
#include<iomanip>
#include<string>
#include<bitset>
#include<iostream>

using namespace std;
bitset<10>p10(bitset<10> bs);
bitset<8>p8(bitset<10> bs);
bitset<4>p4(bitset<4> bs);
bitset<8>IP(bitset<8> bs);
bitset<8>Inverse_IP(bitset<4> h1, bitset<4> h2);
bitset<8>EP(bitset<4> bs);
bitset<5>left_shift_by_1(bitset<5> bs);
bitset<8>initial_get_key(bitset<10> bs);
bitset<8>two_get_key(bitset<10> bs);
bitset<8>three_get_key(bitset<10> bs);
bitset<8>four_get_key(bitset<10> bs);
bitset<8>get_round(bitset<4>h1, bitset<4>h2);
bitset<2>S0(bitset<4> bs);
bitset<2>S1(bitset<4> bs);
bitset<8> KEY;
int main()
{
	string plain_text;
	bitset<8>round_bs;
	bitset<10> bs;
	int key;

	cin >> key;
	bs = bitset<10>(key);
	bs = p10(bs);

	KEY = initial_get_key(bs);


	cin.ignore();
	getline(cin, plain_text);

	//loop to do 4 rounds for every letter
	for (int i=0;i<plain_text.length();i++)
	{
		bitset<8>letter(plain_text[i]);

		letter = IP(letter);

		bitset<4>h1;
		bitset<4>h2;

		h1[0] = letter[4];
		h1[1] = letter[5];
		h1[2] = letter[6];
		h1[3] = letter[7];

		h2[0] = letter[0];
		h2[1] = letter[1];
		h2[2] = letter[2];
		h2[3] = letter[3];


		//intial ends here
		round_bs = get_round(h1, h2);
		KEY = two_get_key(bs);
		h1[0] = round_bs[4];
		h1[1] = round_bs[5];
		h1[2] = round_bs[6];
		h1[3] = round_bs[7];

		h2[0] = round_bs[0];
		h2[1] = round_bs[1];
		h2[2] = round_bs[2];
		h2[3] = round_bs[3];
		round_bs = get_round(h1, h2);

		KEY = three_get_key(bs);

		h1[0] = round_bs[4];
		h1[1] = round_bs[5];
		h1[2] = round_bs[6];
		h1[3] = round_bs[7];


		h2[0] = round_bs[0];
		h2[1] = round_bs[1];
		h2[2] = round_bs[2];
		h2[3] = round_bs[3];

		round_bs = get_round(h1, h2);

		KEY = two_get_key(bs);

		h1[0] = round_bs[4];
		h1[1] = round_bs[5];
		h1[2] = round_bs[6];
		h1[3] = round_bs[7];

		h2[0] = round_bs[0];
		h2[1] = round_bs[1];
		h2[2] = round_bs[2];
		h2[3] = round_bs[3];

		round_bs = get_round(h1, h2);
		//flip halves then use inverse IP
		h1[0] = round_bs[0];
		h1[1] = round_bs[1];
		h1[2] = round_bs[2];
		h1[3] = round_bs[3];

		h2[0] = round_bs[4];
		h2[1] = round_bs[5];
		h2[2] = round_bs[6];
		h2[3] = round_bs[7];
		Inverse_IP(h1, h2);
		cout << hex << Inverse_IP(h1, h2).to_ulong();
	}
	

}

bitset<10>p10(bitset<10> bs)
{
	bitset<10> p_bs;
	p_bs[9] = bs[7];
	p_bs[8] = bs[5];
	p_bs[7] = bs[8];
	p_bs[6] = bs[3];
	p_bs[5] = bs[6];
	p_bs[4] = bs[0];
	p_bs[3] = bs[9];
	p_bs[2] = bs[1];
	p_bs[1] = bs[2];
	p_bs[0] = bs[4];

	return p_bs;
}

bitset<8>p8(bitset<10> bs)
{

	bitset<8> p_bs;
	p_bs[7] = bs[4];
	p_bs[6] = bs[7];
	p_bs[5] = bs[3];
	p_bs[4] = bs[6];
	p_bs[3] = bs[2];
	p_bs[2] = bs[5];
	p_bs[1] = bs[0];
	p_bs[0] = bs[1];
	return p_bs;
}

bitset<4>p4(bitset<4> bs)
{
	bitset<4> p_bs;
	p_bs[3] = bs[2];
	p_bs[2] = bs[0];
	p_bs[1] = bs[1];
	p_bs[0] = bs[3];
	return p_bs;
}
bitset<8> IP(bitset<8> bs)
{
	bitset<8> p_bs;
	p_bs[7] = bs[6];
	p_bs[6] = bs[2];
	p_bs[5] = bs[5];
	p_bs[4] = bs[7];
	p_bs[3] = bs[4];
	p_bs[2] = bs[0];
	p_bs[1] = bs[3];
	p_bs[0] = bs[1];
	return p_bs;

	return bitset<8>();
}
bitset<8>Inverse_IP(bitset<4> h1, bitset<4> h2)
{
	//put back halves
	bitset<8> bs;
	bitset<8> p_bs;
	bs[4] = h1[0];
	bs[5] = h1[1];
	bs[6] = h1[2];
	bs[7] = h1[3];

    bs[0] = h2[0];
	bs[1] = h2[1];
	bs[2] = h2[2];
	bs[3] = h2[3];
	

	p_bs[7] = bs[4];
	p_bs[6] = bs[7];
	p_bs[5] = bs[5];
	p_bs[4] = bs[3];
	p_bs[3] = bs[1];
	p_bs[2] = bs[6];
	p_bs[1] = bs[0];
	p_bs[0] = bs[2];
	return p_bs;
}
bitset<8> EP(bitset<4> bs)
{
	bitset<8> p_bs;
	p_bs[7] = bs[0];
	p_bs[6] = bs[3];
	p_bs[5] = bs[2];
	p_bs[4] = bs[1];
	p_bs[3] = bs[2];
	p_bs[2] = bs[1];
	p_bs[1] = bs[0];
	p_bs[0] = bs[3];
	return p_bs;
}
bitset<5>left_shift_by_1(bitset<5> bs)
{
	int temp = bs[4];
	bs.operator<<=(1);
	bs[0] = temp;
	return bs;
}

bitset<8>initial_get_key(bitset<10> bs)
{
	bitset<8> key;
	//split
	bitset<5>h1;
	bitset<5>h2;
	h1[0] = bs[5];
	h1[1] = bs[6];
	h1[2] = bs[7];
	h1[3] = bs[8];
	h1[4] = bs[9];

	h2[0] = bs[0];
	h2[1] = bs[1];
	h2[2] = bs[2];
	h2[3] = bs[3];
	h2[4] = bs[4];


	h1 = left_shift_by_1(h1);
	h2 = left_shift_by_1(h2);


	//put back together
	bs[5] = h1[0];
	bs[6] = h1[1];
	bs[7] = h1[2];
	bs[8] = h1[3];
	bs[9] = h1[4];

	bs[0] = h2[0];
	bs[1] = h2[1];
	bs[2] = h2[2];
	bs[3] = h2[3];
	bs[4] = h2[4];

	key = p8(bs);

	return key;
}

bitset<8>two_get_key(bitset<10> bs)
{
	bitset<8> key;
	//split
	bitset<5>h1;
	bitset<5>h2;
	h1[0] = bs[5];
	h1[1] = bs[6];
	h1[2] = bs[7];
	h1[3] = bs[8];
	h1[4] = bs[9];

	h2[0] = bs[0];
	h2[1] = bs[1];
	h2[2] = bs[2];
	h2[3] = bs[3];
	h2[4] = bs[4];

	h1 = left_shift_by_1(h1);
	h1 = left_shift_by_1(h1);
	h1 = left_shift_by_1(h1);
	h2 = left_shift_by_1(h2);
	h2 = left_shift_by_1(h2);
	h2 = left_shift_by_1(h2);

	bs[5] = h1[0];
	bs[6] = h1[1];
	bs[7] = h1[2];
	bs[8] = h1[3];
	bs[9] = h1[4];

	bs[0] = h2[0];
	bs[1] = h2[1];
	bs[2] = h2[2];
	bs[3] = h2[3];
	bs[4] = h2[4];


	key = p8(bs);

	return key;
}

bitset < 8>three_get_key(bitset<10> bs)
{
	bitset<8> key;
	//split
	bitset<5>h1;
	bitset<5>h2;
	h1[0] = bs[5];
	h1[1] = bs[6];
	h1[2] = bs[7];
	h1[3] = bs[8];
	h1[4] = bs[9];

	h2[0] = bs[0];
	h2[1] = bs[1];
	h2[2] = bs[2];
	h2[3] = bs[3];
	h2[4] = bs[4];


	h1 = left_shift_by_1(h1);
	h1 = left_shift_by_1(h1);
	h1 = left_shift_by_1(h1);
	h1 = left_shift_by_1(h1);
	h2 = left_shift_by_1(h2);
	h2 = left_shift_by_1(h2);
	h2 = left_shift_by_1(h2);
	h2 = left_shift_by_1(h2);

	//put back together
	bs[5] = h1[0];
	bs[6] = h1[1];
	bs[7] = h1[2];
	bs[8] = h1[3];
	bs[9] = h1[4];

	bs[0] = h2[0];
	bs[1] = h2[1];
	bs[2] = h2[2];
	bs[3] = h2[3];
	bs[4] = h2[4];

	key = p8(bs);
	return key;
}

bitset < 8>four_get_key(bitset<10> bs)
{
	bitset<8> key;
	//split
	bitset<5>h1;
	bitset<5>h2;
	h1[0] = bs[5];
	h1[1] = bs[6];
	h1[2] = bs[7];
	h1[3] = bs[8];
	h1[4] = bs[9];

	h2[0] = bs[0];
	h2[1] = bs[1];
	h2[2] = bs[2];
	h2[3] = bs[3];
	h2[4] = bs[4];

	h1 = left_shift_by_1(h1);
	h1 = left_shift_by_1(h1);
	h1 = left_shift_by_1(h1);
	h1 = left_shift_by_1(h1);
	h1 = left_shift_by_1(h1);
	h1 = left_shift_by_1(h1);
	h2 = left_shift_by_1(h2);
	h2 = left_shift_by_1(h2);
	h2 = left_shift_by_1(h2);
	h2 = left_shift_by_1(h2);
	h2 = left_shift_by_1(h2);
	h2 = left_shift_by_1(h2);


	//put back together
	bs[5] = h1[0];
	bs[6] = h1[1];
	bs[7] = h1[2];
	bs[8] = h1[3];
	bs[9] = h1[4];

	bs[0] = h2[0];
	bs[1] = h2[1];
	bs[2] = h2[2];
	bs[3] = h2[3];
	bs[4] = h2[4];

	key = p8(bs);
	return key;
}

bitset<2> S0(bitset<4> bs)
{
	bitset<2>result;
	bitset<2>row;
	row[0] = bs[0];
	row[1] = bs[3];
	bitset<2>col;
	col[0] = bs[1];
	col[1] = bs[2];
	int s_table[4][4];
	s_table[0][0] = 1;
	s_table[0][1] = 0;
	s_table[0][2] = 3;
	s_table[0][3] = 2;
	s_table[1][0] = 3;
	s_table[1][1] = 2;
	s_table[1][2] = 1;
	s_table[1][3] = 0;
	s_table[2][0] = 0;
	s_table[2][1] = 2;
	s_table[2][2] = 1;
	s_table[2][3] = 3;
	s_table[3][0] = 3;
	s_table[3][1] = 1;
	s_table[3][2] = 0;
	s_table[3][3] = 2;

	result = bitset<2>(s_table[(int)row.to_ulong()][(int)col.to_ulong()]);
	return result;
}

bitset<2> S1(bitset<4> bs)
{
	bitset<2>result;
	bitset<2>row;
	row[0] = bs[0];
	row[1] = bs[3];

	bitset<2>col;
	col[0] = bs[1];
	col[1] = bs[2];

	int s_table[4][4];
	s_table[0][0] = 0;
	s_table[0][1] = 1;
	s_table[0][2] = 2;
	s_table[0][3] = 3;
	s_table[1][0] = 2;
	s_table[1][1] = 0;
	s_table[1][2] = 1;
	s_table[1][3] = 3;
	s_table[2][0] = 3;
	s_table[2][1] = 0;
	s_table[2][2] = 1;
	s_table[2][3] = 2;
	s_table[3][0] = 2;
	s_table[3][1] = 1;
	s_table[3][2] = 0;
	s_table[3][3] = 3;

	result = bitset<2>(s_table[(int)row.to_ulong()][(int)col.to_ulong()]);
	return result;
}

bitset<8>get_round(bitset<4>h1, bitset<4>h2)
{
	bitset<8> EP_set;

	EP_set = EP(h2);

	//xor EP with key
	//if round is odd
	for (int i = 0; i < 8; i++)
	{
		//EP_set[i] = EP_set[i] ^ odd_key[i];
		EP_set[i] = EP_set[i] ^ KEY[i];
	}

	bitset<4>h2_1;
	bitset<4>h2_2;
	h2_1[0] = EP_set[4];
	h2_1[1] = EP_set[5];
	h2_1[2] = EP_set[6];
	h2_1[3] = EP_set[7];

	h2_2[0] = EP_set[0];
	h2_2[1] = EP_set[1];
	h2_2[2] = EP_set[2];
	h2_2[3] = EP_set[3];

	bitset<4>P4_set;
	bitset<2>S0_set;
	bitset<2>S1_set;
	S0_set = S0(h2_1);
	S1_set = S1(h2_2);

	//p4 permutation
	P4_set[3] = S0_set[1];
	P4_set[2] = S0_set[0];
	P4_set[1] = S1_set[1];
	P4_set[0] = S1_set[0];
	P4_set = p4(P4_set);

	//xor with left side from beginning
	for (int i = 0; i < 4; i++)
	{
		P4_set[i] = P4_set[i] ^ h1[i];
	}

	bitset<8>round;
	round[7] = h2[3];
	round[6] = h2[2];
	round[5] = h2[1];
	round[4] = h2[0];
	round[3] = P4_set[3];
	round[2] = P4_set[2];
	round[1] = P4_set[1];
	round[0] = P4_set[0];

	return round;
}
