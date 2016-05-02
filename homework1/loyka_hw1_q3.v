//Kyle Loyka
//ECEN 449 - 503
//Homework 1
//Question 3

`timescale 1ns/1ps

module q3(
	input A,
	input B,
	input C,
	input D,
	output f
	);

	/* internal nets */
	wire e,u,g,h,j,k,m,n,p,q,r,s,t;

	// A*B
	nand n0(e,A,B);
	nand n1(u,e,e); // u = A*B

	// C*D*B
	nand n2(g,C,D);
	nand n3(h,g,B);
	nand n4(j,h,h); // j = C*D*B

	// ~C
	nand n5(k,C,C); // k = ~C

	// A*~C
	nand n6(m,A,k);
	nand n7(n,m,m);	// n = A*~C

	// (AB) + (CDB)
	nand n8(p,u,u);
	nand n9(q,j,j);
	nand n10(r,q,p);	// r = [AB + BCD]

	// [(AB) + (CDB)] + (A*~C)
	nand n11(s,n,n);
	nand n12(t,r,r);
	nand n13(f,s,t);	// f = AB + CBD + A*~C

endmodule
