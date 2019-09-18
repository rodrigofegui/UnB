--Módulo somador simples de duas entradas
--usado para obter pc+4 e tambem para calcular o endereço destino de um branch
library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity somador is
	generic (DATA_WIDTH : natural := 32);
	port (
		dataIn1, dataIn2 : in std_logic_vector (DATA_WIDTH - 1 downto 0);
		dataOut : out std_logic_vector (DATA_WIDTH - 1 downto 0));
end entity somador;

architecture Behavioral of somador is

begin
	process(dataIn1, dataIn2)
	begin
		dataOut <= std_logic_vector(unsigned(dataIn1) + signed(dataIn2));
	end process;
	
end Behavioral;
