----------------------------------------------------------------------------------
-- Responsáveis:			Danillo Neves
--								Luiz Gustavo
--								Rodrigo Guimarães
-- Ultima mod.:			03/jun/2017 
-- Nome do Módulo:		TestBank do Banco de Registradores
-- Descrição:				TestBank para o Conjunto de registradores com largura de
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
entity RG_tb is
	Generic	(DATA_WIDTH_GB 	: natural := 32;
				 ADDRESS_WIDTH_GB : natural := 5;
				 AMOUNT_REG_GB		: natural := 32);
end RG_tb;

----------------------------------
--	Descritivo da operacionalidade da entidade
----------------------------------
architecture RG_tb_Op of RG_tb is
	--	Componente descrito no proprio arquivo *.vhd
	component RegBank is
		Generic	(DATA_WIDTH 	: natural := DATA_WIDTH_GB;
					 ADDRESS_WIDTH : natural := ADDRESS_WIDTH_GB;
					 AMOUNT_REG		: natural := AMOUNT_REG_GB);
		Port		(clk, wren		: in std_logic;
					 radd1, radd2	: in std_logic_vector(ADDRESS_WIDTH - 1 downto 0);
					 wadd 			: in std_logic_vector(ADDRESS_WIDTH - 1 downto 0);
					 wdata			: in std_logic_vector(DATA_WIDTH - 1 downto 0);
					 rdata1, rdata2: out std_logic_vector(DATA_WIDTH - 1 downto 0));
	end component;
	
	type vector_array  is array (natural range <>) of std_logic_vector(ADDRESS_WIDTH_GB - 1 downto 0);
	type vector_array2 is array (natural range <>) of std_logic_vector(DATA_WIDTH_GB - 1 downto 0);
	
	-- Clock e periodo de mudanca
	signal	CLK 				: std_logic	:= '0';
	constant PERIOD			: time		:= 25 us;
	constant PAUSA				: time		:= 24 us;
	
	--	Manipuladores do banco de registradores
	signal 	WREN 				: std_logic;
	signal	RADD1, RADD2	: std_logic_vector(ADDRESS_WIDTH_GB - 1 downto 0);
	signal	WADD				: std_logic_vector(ADDRESS_WIDTH_GB - 1 downto 0);
	signal	WDATA				: std_logic_vector(DATA_WIDTH_GB - 1 downto 0);
	signal	RDATA1, RDATA2	: std_logic_vector(DATA_WIDTH_GB - 1 downto 0);

begin
	-- Gerar clock
	CLK <= not(CLK) after PERIOD;

	-- Manipulador do Banco de Registradores
	RB_TB: RegBank port map(CLK, WREN,
									RADD1, RADD2,
									WADD,
									WDATA,
									RDATA1, RDATA2);
				
	-- Teste em si
	teste: process
		variable init0 : std_logic := '0';
		variable init1	: std_logic_vector(ADDRESS_WIDTH_GB - 1 downto 0) := (others => '0');
		variable init2	: std_logic_vector(DATA_WIDTH_GB - 1 downto 0) := (others => '0');
		variable	ender	: vector_array(0 to 7);
		variable	valor	: vector_array2(0 to 15);
	begin
		-- Inicializaçao para o teste
		WREN <= init0;
		RADD1 <= init1;
		RADD2 <= init1;
		WADD <= init1;
		WDATA <= init2;
		RDATA1 <= init2;
		RDATA2 <= init2;
		
		-- Valores aleatorios para escrita
		valor(00) := x"00025900";
		valor(01) := x"00026797";
		valor(02) := x"00092430";
		valor(03) := x"00059664";
		valor(04) := x"00008572";
		valor(05) := x"00004416";
		valor(06) := x"00000016";
		valor(07) := x"00030581";
		valor(08) := x"00006963";
		valor(09) := x"00009871";
		valor(10) := x"00091257";
		valor(11) := x"00082022";
		valor(12) := x"00089633";
		valor(13) := x"00058236";
		valor(14) := x"00052965";
		valor(15) := x"00000001";
		
		-- Teste com WREN em '1' e em '0'
		for enable in std_logic range '1' downto '0' loop
			WREN <= enable;
			
			-- Escrevendo valores nos registradores
			for valorAtri in valor'range loop
				WDATA <= valor(valorAtri);
				
				-- Acesso ao endereco para escrita, para todos os registradores
				--	incluindo o $zero (o mesmo nao deve ser alterado)
				for endereco in 0 to AMOUNT_REG_GB loop
					WADD <= std_logic_vector(to_signed(endereco, WADD'length));
					
					report "Com WREN = " & std_logic'image(WREN) severity NOTE;
					report "Escreveu-se -> " & integer'image(to_integer(unsigned(WADD)))
								& " no end. -> " & integer'image(to_integer(unsigned(WDATA))) severity NOTE;
					
					wait for 2 * PERIOD;
					
					-- Testando leitura, com e sem a habilitacao do WREN
					-- com RADD1 e RADD2 para todas as possibilidades;
					--	Considera-se leitura e escrita para o mesmo registrador
					for leitura1 in 0 to AMOUNT_REG_GB loop
						RADD1 <= std_logic_vector(to_signed(leitura1, RADD1'length));
						
						for leitura2 in 0 to AMOUNT_REG_GB loop
							RADD2 <= std_logic_vector(to_signed(leitura2, RADD2'length));
							
							report "Com WREN = " & std_logic'image(WREN) severity NOTE;
							report "Leu-se -> " & integer'image(to_integer(unsigned(RDATA1))) & " do end. -> " & integer'image(to_integer(unsigned(RADD1))) severity NOTE;
							report "Leu-se -> " & integer'image(to_integer(unsigned(RDATA2))) & " do end. -> " & integer'image(to_integer(unsigned(RADD2))) severity NOTE;
							
							wait for 2 * PERIOD;
						end loop;
					end loop;
				end loop;
			end loop;
		end loop;
	end process teste;
end architecture RG_tb_Op;