exHOME=$(VERILATOR_ROOT)/..
V_BIN=${VERILATOR_ROOT}/bin/verilator
DESIGN=${exHOME}/exaDatabase
VERI_HEAD=${VERILATOR_ROOT}/include

add : add.cpp ${DESIGN}/add.v
	${V_BIN} --cc -I${VERI_HEAD} --build $^



ff : ff.cpp ${DESIGN}/ff.v
	${V_BIN} --cc -I${VERI_HEAD} --build $^ -trace-vcd --exe


