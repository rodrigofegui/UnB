.data
ari: 	.word	1 2 3 4 5

.text
	addi 	$t0, $zero, 15	# testa addi 	=> t0 = 15  0xF
	addi	$t1, $zero, 37	#		=> t1 = 37  0x25
	add	$t2, $t0, $t1	# testa add	=> t2 = 52  0x34 falha
	add	$t2, $t0, $t1	# testa add	=> t2 = 52  0x34 falha
	add	$t2, $t0, $t1	# testa add	=> t2 = 52  0x34 falha
	add	$t2, $t0, $t1	# testa add	=> t2 = 52  0x34 OK
	sub	$t3, $t1, $t0	# testa sub	=> t3 = 12  0x16
	and	$t4, $t1, $t0 	# testa and	=> t4 = 5   0x5
	or 	$t5, $t1, $t0	# testa or	=> t5 = 47  0x2F
	nor	$t6, $t1, $t0	# testa nor	=> t6 = -48 0xFFFFFFD0
	xor	$t7, $t1, $t0	# testa xor	=> t7 = 42  0x2A
	slt	$s0, $t1, $t0	# testa slt	=> s0 = 0
	bne	$s0, $zero, 	PrimPulo	# falha
	slt	$s1, $t0, $t1	# testa slt	=> s1 = 1
	nop 
	nop 
	nop
	bne	$s1, $zero, PrimPulo	# salta
	nop
PrimVolta:
	jal	SubRot
	nop
	j	FIM
	nop
PrimPulo:
	beq 	$s1, $zero, FIM # falha
	nop
	j	PrimVolta	
SubRot:
	sll	$s2, $t0, 4	# testa sll	=> s2 = 240 0xF0
	srl	$s3, $t6, 1	# testa srl	=> s3 = 2147483624 0x7fffffe8
	sra	$s4, $t6, 1	# testa sra	=> s4 = -24 0xffffffe8
	jr	$ra
	nop
FIM:
	la	$s5, ari
	nop
	nop
	nop
	lw	$s6, 0($s5)
	lw 	$s7, 4($s5)
	sw	$t4, 8($s5) 
