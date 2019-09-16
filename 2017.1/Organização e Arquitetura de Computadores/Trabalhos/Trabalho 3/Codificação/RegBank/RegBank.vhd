----------------------------------------------------------------------------------
-- Responsáveis:			Danillo Neves
--								Luiz Gustavo
--								Rodrigo Guimarães
-- Ultima mod.:			03/jun/2017 
-- Nome do Módulo:		Banco de Registradores
-- Descrição:				Conjunto de registradores com largura de palavra parametrizável
--								e com habilitação
----------------------------------------------------------------------------------

----------------------------------
--	Importando a biblioteca IEEE e especificando o uso dos estados lógicos 
--	padrão
----------------------------------
library	ieee;	
	use	ieee.std_logic_1164.all;
	use 	ieee.std_logic_unsigned.all;
	use	ieee.numeric_std.all;

----------------------------------
--	Definiçao da entidade
----------------------------------
entity RegBank is
	Generic	(DATA_WIDTH 	: natural := 32;
				 ADDRESS_WIDTH : natural := 5;
				 AMOUNT_REG		: natural := 32);
	Port		(clk, wren		: in std_logic;
				 radd1, radd2	: in std_logic_vector(ADDRESS_WIDTH - 1 downto 0);
				 wadd 			: in std_logic_vector(ADDRESS_WIDTH - 1 downto 0);
				 wdata			: in std_logic_vector(DATA_WIDTH - 1 downto 0);
				 rdata1, rdata2: out std_logic_vector(DATA_WIDTH - 1 downto 0));
end entity RegBank;

----------------------------------
--	Descritivo da operacionalidade da entidade
----------------------------------
architecture RegBank_Op of RegBank is
	-- Modelo de Registrador a ser utilizado no banco
	component Registrador_Nbits is
		Generic	(N					: integer := DATA_WIDTH);
		Port 		(clk, rst, ce	: in	std_logic;
					 D					: in	std_logic_vector(N - 1 downto 0);
					 Q					: out	std_logic_vector(N - 1 downto 0));
	end component;
	
	--	Manipuladores dos registradores do banco
	type vector_array is array (natural range <>) of std_logic_vector(DATA_WIDTH - 1 downto 0);
	signal RST	: std_logic_vector(AMOUNT_REG - 1 downto 0);
	signal CE	: std_logic_vector(AMOUNT_REG - 1 downto 0);
	signal D		: vector_array(AMOUNT_REG - 1 downto 0);
	signal Q		: vector_array(AMOUNT_REG - 1 downto 0);

begin
	-- Geraçao do banco de registradores
	Reg_Index:	for i in 0 to AMOUNT_REG - 1 generate
						Regx : Registrador_Nbits port map
								 (clk, RST(i), CE(i), D(i), Q(i));
					end generate Reg_Index;

	Sincronizacao: process (clk)
	begin
		if rising_edge(clk) then
			if wren = '1' and  to_integer(unsigned(wadd)) /= 0 then -- (unsigned(wadd))
				D(to_integer(unsigned(wadd))) <= wdata;
			end if;

			rdata1 <= Q(to_integer(unsigned(radd1)));
			rdata2 <= Q(to_integer(unsigned(radd2)));
		end if;
	end process Sincronizacao;
end architecture RegBank_Op;