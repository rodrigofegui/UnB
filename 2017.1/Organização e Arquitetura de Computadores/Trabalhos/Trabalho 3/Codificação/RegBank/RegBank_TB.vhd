----------------------------------------------------------------------------------
-- Responsáveis:			Danillo Neves
--								Luiz Gustavo
--								Rodrigo Guimarães
-- Ultima mod.:			03/jun/2017 
-- Nome do Módulo:		TestBench do Banco de Registradores
-- Descrição:				TestBench para o Conjunto de registradores com largura de
--								palavra parametrizável e com habilitação
----------------------------------------------------------------------------------

----------------------------------
--	Importando a biblioteca IEEE e especificando o uso dos estados lógicos 
--	padrão
----------------------------------
LIBRARY ieee;
	use ieee.std_logic_1164.all;
	use ieee.numeric_std.all;

----------------------------------
--	Definiçao da entidade
----------------------------------
entity RegBank_TB is
	Generic	(DATA_WIDTH 	: natural := 32;
				 ADDRESS_WIDTH : natural := 5;
				 AMOUNT_REG		: natural := 32);
end RegBank_TB;

----------------------------------
--	Descritivo da operacionalidade da entidade
----------------------------------
architecture RegBank_TB_Op of RegBank_TB is
	component RegBank is
		Generic	(DATA_WIDTH 	: natural := 32;
					 ADDRESS_WIDTH : natural := 5;
					 AMOUNT_REG		: natural := 32);
		Port		(clk, wren		: in std_logic;
					 radd1, radd2	: in std_logic_vector(ADDRESS_WIDTH-1 downto 0);
					 wadd 			: in std_logic_vector(ADDRESS_WIDTH-1 downto 0);
					 wdata			: in std_logic_vector(DATA_WIDTH-1 downto 0);
					 rdata1, rdata2: out std_logic_vector(DATA_WIDTH-1 downto 0));
	end component;
	
	type vector_array1 is array (natural range <>) of std_logic_vector(ADDRESS_WIDTH-1 downto 0);
	type vector_array2 is array (natural range <>) of std_logic_vector(DATA_WIDTH-1 downto 0);
	
	signal	CLK 				: std_logic	:= '0';
	constant PERIOD			: time		:= 5 ps;
	
	signal 	WREN 				: std_logic;
	signal	RADD1, RADD2	: std_logic_vector(ADDRESS_WIDTH - 1 downto 0);
	signal	WADD				: std_logic_vector(ADDRESS_WIDTH - 1 downto 0);
	signal	WDATA				: std_logic_vector(DATA_WIDTH - 1 downto 0);
	signal	RDATA1, RDATA2	: std_logic_vector(DATA_WIDTH - 1 downto 0);

begin
	CLK <= not CLK after PERIOD;

	RB_TB: RegBank port map
			 (CLK, WREN,
				RADD1, RADD2,
				WADD,
				WDATA,
				RDATA1, RDATA2);
				
	teste: process
		variable init0 : std_logic := '0';
		variable init1	: std_logic_vector(ADDRESS_WIDTH - 1 downto 0) := (others => '0');
		variable init2	: std_logic_vector(DATA_WIDTH - 1 downto 0) := (others => '0');
		variable	ender	: vector_array1(7 downto 0);
		variable	valor	: vector_array2(15 downto 0);
	begin
		WREN <= init0;
		RADD1 <= init1;
		RADD2 <= init1;
		WADD <= init1;
		WDATA <= init2;
		RDATA1 <= init2;
		RDATA2 <= init2;
		
		ender(0) := "00000";
		ender(1) := "11111";
		ender(2) := "00110";
		ender(3) := "01101";
		ender(4) := "00011";
		ender(5) := "01010";
		ender(6) := "01110";
		ender(7) := "00010";
		
		valor(0) := x"00025900";
		valor(1) := x"00026797";
		valor(2) := x"00092430";
		valor(3) := x"00059664";
		valor(4) := x"00008572";
		valor(5) := x"00004416";
		valor(6) := x"00000016";
		valor(7) := x"00030581";
		valor(8) := x"00006963";
		valor(9) := x"00009871";
		valor(10) := x"00091257";
		valor(11) := x"00082022";
		valor(12) := x"00089633";
		valor(13) := x"00058236";
		valor(14) := x"00052965";
		valor(15) := x"00000001";
		
		for var1 in std_logic range '0' to '1' loop
			WREN <= var1;
			wait for PERIOD;
			
			for var2 in ender'range loop
				WADD <= ender(var2);
				wait for PERIOD;
				
				for var3 in valor'range loop
					WDATA <= valor(var3);
					wait for PERIOD;
					
					report "Testando WREN = " & std_logic'image(WREN) severity NOTE;
					report "Testando WADD = " & integer'image(to_integer(unsigned(WADD))) & " e WDATA = " & integer'image(to_integer(unsigned(WDATA))) severity NOTE;
					
				end loop;
			end loop;
		end loop;
		wait for PERIOD;
	end process teste;
end architecture RegBank_TB_Op;