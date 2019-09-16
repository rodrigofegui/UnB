----------------------------------------------------------------------------------
-- Organizacao e Arquitetura de Computadores
-- Professor: Marcelo Grandi Mandelli
-- Responsaveis:			Danillo Neves
--								Luiz Gustavo
--								Rodrigo Guimaraes
----------------------------------------------------------------------------------

--MÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Â ÃƒÂ¢Ã¢â€šÂ¬Ã¢â€žÂ¢ÃƒÆ’Ã†â€™ÃƒÂ¢Ã¢â€šÂ¬Ã‚Â ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â‚¬Å¡Ã‚Â¬ÃƒÂ¢Ã¢â‚¬Å¾Ã‚Â¢ÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â‚¬Å¡Ã‚Â¬Ãƒâ€šÃ‚Â ÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â¢ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â€šÂ¬Ã…Â¡Ãƒâ€šÃ‚Â¬ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â€šÂ¬Ã…Â¾Ãƒâ€šÃ‚Â¢ÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Â ÃƒÂ¢Ã¢â€šÂ¬Ã¢â€žÂ¢ÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â¢ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â€šÂ¬Ã…Â¡Ãƒâ€šÃ‚Â¬ÃƒÆ’Ã¢â‚¬Â¦Ãƒâ€šÃ‚Â¡ÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â‚¬Å¡Ã‚Â¬Ãƒâ€¦Ã‚Â¡ÃƒÆ’Ã†â€™ÃƒÂ¢Ã¢â€šÂ¬Ã…Â¡ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â³dulo principal do processador uniciclo, fazendo a uniÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Â ÃƒÂ¢Ã¢â€šÂ¬Ã¢â€žÂ¢ÃƒÆ’Ã†â€™ÃƒÂ¢Ã¢â€šÂ¬Ã‚Â ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â‚¬Å¡Ã‚Â¬ÃƒÂ¢Ã¢â‚¬Å¾Ã‚Â¢ÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â‚¬Å¡Ã‚Â¬Ãƒâ€šÃ‚Â ÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â¢ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â€šÂ¬Ã…Â¡Ãƒâ€šÃ‚Â¬ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â€šÂ¬Ã…Â¾Ãƒâ€šÃ‚Â¢ÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Â ÃƒÂ¢Ã¢â€šÂ¬Ã¢â€žÂ¢ÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â¢ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â€šÂ¬Ã…Â¡Ãƒâ€šÃ‚Â¬ÃƒÆ’Ã¢â‚¬Â¦Ãƒâ€šÃ‚Â¡ÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â‚¬Å¡Ã‚Â¬Ãƒâ€¦Ã‚Â¡ÃƒÆ’Ã†â€™ÃƒÂ¢Ã¢â€šÂ¬Ã…Â¡ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â£o dos mÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Â ÃƒÂ¢Ã¢â€šÂ¬Ã¢â€žÂ¢ÃƒÆ’Ã†â€™ÃƒÂ¢Ã¢â€šÂ¬Ã‚Â ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â‚¬Å¡Ã‚Â¬ÃƒÂ¢Ã¢â‚¬Å¾Ã‚Â¢ÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â‚¬Å¡Ã‚Â¬Ãƒâ€šÃ‚Â ÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â¢ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â€šÂ¬Ã…Â¡Ãƒâ€šÃ‚Â¬ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â€šÂ¬Ã…Â¾Ãƒâ€šÃ‚Â¢ÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Â ÃƒÂ¢Ã¢â€šÂ¬Ã¢â€žÂ¢ÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â¢ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â€šÂ¬Ã…Â¡Ãƒâ€šÃ‚Â¬ÃƒÆ’Ã¢â‚¬Â¦Ãƒâ€šÃ‚Â¡ÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â‚¬Å¡Ã‚Â¬Ãƒâ€¦Ã‚Â¡ÃƒÆ’Ã†â€™ÃƒÂ¢Ã¢â€šÂ¬Ã…Â¡ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â³dulos componentes
library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity uniciclo is
	generic(DATA_WIDTH	:	natural	:=	32;
			  ADDRESS_WIDTH:	natural	:=	5);
	port (clk, rst : in std_logic := '1';
			SW  : in std_logic_vector(13 downto 0);
			HEX0, HEX1, HEX2, HEX3, HEX4, HEX5, HEX6, HEX7: out std_logic_vector(6 downto 0));
end entity uniciclo;

architecture Behavioral of uniciclo is

