--Módulo de controle do processador, com sinais de controle para funcionamento dos demais módulos.
--Define os sinais de controle de acordo com opcode
library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity controle is
	port (
		opcode : in std_logic_vector (5 downto 0);
		RegDst : out std_logic_vector (1 downto 0);
		Jump : out std_logic;
		Jal : out std_logic;
		Branch : out std_logic;
		Bne : out std_logic;
		MemtoReg : out std_logic;
		ALUOp : out std_logic_vector (2 downto 0);
		MemWrite : out std_logic;
		ALUSrc : out std_logic;
		RegWrite : out std_logic);
end entity controle;

architecture Behavioral of controle is

begin

	process(opcode)
	begin
		case opcode is
			--lw
			when "100011" =>
				RegDst <= "00";
				Jump <= '0';
				Jal <= '0';
				Branch <= '0';
				Bne <= '0';
				MemtoReg <= '1';
				ALUOp <= "010";
				MemWrite <= '0';
				ALUSrc <= '1';
				RegWrite <= '1';
			
			--sw
			when "101011" =>
				RegDst <= "00";
				Jump <= '0';
				Jal <= '0';
				Branch <= '0';
				Bne <= '0';
				MemtoReg <= '0';
				ALUOp <= "000";
				MemWrite <= '1';
				ALUSrc <= '1';
				RegWrite <= '0';

			--tipo R
			when "000000" =>
				RegDst <= "01";
				Jump <= '0';
				Jal <= '0';
				Branch <= '0';
				Bne <= '0';
				MemtoReg <= '0';
				ALUOp <= "010";
				MemWrite <= '0';
				ALUSrc <= '0';
				RegWrite <= '1';
				
			--addi
			when "001000" =>
				RegDst <= "00";
				Jump <= '0';
				Jal <= '0';
				Branch <= '0';
				Bne <= '0';
				MemtoReg <= '0';
				ALUOp <= "011";
				MemWrite <= '0';
				ALUSrc <= '1';
				RegWrite <= '1';

			--andi
			when "001100" =>
				RegDst <= "00";
				Jump <= '0';
				Jal <= '0';
				Branch <= '0';
				Bne <= '0';
				MemtoReg <= '0';
				ALUOp <= "100";
				MemWrite <= '0';
				ALUSrc <= '1';
				RegWrite <= '1';

			--ori
			when "001101" =>
				RegDst <= "00";
				Jump <= '0';
				Jal <= '0';
				Branch <= '0';
				Bne <= '0';
				MemtoReg <= '0';
				ALUOp <= "101";
				MemWrite <= '0';
				ALUSrc <= '1';
				RegWrite <= '1';
				
			--xori
			when "001110" =>
				RegDst <= "00";
				Jump <= '0';
				Jal <= '0';
				Branch <= '0';
				Bne <= '0';
				MemtoReg <= '0';
				ALUOp <= "110";
				MemWrite <= '0';
				ALUSrc <= '1';
				RegWrite <= '1';
				
			--slti
			when "001010" =>
				RegDst <= "00";
				Jump <= '0';
				Jal <= '0';
				Branch <= '0';
				Bne <= '0';
				MemtoReg <= '0';
				ALUOp <= "111";
				MemWrite <= '0';
				ALUSrc <= '1';
				RegWrite <= '1';
				
			--j
			when "000010" =>
				RegDst <= "00";
				Jump <= '1';
				Jal <= '0';
				Branch <= '0';
				Bne <= '0';
				MemtoReg <= '0';
				ALUOp <= "010";
				MemWrite <= '0';
				ALUSrc <= '0';
				RegWrite <= '0';
			
			--jal
			when "000011" =>
				RegDst <= "10";
				Jump <= '1';
				Jal <= '1';
				Branch <= '0';
				Bne <= '0';
				MemtoReg <= '0';
				ALUOp <= "010";
				MemWrite <= '0';
				ALUSrc <= '0';
				RegWrite <= '1';
				
			--beq
			when "000100" =>
				RegDst <= "00";
				Jump <= '0';
				Jal <= '0';
				Branch <= '1';
				Bne <= '0';
				MemtoReg <= '0';
				ALUOp <= "001";
				MemWrite <= '0';
				ALUSrc <= '0';
				RegWrite <= '0';
				
			--bne
			when "000101" =>
				RegDst <= "00";
				Jump <= '0';
				Jal <= '0';
				Branch <= '1';
				Bne <= '0';
				MemtoReg <= '0';
				ALUOp <= "001";
				MemWrite <= '0';
				ALUSrc <= '0';
				RegWrite <= '0';
		
			when others => null;

		end case;

	end process;
	
end Behavioral;
