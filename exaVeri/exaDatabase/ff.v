module ffex(input [size_in-1:0]d, input clk,reset,output [size_in-1:0]q);

parameter size_in=2;
reg [size_in-1:0]q1;
assign q=q1;
reg [size_in-1:0]q2;

always@(posedge clk,posedge reset)
	begin
	if(reset)
	begin 
		q1<=0;
		q2<=0;
	end
	else
	begin
		q1<=d;
		q2<=q1;
	end
	
	end
endmodule