signal aux_switch : std_logic_vector(1 downto 0);
signal HEX0_pc, HEX1_pc, HEX2_pc, HEX3_pc, HEX4_pc, HEX5_pc, HEX6_pc, HEX7_pc: std_logic_vector(6 downto 0);
signal HEX0_mi, HEX1_mi, HEX2_mi, HEX3_mi, HEX4_mi, HEX5_mi, HEX6_mi, HEX7_mi: std_logic_vector(6 downto 0);
signal HEX0_reg, HEX1_reg, HEX2_reg, HEX3_reg, HEX4_reg, HEX5_reg, HEX6_reg, HEX7_reg: std_logic_vector(6 downto 0);
signal HEX0_md, HEX1_md, HEX2_md, HEX3_md, HEX4_md, HEX5_md, HEX6_md, HEX7_md: std_logic_vector(6 downto 0);

signal display, result_soma1, result_soma2, md_out : std_logic_vector(31 downto 0);
signal result_mux_branch, result_mux_jump : std_logic_vector(31 downto 0);
signal pc_in, pc_out, mi_out, rdata1, rdata2, rdata3, imediato_shift, imediato_shift_desloc, shamt_shift, mux_jump_in : std_logic_vector(31 downto 0);
signal opcode : std_logic_vector(5 downto 0);
signal wdata : std_logic_vector(31 downto 0);
signal wadd: std_logic_vector(4 downto 0);

signal beq_and_z, bne_and_notz, beq_or_bne : std_logic;
signal jump_jr : std_logic;

signal ulain : std_logic_vector(31 downto 0);
signal saida_mux_mem : std_logic_vector(31 downto 0);
signal ulaout : std_logic_vector(31 downto 0);
signal zero : std_logic := '0';
signal ctrl_alu : std_logic_vector(3 downto 0);
signal saida_mux_ula :  std_logic_vector(31 downto 0);

signal nro_4 : std_logic_vector(31 downto 0):=x"00000004";
signal ra : std_logic_vector(4 downto 0):="11111";

--sinais de controle
signal RegDst : std_logic_vector(1 downto 0);
signal ALUOp : std_logic_vector (2 downto 0);
signal Jump, Jal, Branch, Bne, MemtoReg, MemWrite, ALUSrc, RegWrite : std_logic;

