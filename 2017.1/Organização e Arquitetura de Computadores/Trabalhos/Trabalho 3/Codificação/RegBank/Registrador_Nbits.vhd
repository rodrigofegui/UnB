----------------------------------------------------------------------------------
-- Responsáveis:			Danillo Neves
--								Luiz Gustavo
--								Rodrigo Guimarães
-- Ultima mod.:			03/jun/2017 
-- Nome do Módulo:		Registrador 
-- Descrição:				Registrador com largura de palavra parametrizável
--								e com habilitação
----------------------------------------------------------------------------------

----------------------------------
--	Importando a biblioteca IEEE e especificando o uso dos estados lógicos 
--	padrão
----------------------------------
library IEEE;
	use IEEE.STD_LOGIC_1164.ALL;

----------------------------------
--	Definiçao da entidade
----------------------------------
entity Registrador_Nbits is
	Generic	(N					: integer := 32);
	Port 		(clk, rst, ce	: in	std_logic;
				 D					: in	std_logic_vector(N - 1 downto 0);
				 Q					: out	std_logic_vector(N - 1 downto 0));
end Registrador_Nbits;

----------------------------------
--	Descritivo da operacionalidade da entidade
----------------------------------
architecture Registrador_Nbits_Op of Registrador_Nbits is
begin
	process (clk, rst)
	begin
		if rst = '1' then
			Q <= (others => '0');
		elsif rising_edge(clk) then
			if ce = '1' then
				Q <= D;
			end if;
		end if;
	end process;
end architecture Registrador_Nbits_Op;
