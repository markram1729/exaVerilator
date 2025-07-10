module add(input [L-1:0]a,[L-1:0]b,output [E-1:0] c);

parameter L=4;
parameter E=5;

assign c = a+b;

endmodule
