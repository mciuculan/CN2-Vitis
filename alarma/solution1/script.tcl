############################################################
## This file is generated automatically by Vitis HLS.
## Please DO NOT edit it.
## Copyright 1986-2021 Xilinx, Inc. All Rights Reserved.
############################################################
open_project alarma
set_top alarma
add_files alarma/alarma.cpp
add_files -tb alarma/alarma_test.h -cflags "-Wno-unknown-pragmas" -csimflags "-Wno-unknown-pragmas"
add_files -tb alarma/alarma_test.cpp -cflags "-Wno-unknown-pragmas" -csimflags "-Wno-unknown-pragmas"
open_solution "solution1" -flow_target vivado
set_part {xc7a100t-csg324-1}
create_clock -period 10 -name default
#source "./alarma/solution1/directives.tcl"
csim_design
csynth_design
cosim_design
export_design -format ip_catalog