begin
	contador_programa: entity work.PC port map(clk => clk, rst => rst, add_in => pc_in, add_out => pc_out);
	
	soma1: entity work.somador port map(dataIn1 => pc_out, dataIn2 => nro_4,	dataOut => result_soma1);
	
	mi: entity work.mi port map(clk => clk, address	=> pc_out(8 downto 2), instruction => mi_out);
	
	controle: entity work.controle port map(opcode => mi_out(31 downto 26) , RegDst => RegDst , Jump => Jump, Jal => Jal,
										Branch => Branch, Bne => Bne, MemtoReg => MemtoReg , ALUOp => ALUOp,
										MemWrite => MemWrite, ALUSrc => ALUSrc, RegWrite => RegWrite);
	
	mux1: entity work.mux_5bits port map(sel	=> RegDst, dataIn1 => mi_out(20 downto 16), dataIn2 => mi_out(15 downto 11),
									dataIn3 => ra, dataOut => wadd);
	
	breg: entity work.reg_bank port map(clk => clk, wren => RegWrite, radd1 => mi_out(25 downto 21), radd2 => mi_out(20 downto 16),
													radd3 => SW(6 downto 2) ,wadd => wadd,
													wdata => wdata,
													rdata1 => rdata1, rdata2 => rdata2, rdata3 => rdata3);
								
										
	mux_ula: entity work.mux2 port map(sel	=> ALUSrc, dataIn1 => rdata2, dataIn2 => imediato_shift,
													dataOut => saida_mux_ula);
							 
	ula_controle: entity work.controleAlu port map(funct   => mi_out(5 downto 0),
													ALUOp  => ALUOp,
													CTRLOut => ctrl_alu,
													Jr => jump_jr);
							 
	ula: entity work.alu port map(input1 => rdata1, input2 => saida_mux_ula, input3 => shamt_shift, operation => ctrl_alu,
							output => ulaout, zero => zero);
							
	mem_data: entity work.md port map(clk => clk, 
			we => MemWrite,
			adr => ulaout(8 downto 2),
			din => rdata2,
			dout => md_out);
	
	mux_mem: entity work.mux2 port map(sel	=> MemtoReg, dataIn1 => ulaout, dataIn2 => md_out,
							 dataOut => saida_mux_mem);
							 
	soma2: entity work.somador port map(dataIn1 => result_soma1, dataIn2 => imediato_shift_desloc, dataOut => result_soma2);
							 
	mux_branch: entity work.mux2 port map(sel	=> beq_or_bne, dataIn1 => result_soma1, dataIn2 => result_soma2,
							 dataOut => result_mux_branch);
					
	mux_jump: entity work.mux2 port map(sel	=> Jump, dataIn1 => result_mux_branch, dataIn2 => mux_jump_in,
													dataOut => result_mux_jump);
	
	mux_jr: entity work.mux2 port map(sel	=> jump_jr, dataIn1 => result_mux_jump, dataIn2 => rdata1,
												dataOut => pc_in);
							 
	mux_jal: entity work.mux2 port map(sel	=> Jal, dataIn1 => saida_mux_mem, dataIn2 => result_soma1,
							 dataOut => wdata);
							 
	dec1 : entity work.dec_pc port map(clk => clk, rst => rst, SW => pc_out,
													HEX0 	=>HEX0_pc,
													HEX1 	=>HEX1_pc,
													HEX2 	=>HEX2_pc,
													HEX3 	=>HEX3_pc,
													HEX4 	=>HEX4_pc,
													HEX5 	=>HEX5_pc,
													HEX6 	=>HEX6_pc,
													HEX7 	=>HEX7_pc);
			
	dec2 : entity work.dec_mi port map(clk => clk, SW => pc_out(8 downto 2),
													HEX0 	=>HEX0_mi,
													HEX1 	=>HEX1_mi,
													HEX2 	=>HEX2_mi,
													HEX3 	=>HEX3_mi,
													HEX4 	=>HEX4_mi,
													HEX5 	=>HEX5_mi,
													HEX6 	=>HEX6_mi,
													HEX7 	=>HEX7_mi);

	dec3 : entity work.dec_reg port map(clk => clk, SW => SW(6 downto 2),
													HEX0 	=>HEX0_reg,
													HEX1 	=>HEX1_reg,
													HEX2 	=>HEX2_reg,
													HEX3 	=>HEX3_reg,
													HEX4 	=>HEX4_reg,
													HEX5 	=>HEX5_reg,
													HEX6 	=>HEX6_reg,
													HEX7 	=>HEX7_reg);
			
	dec4 : entity work.dec_mem port map(clk => clk, SW => SW(13 downto 7),
			HEX0 	=>HEX0_md,
			HEX1 	=>HEX1_md,
			HEX2 	=>HEX2_md,
			HEX3 	=>HEX3_md,
			HEX4 	=>HEX4_md,
			HEX5 	=>HEX5_md,
			HEX6 	=>HEX6_md,
			HEX7 	=>HEX7_md);

	--definicao de alguns sinais intermediarios
	mux_jump_in <= result_soma1(31 downto 28)&mi_out(25 downto 0)&"00";
	beq_and_z <= Branch and zero;
	bne_and_notz <= Branch and not(zero);
	beq_or_bne <= beq_and_z or bne_and_notz;
	imediato_shift <= x"0000"&(mi_out(15 downto 0)) when mi_out(15)='0' else x"ffff"&(mi_out(15 downto 0)) when mi_out(15)='1';
	imediato_shift_desloc <= imediato_shift(29 downto 0)&"00";
	shamt_shift <= "000000000000000000000000000" & (mi_out(10 downto 6)) when mi_out(10)='0' else
						"111111111111111111111111111" & (mi_out(10 downto 6)) when mi_out(10)='1';

	aux_switch <= SW(1 downto 0);
	
	HEX0 	<= HEX0_pc when aux_switch <= "00" else
				HEX0_mi when aux_switch <= "01" else
				HEX0_reg when aux_switch <= "10" else
				HEX0_md when aux_switch <= "11";
	HEX1 	<=HEX1_pc when aux_switch <= "00" else
				HEX1_mi when aux_switch <= "01" else
				HEX1_reg when aux_switch <= "10" else
				HEX1_md when aux_switch <= "11";
	HEX2 	<=HEX2_pc when aux_switch <= "00" else
				HEX2_mi when aux_switch <= "01" else
				HEX2_reg when aux_switch <= "10" else
				HEX2_md when aux_switch <= "11";
	HEX3 	<=HEX3_pc when aux_switch <= "00" else
				HEX3_mi when aux_switch <= "01" else
				HEX3_reg when aux_switch <= "10" else
				HEX3_md when aux_switch <= "11";
	HEX4 	<=HEX4_pc when aux_switch <= "00" else
				HEX4_mi when aux_switch <= "01" else
				HEX4_reg when aux_switch <= "10" else
				HEX4_md when aux_switch <= "11";
	HEX5 	<=HEX5_pc when aux_switch <= "00" else
				HEX5_mi when aux_switch <= "01" else
				HEX5_reg when aux_switch <= "10" else
				HEX5_md when aux_switch <= "11";
	HEX6 	<=HEX6_pc when aux_switch <= "00" else
				HEX6_mi when aux_switch <= "01" else
				HEX6_reg when aux_switch <= "10" else
				HEX6_md when aux_switch <= "11";
	HEX7 	<=HEX7_pc when aux_switch <= "00" else
				HEX7_mi when aux_switch <= "01" else
				HEX7_reg when aux_switch <= "10" else
				HEX7_md when aux_switch <= "11";
end Behavioral;
