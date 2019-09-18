----------------------------------------------------------------------------------
-- Organizacao e Arquitetura de Computadores
-- Professor: Marcelo Grandi Mandelli
-- Responsaveis:			Danillo Neves
--								Luiz Gustavo
--								Rodrigo GuimarÃ£es
----------------------------------------------------------------------------------

LIBRARY ieee;                                               
USE ieee.std_logic_1164.all;    
USE ieee.numeric_std.all;    

ENTITY somador_tb IS
	GENERIC (DATA_WIDTH : natural := 32);
END somador_tb;



ARCHITECTURE somador_arch OF somador_tb IS	
	COMPONENT somador --componente que sera testado
		port (dataIn1, dataIn2 : in std_logic_vector (DATA_WIDTH - 1 downto 0);
				dataOut : out std_logic_vector (DATA_WIDTH - 1 downto 0));
	END COMPONENT;
	
	SIGNAL ent1, ent2, saida : std_logic_vector (DATA_WIDTH - 1 downto 0) := (others => '0');

BEGIN
	SomadorTB : somador PORT MAP (ent1, ent2, saida);
	Stimulus : PROCESS
	BEGIN
		wait for 5 ns;
		ent1 <= x"00000000000000000000000000000101";
		ent2 <= x"00000000000000000000000000000101";
		
		wait for 10 ns;
		ent1 <= x"00000000000000000000000000000101";
		ent2 <= x"00000000000000000000000000001010";
		
		wait for 10 ns;
		ent1 <= x"00000000000000000000000000011001";
		ent2 <= x"00000000000000000000000001001001";
		
		wait for 10 ns;
		ent1 <= x"00000000000010000000000000011001";
		ent2 <= x"00000000000010000000000001001001";
	END PROCESS Stimulus;
			
END somador_arch; --fim do testbench