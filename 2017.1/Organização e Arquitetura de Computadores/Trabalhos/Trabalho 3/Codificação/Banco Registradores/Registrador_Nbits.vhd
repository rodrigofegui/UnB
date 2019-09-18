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
--	Definiçao da entidade:
--		N - controle da palavra
--		clk - clock
--		D - dado de entrada
--		Q - saida
----------------------------------
entity Registrador_Nbits is
	Generic	(N		: integer := 16);
	Port 		(clk	: in	std_logic;
				 D		: in	std_logic_vector(N - 1 downto 0) := (others => '0');
				 Q		: out	std_logic_vector(N - 1 downto 0) := (others => '0'));
end Registrador_Nbits;

----------------------------------
--	Descritivo da operacionalidade da entidade
----------------------------------
architecture Comportamental of Registrador_Nbits is
begin
	process (clk)
	begin
		if rising_edge(clk) then
			Q <= D;
		end if;
	end process;
end architecture Comportamental;
