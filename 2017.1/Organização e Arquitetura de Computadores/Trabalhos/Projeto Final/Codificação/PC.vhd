--MÃƒÂ³dulo para contador de programa PC
--Declaracao de bibliotecas
library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity PC is
	generic (DATA_WIDTH : natural := 32); --ULA faz operacoes com dados de 32 bits
	port (
		clk, rst : in std_logic;
		add_in: in std_logic_vector(DATA_WIDTH-1 downto 0) := (others => '0');
		add_out: out std_logic_vector(DATA_WIDTH-1 downto 0)
	);
end entity PC;

architecture Behavioral of PC is

begin

	process(clk, rst)
	begin
		if (rst = '0') then
			add_out <= (others => '0');	--endereco inicial
		else 
			if rising_edge(clk) then
				add_out <= add_in;	--o valor da entrada ira passar para saida
			end if;
		end if;
	end process;
	
end Behavioral;