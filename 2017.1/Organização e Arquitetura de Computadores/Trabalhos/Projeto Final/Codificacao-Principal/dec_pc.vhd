--MÃ³dulo para definir valor de pc a ser destinado ao display 7 segmentos
library IEEE; 
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;

entity dec_pc is
  generic(N: integer := 7; M: integer := 32);
  port(
			clk, rst : in std_logic;
			SW 	:  in  STD_LOGIC_VECTOR(M-1 downto 0);
			HEX0 	: out STD_LOGIC_VECTOR(6 downto 0);
			HEX1 	: out STD_LOGIC_VECTOR(6 downto 0);
			HEX2 	: out STD_LOGIC_VECTOR(6 downto 0);
			HEX3 	: out STD_LOGIC_VECTOR(6 downto 0);
			HEX4 	: out STD_LOGIC_VECTOR(6 downto 0);
			HEX5 	: out STD_LOGIC_VECTOR(6 downto 0);
			HEX6 	: out STD_LOGIC_VECTOR(6 downto 0);
			HEX7 	: out STD_LOGIC_VECTOR(6 downto 0)
		);
end;

architecture dec_pc_arch of dec_pc is

-- signals                                                   
signal dout : STD_LOGIC_VECTOR(31 DOWNTO 0);

begin
	
	i1 : entity work.PC
	generic map(DATA_WIDTH => M)
	port map (
					clk => clk,
					rst => rst,
					add_in => SW,
					add_out => dout
				);
				
	i2 : entity work.seven_seg_decoder
	port map (
					data => dout(3 downto 0),
					segments => HEX0
				);
	
	i3 : entity work.seven_seg_decoder
	port map (
					data => dout(7 downto 4),
					segments => HEX1
				);

	i4 : entity work.seven_seg_decoder
	port map (
					data => dout(11 downto 8),
					segments => HEX2
				);
	i5 : entity work.seven_seg_decoder
	port map (
					data => dout(15 downto 12),
					segments => HEX3
				);
	
	i6 : entity work.seven_seg_decoder
	port map (
					data => dout(19 downto 16),
					segments => HEX4
				);

	i7 : entity work.seven_seg_decoder
	port map (
					data => dout(23 downto 20),
					segments => HEX5
				);
				
	i8 : entity work.seven_seg_decoder
	port map (
					data => dout(27 downto 24),
					segments => HEX6
				);
	
	i9 : entity work.seven_seg_decoder
	port map (
					data => dout(31 downto 28),
					segments => HEX7
				);
	
end;