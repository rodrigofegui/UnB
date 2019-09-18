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
--	Definiçao da entidade:
--		DATA_WIDTH - palavra
--		ADDRESS_WIDTH - enderecamento dos registradores
--		AMOUNT_REG - qnt de registradores possiveis
--		clk - clock de sincronizacao
--		wren - habilitar escrita
--		radd1 - endereço leitura 1
--		radd2 - endereço leitura 2
--		wadd - endereço escrita
--		wdata - dado escrita
--		rdata1 - dado escrita 1
--		rdata2 - dado escrita 2
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
	--	Componente descrito no proprio arquivo *.vhd
	component Registrador_Nbits is
		Generic	(N		: integer := DATA_WIDTH);
		Port 		(clk	: in	std_logic;
					 D		: in	std_logic_vector(N - 1 downto 0) := (others => '0');
					 Q		: out	std_logic_vector(N - 1 downto 0));
	end component;
	
	--	Manipuladores dos registradores do banco
	type vector_array is array (natural range <>) of std_logic_vector(DATA_WIDTH - 1 downto 0);
	signal D				: vector_array(0 to AMOUNT_REG - 1);
	signal Q				: vector_array(0 to AMOUNT_REG - 1);

begin
	-- Geraçao do banco de registradores
	Reg_Index:	for i in 0 to AMOUNT_REG - 1 generate
						Regx : Registrador_Nbits port map
								 (clk, D(i), Q(i));
					end generate Reg_Index;

	Sincronizacao: process (clk)
	begin
		-- Sincronizado com o flanco de subida
		if rising_edge(clk) then
			-- Nao havendo escrita habilitada, so le
			if wren = '0' then
				rdata1 <= Q(to_integer(unsigned(radd1)));
				rdata2 <= Q(to_integer(unsigned(radd2)));
			
			-- Com a escrita habilitada
			else
				-- Sendo diferente do $zero, escreve-se
				if to_integer(unsigned(wadd)) /= 0 then
					D(to_integer(unsigned(wadd))) <= wdata;
				end if;
				
				-- Se WADD != RADD1, se le; senao le 0
				if to_integer(unsigned(wadd)) /= to_integer(unsigned(radd1)) then
					rdata1 <= Q(to_integer(unsigned(radd1)));
				else
					rdata1 <= (others => '0');
				end if;
				
				-- Leitura: WADD != RADD2; senao le 0
				if to_integer(unsigned(wadd)) /= to_integer(unsigned(radd2)) then
					rdata2 <= Q(to_integer(unsigned(radd2)));
				else
					rdata2 <= (others => '0');
				end if;
			end if;
		end if;
	end process Sincronizacao;
end architecture RegBank_Op;