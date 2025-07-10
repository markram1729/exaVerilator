#include <iostream>
#include "Vadd.h"
#include <verilated.h>
#include <vector>


using Vmodule = Vadd;

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
	VerilatedContext* const exCon = new VerilatedContext;

	exCon->commandArgs(argc,argv);
	Vmodule* const extop = new Vmodule;

	std::vector<uint8_t> marka={0x2,0x3,0xf,0x5,0x6};
	std::vector<uint8_t> markb={0x4,0x5,0x6,0x7,0x8};
	std::vector<uint8_t> markc;
	size_t iterations = marka.size();

	for(size_t i=0;i<iterations;i++)
	 {
	      extop->a = marka[i];
	      extop->b = markb[i];
	      extop->eval();
	      markc.push_back(extop->c);
	 }
	printCon<uint8_t>(markc);
	return 0;
}
