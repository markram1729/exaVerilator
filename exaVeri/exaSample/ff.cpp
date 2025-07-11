
#include <iostream>
#include "Vff.h"
#include <verilated.h>
#include <vector>
#include "verilated_vcd_c.h"
#include "verilated_types.h"

using Vmodule = Vff;

template <typename T>
void printCon(std::vector<T> vec)
{
	for(auto i: vec)
	 {
		std::cout<<std::hex<<i<<std::endl; // Temporary for hex values 
	 }
}

int main(int argc, char* argv[])
{
	const std::unique_ptr<VerilatedContext> exCon{new VerilatedContext};
	exCon->commandArgs(argc,argv);
	const std::unique_ptr<Vmodule> extop{new Vmodule};

	std::vector<uint8_t> marka={0x0,0x1,0x2,0x3,0x0};
	Verilated::traceEverOn(true);
	VerilatedVcdC* tracein=nullptr;
	const char *stinf=exCon->commandArgsPlusMatch("trace");
	if(stinf && std::strcmp(stinf,"trace"))
	 {
		tracein = new VerilatedVcdC;
		extop->trace(tracein,5); // 5 is depth 
		tracein->open("ffd.vcd");
	 }
	size_t iterations = 400;
	extop->clk=0;
	extop->reset=0;
	std::srand(1);
	size_t somer=marka.size();
	for(size_t i=0;i<iterations;i++)
	 {
		exCon->timeInc(1);
		if(i==5)
		 {
			extop->reset=1;
			extop->d = marka[std::rand()%somer];
		 }
		if(i==10) extop->reset=0;
		if(extop->clk)
		 {
			extop->d = marka[std::rand()%somer];
		 }
		if(i%3==0)
		 {
			extop->clk=!extop->clk;
			extop->eval();
		 }
		if(tracein)tracein->dump(exCon->time());
	 }
	extop->final();

	if(tracein)
	 {
		tracein->close();
		tracein=nullptr;
	 }
	exCon->statsPrintSummary();
	return 0;
}
