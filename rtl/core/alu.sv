import alu::*;

module Alu #(
	parameter D = 8
) (
	input [D-1:0]  a,
 	input [D-1:0]  b,
 	input Immed    n,
 	input AluCmd   cmd,
 	output logic [D-1:0] x
);

	always_comb begin
		case (cmd)
			ADD: x <= a + b;
			NAND: x <= ~(a & b);
			SHFT: x <= n.flag ? a >> n.shamt : a << n.shamt;
			default: x <= 'x;
		endcase
	end

endmodule : Alu

/* 
Decisão aberta para mudanças:
Coloquei a entrada do offset 'n' como um barramento separado da entrada b,
já que o n é um imediato de 4 bits enquanto o b é o conteúdo de um registrador
de 8 bits. Isso simplifica a necessidade de um mux externo, mas conta com um 
barramento adicional. De qualquer modo, pra implementar instruções como Fetch
e Send, será necessário multiplexar a entrada b do adder (ou adicionar outro
adder), afim de somar o conteúdo de um registrador a um imediato. 
Esse é um estudo que exige uma análise de temporização, consumo de 
área/energia e etc. que provavelmente terá resultados diferentes dependendo 
das outras funções implementadas nativamente para a Ula, portanto, creio que
deva ser mantido sobre supervisão.
*/