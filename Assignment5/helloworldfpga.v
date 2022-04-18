/*BCD to 7 segment display decoder
January 21,2021
Code by G V V Sharma
Released under GNU GPL
*/

//declaring the blink module
module helloworldfpga(

input  wire U,
input  wire V,
input  wire W,


output wire a

);


//Display Decoder
always @(*)
begin

a=(!U|V)&(!V|!W);


end
endmodule
//end of the module
