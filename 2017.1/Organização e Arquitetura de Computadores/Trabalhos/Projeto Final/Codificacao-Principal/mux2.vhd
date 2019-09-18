--Mux de duas entradas de 32 bits e uma saida de 32 bits. Usado para tratar dados
library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity mux2 is
	generic (DATA_WIDTH : natural := 32);
	port (sel	: in std_logic := '0';
			dataIn1, dataIn2 : in std_logic_vector (DATA_WIDTH - 1 downto 0);
			dataOut : out std_logic_vector(DATA_WIDTH - 1 downto 0));
end entity mux2;

architecture Behavioral of mux2 is
begin
	WITH sel SELECT
		dataOut	<=	dataIn1 when '0',
						dataIn2 when '1',
						(others => '0') when others;	
end Behavioral;
