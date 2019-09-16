--mÃƒÆ’Ã‚Â³dulo de memÃƒÆ’Ã‚Â³ria de instruÃƒÆ’Ã‚Â§ÃƒÆ’Ã‚Âµes
library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity mi is
	generic(N: integer := 7; M: integer := 32);
	port (clk : in std_logic := '0';
			address	: in std_logic_vector(N - 1 downto 0) := (others => '0');
			instruction : out std_logic_vector(M - 1 downto 0));
end entity mi;

architecture Behavioral of mi is

signal aux : std_logic_vector(N-1 downto 0); 

type mem_array is array(0 to (2**N-1)) of STD_LOGIC_VECTOR(M-1 downto 0);
signal mem: mem_array := (
									x"2008000f",
									x"20090025",
									x"01095020",
									x"01095020",
									x"01095020",
									x"01095020",
									x"01285822",
									x"01286024",
									x"01286825",
									x"01287027",
									x"01287826",
									x"00089100",
									x"000e9842",
									x"000ea043",
									x"353500ff",
									x"393600ff",
									x"313600ff",
									x"29160014",
									x"29150001",
									x"20152000",
									x"8eb60000",
									x"8eb70004",
									x"aeac0008",
									x"0128802a",
									x"16000005",
									x"0109882a",
									x"16200003",
									x"0c000021",
									x"08000023",
									x"00000020",
									x"12200004",
									x"00000020",
									x"0800001b",
									x"03e00008",
									x"00000020",
									x"08000023",
									others => (others => '0')
								);

begin
	aux <= address;
	-- aux <= address(8) & address(7) & address(6) & address(5) & 
	--			address(4) & address(3) & address(2);
	
	process(clk)
	begin
		if rising_edge(clk) then 
				instruction <= mem(to_integer(unsigned(aux)));
		end if;
	end process;
end Behavioral;
