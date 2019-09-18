----------------------------------------------------------------------------------
-- Organizacao e Arquitetura de Computadores
-- Professor: Marcelo Grandi Mandelli
-- Responsaveis:			Danillo Neves
--								Luiz Gustavo
--								Rodrigo Guimaraes
----------------------------------------------------------------------------------

LIBRARY ieee;                                               
USE ieee.std_logic_1164.all;    
use ieee.numeric_std.all;    

ENTITY Uniciclo_tb IS
	generic (
		DATA_WIDTH : natural := 32; --32 bits para dados
		ADDRESS_WIDTH : natural := 5 --5 bits para endereco
	);
END Uniciclo_tb;



ARCHITECTURE Uniciclo_arch OF Uniciclo_tb IS    
	--declaracao de sinais
	SIGNAL clk : std_logic := '1';
	SIGNAL SW : std_logic_vector(13 downto 0);
	SIGNAL HEX0, HEX1, HEX2, HEX3, HEX4, HEX5, HEX6, HEX7: std_logic_vector(6 downto 0);
	
	COMPONENT Uniciclo --componente que sera testado
		port (
			clk : in std_logic := '1';
			SW  : in std_logic_vector(13 downto 0);
			HEX0, HEX1, HEX2, HEX3, HEX4, HEX5, HEX6, HEX7: out std_logic_vector(6 downto 0)
		);
	END COMPONENT;

	BEGIN
		i1 : Uniciclo
		PORT MAP (
			clk => clk,
			SW => SW,
			HEX0 	=>HEX0,
			HEX1 	=>HEX1,
			HEX2 	=>HEX2,
			HEX3 	=>HEX3,
			HEX4 	=>HEX4,
			HEX5 	=>HEX5,
			HEX6 	=>HEX6,
			HEX7 	=>HEX7
		);
			
		Clk_process : PROCESS --geracao do clock
			variable auxMod : integer;
		BEGIN
			for op in 0 to 16383 loop
				SW <= std_logic_vector(to_signed(op, SW'length));
				for i in 0 to 255 loop
					clk <= not(clk);
					wait for 5 ps;
				end loop;
			end loop;
		END PROCESS Clk_process;
			
END Uniciclo_arch; --fim do testbench