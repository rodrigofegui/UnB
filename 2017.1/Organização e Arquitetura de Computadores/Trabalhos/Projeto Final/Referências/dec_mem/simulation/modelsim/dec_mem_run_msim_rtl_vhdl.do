transcript on
if {[file exists rtl_work]} {
	vdel -lib rtl_work -all
}
vlib rtl_work
vmap work rtl_work

vcom -93 -work work {C:/Users/andre/Desktop/Projeto Final/Referências/dec_mem/seven_seg_decoder.vhd}
vcom -93 -work work {C:/Users/andre/Desktop/Projeto Final/Referências/dec_mem/memory.vhd}
vcom -93 -work work {C:/Users/andre/Desktop/Projeto Final/Referências/dec_mem/dec_mem.vhd}

