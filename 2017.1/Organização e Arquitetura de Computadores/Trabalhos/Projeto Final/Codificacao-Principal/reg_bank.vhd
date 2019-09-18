--mÃ³dulo para o banco de registradores
--Bibliotecas
library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity reg_bank is --declaracao de entidade

	generic (
	DATA_WIDTH : natural := 32; --32 bits dos dados
	ADDRESS_WIDTH : natural := 5 --5 bits para representar enderecos
	);

	port (--declaracao de entradas e saidas
	clk, wren : in std_logic;
	radd1, radd2, radd3, wadd : in std_logic_vector(ADDRESS_WIDTH-1 downto 0);
	wdata : in std_logic_vector(DATA_WIDTH -1 downto 0);
	rdata1, rdata2, rdata3: out std_logic_vector(DATA_WIDTH -1 downto 0)
	);

end entity reg_bank;

architecture Behavioral of reg_bank is
	type regArray is array(0 to DATA_WIDTH-1) of std_logic_vector(DATA_WIDTH-1 downto 0);
	signal reg_bank : regArray;-- matriz 32 por 32 dos registradores

begin
	escrita: process(clk) --processo para escrita
		variable aux: integer;--auxiliar para conversao de tipos
	begin
		if (clk'event and clk = '1') then--executado na subida do clock
			aux := to_integer(unsigned(wadd));
			if ((wren = '1') and (aux/= 0)) then --escrita deve estar habilitada e nao pode alterar registrador zero
				if ((wadd /= radd1) and (wadd /= radd2)) then --leitura tem precedencia sobre escrita
					reg_bank(aux) <= wdata; --registrador armazena o dado
				end if;
			end if;		
		end if;
	end process;

	
	--rdata1 <= (others=>'0') when to_integer(unsigned(radd1)) = 0 else reg_bank(to_integer(unsigned(radd1))); -- registrador zero sempre contem valor nulo
	--rdata2 <= (others=>'0') when to_integer(unsigned(radd2)) = 0 else reg_bank(to_integer(unsigned(radd2)));
	
	rdata1 <= reg_bank(to_integer(unsigned(radd1))); -- registrador zero sempre contem valor nulo
	rdata2 <= reg_bank(to_integer(unsigned(radd2)));
	rdata3 <= reg_bank(to_integer(unsigned(radd3)));

end Behavioral;