--Decodificar registrador para apÃƒÆ’Ã‚Â³s mostrar seu conteudo no display 7 segmentos
library IEEE; 
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;

entity dec_reg is
  generic(N: integer := 5; M: integer := 32);
  port(
			clk : in std_logic;
			SW 	:  in  STD_LOGIC_VECTOR(N-1 downto 0);
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

architecture dec_reg_arch of dec_reg is

-- signals                                                   
signal din : STD_LOGIC_VECTOR(31 DOWNTO 0);
signal dout : STD_LOGIC_VECTOR(31 DOWNTO 0);
signal dout2, dout3 : STD_LOGIC_VECTOR(31 DOWNTO 0);
signal we : STD_LOGIC := '0';

begin

	we <= '0';
	din <= (others => '0');
	
	i1 : entity work.reg_bank
	generic map(DATA_WIDTH => M, ADDRESS_WIDTH => N)
	port map (
					clk => clk,
					wren => we,
					radd1 => "00000",
					radd2 => "00000",
					radd3 => SW,
					wadd => "UUUUU",
					rdata1 => dout2,
					rdata2 => dout3,
					rdata3 => dout,
					wdata => din
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