--Mux de 3 entradas de 5 bits e uma saida de 5 bits. Usado para endereços de registradores
library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity mux_5bits is
	port (sel	: in std_logic_vector(1 downto 0) := "00";
			dataIn1, dataIn2, dataIn3 : in std_logic_vector (4 downto 0);
			dataOut : out std_logic_vector(4 downto 0));
end entity mux_5bits;

architecture Behavioral of mux_5bits is
begin
	WITH sel SELECT
		dataOut	<=	dataIn1 when "00",
						dataIn2 when "01",
						dataIn3 when "10",
						(others => '0') when others;	
end Behavioral;
