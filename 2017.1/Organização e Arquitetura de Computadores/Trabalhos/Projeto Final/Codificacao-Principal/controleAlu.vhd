--Módulo para controle da ULA. Definirá a operação a ser realizada pela ula, e também identifica se deve ocorrer JR
library	ieee;
use	ieee.std_logic_1164.all;
use	ieee.numeric_std.all;

entity controleAlu is
	port(
	  funct   : in std_logic_vector(5 downto 0);
	  ALUOp  : in std_logic_vector(2 downto 0);
	  CTRLOut : out std_logic_vector(3 downto 0);
	  Jr : out std_logic
	  );
end controleAlu;

architecture Behavioral of controleAlu is

signal aux : std_logic_vector(3 downto 0);

begin

CTRLOut <= aux;

process (funct, ALUOp, aux)
begin
	Jr <= '0';
  case ALUOp is
		when "000" => -- LW e SW
			aux <= "0010"; -- ADD
		when "001" => -- BEQ e BNE
			aux <= "0011"; -- SUB
		when "010" =>
			case funct is
				when "100000" =>
					aux <= "0010"; -- ADD
				when "100010" =>
					aux <= "0011"; -- SUB
				when "100100" =>
					aux <= "0000"; -- AND
				when "100101" =>
					aux <= "0001"; -- OR
				when "101010" =>
					aux <= "0100"; -- SLT
				when "100111" =>
					aux <= "0101"; -- NOR
				when "100110" =>
					aux <= "0110"; -- XOR
				when "000000" =>
					aux <= "0111"; -- SLL
				when "000010" =>
					aux <= "1000"; -- SRL
				when "000011" =>
					aux <= "1001"; -- SRA
				when "001000" => -- JR
					Jr <= '1';
					aux <= "1111";
				when others => 
					aux <= (others => 'X');
			end case;
		when "011" =>
			aux <= "0010"; -- ADDI
		when "100" =>
			aux <= "0000"; --ANDI
		when "101" =>
			aux <= "0001"; --ORI
		when "110" =>
			aux <= "0110"; --XORI
		when "111" =>
			aux <= "0100"; --SLTI
		when others =>
			aux <= (others => 'X');
	end case;
end process;
end Behavioral;